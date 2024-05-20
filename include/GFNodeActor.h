

@class GFPort;

@interface GFNodeActor : NSObject
{
	GFPort *_tooltipPort;	// 4 = 0x4
	void *_unused[4];	// 8 = 0x8
}

+ (GFNodeActor*)sharedActor;
- (NSSize)sizeForNode:(GFNode*)node;
- (id)_portForPoint:(NSPoint)point inNode:(id)fp16 bounds:(NSRect)bounds outBounds:(NSRect *)outBounds;
- (id)portForPoint:(NSPoint)point inNode:(id)fp16 bounds:(NSRect)bounds;
- (NSPoint)pointForPort:(id)fp8 inNode:(id)fp12 bounds:(NSRect)bounds;
- (void)drawNode:(GFNode*)node bounds:(NSRect)bounds view:(GFGraphView*)view;
- (void)drawSelectionRingWithColor:(NSColor*)color width:(CGFloat)width forNode:(id)fp16 bounds:(NSRect)bounds view:(NSView*)view;
- (BOOL)trackMouse:(id)fp8 inNode:(id)fp12 bounds:(NSRect)bounds view:(id)fp32;
- (NSMenu*)menuForNode:(GFNode*)node view:(GFGraphView*)view;
- (BOOL)nodeAcceptsFirstResponder:(id)fp8 view:(NSView*)view;
- (BOOL)nodeBecomesFirstResponder:(id)fp8 view:(NSView*)view;
- (BOOL)nodeResignsFirstResponder:(id)fp8 view:(NSView*)view;
- (BOOL)handleKeyUp:(id)fp8 inNode:(id)fp12 view:(NSView*)view;
- (BOOL)handleKeyDown:(id)fp8 inNode:(id)fp12 view:(NSView*)view;
- (id)setupInspectorViewsForNode:(id)fp8;
- (void)resetInspectorViews;
- (id)tooltipStringForPoint:(NSPoint)point inNode:(GFNode*)node bounds:(NSRect)bounds tooltipBounds:(NSRect *)tooltipBounds;
- (id)setupTooltipViewForPoint:(NSPoint)point inNode:(GFNode*)node bounds:(NSRect)bounds tooltipBounds:(NSRect *)tooltipBounds;
- (void)resetTooltipView;
@end

@interface GFNodeActor (MenuActions)
- (void)_publish:(NSMenuItem*)sender;
- (void)__setNodeSelection:(BOOL)selected adjacentToNode:(id)fp12 inputNodes:(BOOL)inputs selectedList:(NSArray*)list;
- (void)_selectDownstream:(NSMenuItem*)sender;
- (void)_deselectDownstream:(NSMenuItem*)sender;
- (void)_selectUpstream:(NSMenuItem*)sender;
- (void)_deselectUpstream:(NSMenuItem*)sender;
- (void)_editSubgraph:(NSMenuItem*)sender;
@end

@interface GFNodeActor (Private)
- (NSDictionary*)_titleTextAttributesForNode:(GFNode*)node;
- (NSDictionary*)_portTextAttributesForNode:(GFNode*)node;
- (NSColor*)_colorForNode:(GFNode*)node;
- (void)_makeCGPathForNode:(GFNode*)node bounds:(NSRect)bounds inContext:(CGContextRef)cgctx;
- (CGColorRef)_overlayColorForNode:(id)fp8 view:(NSView*)view;
- (GFConnection*)_portIsConnected:(GFPort*)port view:(NSView*)view;
@end
