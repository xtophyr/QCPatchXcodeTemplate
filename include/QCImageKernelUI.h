
#import "QCInspector.h"

@class QCProgrammablePatchView;

@interface QCImageKernelUI : QCInspector
{
	IBOutlet QCProgrammablePatchView *sourceView;	// 28 = 0x1c
	IBOutlet QCProgrammablePatchView *advancedViewMain;	// 32 = 0x20
	IBOutlet NSButton *dodButton;	// 36 = 0x24
	IBOutlet NSSplitView *splitView;	// 40 = 0x28
	IBOutlet NSButton *advancedModeButton;	// 44 = 0x2c
}

+ (NSString*)viewNibName;
- (void)setupViewForPatch:(id)fp8;
- (void)resetView;
- (void)changeMode:(id)fp8;
/* NSSplitViewDelegate stuff */
- (CGFloat)splitView:(NSSplitView*)splitView constrainSplitPosition:(CGFloat)proposedPosition ofSubviewAt:(NSInteger)dividerIndex;
- (BOOL)splitView:(NSSplitView*)splitView canCollapseSubview:(NSView*)subview;
- (CGFloat)splitView:(NSSplitView*)splitView constrainMinCoordinate:(CGFloat)proposedMinimumPosition ofSubviewAt:(NSInteger)dividerIndex;
- (CGFloat)splitView:(NSSplitView*)splitView constrainMaxCoordinate:(CGFloat)proposedMaximumPosition ofSubviewAt:(NSInteger)dividerIndex;
- (BOOL)splitView:(NSSplitView*)splitView shouldCollapseSubview:(NSView*)subview forDoubleClickOnDividerAtIndex:(NSInteger)dividerIndex;

@end
