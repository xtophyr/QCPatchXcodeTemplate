

@interface QCCompositionPickerNavigationView : NSView
{
	id _controller;	// 80 = 0x50
	id _leftButton;	// 84 = 0x54
	id _rightButton;	// 88 = 0x58
}

- (void)update;
- (id)initWithFrame:(NSRect)frame andController:(id)fp24;
- (void)setHidden:(BOOL)hidden;
- (void)dealloc;

@end
