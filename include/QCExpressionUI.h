
#import "QCInspector.h"

@class QCProgrammablePatchView;

@interface QCExpressionUI : QCInspector
{
	IBOutlet QCProgrammablePatchView *expressionView;	// 28 = 0x1c
}

+ (NSString*)viewNibName;
- (void)setupViewForPatch:(id)fp8;
- (void)resetView;

@end
