@class QCImageKernel;

// This class is used for Core Image Filter's Edit Filter Function machinery (need to check the box to instantiate it).

@interface QCFilter : CIFilter
{
	JSContextRef _jsContext;
	QCImageKernel *_patch;
}

- (void)dealloc;
- (void)finalize;
- (id)initWithQCImageKernelPatch:(QCImageKernel*)patch;
- (CGRect)QCImageKernelJavaScriptROIHandler:(int)fp8 destRect:(CGRect)rect userInfo:(id)info;
- (void)setROISelectorForKernel:(id)fp8 jsROIFunction:(JSValueRef)fp12;
- (void)setROIInfoForKernel:(id)fp8 jsROIInfo:(JSValueRef)fp12;

@end
