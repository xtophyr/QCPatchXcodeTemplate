#import "QCInspector.h"

@class QCPlugInViewController;

@interface QCPlugInInspector : QCInspector
{
	QCPlugInViewController *_viewController;	// 28 = 0x1c
}

+ (NSString*)viewNibName;
- (void)observeValueForKeyPath:(NSString*)path ofObject:(id)object change:(NSDictionary*)change context:(void *)context;
- (id)initWithBundle:(NSBundle*)bundle nibName:(NSString*)nibName;
- (void)setupViewForPatch:(id)fp8;
- (id)view;
- (id)viewTitle;
- (void)resetView;

@end
