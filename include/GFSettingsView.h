

@class GFList;

@interface GFSettingsView : NSView
{
	NSView *_insideView;	// 80 = 0x50
	NSTableView *_tableView;	// 84 = 0x54
	NSCell *_keyCell;	// 88 = 0x58
	NSTextFieldCell *_stringCell;	// 92 = 0x5c
	NSTextFieldCell *_integerCell;	// 96 = 0x60
	NSTextFieldCell *_floatingCell;	// 100 = 0x64
	NSButtonCell *_booleanCell;	// 104 = 0x68
	NSPopUpButtonCell *_menuCell;	// 108 = 0x6c
	GFList *_defaults;	// 112 = 0x70
	id _delegate;	// 116 = 0x74
}

- (void)_finish_initialization;
- (id)initWithFrame:(NSRect)frame;
- (void)dealloc;
- (void)_updateDefaults;
- (void)setDefaults:(NSDictionary *)defaults; // yes, this is a dict, not a GFList
- (GFList*)defaults;
- (void)setDefault:(id)fp8 forKey:(NSString*)key;
- (void)removeDefaultForKey:(NSString*)key;
- (id)delegate;
- (void)setDelegate:(id)delegate;
- (void)reloadSettings;
- (void)encodeWithCoder:(NSCoder *)aCoder;
- (id)initWithCoder:(NSCoder *)aDecoder;
- (void)keyDown:(id)fp8;
- (id)_defaults;

@end

@interface GFSettingsView (TableViewSource)
- (NSInteger)numberOfRowsInTableView:(NSTableView*)fp8;
- (id)tableView:(NSTableView*)tableView objectValueForTableColumn:(NSTableColumn*)column row:(NSInteger)row;
- (BOOL)tableView:(NSTableView*)tableView shouldEditTableColumn:(NSTableColumn*)column row:(NSInteger)row;
- (void)tableView:(NSTableView*)tableView setObjectValue:(id)fp12 forTableColumn:(NSTableColumn*)column row:(NSInteger)row;
- (void)tableView:(NSTableView*)tableView willDisplayCell:(id)fp12 forTableColumn:(NSTableColumn*)column row:(NSInteger)row;
- (id)_cellForRow:(NSInteger)row;
@end
