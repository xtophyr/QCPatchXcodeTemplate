@interface QCImageView : NSImageView
- (void)_resetImage;
- (void)_loadImage;
- (void)mouseDown:(NSEvent*)theEvent;
- (BOOL)_canCreateImageFromPasteboard:(NSPasteboard*)pasteboard;
- (id)_newImageFromPasteboard:(NSPasteboard*)pasteboard;
- (NSDragOperation)draggingEntered:(id <NSDraggingInfo>)sender;
- (void)draggingExited:(id <NSDraggingInfo>)sender;
- (BOOL)performDragOperation:(id <NSDraggingInfo>)sender;
- (void)concludeDragOperation:(id <NSDraggingInfo>)sender;
- (void)paste:(id)sender;
- (BOOL)_copyImage;
- (void)copy:(id)sender;
- (void)cut:(id)sender;
@end
