

@class QCCompositionPickerController;

@interface QCCompositionPickerLayer : CALayer
{
	QCCompositionPickerController *_controller;	// 48 = 0x30
}

- (void)_setBackgroundColor:(id)fp8;
- (void)_setDrawsBackground:(BOOL)fp8;
- (id)gridWithCompositions:(id)fp8;
- (void)observeValueForKeyPath:(NSString*)path ofObject:(id)object change:(NSDictionary*)change context:(void *)context;
- (void)_finishInitializationWithFrame:(CGRect)fp8 andController:(id)fp24;
- (id)initWithFrame:(NSRect)fp8 andController:(id)fp24;
- (void)wakeup;
- (void)sleep;

@end
