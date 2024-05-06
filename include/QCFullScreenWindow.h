@interface QCFullScreenWindow : NSWindow
{
	CGDirectDisplayID _displayID;	// 132 = 0x84
}

- (id)initWithScreen:(NSScreen*)screen;
- (CGDirectDisplayID)displayID;
- (BOOL)canBecomeMainWindow;
- (BOOL)canBecomeKeyWindow;
- (void)sendEvent:(NSEvent*)event;

@end
