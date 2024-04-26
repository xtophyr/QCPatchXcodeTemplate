
#import "QCInspector.h"

@class QCTableView;

@interface QCOpenGLInfoUI : QCInspector
{
	IBOutlet QCTableView *tableView;	// 28 = 0x1c
}

+ (NSString*)viewNibName;
- (void)setupViewForPatch:(id)fp8;
- (void)addExtension:(id)fp8;
- (void)removeExtension:(id)fp8;
- (NSInteger)numberOfRowsInTableView:(NSTableView*)tableView;
- (id)tableView:(NSTableView*)tableView objectValueForTableColumn:(NSTableColumn*)tableColumn row:(NSInteger)row;
- (void)tableView:(NSTableView*)tableView setObjectValue:(id)value forTableColumn:(NSTableColumn*)tableColumn row:(NSInteger)row;

@end
