// QCTableView is used as a superclass for a few other tableview-based inspectors (GL Info, for example).  It handles basic editing and cancellation.

@interface QCTableView : NSTableView
{
	BOOL _cancelEditing;	// 228 = 0xe4
}

- (void)cancelOperation:(id)sender;
- (void)textDidEndEditing:(NSNotification*)notification;
@end
