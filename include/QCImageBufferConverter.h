



@class QCImageManager;

@interface QCImageBufferConverter : NSObject <QCImageBufferConverter>
{
	QCImageManager *_manager;	// 4 = 0x4
	void *_unused[4];	// 8 = 0x8
}

+ (id)allocWithZone:(NSZone *)zone;     // ensures there are only subclasses - this class cannot be instantiated directly.
+ (id)converterForImageManager:(id)fp8;
- (id)initWithImageManager:(id)fp8;
- (id)imageManager;
- (BOOL)supportsCropping;
- (BOOL)supportsTransformation;
- (BOOL)supportsColorMatching;
- (id)supportedPixelBufferFormatsForFormat:(id)fp8;
- (id)createPixelBufferFromImageBuffer:(id)fp8 withFormat:(id)fp12 transformation:(id)fp16 bounds:(NSRect)fp20 colorSpace:(CGColorSpaceRef)fp36 options:(id)fp40;
- (id)supportedTextureBufferFormatsForFormat:(id)fp8;
- (id)createTextureBufferFromImageBuffer:(id)fp8 withFormat:(id)fp12 target:(GLuint)fp16 transformation:(id)fp20 bounds:(NSRect)fp24 colorSpace:(CGColorSpaceRef)fp40 options:(id)fp44;
- (NSString*)description;

@end
