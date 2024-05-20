
// GFGraphPathView draws the path at the top of the editor window.  NSPathControl does most of the heavy lifting.
// Uniquely, this doesn't have an initWithCoder: initializer, but it _does_ have a _finishInitializing method, so if you serialize this into
// a nib it'll deserialize and be broken unless you drive _finishInitializing yourself.  This view is apparently only intended to be made
// programaticaly.

@class GFGraph, GFGraphEditorView, GFNode;

@interface GFGraphPathView : NSView
{
	GFGraph *_rootGraph;	// 80 = 0x50
	GFGraphEditorView *_graphEditor;	// 84 = 0x54
	GFNode *_currentNode;	// 88 = 0x58
	BOOL _displayNodes;	// 92 = 0x5c
	NSPathControl *_control;	// 96 = 0x60
	void *_unused[4];	// 100 = 0x64
}

- (id)nodes;
- (void)setRootGraph:(id)fp8;
- (id)rootGraph;
- (id)currentNode;
- (void)__graphDidChange:(id)fp8;
- (void)setPath:(NSString*)path;
- (void)setCurrentNode:(id)fp8;
- (void)setGraphEditor:(id)fp8;
- (id)graphEditor;
- (id)initWithFrame:(NSRect)fp8;
- (void)dealloc;
- (BOOL)isOpaque;
- (void)drawRect:(NSRect)fp8;

@end

@interface GFGraphPathView (Private)
+ (BOOL)_isGraph:(id)fp8;
//- (BOOL)_getPathFromGraph:(id)fp8 toNode:(id)fp12 withBuffer:(id *)fp16; // this is now gone, replaced with the array variant
- (BOOL)_getPathFromGraph:(id)graph toNode:(id)node withArray:(id)arg3; // added after SSDK was dumped
- (void)_setCurrentNode:(id)node;
//- (id)_setPathWithBuffer:(id *)fp8; // this is now gone, replaced with the array variant
- (id)_setPathWithArray:(NSArray*)pathArray;
- (void)_graphUpdated:(NSNotification*)notification;
- (void)__hierarchyControlAction:(id)fp8;
- (void)_finishInitialization;
@end
