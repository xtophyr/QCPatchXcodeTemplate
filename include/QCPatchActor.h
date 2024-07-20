
#import "GFNodeActor.h"

/* QCPatchActor draws nodes in the graph editor view.  It controls stuff like the node's name and title, where ports are located,
 and the visual appearance of the patches.  QCCirclePatchActor is a subclass used to get Logic and Mathematical Expression's different look. */

// UI is backed by QCPatchActorInspectorViews.nib

@class QCInspector, QCPatch, QCTableView;

@interface QCPatchActor : GFNodeActor
{
	NSView *noSettingsView;	// 24 = 0x18
	NSView *noPublishingView;	// 28 = 0x1c
	NSView *notApplicableView;	// 32 = 0x20
	NSView *noParametersView;	// 36 = 0x24
	NSView *publishingView;	// 40 = 0x28
	QCTableView *inputsTableView;	// 44 = 0x2c
	QCTableView *outputsTableView;	// 48 = 0x30
	NSTableColumn *_inputsKeyColumn;	// 52 = 0x34
	NSTableColumn *_outputsKeyColumn;	// 56 = 0x38
	QCPatch *_currentPatch;	// 60 = 0x3c
	QCInspector *_currentInspector;	// 64 = 0x40
	void *_unused2[4];	// 68 = 0x44
}

+ (void)initialize;
- (id)init;
- (void)dealloc;
- (CGColorRef)_overlayColorForNode:(id)fp8 view:(NSView*)view;
- (void)_drawTitle:(id)fp8 inContext:(CGContextRef)context atPoint:(NSPoint)point withAttributes:(id)fp24;
- (void)_drawString:(id)fp8 inContext:(CGContextRef)context atPoint:(NSPoint)point withAttributes:(id)fp24;
- (id)_colorForNode:(id)fp8;
- (NSDictionary*)_titleTextAttributesForNode:(id)node;
- (NSDictionary*)_portTextAttributesForNode:(id)node;
- (NSDictionary*)_patchTypeTextAttributesForNode:(id)node;  // used for subtitle text when a patch has a custom title
- (void)_makeCGPathForNode:(id)fp8 bounds:(NSRect)fp12 inContext:(CGContextRef)context;
- (void)_makeSelectionPathForNode:(id)fp8 border:(float)fp12 bounds:(NSRect)fp16 inContext:(CGContextRef)context;
- (void)_drawBackgroundGradientLayerForNode:(id)fp8 bounds:(NSRect)fp12 reflectionHeight:(CGFloat)fp28 inContext:(CGContextRef)context;
- (id)portForPoint:(NSPoint)fp8 inNode:(id)fp16 bounds:(NSRect)fp20;
- (id)_portForPoint:(NSPoint)fp8 inNode:(id)fp16 bounds:(NSRect)fp20 outBounds:(NSRect *)fp36;
- (NSPoint)pointForPort:(id)fp8 inNode:(id)fp12 bounds:(NSRect)fp16;
- (void)_drawHighLightForNode:(id)fp8 bounds:(NSRect)fp12 inContext:(CGContextRef)context;
- (void)_drawSelectionForNode:(id)fp8 bounds:(NSRect)fp12 inContext:(CGContextRef)context;
- (void)_drawNode:(id)fp8 bounds:(NSRect)fp12 inContext:(CGContextRef)context;
- (CGFloat)_drawBadgeForNode:(id)fp8 bounds:(NSRect)fp12 inContext:(CGContextRef)context;
- (CGFloat)_drawOrderForNode:(id)fp8 bounds:(NSRect)fp12 inContext:(CGContextRef)context;
- (void)_drawTitleForNode:(id)fp8 bounds:(NSRect)fp12 inContext:(CGContextRef)context;
- (void)_drawNameForPort:(id)fp8 node:(id)fp12 atPoint:(NSPoint)fp16 bounds:(NSRect)fp24 inContext:(CGContextRef)context;
- (CGLayerRef)_createPortRingWithColor:(CGColorRef)fp8 inContext:(CGContextRef)context zoom:(CGFloat)fp16;
- (void)_drawPortsForNode:(id)fp8 bounds:(NSRect)fp12 view:(id)fp28 inContext:(CGContextRef)context;
- (void)_drawPortColorsForNode:(id)fp8 bounds:(NSRect)fp12 view:(id)fp28 inContext:(CGContextRef)context;
- (void)_drawOverlayForNode:(id)fp8 bounds:(NSRect)fp12 stroke:(BOOL)fp28 view:(id)fp32 inContext:(CGContextRef)context;
- (void)_drawOverlayForNode:(id)fp8 bounds:(NSRect)fp12 view:(id)fp28 inContext:(CGContextRef)context;
- (QCMD5Sum *)nodeMD5List:(id)fp8 bounds:(NSRect)fp12 view:(id)fp28 zoom:(CGFloat)fp32 outCount:(NSUInteger *)fp36;
- (void)drawNode:(id)fp8 bounds:(NSRect)bounds view:(NSView*)view;
- (id)parametersViewForPatch:(id)fp8;
- (NSSize)sizeForNode:(QCPatch*)node;
- (BOOL)dragsOnPortForNode:(id)fp8;

@end

@interface QCPatchActor (Interaction)
- (BOOL)pointInConsumerOrderRect:(NSPoint)fp8 inNode:(id)fp16 bounds:(NSRect)fp20;
- (BOOL)pointInTitleRect:(NSPoint)fp8 inNode:(id)fp16 bounds:(NSRect)fp20;
- (void)setTitle:(NSString*)title forNode:(id)patch;
- (BOOL)trackMouse:(id)fp8 inNode:(id)fp12 bounds:(NSRect)fp16 view:(id)fp32;
- (id)_portIsConnected:(id)fp8 view:(id)view;
- (id)inspectorForPatch:(id)fp8;
- (void)_updatedParameters:(id)fp8;
- (id)setupInspectorViewsForNode:(id)fp8;
- (void)resetInspectorViews;
- (void)_updatedState:(id)fp8;
- (void)_updatedPorts:(id)fp8;

// NSTableView delegates, used to populate the published port UI in the inspector.  Also manages drag/drop reordering of the ports.
- (NSInteger)numberOfRowsInTableView:(NSTableView*)tableView;
- (id)tableView:(NSTableView*)tableView portForRow:(NSInteger)row;
- (id)tableView:(NSTableView*)tableView objectValueForTableColumn:(NSTableColumn*)fp12 row:(NSInteger)row;
- (BOOL)tableView:(NSTableView*)tableView shouldEditTableColumn:(NSTableColumn*)fp12 row:(NSInteger)row;
- (void)tableView:(NSTableView*)tableView setObjectValue:(id)value forTableColumn:(NSTableColumn*)column row:(NSInteger)row;
- (BOOL)tableView:(NSTableView*)tableView writeRows:(id)fp12 toPasteboard:(NSPasteboard*)pboard;
- (NSUInteger)tableView:(NSTableView*)tableView validateDrop:(id)fp12 proposedRow:(NSInteger)row proposedDropOperation:(NSUInteger)fp20;
- (BOOL)tableView:(NSTableView*)tableView acceptDrop:(id)fp12 row:(NSInteger)row dropOperation:(NSUInteger)fp20;

- (id)parametersViewForPatch:(id)patch;
- (void)_setLayer:(id)fp8;
- (void)_explodeSubgraph:(id)fp8;
- (void)_parent:(NSMenuItem*)sender;
- (void)_local:(NSMenuItem*)sender;
- (void)_external:(NSMenuItem*)sender;
- (void)_refactor:(id)fp8;
- (id)menuForNode:(id)node view:(id)view;
@end

@interface QCPatchActor (Tooltip)
- (id)tooltipStringForPoint:(NSPoint)point inNode:(id)fp16 bounds:(NSRect)bounds tooltipBounds:(NSRect *)fp36;
@end
