
#import "QCInspector.h"

@interface QCBillboardUI : QCInspector
{
	IBOutlet NSPopUpButton *scaleMenu;	// 28 = 0x1c
}

+ (NSString*)viewNibName;
- (void)setupViewForPatch:(id)fp8;
- (void)updateScale:(id)fp8;
@end
