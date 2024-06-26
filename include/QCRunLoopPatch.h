@interface QCRunLoopPatch : QCPatch
{
	void *_unused4[4];	// 156 = 0x9c
}

+ (id)allocWithZone:(NSZone *)zone;     // ensures there are only subclasses - this class cannot be instantiated directly.
- (void)_runLoopThread:(id)argument;
- (BOOL)setup:(QCOpenGLContext *)context;
- (id)runLoop;
- (void)cleanup:(QCOpenGLContext *)context;
- (void)performSelectorOnRunloop:(SEL)selector withArgument:(id)arg waitForCompletion:(BOOL)waitForCompletion;
@end
