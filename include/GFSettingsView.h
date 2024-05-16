/* GFSettingsView is used to drive the scrollview and tableview that display and manage the private preferences. */
// its UI is backed by GFSettingsView.nib (this holds the cached NSCells and the scrollview and tableview, for instance)

// It appears as though it's incomplete - there are cells for data types that aren't used (menu cell, key cell), and some of the methods
// check for classes like NSArray only to throw special exceptions for them.  Perhaps the intent was something richer, like Property List Editor?

@class GFList;

@interface GFSettingsView : NSView
{
	NSView *_insideView;	// 80 = 0x50    // this is used to hold the NSScrollView that holds the tableview
	NSTableView *_tableView;	// 84 = 0x54
	NSCell *_keyCell;	// 88 = 0x58                // this appears to be unused?
	NSTextFieldCell *_stringCell;	// 92 = 0x5c    //
	NSTextFieldCell *_integerCell;	// 96 = 0x60    //
	NSTextFieldCell *_floatingCell;	// 100 = 0x64   //
	NSButtonCell *_booleanCell;	// 104 = 0x68       //
	NSPopUpButtonCell *_menuCell;	// 108 = 0x6c   // this appears to be unused?
	GFList *_defaults;	// 112 = 0x70               // this holds the names and default values for the prefs.  differing values render in bold
	id _delegate;	// 116 = 0x74                   // GFSettingsViewDelegate category on NSObject (informal protocol)
}

- (void)_finish_initialization;
- (id)initWithFrame:(NSRect)frame;
- (void)dealloc;
- (void)_updateDefaults;
- (void)setDefaults:(NSDictionary *)defaults; // yes, this is a dict, not a GFList
- (NSDicrionary*)defaults;  // _defaults made into a dictionary
- (void)setDefault:(id)value forKey:(NSString*)key;
- (void)removeDefaultForKey:(NSString*)key;
- (id)delegate;
- (void)setDelegate:(id)delegate;
- (void)reloadSettings;
- (void)encodeWithCoder:(NSCoder *)aCoder;
- (id)initWithCoder:(NSCoder *)aDecoder;
- (void)keyDown:(NSEvent*)event;
- (GFList*)_defaults;   // raw pointer to _defaults

@end

@interface GFSettingsView (TableViewSource)
- (NSInteger)numberOfRowsInTableView:(NSTableView*)tableView;
- (id)tableView:(NSTableView*)tableView objectValueForTableColumn:(NSTableColumn*)column row:(NSInteger)row;
- (BOOL)tableView:(NSTableView*)tableView shouldEditTableColumn:(NSTableColumn*)column row:(NSInteger)row;
- (void)tableView:(NSTableView*)tableView setObjectValue:(id)value forTableColumn:(NSTableColumn*)column row:(NSInteger)row;
- (void)tableView:(NSTableView*)tableView willDisplayCell:(id)cell forTableColumn:(NSTableColumn*)column row:(NSInteger)row;
- (id)_cellForRow:(NSInteger)row;
@end
