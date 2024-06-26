extern NSString * const QCPixelFormatCompatibility_CoreVideo;
extern NSString * const kQCPixelFormatCompatibility_CGBitmapContext;
extern NSString * const kQCPixelFormatCompatibility_CGImage;
extern NSString * const kQCPixelFormatCompatibility_CIBitmapContext;
extern NSString * const kQCPixelFormatCompatibility_CIImage;
extern NSString * const kQCPixelFormatCompatibility_CoreVideo;
extern NSString * const kQCPixelFormatCompatibility_GLContext;
extern NSString * const kQCPixelFormatCompatibility_OpenCL_Read;
extern NSString * const kQCPixelFormatCompatibility_OpenCL_Write;
extern NSString * const kQCPixelFormatCompatibility_OpenGL;
extern NSString * const kQCPixelFormatCompatibility_QuickTime;

// TODO: figure out compatibility bits

@interface QCPixelFormat : NSObject
{
	void *_unused[4];	// 4 = 0x4
}
+ (id)allocWithZone:(NSZone *)zone;     // ensures there are only subclasses - this class cannot be instantiated directly.
+ (void)initialize;                 //
- (NSString*)name;                  //
- (unsigned long long)compatibilities;//      These methods generally throw NSInternalInconsistency : "Function not implemented"
- (int)pixelColorModel;             //      or 0, further enforcing that this is a pure virtual class.
- (int)pixelType;                   //
- (int)pixelAlpha;                  //
- (NSUInteger)pixelBlockWidth;      //
- (NSUInteger)pixelBlockHeight;     //
- (NSUInteger)bitsPerBlock;         //
- (unsigned int)QTPixelFormat;      //
- (GLuint)openGLInternalFormat;     //
- (GLuint)openGLPixelFormat;        //
- (GLuint)openGLPixelType;          //
- (CIFormat)CIFormat;               //
- (NSUInteger)CGBitsPerComponent;   //
- (NSUInteger)CGBitsPerPixel;       //
- (CGBitmapInfo)CGBitmapInfo;       //
- (CGColorSpaceRef)defaultColorSpace;//
- (BOOL)isValidColorSpace:(CGColorSpaceRef)colorspace;  //
- (BOOL)isSupportedOnContext:(QCCGLContext *)context;   //
- (NSString*)description;           //
- (cl_image_format)CLFormat;        //
@end

@interface QCPixelFormat (Extensions)
+ (QCPixelFormat *)defaultClosestPixelFormat:(QCPixelFormat *)pixelformat withColorSpace:(CGColorSpaceRef)colorspace;
- (BOOL)hasCompatibility:(unsigned long long)trialCompatability;
- (BOOL)isValidWidth:(NSUInteger)trialWidth;
- (BOOL)isValidHeight:(NSUInteger)trialHeight;
- (BOOL)areValidBounds:(NSRect)trialBounds;
- (NSRect)validateBounds:(NSRect)bounds;
- (NSUInteger)packedBytesPerRowForWidth:(NSUInteger)width;
- (NSUInteger)optimalBytesPerRowForWidth:(NSUInteger)height;
- (double)compareWithPixelFormat:(id)fp8;
- (QCPixelFormat *)closestPixelFormat:(QCPixelFormat *)pixelformat outDifference:(double *)fp12;
- (NSUInteger)pixelSamples;
@end

@interface QCPixelFormat (QCStreamExtensions)
+ (id)pixelFormatsForElementSize:(NSUInteger)elementSize type:(int)type;
- (int)type;
- (NSUInteger)elementSize;
@end

@interface QCPixelFormat (Registry)
+ (void)registerPixelFormat:(id)fp8;
+ (id)allPixelFormats;
+ (id)pixelFormatsWithCompatibility:(id)fp8;
+ (id)pixelFormatsWithCompatibilities:(id)fp8 pixelColorModel:(int)fp12 pixelAlpha:(int)fp16 pixelType:(int)fp20;
+ (id)findPixelFormat:(id)fp8 withColorSpace:(CGColorSpaceRef)fp12 closestToFormats:(id)fp16;
+ (id)pixelFormatWithName:(NSString*)name;
@end

@interface QCPixelFormat (pixelFormat422YpCbCr8_601)
+ (id)pixelFormat422YpCbCr8_601;
@end

@interface QCPixelFormat (pixelFormat422YpCbCr8_709)
+ (id)pixelFormat422YpCbCr8_709;
@end

@interface QCPixelFormat (pixelFormatARGB8)
+ (id)pixelFormatARGB8;
@end

@interface QCPixelFormat (pixelFormatBGRA8)
+ (id)pixelFormatBGRA8;
@end

@interface QCPixelFormat (pixelFormatBGRX8)
+ (id)pixelFormatBGRX8;
@end

@interface QCPixelFormat (pixelFormatCMYK16)
+ (id)pixelFormatCMYK16;
@end

@interface QCPixelFormat (pixelFormatCMYK8)
+ (id)pixelFormatCMYK8;
@end

@interface QCPixelFormat (pixelFormatCMYKf)
+ (id)pixelFormatCMYKf;
@end

@interface QCPixelFormat (pixelFormatI16)
+ (id)pixelFormatI16;
@end

@interface QCPixelFormat (pixelFormatI8)
+ (id)pixelFormatI8;
@end

@interface QCPixelFormat (pixelFormatIf)
+ (id)pixelFormatIf;
@end

@interface QCPixelFormat (pixelFormatIh)
+ (id)pixelFormatIh;
@end

@interface QCPixelFormat (pixelFormatIndexedGray8)
+ (id)pixelFormatIndexedGray8;
@end

@interface QCPixelFormat (pixelFormatKYMC8)
+ (id)pixelFormatKYMC8;
@end

@interface QCPixelFormat (pixelFormatM_I16)
+ (id)pixelFormatM_I16;
@end

@interface QCPixelFormat (pixelFormatM_I8)
+ (id)pixelFormatM_I8;
@end

@interface QCPixelFormat (pixelFormatM_If)
+ (id)pixelFormatM_If;
@end

@interface QCPixelFormat (pixelFormatM_Ih)
+ (id)pixelFormatM_Ih;
@end

@interface QCPixelFormat (pixelFormatRGB16)
+ (id)pixelFormatRGB16;
@end

@interface QCPixelFormat (pixelFormatRGB8)
+ (id)pixelFormatRGB8;
@end

@interface QCPixelFormat (pixelFormatRGBA16)
+ (id)pixelFormatRGBA16;
@end

@interface QCPixelFormat (pixelFormatRGBA8)
+ (id)pixelFormatRGBA8;
@end

@interface QCPixelFormat (pixelFormatRGBAf)
+ (id)pixelFormatRGBAf;
@end

@interface QCPixelFormat (pixelFormatRGBAh)
+ (id)pixelFormatRGBAh;
@end

@interface QCPixelFormat (pixelFormatRGBX8)
+ (id)pixelFormatRGBX8;
@end

@interface QCPixelFormat (pixelFormatRGBf)
+ (id)pixelFormatRGBf;
@end

@interface QCPixelFormat (pixelFormatRGBh)
+ (id)pixelFormatRGBh;
@end

@interface QCPixelFormat (pixelFormatXRGB8)
+ (id)pixelFormatXRGB8;
@end
