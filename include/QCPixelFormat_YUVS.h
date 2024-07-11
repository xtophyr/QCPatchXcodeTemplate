@interface QCPixelFormat_YUVS : QCPixelFormat
{
    unsigned long long _compatibilities;
}

- (unsigned int)CGBitmapInfo;
- (unsigned long long)CGBitsPerPixel;
- (unsigned long long)CGBitsPerComponent;
- (struct _cl_image_format)CLFormat;
- (int)CIFormat;
- (unsigned int)openGLPixelType;
- (unsigned int)openGLPixelFormat;
- (unsigned int)openGLInternalFormat;
- (unsigned int)QTPixelFormat;
- (BOOL)isSupportedOnContext:(id)arg1;
- (unsigned long long)bitsPerBlock;
- (unsigned long long)pixelBlockHeight;
- (unsigned long long)pixelBlockWidth;
- (int)pixelAlpha;
- (int)pixelType;
- (int)pixelColorModel;
- (id)description;
- (unsigned long long)compatibilities;
- (id)name;

@end
