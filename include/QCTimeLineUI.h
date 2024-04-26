
#import "QCInspector.h"

@class QCTimeLineEditorView;

@interface QCTimeLineUI : QCInspector
{
	IBOutlet QCTimeLineEditorView *editorView;	// 28 = 0x1c
}

+ (NSString*)viewNibName;
- (void)setupViewForPatch:(id)fp8;

@end
