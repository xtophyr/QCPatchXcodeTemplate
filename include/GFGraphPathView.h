
// GFGraphPathView draws the path at the top of the editor window.  NSPathControl does most of the heavy lifting.
// Uniquely, this doesn't have an initWithCoder: initializer, but it _does_ have a _finishInitializing method, so if you serialize this into
// a nib it'll deserialize and be broken unless you drive _finishInitializing yourself.  This view is apparently only intended to be made
// programaticaly.

// a path in this context is similar to a file system path, where each "directory" is a macro patch.

@class GFGraph, GFGraphEditorView, GFNode;

@interface GFGraphPathView : NSView
{
	GFGraph *_rootGraph;	// 80 = 0x50        // this holds the root macro patch of the composition
	GFGraphEditorView *_graphEditor;	// 84 = 0x54
	GFNode *_currentNode;	// 88 = 0x58        // this holds the currently visible node in _graphEditor
	NSPathControl *_control;	// 96 = 0x60    // draws the path from _rootGraph to _currentNode
	void *_unused[4];	// 100 = 0x64
}

- (id)initWithFrame:(NSRect)frame;
- (void)dealloc;

- (id)nodes;
- (void)setRootGraph:(GFGraph*)graph;
- (GFGraph*)rootGraph;
- (void)setCurrentNode:(GFNode*)currentNode;
- (GFNode*)currentNode;
- (void)setGraphEditor:(GFGraphEditorView*)graphEditor;
- (GFGraphEditorView*)graphEditor;

- (void)__graphDidChange:(NSNotification*)notification;
- (void)setPath:(NSString*)path;
- (BOOL)isOpaque;
- (void)drawRect:(NSRect)rect;

@end

@interface GFGraphPathView (Private)
+ (BOOL)_isGraph:(id)graph; // this checks graph if it's a GFGraph subclass.  used in various methods while traversing graphs to build/set paths.
//- (BOOL)_getPathFromGraph:(id)fp8 toNode:(id)fp12 withBuffer:(id *)fp16; // this is now gone, replaced with the array variant
- (BOOL)_getPathFromGraph:(id)graph toNode:(id)node withArray:(id)pathArray; // added after SSDK was dumped
//- (id)_setPathWithBuffer:(id *)fp8; // this is now gone, replaced with the array variant
- (id)_setPathWithArray:(NSArray*)pathArray;

- (void)_setCurrentNode:(id)node;
- (void)_graphUpdated:(NSNotification*)notification;
- (void)__hierarchyControlAction:(id)sender;
- (void)_finishInitialization;
@end
