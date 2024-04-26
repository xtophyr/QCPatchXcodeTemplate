

#import "QCInspector.h"

@interface QCWatcherUI : QCInspector
{
	IBOutlet NSPopUpButton *classMenu;	// 28 = 0x1c
}

+ (NSString*)viewNibName;
- (void)setupViewForPatch:(id)fp8;
- (void)setClass:(id)fp8;
@end
