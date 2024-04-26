

@interface QCKeyFrameEditorWindow : NSWindow
- (id)initWithContentRect:(NSRect)contentRect styleMask:(NSWindowStyleMask)style backing:(NSBackingStoreType)backing defer:(BOOL)defer;
- (void)setHidesOnDeactivate:(BOOL)fp8;
- (NSSize)size;
- (void)setSize:(NSSize)fp8;
- (BOOL)canBecomeKeyWindow;
- (void)sendEvent:(NSEvent*)event;
@end
