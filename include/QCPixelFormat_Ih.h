@interface QCPixelFormat_Ih : QCPixelFormat
{
    unsigned long long _compatibilities;	// 20 = 0x14
}

- (NSString*)name;
- (unsigned long long)compatibilities;
- (NSString*)description;
- (void)dealloc;
- (int)pixelColorModel;
- (int)pixelType;
- (int)pixelAlpha;
- (NSUInteger)pixelBlockWidth;
- (NSUInteger)pixelBlockHeight;
- (NSUInteger)bitsPerBlock;
- (BOOL)isSupportedOnContext:(id)context;
- (unsigned int)QTPixelFormat;
- (GLuint)openGLInternalFormat;
- (GLuint)openGLPixelFormat;
- (GLuint)openGLPixelType;
- (CIFormat)CIFormat;
#if MAC_OS_X_VERSION_MAX_ALLOWED >= 1060
- (cl_image_format)CLFormat;
#endif
- (NSUInteger)CGBitsPerComponent;
- (NSUInteger)CGBitsPerPixel;
- (CGBitmapInfo)CGBitmapInfo;
@end
