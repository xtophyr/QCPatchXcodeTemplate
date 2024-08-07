#import "QCResource.h"

@class QCPixelFormat, QCResourcePool;

// flags:
//  rootContext     0x01  (maybe?)
//  softwareCIMode  0x02
//  maxTextureSize  0x04  max texture size override set

// these flags are paired -- one flags if we've checked or not, so we don't interrogate the context or pixelformat more than once.
// the second flag flags the result of the query.

//  0x10000 - Asked the pixelformat if it's accelerated Flag (kCGLPFAAccelerated) -isAccelerated will always set this
//  0x20000 - pixelFormat is accelerated Flag (kCGLPFAAccelerated) -isAccelerated might set this if the pf is accelerated

//  0x40000 - checked context for GL_ARB_fragment_program extension -isProgrammable always sets this
//  0x80000 - context has GL_ARB_fragment_program extension -isProgrammable might set this

//  0x100000 - checked context for GL_EXT_framebuffer_object extension -isFBOSupported always sets this
//  0x200000 - context has GL_EXT_framebuffer_object extension -isFBOSupported might set this

//  0x400000 - checked context for GL_APPLE_float_pixels extension -isFloatSupported always sets this
//  0x800000 - context has GL_APPLE_float_pixels extension -isFloatSupported might set this

//  0x1000000 - checked for isCoreImageAccelerated -isCoreImageAccelerated will always set this
//  0x2000000 - isCoreImageAccelerated flag -isCoreImageAccelerated might set this

@interface QCCGLContext : QCResource
{
	QCCGLContext *_rootContext;	// 28 = 0x1c
	NSDictionary *_options;	// 32 = 0x20
	CGLContextObj   _cglContext;	// 36 = 0x24
	CGLPixelFormatObj  _cglPixelFormat;	// 40 = 0x28
	NSUInteger _virtualScreenCount;	// 44 = 0x2c
	CFDictionaryRef _ciContextCache;	// 48 = 0x30
	CFDictionaryRef _rootContextCache;	// 52 = 0x34
	struct __C3DEngineContext *_c3dContext;	// 56 = 0x38
	QCResourcePool *_sharedPool;	// 60 = 0x3c
	NSUInteger _defaultSharedVirtualScreen;	// 64 = 0x40
	NSUInteger _cachedVirtualScreen;	// 68 = 0x44
	NSUInteger _flags;	// 72 = 0x48
	QCPixelFormat *_renderPixelFormat;	// 76 = 0x4c
	CFArrayRef _dependentTextures;	// 80 = 0x50
	id _nsglContext;	// 84 = 0x54
	id _nsglPixelFormat;	// 88 = 0x58
	void *_unused2[2];	// 92 = 0x5c
}

+ (void)initialize;
+ (id)contextWithPixelFormatAttributes:(const int *)fp8 options:(NSDictionary *)options;
+ (id)softwareContextForFormat:(QCPixelFormat *)format;
+ (id)hardwareContextForDisplay:(CGDirectDisplayID)display;
- (id)initWithPixelFormatAttributes:(const int *)fp8 options:(NSDictionary *)options;
- (id)initWithCGLContext:(CGLContextObj)fp8 pixelFormat:(CGLPixelFormatObj)fp12 options:(NSDictionary *)options;
- (void)_finalize_QCCGLContext;
- (void)finalize;
- (void)dealloc;
- (id)options;
- (CGLContextObj)CGLContextObj;
- (CGLPixelFormatObj)CGLPixelFormatObj;
- (BOOL)enable:(CGLContextEnable)pname;
- (BOOL)disable:(CGLContextEnable)pname;
- (BOOL)isEnabled:(CGLContextEnable)pname;
- (BOOL)setParameter:(CGLContextParameter)pname value:(int)value;
- (int)getParameter:(CGLContextParameter)pname;
- (void)lock;
- (void)unlock;
- (void)setBestVirtualScreenForRenderingSize:(NSSize)renderingSize;
- (void)setVirtualScreen:(NSUInteger)virtualScreen;
- (NSUInteger)virtualScreen;
- (NSUInteger)virtualScreenCount;
- (id)createMinimalSharedContext;
- (QCCGLContext *)createMinimalSharedContextWithAdditionalAttributes:(const int *)attributes recycleWhenDone:(BOOL)recycle;
- (id)minimalSharedContextForCurrentThread;
- (void)clearMinimalSharedContextForCurrentThread;
- (void)setResourcePool:(id)fp8;
- (void)willRecycleResource:(id)fp8;
- (BOOL)didRecycleResource:(id)fp8;
- (id)rootContext;
- (BOOL)isSharedWithContext:(id)fp8;
- (void)reclaimResources;
- (void)purgeResources;
- (NSString*)description;
@end

@interface QCCGLContext (Extensions)
+ (id)CIBitmapContext;
- (id)_ciContext;
- (id)CIContext;
- (struct __C3DEngineContext *)QCSCN_Context;
@end

@interface QCCGLContext (NSOpenGLContext)
- (id)initWithOpenGLContext:(NSOpenGLContext*)context pixelFormat:(NSOpenGLPixelFormat*)pixelFormat options:(NSDictionary *)options;
- (NSOpenGLContext*)NSOpenGLContext;
- (NSOpenGLPixelFormat*)NSOpenGLPixelFormat;
@end

@interface QCCGLContext (QCGraphicsContext)
+ (id)copyGlobalRootContext;
+ (id)createUniqueContextWithOptions:(NSDictionary *)options;
@end

@interface QCCGLContext (SnapshotImage)
- (id)createSnapshotImageOfType:(id)fp8 withColorSpace:(CGColorSpaceRef)fp12;
@end

@interface QCCGLContext (Utilities)
- (BOOL)hasDrawable;
- (int)_rendererPropertyValue:(int)fp8;
- (NSUInteger)videoMemorySize;
- (NSUInteger)textureMemorySize;
- (NSUInteger)_validateCachedVirtualScreen;
- (NSString*)rendererVendor;
- (NSString*)rendererName;
- (float)rendererVersion;
- (NSInteger)rendererID;
- (NSInteger)rendererIDForVirtualScreen:(NSInteger)virtualScreen;
- (NSUInteger)textureUnits;
- (NSUInteger)textureMaxImageUnits;
- (BOOL)isAccelerated;
- (BOOL)isProgrammable;
- (BOOL)isCoreImageAccelerated;
- (BOOL)isFBOSupported;
- (BOOL)isFloatSupported;
- (BOOL)isExtensionSupported:(id)fp8;
- (NSUInteger)maxRenderingSize;
- (NSUInteger)maxTextureSizeForTarget:(GLuint)fp8;
- (QCPixelFormat*)renderingPixelFormat;
- (NSSize)fitTextureSize:(NSSize)size forTarget:(GLuint)target uniformScaling:(BOOL)uniformScaling;
- (BOOL)readPixelsFromBounds:(int *)fp8 toBaseAddress:(void *)fp12 withBytesPerRow:(NSUInteger)fp16 pixelType:(unsigned int)fp20;
- (BOOL)copyPixelsFromBounds:(int *)fp8 toSharedCGLContext:(CGLContextObj)fp12 usingInternalFormat:(GLuint)fp16;
@end
