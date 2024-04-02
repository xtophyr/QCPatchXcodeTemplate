extern NSString * const QCViewDidEnterFullScreenNotification;
extern NSString * const QCViewDidExitFullScreenNotification;
extern NSString * const QCViewDidSetPatchNotification;
extern NSString * const QCViewDidStartRenderingNotification;
extern NSString * const QCViewDidStopRenderingNotification;

/* kQCOptionFlags are OR'd together. */
typedef enum {
    kQCOptionFlagDisableDoubleBuffering = 0x1,
    kQCOptionFlagDisableDepthBuffer     = 0x2,
    kQCOptionFlagSoftwareRendering      = 0x4,
    kQCOptionFlagDisableVBLSyncing      = 0x8,
    // multithreadedOpenGL maybe sets 0x10 (?), but no logging verifies that so far
    // (this ends up being useless anyway, may have been removed)
    // multisampling sets maybe 0x100 (?), but no logging verifies that so far
    kQCOptionFlagAttributeLoading       = 0x10000, // loads attributes, like patch port localizations
    kQCOptionFlagUserInfoLoading        = 0x20000, // loads userInfo data, like patch locations
    kQCOptionFlagRenderingDisabled      = 0x40000, // prevents rendering?
} QCViewOptionFlags;

typedef struct __QCViewPrivateStruct
{
#ifdef __LP64__
    // this may be 0x190 (400) bytes in the latest versions (MacOS 14.4.1) NSAllocateCollectable is called with 0x190 (size), 1 (NSScannedOption)
	void *unknown[39];	// 0x138 (312) bytes alloc'd
    // QCViewOptionFlags _flags is at 0x20 [5]
    // double W:H aspect ratio is at 0xf0:0xf8 [30, 31]
    // 0xc8 contains a dispatch_source
    // 0xc0 contains something that gets dispatch_release'd in -dealloc
    // 0x80 might be a pthread_mutex?
    // the following offsets get -release'd in -dealloc (in this order):
    //   0x10, 0x8, 0x30, 0x38, 0x28, 0x148, 0x160, 0xe0, 0xe8
    //
#else
	void *unknown[43];	// 0x0ac (172) bytes alloc'd
#endif
} QCViewPrivateStruct;


@interface QCView : NSView <QCCompositionRenderer>
{
	void *_QCViewPrivate;	// 80 = 0x50
}

+ (id)defaultRenderingOptions; // always returns nil
+ (void)setDefaultOptionFlags:(QCViewOptionFlags)flags;
+ (void)initialize;
- (Class)valueClassForBinding:(NSBindingName)binding;
- (id)_createLayer;
- (void)setEraseColor:(NSColor*)eraseColor;
- (NSColor*)eraseColor;
- (void)setBackgroundColor:(NSColor*)bgColor;
- (NSColor*)backgroundColor;
- (void)erase;
- (NSImage*)snapshotImage;
- (id)createSnapshotImageOfType:(NSString*)type;
- (QCViewOptionFlags)_flags;
- (void)_updateColorSpace;
- (void)_reconfigure;
- (void)_viewGlobalFrameDidChange:(id)fp8;
- (void)__timebaseChanged:(id)fp8;
- (void)_initializeRenderView;
- (void)_releaseRenderView;
- (id)_backingLayer;
- (void)_finishInitialization;
- (id)initWithFrame:(NSRect)frameRect optionFlags:(NSUInteger)flags;
- (id)initWithFrame:(NSRect)frameRect;
- (void)finalize;
- (void)dealloc;
- (void)resizeSubviewsWithOldSize:(NSSize)fp8;
- (void)setAspectRatio:(NSSize)aspectRatio;
- (NSSize)aspectRatio;
- (void)_setupOpenGLContext;
- (void)lockFocus;
- (void)drawRect:(NSRect)rect;
- (void)_forwardEvent:(NSEvent*)event location:(NSPoint)fp12;
- (void)_renderGLContext;
- (BOOL)_hasSurface;
- (void)_surfaceWillGoAway;
- (void)_surfaceDidComeBack;
- (NSDictionary*)defaultRenderingOptions;
- (float)averageLoad;
- (void)_purgeImageManagerResourcesIfNeeded;
- (id)saveComposition:(BOOL)fp8;
- (BOOL)saveCompositionToFile:(NSString*)path;
- (BOOL)saveCompositionToFile:(NSString*)path flatten:(BOOL)shouldFlatten;
- (BOOL)loadCompositionFromFile:(NSString*)path stateOK:(char *)fp12;
- (BOOL)loadCompositionFromFile:(NSString*)path;
- (BOOL)loadComposition:(id)fp8 options:(id)fp12 stateOK:(char *)fp16;
- (BOOL)isCompositionLoaded;
- (void)encodeWithCoder:(NSCoder *)aCoder;
- (id)initWithCoder:(NSCoder *)aDecoder;
- (void)setEventForwardingMask:(NSUInteger)forwardingMask;
- (NSUInteger)eventForwardingMask;
- (NSUInteger)optionFlags;
- (void)setOptionFlags:(NSUInteger)flags;
- (void)_cleanUpOpenGLContext;
- (void)_windowWillOrderOnScreen:(id)fp8;
- (void)_windowDidOrderOffScreen:(id)fp8;
- (void)_windowScreenDidChange:(id)fp8;
- (void)viewDidMoveToWindow;
- (BOOL)autostartsRendering;
- (void)setAutostartsRendering:(BOOL)autostartsRendering;
- (void)setDrawsBackground:(BOOL)drawsBackground;
- (BOOL)drawsBackground;
- (BOOL)clearsBackground;
- (void)setClearsBackground:(BOOL)clearsBackground;
- (void)setBackgroundCheckerboardSize:(NSUInteger)checkerboardSize;
- (NSUInteger)backgroundCheckerboardSize;
- (id)_compositionInfo;
- (BOOL)_hasTimer;
- (id)_fullScreenWindow;
- (BOOL)isFullScreen;
- (void)setFullScreen:(id)fp8 options:(id)fp12;
- (void)setLayer:(id)fp8;
- (id)openGLContext;
- (id)openGLPixelFormat;
- (void)setPixelAspectRatio:(NSSize)pixelAspectRatio;
- (NSSize)pixelAspectRatio;
- (void)setCleanAperture:(NSRect)aperture;
- (NSRect)cleanAperture;
- (BOOL)mouseDownCanMoveWindow;
- (void)setObservationInfo:(void *)fp8;
- (void *)observationInfo;
- (BOOL)loadComposition:(QCComposition*)composition;
- (QCComposition*)loadedComposition;
- (void)unloadComposition;
- (void)__stateUpdated:(id)fp8;
- (void)_renderTimer;
- (void)_setupRendering;
- (double)nextExecutionTime:(double)time arguments:(NSDictionary*)args;
- (BOOL)renderAtTime:(double)time arguments:(NSDictionary*)args;
- (BOOL)render:(double)time arguments:(NSDictionary*)args;
- (void)_cleanupRendering;
- (void)setPatch:(id)fp8;
- (BOOL)startRendering;
- (BOOL)startRendering:(id)fp8;
- (void)stopRendering;
- (BOOL)isRendering;
- (void)pauseRendering;
- (void)resumeRendering;
- (BOOL)isPausedRendering;
- (float)averageFPS;
- (id)renderingContext;
- (id)patch;
- (void)setRenderTime:(double)renderTime;
- (double)renderTime;
- (void)setMaxRenderingFrameRate:(float)maxFrameRate;
- (float)maxRenderingFrameRate;
- (NSDictionary*)attributes;
- (NSArray*)inputKeys;
- (NSArray*)outputKeys;
- (BOOL)setValue:(id)value forInputKey:(NSString*)key;
- (id)valueForInputKey:(NSString*)key;
- (id)valueForOutputKey:(NSString*)key;
- (id)valueForOutputKey:(NSString*)key ofType:(NSString*)type;
- (id)propertyListFromInputValues;
- (void)setInputValuesWithPropertyList:(id)plist;
- (NSMutableDictionary*)userInfo;
- (void)setInteractive:(BOOL)interactive;
@end

@interface QCView (IBExtensions)
- (void)start:(id)sender;
- (void)stop:(id)sender;
- (void)play:(id)sender;
@end

@interface QCView (EventHandling)
- (id)hitTest:(NSPoint)aPoint;
- (BOOL)acceptsFirstResponder;
- (BOOL)becomeFirstResponder;
- (BOOL)resignFirstResponder;
- (BOOL)acceptsFirstMouse:(NSEvent*)theEvent;
- (NSPoint)_normalizedMouseLocationWithOptionalEvent:(NSEvent*)theEvent;
- (void)keyDown:(NSEvent *)theEvent;
- (void)keyUp:(NSEvent *)theEvent;
- (void)flagsChanged:(NSEvent *)theEvent;
- (void)scrollWheel:(NSEvent *)theEvent;
- (void)mouseDown:(NSEvent *)theEvent;
- (void)mouseMoved:(NSEvent *)theEvent;
- (void)mouseDragged:(NSEvent *)theEvent;
- (void)mouseUp:(NSEvent *)theEvent;
- (void)rightMouseDown:(NSEvent *)theEvent;
- (void)rightMouseDragged:(NSEvent *)theEvent;
- (void)rightMouseUp:(NSEvent *)theEvent;
- (void)otherMouseDown:(NSEvent *)theEvent;
- (void)otherMouseDragged:(NSEvent *)theEvent;
- (void)otherMouseUp:(NSEvent *)theEvent;
- (void)magnifyWithEvent:(NSEvent *)theEvent;
- (void)rotateWithEvent:(NSEvent *)theEvent;
- (void)swipeWithEvent:(NSEvent *)theEvent;
- (void)beginGestureWithEvent:(NSEvent *)theEvent;
- (void)endGestureWithEvent:(NSEvent *)theEvent;
- (void)tabletPoint:(NSEvent *)theEvent;
- (void)tabletProximity:(NSEvent *)theEvent;
- (void)copy:(id)sender;
- (BOOL)wantsBestResolutionOpenGLSurface; // always returns YES (not sure when this was added, probably when retina/2x displays launched)
@end
