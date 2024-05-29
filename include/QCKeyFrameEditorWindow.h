

@interface QCKeyFrameEditorWindow : NSWindow
- (id)initWithContentRect:(NSRect)contentRect styleMask:(NSWindowStyleMask)style backing:(NSBackingStoreType)backing defer:(BOOL)defer;
- (void)setHidesOnDeactivate:(BOOL)flag;
- (NSSize)size;
- (void)setSize:(NSSize)size;
- (BOOL)canBecomeKeyWindow;
- (void)sendEvent:(NSEvent*)event;
@end
