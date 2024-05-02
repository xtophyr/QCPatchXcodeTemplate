extern NSString * const QCCompositionPickerPanelDidSelectCompositionNotification;
extern NSString * const QCCompositionPickerPanelWillSelectCompositionNotification;

@interface QCCompositionPickerPanel : NSPanel
{
	void *_private;	// NSView *compositionPickerView
}

+ (id)allocWithZone:(NSZone *)zone;
+ (id)sharedCompositionPickerPanel;
- (id)compositionPickerView;
- (void)_willSelectComposition:(NSNotification *)notification;
- (void)_didSelectComposition:(NSNotification *)notification;
- (id)initWithContentRect:(NSRect)rect;
- (BOOL)canBecomeKeyWindow;

@end
