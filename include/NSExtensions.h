@interface NSArray (GFExtensions)
- (id)GFArrayEnumerator;        // this appears to no longer be present
@end

@interface NSColor (QCHue)
+ (id)_colorWithHue:(float)hue; // this appears to no longer be present
@end

@interface NSDictionary (GFExtensions)
- (id)GFDictionaryEnumerator;   // this appears to no longer be present
@end

@interface NSMutableDictionary (GFPrivateExtensions)
- (void)_mergeEntriesFromDictionary:(NSDictionary*)dict maxDepth:(unsigned int)depth; // adds dict's key/value pairs to self, recursively to depth when value is a dictionary.  common depth values appear to be 0 and 0x400.  TODO: if self and dict share a key, who wins?
- (id)_stripDotEntries;     // used to sanitize userInfo dicts (editor uses .-prefixed keys for bookkeeping, like .selected)
- (void)_setNullForKey:(id)aKey;    // convenience method to set [NSNull null] for aKey
@end

@interface NSObject (GFExtensions)
- (void)__performUndo2:(id)fp8;     //
- (void)__performUndo3:(id)fp8;     // these appear to no longer be present
- (void)__performUndo4:(id)fp8;     //
@end

/* This might be a kludge category interface.  PreferencesController in the editor deals with settings,
   maybe there's a private pref to tweak them outside the editor too.  But putting these on
   every NSObject seems quite overly broad.  GFSettingsView drives a lot of these. */
@interface NSObject (GFSettingsViewDelegate)
- (id)settingsView:(id)fp8 settingForKey:(id)fp12;                  // returns 0
- (void)settingsView:(id)fp8 setSetting:(id)fp12 forKey:(id)fp16;   // does nothing
- (void)settingsView:(id)fp8 clearSettingForKey:(id)fp12;           // this calls setSetting:0
- (BOOL)settingsView:(id)fp8 shouldRenameKey:(id)fp12;              // returns 0
- (void)settingsView:(id)fp8 renameKey:(id)fp12 toKey:(id)fp16;     // does nothing
@end

@interface NSObject (QCCompositionParameterViewDelegate)
- (BOOL)compositionParameterView:(QCCompositionParameterView*)parameterView shouldDisplayParameterWithKey:(NSString*)portKey attributes:(NSDictionary*)portAttributes;
- (void)compositionParameterView:(QCCompositionParameterView*)parameterView didChangeParameterWithKey:(NSString*)portKey;
@end

@interface NSObject (QCCompositionPickerViewDelegate)
- (void)compositionPickerView:(id)fp8 didLoadComposition:(id)fp12;
- (void)compositionPickerView:(id)fp8 willSelectComposition:(id)fp12;
- (void)compositionPickerView:(id)fp8 didSelectComposition:(id)fp12;
- (void)compositionPickerViewDidStartAnimating:(id)fp8;
- (void)compositionPickerViewWillStopAnimating:(id)fp8;
- (unsigned int)compositionPickerView:(id)fp8 draggingEnteredComposition:(id)fp12 sender:(id)fp16;
- (BOOL)compositionPickerView:(id)fp8 performDragOperationOnComposition:(id)fp12 sender:(id)fp16;
- (BOOL)compositionPickerView:(id)fp8 keyDown:(id)fp12;
@end

@interface NSObject (QCImage)
- (id)createOptimizedProviderWithTransformation:(id)fp8 cropping:(NSRect)fp12;
- (id)createImageWithOptions:(id)fp8;
@end

@interface NSObject (QCObjectMetadata)
- (id)resolveForwardingConflictWithPreviousMetadata:(id)fp8 forKey:(id)fp12;
@end

@interface NSObject (QCPlugInOutputImageProvider)
- (BOOL)shouldColorMatch;
- (id)supportedBufferPixelFormats;
- (BOOL)renderToBuffer:(void *)fp8 withBytesPerRow:(unsigned int)fp12 pixelFormat:(id)fp16 forBounds:(NSRect)fp20;
- (id)supportedRenderedTexturePixelFormats;
- (unsigned int)copyRenderedTextureForCGLContext:(CGLContextObj)context pixelFormat:(id)fp12 bounds:(NSRect)bounds isFlipped:(char *)fp32;
- (void)releaseRenderedTexture:(unsigned int)fp8 forCGLContext:(CGLContextObj)context;
- (BOOL)canRenderWithCGLContext:(CGLContextObj)context;
- (BOOL)renderWithCGLContext:(CGLContextObj)context forBounds:(NSRect)bounds;
@end

@interface NSOpenGLContext_QuartzComposer : NSOpenGLContext
- (void)_surfaceWillGoAway:(id)fp8;
- (void)_surfaceDidComeBack:(id)fp8;
@end

@interface NSSet (GFExtensions)
- (id)GFSetEnumerator;      // this appears to no longer be present
@end

@interface NSString (QCTextRenderer)
- (void)drawInContext:(CGContextRef)context atPoint:(NSPoint)point withFontName:(id)fontName size:(float)size alignement:(int)align;
@end

// used by GFLog/GFDebug for logging to the Graph Foundation Log window
@interface NSTextView (GFLogMessage)
- (void)_GFLogMessage:(id)fp8;
@end

// these appear to no longer be present
@interface NSUndoManager (GFExtensions)
- (void)registerUndoWithTarget:(id)fp8 selector:(SEL)fp12 object1:(id)fp16 object2:(id)fp20;
- (void)registerUndoWithTarget:(id)fp8 selector:(SEL)fp12 object1:(id)fp16 object2:(id)fp20 object3:(id)fp24;
- (void)registerUndoWithTarget:(id)fp8 selector:(SEL)fp12 object1:(id)fp16 object2:(id)fp20 object3:(id)fp24 object4:(id)fp28;
@end
