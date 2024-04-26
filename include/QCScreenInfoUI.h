
#import "QCInspector.h"

@interface QCScreenInfoUI : QCInspector
{
	IBOutlet NSButton *fullButton;	// 28 = 0x1c
}

+ (NSString*)viewNibName;
- (void)setupViewForPatch:(id)fp8;
- (void)update:(id)fp8;

@end
