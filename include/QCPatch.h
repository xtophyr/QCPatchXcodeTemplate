extern NSString * const QCPatchDidActivateNotification;
extern NSString * const QCPatchDidDeactivateNotification;
extern NSString * const QCPatchDidExecuteNotification;
extern NSString * const QCPatchDidFailNotification;
extern NSString * const QCPatchDidRenderNotification;
extern NSString * const QCPatchDidStartRenderingNotification;
extern NSString * const QCPatchDidStopRenderingNotification;
extern NSString * const QCPatchLogMessageNotification;
extern NSString * const QCPatchParametersViewDidUpdateNotification;
extern NSString * const QCPatchTimebaseDidChangeNotification;

@interface QCPatch : GFGraph
{
	QCPatchRenderingInfo *_renderingInfo;	// 84 = 0x54
	QCRenderState *_renderState;	// 88 = 0x58
	int _executionMode;	// 92 = 0x5c
	QCRenderingManager *_renderingManager;	// 96 = 0x60
	QCPatchExecutionInfo *_executionInfo;	// 100 = 0x64
	NSUInteger _executionFlags;	// 104 = 0x68
	int _timebase;	// 108 = 0x6c
	QCBooleanPort *_enableInput;	// 112 = 0x70
	QCNumberPort *_timeInput;	// 116 = 0x74
	BOOL _enabled;	// 120 = 0x78
	NSUInteger _activeCount;	// 124 = 0x7c
	void *_observationInfo;	// 128 = 0x80
	id _proExtension;       // QCPatchProExtension
	double _unused31[2];	// 136 = 0x88
	NSUInteger _unused32[1];	// 152 = 0x98
}

+ (void)initialize;
+ (id)allocWithZone:(NSZone *)zone;
+ (BOOL)automaticallyNotifiesObserversForKey:(NSString*)key;
- (NSArray *)consumerSubpatches;	// This is likely pricey (no NSArrays are used internally, so they're synthesized on demand)
- (void)setOrder:(NSUInteger)order forConsumerSubpatch:(QCPatch*)patch;   // used to change consumer layer numbers
- (NSUInteger)orderForConsumerSubpatch:(QCPatch*)patch;
- (void)setTimebase:(int)timebase;
- (int)timebase;
- (NSArray *)customInputPorts;
- (NSArray *)customOutputPorts;
- (NSArray *)systemInputPorts;
- (NSArray *)systemOutputPorts;
- (void)applyFunctionOnSubpatches:(void(*)(id patch, void*ctx))function context:(void *)ctx recursive:(BOOL)recurse;
@end


typedef enum
{
	kQCPatchExecutionModeProcessor,	// 0 (e.g., "Math", "Image With String")
	kQCPatchExecutionModeConsumer,	// 1 (e.g., "Clear", "Billboard", "Lighting")
	kQCPatchExecutionModeProvider,	// 2 (e.g., "Mouse", "Interaction", "XML", "Directory Scanner", "Host Info")
	kQCPatchExecutionModeRII1050,	// 3 --- 10.5: RII;     10.6: unused
	kQCPatchExecutionModeRII1060,	// 4 --- 10.5: unused;  10.6: RII      ..?!   auto, based on subpatches?
									// >4 --- invalid (editor throws exception when drawing)
} QCPatchExecutionMode;

typedef enum
{
	kQCPatchTimeModeNone,			// 0 (e.g., "Math", "Image With String")
	kQCPatchTimeModeTimeBase,		// 1 (e.g., "Patch Time", "Interpolation", "Random")
	kQCPatchTimeModeIdle,			// 2 (e.g., "Keyboard", "Mouse", "Tablet", "Repository Compositions")
} QCPatchTimeMode;


@interface QCPatch (Customization)
+ (BOOL)isSafe;															// defaults to NO if unimplemented
+ (QCPatchExecutionMode)executionModeWithIdentifier:(id)identifier;		// defaults to 0 (kQCPatchExecutionModeProcessor) if unimplemented
+ (BOOL)allowsSubpatchesWithIdentifier:(id)identifier;					// defaults to YES if unimplemented
+ (QCPatchTimeMode)timeModeWithIdentifier:(id)identifier;				// defaults to 0 (kQCPatchTimeModeNone) if unimplemented
+ (NSArray*)stateKeysWithIdentifier:(id)identifier;	// NSArray of NSStrings for state keys
+ (id)serializedStateKeysWithIdentifier:(id)identifier;
+ (BOOL)usesLocalContextForIdentifier:(id)identifier;


// name =
//		graphicsContext.frameDidChange
//		graphicsContext.boundsDidChange
//      graphicsContext.colorspaceDidChange     // probably sent when changing displays
//      openGLContext.virtualScreenDidChange    // sent when changing GPUs
//      graphicsContext.qualityDidChange
//		...?
- (void)receiveMessage:(id)context name:(NSString*)name attributes:(id)attrs;

- (BOOL)setup:(QCContext *)context;
- (void)enable:(QCContext*)context;
- (BOOL)execute:(QCContext*)context time:(double)time arguments:(NSDictionary*)args;
- (void)disable:(QCContext*)context;
- (void)cleanup:(QCContext *)context;
- (id)serializedValueForStateKey:(NSString*)key;
- (void)setSerializedValue:(id)value forStateKey:(NSString*)key;

+ (NSMutableDictionary*)cachedStateArrays;    // this returns a dictionary initialized in +initialize that isn't used for anything (it's got cache in the name, so just having it helps performance I guess?)
+ (id)stateArrays;
+ (BOOL)supportsOptimizedExecutionForIdentifier:(id)identifier;	// default to false.  true for QCRenderInImage, QCCamera, QCGLSLShader, QCTrackBall, QCIterator, QCReplicator.  "optimized execution" apparently means something like "can tell you that it doesn't need to run until a specified time" (specified by -nextExecutionTime).
- (double)nextExecutionTime:(QCContext*)context time:(double)time arguments:(NSDictionary*)args;
- (double)nextExecutionTimeForSubpatches:(QCContext*)context time:(double)time arguments:(NSDictionary*)args;
- (void)invalidateDodForSubpatches;
@end

@interface QCPatch (Execution)
- (void)abortExecution;
- (void)suspendExecution;
- (void)resumeExecution;
- (BOOL)isExecutionSuspended;
@end

@interface QCPatch (Extensions)
+ (id)validateResourceURL:(NSURL*)url withOptions:(NSDictionary*)options;
- (BOOL)inSafeMode;
- (id)dataWithContentsOfURL:(NSURL*)url error:(NSError**)error;
- (id)safeURLFromURL:(NSURL*)url;
- (id)safeURLFromString:(NSString*)urlString;
- (void)updateTimebase:(int)timebase;
- (void)setNeedsExecution;
- (BOOL)executeSubpatches:(double)time arguments:(NSDictionary*)args;
- (BOOL)debuggingMode;
- (BOOL)shouldAbortExecution;
- (void)setCustomizedName:(NSString*)name; // sets displayed patch name to "name" (in quotes)
- (BOOL)beginLocalContext;
- (void)endLocalContext;
- (void)setForceInputsUpdate;
- (void)_drawDirtyRect;
@end

@interface QCPatch (File)
+ (BOOL)canInstantiateWithFile:(NSString*)filePath;
+ (id)instantiateWithFile:(NSString*)filePath;
@end

@interface QCPatch (Override)
+ (BOOL)shouldLoadAttributes;
+ (Class)nodeClassDescriptionClass;
+ (Class)baseClass;
+ (Class)proxyPortClass;
+ (Class)connectionClass;
+ (Class)_listClass;
+ (id)_keyFromName:(NSString*)name;
- (id)_baseKey;
- (void)_logMessage:(NSString*)message;
- (id)initWithIdentifier:(NSString*)identifier;
- (void)finalize;
- (void)dealloc;
- (void)encodeWithCoder:(NSCoder *)aCoder;
- (id)initWithCoder:(NSCoder *)aDecoder;
- (id)copyWithZone:(NSZone *)zone;
- (NSDictionary*)state;
- (BOOL)setState:(NSDictionary*)state;
- (void)stateUpdated;
- (id)createInputPortWithArguments:(id)fp8 forKey:(NSString*)key;
- (id)createOutputPortWithArguments:(id)fp8 forKey:(NSString*)key;
- (BOOL)canAddNode:(id)fp8;
- (BOOL)addNode:(id)fp8 forKey:(NSString*)key;
- (void)removeNodeForKey:(NSString*)key;
- (BOOL)canCreateConnectionFromPort:(id)fp8 toPort:(id)fp12;
- (id)createConnectionFromPort:(id)fp8 toPort:(id)fp12 forKey:(NSString*)key;
- (void)deleteConnectionForKey:(id)fp8;
- (id)createProxyPortWithOriginalPort:(id)fp8 forKey:(NSString*)key;
- (void)deleteProxyPortForKey:(NSString*)key;
- (void)deleteInputPortForKey:(NSString*)key;
- (void)deleteOutputPortForKey:(NSString*)key;
- (int)directionForPort:(QCPort*)port;
- (void)setValue:(id)value forKey:(NSString*)key;
- (void)setNilValueForKey:(NSString*)key;
- (id)valueForKey:(NSString*)key;
- (id)customInputPorts;
- (id)customOutputPorts;
- (id)proxyPortForOriginalPort:(QCPort*)port;
- (void)setInputPortOrder:(NSUInteger)order forKey:(NSString*)key;
- (void)setOutputPortOrder:(NSUInteger)order forKey:(NSString*)key;
- (void)setObservationInfo:(void *)observationInfo;
- (void *)observationInfo;
- (void)nodeDidAddToGraph:(id)graph;
@end

@interface QCPatch (Private)
+ (BOOL)setShouldLoadAttributes:(BOOL)shouldLoadAttributes;
- (id)performanceCounters;
- (QCPatchRenderingInfo *)_renderingInfo;	// [QCPatchRenderingInfo context] is a QCOpenGLContext
- (QCOpenGLRenderState *)_renderState;
- (QCPatchExecutionMode)_executionMode;
- (id)_enableInput;
- (int)_checkExecutionMode;
- (void)_invalidateExecutionMode;
- (BOOL)__isPatchInUse:(QCPatch*)patch;
- (void)_invalidateTimeMode;
- (BOOL)_enabled;
- (NSUInteger)_activeCount;
- (void)_resetExecution;
- (BOOL)_setup:(QCPatchRenderingInfo*)info state:(QCRenderState*)state;
- (void)_enable;
- (void)_activate;
- (BOOL)_execute:(double)time arguments:(NSDictionary*)args;
- (void)_deactivate;
- (void)_disable;
- (void)_cleanup;
- (int)_executionFlags;
- (void)_forwardRenderingFlag;
- (double)_nextExecutionTime;
- (void)_resetExecutionFlags;
- (BOOL)_executeSubpatches:(double)time arguments:(NSDictionary*)args;
- (BOOL)_renderAtTime:(double)time arguments:(NSDictionary*)args;
- (BOOL)__execute:(double)time arguments:(NSDictionary*)args;
- (double)_nextExecutionTime:(double)time arguments:(NSDictionary*)args;
- (void)_invalidateDodForSubpatches;
- (void)_QCArrayResetSize:(QCArray*)array newSize:(NSUInteger)newSize;
@end

@interface QCPatch (PrivateRuntime)
- (BOOL)prerenderAtTime:(double)time imageSizeHint:(NSSize)sizeHint arguments:(NSDictionary*)args;
@end

@interface QCPatch (QCInspector)
+ (id)inspectorNibNameWithIdentifier:(id)identifier;
+ (Class)inspectorClassWithIdentifier:(id)identifier;
@end

@interface QCPatch (QCNodeManager)
+ (id)_publicAttributesWithIdentifier:(id)identifier;
+ (id)_privateAttributesWithIdentifier:(id)identifier;
@end

@interface QCPatch (QCOpenGLContext)
- (BOOL)checkForGLError;
@end

@interface QCPatch (QCProFX)
+ (BOOL)getMatrixFrom:(id)fp8 toPatch:(id)fp12 matrix:(CGFloat *)fp16 ignoreWithin:(id)fp20 includeFromTransform:(_Bool)fp24;
- (QCMD5Sum)md5WithTime:(double)time arguments:(id)args;
- (CGFloat *)getTransform;
- (BOOL)patchSetsTransform;
- (void)setPatchSetsTransform:(BOOL)flag;
- (BOOL)patchIsInMacro:(id)fp8;
- (NSUInteger)getNumberOfInputImagePorts;
- (id)getNthInputImagePort:(NSUInteger)index;
- (NSUInteger)getNumberOfInputPorts;
- (id)getNthInputPort:(NSUInteger)index;
- (BOOL)getMatrix:(CGFloat *)fp8;
@end

@interface QCPatch (Registry)
+ (QCNodeManager *)patchManager;    // this sets up some node managers (2?) and then calls _RegisterPatches, which does all patch registration and plugin loading
+ (NSArray *)patchNames;
+ (QCPatch *)patchWithName:(NSString *)name; // deprecated -> +createPatchWithName:
+ (QCPatch *)createPatchWithName:(NSString *)name NS_RETURNS_RETAINED; // creates a new instance
+ (NSDictionary *)patchAttributesWithName:(NSString *)name;
+ (void)registerPatch:(QCPatch *)patch withName:(NSString *)name;
+ (void)loadPlugInAtPath:(NSString*)path;
+ (void)loadPlugInsInFolder:(NSString*)folder;
+ (void)loadPlugInsInLibrary:(NSString*)path; // loads stuff from [1]/Library/[path], where [1] is /System, /, and ~/ (changing on 10.7?)
@end

@interface QCPatch (Runtime)
- (BOOL)startRendering:(id)fp8 options:(id)fp12;
- (void)pauseRendering;
- (BOOL)render:(double)time arguments:(NSDictionary*)args;
- (void)resumeRendering;
- (void)stopRendering;
- (BOOL)isPausedRendering;
- (BOOL)isRendering;
- (QCContext *)renderingContext;
- (void)setRenderingFlags:(int)flags;
- (int)renderingFlags;
- (double)nextExecutionTime:(double)time arguments:(NSDictionary*)args;
@end

@interface QCPatch (Search)
- (id)findSubpatchesWithName:(id)name options:(NSUInteger)options;
@end

@interface QCPatch (StateKeys)
- (BOOL)isStateKey:(NSString*)key;
- (id)valueForStateKey:(NSString*)key;
- (void)setValue:(id)value forStateKey:(NSString*)key;
- (BOOL)boolForStateKey:(NSString*)key;
- (void)setBool:(BOOL)value forStateKey:(NSString*)key;
- (NSInteger)integerForStateKey:(NSString*)key;
- (void)setInteger:(NSInteger)value forStateKey:(NSString*)key;
- (double)doubleForStateKey:(NSString*)key;
- (void)setDouble:(double)value forStateKey:(NSString*)key;
@end

@interface QCPatch (UserInterface)
+ (id)inspectorNibNameWithIdentifier:(id)identifier;
+ (Class)inspectorClassWithIdentifier:(id)identifier;
- (id)nodeActorForView:(id)view;
- (Class)graphViewClass;
- (void)__setValue:(id)value forPortKey:(NSString*)key;
// the following two seem misnamed - should be forPortKey:
- (void)_setIndex:(NSNumber*)index forPort:(NSString*)key;
- (void)_setKey:(NSString*)key forPort:(NSString*)portKey;
- (id)selectedNodes;
@end

@interface QCPatch (Wrappers)
- (NSArray *)inputs DEPRECATED_ATTRIBUTE; // deprecated -> inputPorts
- (NSArray *)outputs DEPRECATED_ATTRIBUTE; // deprecated -> outputPorts

// in the following, `attributes` is a dictionary of port metadata, corresponding to the `inputAttributes` section of the patch xml file
- (id)createInputWithPortClass:(Class)portClass forKey:(NSString*)key attributes:(NSDictionary*)fp16;
- (id)createInputWithPortClass:(Class)portClass forKey:(NSString*)key attributes:(NSDictionary*)fp16 arguments:(NSDictionary*)args order:(NSUInteger)order;
- (void)setInputOrder:(NSUInteger)order forKey:(NSString*)key;

- (id)createOutputWithPortClass:(Class)portClass forKey:(NSString*)key attributes:(NSDictionary*)fp16;
- (id)createOutputWithPortClass:(Class)portClass forKey:(NSString*)key attributes:(NSDictionary*)fp16 arguments:(NSDictionary*)args order:(NSUInteger)order;
- (void)setOutputOrder:(NSUInteger)order forKey:(NSString*)key;

- (void)deleteInputForKey:(NSString*)key;
- (void)deleteOutputForKey:(NSString*)key;

- (QCPatch *)parentPatch;
- (NSArray *)subpatches;
- (BOOL)canAddSubpatch:(QCPatch*)patch;
- (BOOL)addSubpatch:(QCPatch*)patch;
- (void)removeSubpatch:(QCPatch*)patch;
- (id)subpatchForKey:(NSString*)key;
- (id)keyForSubpatch:(QCPatch*)patch;
- (id)pathForSubpatch:(QCPatch*)patch;
- (id)subpatchForPath:(NSString*)path;

- (BOOL)canPublishPort:(QCPort*)port;
- (id)publishPort:(QCPort*)port;
- (void)unpublishPort:(QCPort*)port;
- (id)isPortPublished:(QCPort*)port;
@end
