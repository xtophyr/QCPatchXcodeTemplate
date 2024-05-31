@class GFConnection, GFGraph, GFGraphEditorView, GFList, GFNode, GFPort;

extern NSString * const GFGraphViewContentDidChangeNotification;
extern NSString * const GFGraphViewNodeDoubleClickedWithModifiersNotification;
extern NSString * const GFGraphViewSelectionDidChangeNotification;
extern NSString * const GFGraphViewZoomDidChangeNotification;

/* Notes are stored in _graph's userInfo dictionary in an NSMutableArray under the key @"noteList" */

@interface GFGraphView : NSView
{
	GFGraph *_graph;
	GFNode *_firstResponder;
	BOOL _drawsBackground;
	BOOL _drawsShadows;
	NSUInteger _gridStep;
	NSColor *_backgroundColor;
	NSColor *_gridColor;
	NSTimeInterval _tooltipDelay;
	BOOL _spaceDown;
	NSRect _selectionBounds;
	GFPort *_connectionPort;
	NSPoint _connectionStart;
	NSPoint _connectionEnd;
	GFConnection *_connection;
	CFRunLoopTimerRef _tooltipTimer;
	BOOL _tooltipPending;
	NSRect _tooltipBounds;
	GFNode *_tooltipNode;
	NSMutableDictionary *_alignment;
	GFList *_nodeActorCache; // this "caches" -nodeActorForView:.  That's backed by an NSDictionary, so this "optimizes" an O(log(n)) lookup with an O(n) lookup, while also doubling the memory footprint.  And the O(log(n)) implementation could be O(1) if it just used per-actor-class singletons (there are maybe 5 actor classes?).  Value is the actor, key is node (so this scales proportional to number of nodes, rather than number of actors).
	GFGraphEditorView *_graphEditor;
	NSUndoManager *_undoManager;
	BOOL _disableValidation;
	NSPoint _cachedCenter;      // this and _cachedZoomFactor below are used in -cacheZoomState/-restoreZoomState
	float _cachedZoomFactor;    //
    NSTrackingArea *_trackingArea;
	void *_unused[2];
}

- (id)initWithFrame:(NSRect)frameRect;
- (id)initWithCoder:(NSCoder *)aDecoder;
- (void)encodeWithCoder:(NSCoder *)aCoder;
- (void)finalize;   // only used for GarbageCollection (no longer used)
- (void)dealloc;

- (BOOL)isOpaque;
- (BOOL)isFlipped;
- (BOOL)acceptsFirstMouse:(NSEvent *)theEvent;
- (BOOL)acceptsFirstResponder;
- (BOOL)becomeFirstResponder;
- (BOOL)resignFirstResponder;
- (BOOL)performKeyEquivalent:(NSEvent *)theEvent;
- (void)keyDown:(NSEvent *)theEvent;
- (void)keyUp:(NSEvent *)theEvent;
- (NSMenu*)menuForEvent:(NSEvent *)theEvent;
- (void)mouseMoved:(NSEvent *)theEvent;
- (void)mouseDown:(NSEvent *)theEvent;
- (void)rightMouseDown:(NSEvent *)theEvent;
- (void)otherMouseDown:(NSEvent *)theEvent;
- (void)scrollWheel:(NSEvent *)theEvent;
- (void)swipeWithEvent:(NSEvent *)theEvent;     // added after SSDK was dumped
- (void)magnifyWithEvent:(NSEvent *)theEvent;   // added after SSDK was dumped
- (void)undo:(id)sender;
- (void)redo:(id)sender;
- (BOOL)validateMenuItem:(NSMenuItem*)menuItem;
- (void)copy:(id)sender;
- (void)paste:(id)sender;
- (void)cut:(id)sender;
- (void)duplicate:(id)sender;
- (void)selectAll:(id)sender;
- (NSDragOperation)draggingEntered:(id <NSDraggingInfo>)sender;
- (NSDragOperation)draggingUpdated:(id <NSDraggingInfo>)sender;
- (BOOL)performDragOperation:(id <NSDraggingInfo>)sender;
- (void)drawRect:(NSRect)rect;
- (NSRect)adjustScroll:(NSRect)newVisible;
- (BOOL)autoscroll:(NSEvent *)theEvent;
- (void)print:(id)sender;
- (BOOL)knowsPageRange:(NSRange *)range;
- (NSRect)rectForPage:(NSInteger)page;
- (void)setBoundsOrigin:(NSPoint)origin;
- (void)setBoundsSize:(NSSize)size;
- (void)viewWillMoveToWindow:(NSWindow*)newWindow;
- (void)viewDidMoveToWindow;
- (void)updateTrackingAreas; // added after SSDK was dumped

@end

@interface GFGraphView (Actions)
- (id)_createSubgraphFromSelection:(NSMenuItem*)menuItem;
- (id)_createSubgraphFromSelection:(NSMenuItem*)menuItem withMacroType:(Class)macroClass; // added after SSDK was dumped
- (void)_editParentGraph:(NSMenuItem*)menuItem;
- (void)_addNote:(NSMenuItem*)menuItem;
- (void)_editNote:(NSMenuItem*)menuItem;
- (void)_setNoteColor:(NSMenuItem*)menuItem;
- (void)_deleteNote:(NSMenuItem*)menuItem;
@end

@interface GFGraphView (ItemActions)
- (void)__validatePosition:(id)fp8 context:(void *)ctx;
- (void)__savePosition:(id)fp8 context:(void *)ctx;
- (void)__restorePosition:(id)fp8 context:(void *)ctx;
- (void)__saveSelection:(id)fp8 context:(void *)ctx;
- (void)__restoreSelection:(id)fp8 context:(void *)ctx;
- (void)__addToSelection:(id)fp8 context:(void *)ctx;
- (void)__removeFromSelection:(id)fp8 context:(void *)ctx;
- (void)__unionRect:(id)fp8 context:(void *)ctx;
- (void)__select:(id)fp8 context:(void *)ctx;
- (void)__deselect:(id)fp8 context:(void *)ctx;
- (void)__delete:(id)fp8 context:(void *)ctx;
- (void)__move:(id)fp8 context:(void *)ctx;
- (void)__undoableMove:(id)fp8 context:(void *)ctx;
@end

@interface GFGraphView (LocalNodeActor)
- (NSSize)_sizeForNode:(id)fp8;
- (NSPoint)_pointForPort:(id)fp8 inNode:(id)fp12 bounds:(NSRect)fp16;
- (id)_portForPoint:(NSPoint)fp8 inNode:(id)fp16 bounds:(NSRect)fp20;
- (void)_drawNode:(id)fp8 bounds:(NSRect)fp12;
- (void)_drawSelectionRingWithColor:(id)fp8 width:(CGFloat)fp12 forNode:(id)fp16 bounds:(NSRect)fp20;
- (BOOL)_trackMouse:(id)fp8 inNode:(id)fp12 bounds:(NSRect)fp16;
- (NSMenu*)_menuForNode:(id)fp8;
- (BOOL)_nodeAcceptsFirstResponder:(id)fp8;
- (BOOL)_nodeBecomesFirstResponder:(id)fp8;
- (BOOL)_nodeResignsFirstResponder:(id)fp8;
- (BOOL)_handleKeyUp:(id)fp8 inNode:(id)fp12;
- (BOOL)_handleKeyDown:(id)fp8 inNode:(id)fp12;
@end

@interface GFGraphView (Private)
+ (id)_noteAttributes;
- (void)_editNoteAtIndex:(NSUInteger)noteIndex;
- (NSMenu*)_menuForNote:(NSUInteger)noteIndex;
- (void)_setUndoManager:(NSUndoManager*)undoManager;
- (NSPoint)_centerPoint;
- (void)_setCenterPoint:(NSPoint)centerPoint;
- (NSPoint)_pastePoint;
- (void)_startTooltips;
- (void)_showTooltip;
- (void)_hideTooltip;
- (void)_updateTooltipsForMouseLocation:(NSPoint)fp8;
- (void)_stopTooltips;
- (void)_drawGraph:(NSRect)fp8 selectionRingColor:(id)fp24 selectionRingWidth:(CGFloat)fp28 nodeCount:(NSUInteger)fp32 nodeList:(id *)fp36 connectionCount:(NSUInteger)fp40 connectionList:(id *)fp44;
- (BOOL)_editNode:(GFGraph*)npde;
- (void)_printWithInfo:(NSPrintInfo*)info showingPrintPanel:(BOOL)flag;
- (BOOL)_setFirstResponderNode:(id)fp8;
- (void)removeFromSuperview;
- (void)_setGraphEditor:(GFGraphEditorView*)graphEditor;
- (GFGraphEditorView*)_graphEditor;
- (float)_zoomFactor;
- (void)_setZoomFactor:(float)zoomFactor;
- (void)_zoomToFitSelection;
- (void)_zoomToFitAll;
- (void)_cacheZoomState;
- (void)_restoreZoomState;
- (void)_setZoomFactor:(float)zoomFactor centerPoint:(NSPoint)point;
- (void)_zoomWithSpeedFactor:(float)fp8;
- (void)_zoomToFitRect:(NSRect)rect;
- (void)_adjustFrame;
- (void)_validateNodePosition:(id)fp8;
- (void)_validateNodePositions;
- (BOOL)_addNode:(id)fp8 atPosition:(NSPoint)point;
- (void)__stateUpdated:(NSNotification*)notification;
- (void)__layoutUpdated:(NSNotification*)notification;
- (void)__windowKey:(NSNotification*)notification;
- (void)__frameChanged:(NSNotification*)notification;
- (void)_finishInitialization;
- (id)_nodeAtPosition:(NSPoint)fp8 outBounds:(NSRect *)outBounds;
- (NSUInteger)_performActionOnNodes:(SEL)selector context:(void *)ctx selectedOnly:(BOOL)selected;
- (NSUInteger)_performActionOnSelectedNodes:(SEL)selector context:(void *)ctx;
- (NSUInteger)_performActionOnAllNodes:(SEL)selector context:(void *)ctx;
- (NSRect)_boundsForSelection;
- (BOOL)_deselectAll;
- (BOOL)__selectionFilter:(id)fp8;
- (void)_writeSelectionToState:(id)fp8 fromPoint:(NSPoint)point;
- (void)_writeSelectionToArchiver:(id)fp8 fromPoint:(NSPoint)point;
- (void)_writeSelectionToPasteboard:(id)fp8 fromPoint:(NSPoint)point;
- (BOOL)_readSelectionFromState:(id)fp8 toPoint:(NSPoint)point;
- (BOOL)_readSelectionFromUnarchiver:(id)fp8 toPoint:(NSPoint)point;
- (void)_readSelectionFromPasteboard:(id)fp8 toPoint:(NSPoint)point;
- (id)_imageForSelection;
- (id)_firstResponderNode;
- (NSColor*)_colorForConnection:(id)connection;
- (id)_trackedConnection;
- (void)delete:(id)fp8;
@end

@interface GFGraphView (Specific)
- (BOOL)trackMouse:(NSEvent*)event;
- (BOOL)handleKeyDown:(NSEvent*)event;
- (BOOL)handleKeyUp:(NSEvent*)event;
- (BOOL)trackConnection:(NSEvent*)event fromPort:(GFPort*)port atPoint:(NSPoint)point;
- (void)noteContentChanged;
- (id)setupInspectorViews;
- (void)resetInspectorViews;
- (NSString*)tooltipStringForPoint:(NSPoint)point tooltipBounds:(NSRect *)outBounds;
- (id)setupTooltipViewForPoint:(NSPoint)point tooltipBounds:(NSRect *)outBounds;
- (void)resetTooltipView;
- (NSMenu*)menuForGraph;
- (void)setGraph:(GFGraph*)graph;
- (GFGraph*)graph;
- (BOOL)drawsBackground;
- (void)setDrawsBackground:(BOOL)flag;
- (BOOL)drawsShadows;
- (void)setDrawsShadows:(BOOL)flag;
- (void)setGridStep:(NSUInteger)gridStep;
- (NSUInteger)gridStep;
- (NSColor*)backgroundColor;
- (void)setBackgroundColor:(NSColor*)color;
- (NSColor*)gridColor;
- (void)setGridColor:(NSColor*)color;
- (BOOL)alignNodes;
- (void)setAlignNodes:(BOOL)alignNodes;
- (void)setTooltipDelay:(NSTimeInterval)tooltipDelay;
- (NSTimeInterval)tooltipDelay;
- (id)nodeActorForNode:(GFGraph*)node;
- (NSRect)boundsForConnection:(id)connection;
- (NSRect)boundsForNode:(id)node;
- (NSRect)maxBounds;
- (NSRect)boundsForConnection:(id)connection fromPoint:(NSPoint)startPoint toPoint:(NSPoint)endPoint;
- (void)_drawConnection:(id)connection fromPort:(id)port point:(NSPoint)startPoint toPoint:(NSPoint)endPoint;
- (void)drawConnection:(id)connection fromPoint:(NSPoint)startPoint toPoint:(NSPoint)endPoint;
- (void)drawBackground:(NSRect)rect;    // fills background color and draws the grid if _gridStep is non-zero
- (void)drawSelectionArea:(NSRect)rect; // draws the selection box (grey box with outline)
- (NSRect)titlebarBoundsForNote:(NSString*)noteString inBounds:(NSRect)bounds;
- (NSRect)resizeBoundsForNote:(id)fp8 inBounds:(NSRect)bounds;
- (void)drawNote:(NSString*)noteString inBounds:(NSRect)bounds withColor:(NSColor*)color;
- (void)setNeedsDisplayForNode:(id)fp8;
@end
