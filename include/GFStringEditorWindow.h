// GFStringEditorWindow hosts the dimming window that darkens the editor while editing strings, and also holds the
// GFStringEditor that actually handles editing.

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
