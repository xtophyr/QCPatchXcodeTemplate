@class GFNodeManagerView;

// GFGraphEditorView is a thin wrapper over GFGraphView.  It manages notifications, and redirects stuff to a GFGraphView inside _scrollView.

extern NSString * const GFGraphEditorViewCenterDidChangeNotification;
extern NSString * const GFGraphEditorViewContentDidChangeNotification;
extern NSString * const GFGraphEditorViewGraphDidChangeNotification;
extern NSString * const GFGraphEditorViewSelectionDidChangeNotification;

@interface GFGraphEditorView : NSView
{
	NSScrollView *_scrollView;	// 80 = 0x50
	GFNodeManagerView *_nodeManager;	// 84 = 0x54
	void *_unused[4];	// 88 = 0x58
}

- (id)initWithFrame:(NSRect)frame;
- (void)dealloc;
- (BOOL)isOpaque;
- (void)resizeSubviewsWithOldSize:(NSSize)oldSize;  // oldSize is unused
- (void)showGraphEditorInspector:(id)sender;
- (void)printWithInfo:(NSPrintInfo*)info showingPrintPanel:(BOOL)flag;
- (void)setGraph:(id)graph;
- (id)graph;
- (NSPoint)editorCenter;
- (void)setEditorCenter:(NSPoint)center;
- (NSSize)editorSize;
- (void)setEditorSize:(NSSize)size;
- (void)encodeWithCoder:(NSCoder *)aCoder;
- (id)initWithCoder:(NSCoder *)aDecoder;
- (void)setGridStep:(NSUInteger)gridStep;
- (NSUInteger)gridStep;
- (BOOL)drawsShadows;
- (void)setDrawsShadows:(BOOL)flag;
- (NSColor*)backgroundColor;
- (void)setBackgroundColor:(NSColor*)backgroundColor;
- (NSColor*)gridColor;
- (void)setGridColor:(NSColor*)gridColor;
- (BOOL)alignNodes;
- (void)setAlignNodes:(BOOL)flag;
- (float)zoomFactor;
- (void)setZoomFactor:(float)zoomFactor;
- (void)zoomToFitSelection;
- (void)zoomToFitAll;
- (void)setTooltipDelay:(NSTimeInterval)delay;
- (NSTimeInterval)tooltipDelay;
- (void)setNodeManager:(GFNodeManager)nodeManager;
- (id)nodeManager;
- (id)graphView;

@end

@interface GFGraphEditorView (Private)
- (void)__instantiateNode:(NSNotification*)notification;
- (void)_finishInitialization;
- (void)__contentUpdated:(NSNotification*)notification;
- (void)__selectionUpdated:(NSNotification*)notification;
- (void)_setGraphView:(GFGraphView*)graphView;
- (void)removeFromSuperview; // added after SSDK was dumped
- (void)viewDidMoveToWindow; // added after SSDK was dumped, I think this tells the window to not be opaque if the editor view isn't opque.
@end
