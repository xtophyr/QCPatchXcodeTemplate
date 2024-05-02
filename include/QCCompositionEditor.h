


@class QCPatchEditorView, QCPatchManagerView;

@interface QCCompositionEditor : NSObject
{
	NSWindow *window;	// 4 = 0x4
	QCPatchEditorView *editorView;	// 8 = 0x8
	QCPatchManagerView *managerView;	// 12 = 0xc
}

+ (void)setup;
+ (NSInteger)numberOfRowsInTableView:(NSTableView*)tableView;
+ (id)tableView:(NSTableView*)tableView objectValueForTableColumn:(NSTableColumn*)column row:(NSInteger)row;
+ (void)doubleClick:(id)fp8;
+ (void)addPatch:(id)fp8;
+ (void)removePatch:(id)fp8;
+ (void)didUpdatePatchRendering:(id)fp8;
- (id)initWithPatch:(id)fp8;
- (void)windowWillClose:(NSNotification *)notification;

@end
