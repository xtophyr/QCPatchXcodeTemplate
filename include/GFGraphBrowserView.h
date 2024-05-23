@class GFGraph, GFGraphEditorView, GFNode;

// GFGraphBrowserView is optionally at the top of the editor window.
// Setting the graphEditor and rootNode is the minimum needed to get it operating.
// setting displayNodes will show nodes, not just macros.

extern NSString * const GFGraphBrowserViewNodeDidSelectNotification;

@interface GFGraphBrowserView : NSView
{
	NSView *_insideView;	// 80 = 0x50
	GFGraph *_rootGraph;	// 84 = 0x54
	GFGraphEditorView *_graphEditor;	// 88 = 0x58
	NSBrowser *_browser;	// 92 = 0x5c
	GFNode *_currentNode;	// 96 = 0x60
	BOOL _displayNodes;	// 100 = 0x64
	void *_unused[4];	// 104 = 0x68
}

- (void)setCurrentNode:(GFNode*)node;
- (id)initWithFrame:(NSRect)frameRect;
- (void)encodeWithCoder:(NSCoder *)aCoder;
- (id)initWithCoder:(NSCoder *)aDecoder;
- (void)dealloc;
- (BOOL)isOpaque;
- (NSInteger)browser:(NSBrowser*)browser numberOfRowsInColumn:(NSInteger)fp12;
- (void)browser:(NSBrowser*)browser willDisplayCell:(id)cell atRow:(NSInteger)row column:(NSInteger)column;
- (void)setRootGraph:(GFGraph*)graph;
- (GFGraph*)rootGraph;
- (id)currentNode;
- (void)__graphDidChange:(NSNotification*)notification;
- (void)setGraphEditor:(GFGraphEditorView*)editor;
- (GFGraphEditorView*)graphEditor;
- (void)delete:(id)sender;
- (void)keyDown:(NSEvent*)theEvent;
- (void)copy:(id)sender;
- (void)cut:(id)sender;
- (BOOL)validateMenuItem:(NSMenuItem*)menuItem;

@end

@interface GFGraphBrowserView (Private)
+ (BOOL)_isGraph:(id)node;
- (void)_graphUpdated:(NSNotification*)notification;
- (NSUInteger)_indexForNode:(GFNode*)node inGraph:(GFGraph*)graph;
- (id)_nodeFromGraph:(GFGraph*)graph atIndex:(NSUInteger)fp12;
- (NSUInteger)_nodesCountInGraph:(GFGraph*)graph;
- (id)_selectedNodeAtColumn:(NSUInteger)column;
- (void)_setCurrentNode:(GFNode*)node;
- (void)_selectItem:(id)item;
- (BOOL)_getPathFromGraph:(GFGraph*)graph toNode:(GFNode*)node withBuffer:(id *)buffer;
- (id)_setPathWithBuffer:(id *)buffer;
- (void)_setDisplayNodes:(BOOL)flag;
- (BOOL)_displayNodes;
- (void)_finishInitialization;
@end
