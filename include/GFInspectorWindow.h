

@interface GFInspectorWindow : NSPanel
{
	NSUndoManager *_undoManager;	// 132 = 0x84
}

- (void)dealloc;
- (void)setUndoManager:(NSUndoManager*)undoManager;
- (NSUndoManager*)undoManager;
- (BOOL)validateMenuItem:(NSMenuItem*)menuItem;
- (void)undo:(id)sender;
- (void)redo:(id)sender;

@end
