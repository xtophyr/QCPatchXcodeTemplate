

@interface QCCompositionPickerGridLayer : CALayer
{
	id _controller;	// 48 = 0x30
}

- (void)layoutStateDidChange;
- (void)selectCompositionIfNeeded;
- (void)observeValueForKeyPath:(NSString*)path ofObject:(id)object change:(NSDictionary*)change context:(void *)context;
- (void)wakeup;
- (void)sleep;
- (id)initWithFrame:(NSRect)fp8 compositions:(id)fp24 controller:(id)fp28;
- (void)finalize;
- (void)dealloc;
- (id)compositionAtIndex:(int)fp8;
- (int)indexOfComposition:(id)fp8;
- (id)cellForComposition:(id)fp8;
- (int)compositionCount;
- (void)runActionForKey:(id)fp8 object:(id)fp12 arguments:(id)fp16;
@end
