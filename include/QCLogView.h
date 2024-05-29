@class QCPatch;

extern NSString * const QCLogViewNewMessageNotification;
// UI is backed by QCLogView.nib

@interface QCLogView : NSView
{
	NSView *_insideView;	// 80 = 0x50
	NSScrollView *_scrollView;	// 84 = 0x54
	NSTextView *_textView;	// 88 = 0x58
	QCPatch *_rootPatch;	// 92 = 0x5c
	void *_unused[4];	// 96 = 0x60
}

+ (void)initialize;
- (id)initWithFrame:(NSRect)frameRect;
- (id)initWithCoder:(NSCoder *)aDecoder;
- (void)_finishInitialization;
- (void)encodeWithCoder:(NSCoder *)aCoder;
- (void)dealloc;

- (Class)valueClassForBinding:(NSBindingName)binding;
- (void)_appendLog:(NSString*)logMessage;
- (void)_message:(NSNotification*)notification; // [notification userInfo] is the message string, [notification object] is a QCPatch*
- (void)setRootPatch:(QCPatch*)patch;
- (id)rootPatch;
- (void)clear:(id)unused;
@end
