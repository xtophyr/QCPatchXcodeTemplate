
@interface GFStringEditor : NSObject
+ (void)_doneEditing:(id)sender;
// string might be modified by this method
+ (BOOL)runSharedEditorWithString:(id *)string inView:(NSView*)view atPoint:(NSPoint)point width:(NSUInteger)width numLines:(NSUInteger)lines;
@end
