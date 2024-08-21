
#import "QCInspector.h"

@interface QCDemultiplexerUI : QCInspector
{
	IBOutlet NSPopUpButton *classMenu;
}

+ (NSString*)viewNibName;
- (void)setupViewForPatch:(id)patch;
- (IBAction)setClass:(id)sender;

@end
