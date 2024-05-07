/* This view is roughly the Tiger-era patch creator - at least, the list of patches and description blurb at the bottom.
    it supports drag-n-drop into a GFGraphEditorView, and appears to have some search/filtering capabilities too.
 */

extern NSString * const GFNodeManagerViewInstantiateNodeNotification;

@interface GFNodeManagerView : NSView
{
	NSView *_insideView;	// 80 = 0x50
	NSString *_namespace;	// 84 = 0x54
	NSString *_filterString;	// 88 = 0x58
	NSMutableArray *_nodeNames;	// 92 = 0x5c
	NSTableView *_tableView;	// 96 = 0x60
	NSTextView *_textView;	// 100 = 0x64
	NSCell *_defaultDataCell;	// 104 = 0x68
	void *_unused[4];	// 108 = 0x6c
}

- (id)initWithFrame:(NSRect)frame;
- (void)encodeWithCoder:(NSCoder *)aCoder;
- (id)initWithCoder:(NSCoder *)aDecoder;
- (void)dealloc;
- (void)setNodeNamespace:(NSString*)nodeNamespace;   // set to @"com.apple.QuartzComposer" for a trip down memory lane
- (id)nodeNamespace;
- (void)setFilterString:(NSString*)filterString;
- (id)filterString;
@end

@interface GFNodeManagerView (TableViewSource)
- (NSInteger)numberOfRowsInTableView:(NSTableView*)tableView;
- (id)tableView:(NSTableView*)tableView objectValueForTableColumn:(NSTableColumn*)column row:(NSInteger)row;
- (void)tableView:(NSTableView*)tableView sortDescriptorsDidChange:(NSArray*)fp12;
- (BOOL)tableView:(NSTableView*)tableView writeRows:(NSArray*)fp12 toPasteboard:(NSPasteboard*)pboard;
- (void)tableViewSelectionDidChange:(id)fp8;
@end

@interface GFNodeManagerView (Private)
- (void)_finishInitialization;
- (id)_descriptionForNode:(id)fp8;
- (id)_cellContentForNode:(id)fp8 columnIdentifier:(id)identifier;
- (int)_compareNode:(id)fp8 withNode:(id)fp12 usingColumnIdentifier:(id)identifier ascending:(BOOL)flag;
- (id)_filterStringsForNode:(id)fp8;
- (void)_refreshList:(id)fp8;
- (void)_addColumnWithIdentifier:(id)fp8 title:(id)fp12 dataCell:(id)fp16 sortable:(BOOL)flag;
- (void)_removeColumnWithIdentifier:(id)fp8;
- (void)_removeAllColumns;
- (id)_columns;
- (void)_sortByIdentifiers:(id)fp8;
- (void)_selectRow:(NSUInteger)fp8;
- (void)_tableViewDoubleClick;
@end
