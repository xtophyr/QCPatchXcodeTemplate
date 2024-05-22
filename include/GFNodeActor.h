

@class GFPort;

// Many of these aren't used directly any longer.  In the editor, QCPatchActor and its various subclasses override many of these functions.
// TODO: catalog which methods are still used

@interface GFNodeActor : NSObject
{
	GFPort *_tooltipPort;	// 4 = 0x4
	void *_unused[4];	// 8 = 0x8
}

+ (GFNodeActor*)sharedActor;    // this maintains a set of actors for the various subclass types (each subclass gets its own shared actor)
- (NSSize)sizeForNode:(GFNode*)node;    // calcuates the in-editor size of the node
- (id)_portForPoint:(NSPoint)point inNode:(GFNode*)node bounds:(NSRect)bounds outBounds:(NSRect *)outBounds;
- (id)portForPoint:(NSPoint)point inNode:(GFNode*)node bounds:(NSRect)bounds;   // same as _portForPoint... with nil for outBounds
- (NSPoint)pointForPort:(GFPort*)port inNode:(GFNode*)node bounds:(NSRect)nodeBounds;
- (void)drawNode:(GFNode*)node bounds:(NSRect)bounds view:(GFGraphView*)view;
- (void)drawSelectionRingWithColor:(NSColor*)color width:(CGFloat)width forNode:(GFNode*)node bounds:(NSRect)bounds view:(NSView*)view;
- (BOOL)trackMouse:(id)fp8 inNode:(id)fp12 bounds:(NSRect)bounds view:(NSView*)view;
- (NSMenu*)menuForNode:(GFNode*)node view:(GFGraphView*)view;   // this builds part of the secondary-click menu in the editor
- (BOOL)nodeAcceptsFirstResponder:(id)fp8 view:(NSView*)view;
- (BOOL)nodeBecomesFirstResponder:(id)fp8 view:(NSView*)view;
- (BOOL)nodeResignsFirstResponder:(id)fp8 view:(NSView*)view;
- (BOOL)handleKeyUp:(id)fp8 inNode:(GFNode*)node view:(NSView*)view;
- (BOOL)handleKeyDown:(id)fp8 inNode:(GFNode*)node view:(NSView*)view;
- (id)setupInspectorViewsForNode:(GFNode*)node;
- (void)resetInspectorViews;
- (id)tooltipStringForPoint:(NSPoint)point inNode:(GFNode*)node bounds:(NSRect)bounds tooltipBounds:(NSRect *)tooltipBounds;
- (id)setupTooltipViewForPoint:(NSPoint)point inNode:(GFNode*)node bounds:(NSRect)bounds tooltipBounds:(NSRect *)tooltipBounds;
- (void)resetTooltipView;
@end

@interface GFNodeActor (MenuActions)    // these are set as actions for the secondary-click menu in the editor.
- (void)_publish:(NSMenuItem*)sender;
- (void)__setNodeSelection:(BOOL)selected adjacentToNode:(GFNode*)node inputNodes:(BOOL)inputs selectedList:(NSArray*)list;
- (void)_selectDownstream:(NSMenuItem*)sender;  // (de)select Up-/Down-stream all drive __setNodeSelection:...  YES / NO
- (void)_deselectDownstream:(NSMenuItem*)sender;//  NO / NO
- (void)_selectUpstream:(NSMenuItem*)sender;    //  YES / YES
- (void)_deselectUpstream:(NSMenuItem*)sender;  //  NO / YES
- (void)_editSubgraph:(NSMenuItem*)sender;
@end

@interface GFNodeActor (Private)
- (NSDictionary*)_titleTextAttributesForNode:(GFNode*)node;
- (NSDictionary*)_portTextAttributesForNode:(GFNode*)node;
- (NSColor*)_colorForNode:(GFNode*)node;
- (void)_makeCGPathForNode:(GFNode*)node bounds:(NSRect)bounds inContext:(CGContextRef)cgctx;
- (CGColorRef)_overlayColorForNode:(GFNode*)node view:(NSView*)view;
- (GFConnection*)_portIsConnected:(GFPort*)port view:(NSView*)view;
@end
