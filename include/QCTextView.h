// This is only used for QCKeyboardUI, the settings panel for the Keyboard patch.
// under the hood, -keydown: writes to a global bool that's visible to QCKeyboardUI to update the table rows.
// that seems like an unusual design, with atrocious scoping.

@interface QCTextView : NSTextView
+ (id)sharedInstance;
- (void)_windowDidResignKeyNotification:(NSNotification*)notification;
- (void)keyDown:(NSEvent*)event;
- (BOOL)validateMenuItem:(NSMenuItem*)menuItem;
- (BOOL)performKeyEquivalent:(NSEvent*)key;
@end
