/* QCSharedTimers drive all the QCViews -- they register as clients, and this class sets up the timer. */

/*
 Internally, timers are grouped with tolerance (+- 5% of frequency).
 */

@interface QCSharedTimers : NSObject
{
	CFArrayRef _timers;	// 4 = 0x4  // CFArray of CFRunLoopTimerRefs.
}

+ (id)sharedTimers;
- (id)init;
- (void)addClient:(id)client selector:(SEL)selector frequency:(float)timerFrequency;
- (void)removeClient:(id)client selector:(SEL)selector; // nil selector means remove all timers for the client
- (NSString*)description;

@end
