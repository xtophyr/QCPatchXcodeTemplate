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

// These are used typically under -_performActionOn... methods below, where they're applied to all, or just selected patches.
@interface GFGraphView (ItemActions)
- (void)__validatePosition:(GFNode*)node context:(void *)ctx;   // ctx unused
- (void)__savePosition:(GFNode*)node context:(void *)ctx;       // ctx unused
- (void)__restorePosition:(GFNode*)node context:(void *)ctx;    // ctx maybe used?
- (void)__saveSelection:(GFNode*)node context:(void *)ctx;      // ctx unused
- (void)__restoreSelection:(GFNode*)node context:(void *)ctx;   // ctx unused
- (void)__addToSelection:(GFNode*)node context:(void *)ctx;     // ctx is pointer to CGRect
- (void)__removeFromSelection:(GFNode*)node context:(void *)ctx;// ctx is pointer to CGRect
- (void)__unionRect:(GFNode*)node context:(void *)ctx;          // ctx is pointer to CGRect
- (void)__select:(GFNode*)node context:(void *)ctx;             // ctx unused
- (void)__deselect:(GFNode*)node context:(void *)ctx;           // ctx unused
- (void)__delete:(GFNode*)node context:(void *)ctx;             // ctx unused
- (void)__move:(GFNode*)node context:(void *)ctx;               // ctx is pointer to CGPoint delta
- (void)__undoableMove:(GFNode*)node context:(void *)ctx;       // ctx is pointer to CGPoint delta
@end

@interface GFGraphView (LocalNodeActor)
- (NSSize)_sizeForNode:(GFNode*)node;
- (NSPoint)_pointForPort:(id)fp8 inNode:(id)fp12 bounds:(NSRect)fp16;
- (id)_portForPoint:(NSPoint)fp8 inNode:(id)fp16 bounds:(NSRect)fp20;
- (void)_drawNode:(id)fp8 bounds:(NSRect)fp12;
- (void)_drawSelectionRingWithColor:(NSColor*)color width:(CGFloat)fp12 forNode:(id)fp16 bounds:(NSRect)fp20;
- (BOOL)_trackMouse:(id)fp8 inNode:(id)fp12 bounds:(NSRect)fp16;
- (NSMenu*)_menuForNode:(GFNode*)node;
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
- (BOOL)_editNode:(GFGraph*)node;
- (void)_printWithInfo:(NSPrintInfo*)info showingPrintPanel:(BOOL)flag;
- (BOOL)_setFirstResponderNode:(GFNode*)node;
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
- (void)_zoomWithSpeedFactor:(float)speedFactor;
- (void)_zoomToFitRect:(NSRect)rect;
- (void)_adjustFrame;
- (void)_validateNodePosition:(id)node;
- (void)_validateNodePositions;
- (BOOL)_addNode:(GFNode*)node atPosition:(NSPoint)point;
- (void)__stateUpdated:(NSNotification*)notification;
- (void)__layoutUpdated:(NSNotification*)notification;
- (void)__windowKey:(NSNotification*)notification;
- (void)__frameChanged:(NSNotification*)notification;
- (void)_finishInitialization;
- (id)_nodeAtPosition:(NSPoint)fp8 outBounds:(NSRect *)outBounds;

// these return the number of nodes visited (so it's also used with nil selector as a method to count selected nodes, for example).
// ctx is a pointer passed to the __... context: methods above.  It's mainly used to get results out, such as unioned rects.
// move and undoableMove use ctx to pass in a CGPoint where x and y are deltas from the current location.
- (NSUInteger)_performActionOnNodes:(SEL)selector context:(void *)ctx selectedOnly:(BOOL)selected;
- (NSUInteger)_performActionOnSelectedNodes:(SEL)selector context:(void *)ctx;
- (NSUInteger)_performActionOnAllNodes:(SEL)selector context:(void *)ctx;
- (NSRect)_boundsForSelection;
- (BOOL)_deselectAll;
- (BOOL)__selectionFilter:(id)fp8;
- (void)_writeSelectionToState:(NSMutableDictionary*)state fromPoint:(NSPoint)point;
- (void)_writeSelectionToArchiver:(NSKeyedArchiver*)state fromPoint:(NSPoint)point;
- (void)_writeSelectionToPasteboard:(NSPasteboard*)state fromPoint:(NSPoint)point;
- (BOOL)_readSelectionFromState:(NSMutableDictionary*)state toPoint:(NSPoint)point;
- (BOOL)_readSelectionFromUnarchiver:(NSKeyedUnarchiver*)state toPoint:(NSPoint)point;
- (void)_readSelectionFromPasteboard:(NSPasteboard*)state toPoint:(NSPoint)point;
- (id)_imageForSelection;
- (GFNode*)_firstResponderNode;
- (NSColor*)_colorForConnection:(id)connection;
- (GFConnection*)_trackedConnection;
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
- (NSRect)resizeBoundsForNote:(id)node inBounds:(NSRect)bounds;
- (void)drawNote:(NSString*)noteString inBounds:(NSRect)bounds withColor:(NSColor*)color;
- (void)setNeedsDisplayForNode:(id)node;
@end
