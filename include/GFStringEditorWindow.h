@interface GFStringEditorWindow : NSWindow
{
    NSView *_editingView;       // 256 = 0x100
}
- (id)init;
- (void)dealloc;
- (NSSize)size;
- (void)setSize:(NSSize)size;
- (NSView*)editingView;
- (void)setEditingView:(NSView*)editingView;
- (BOOL)canBecomeKeyWindow;
- (void)sendEvent:(NSEvent*)event;
@end
