@interface QCCircularSlider : NSSlider
{
	double _realValue;	// 92 = 0x5c
	double _scale;	// 100 = 0x64
}

+ (void)initialize;
+ (BOOL)accessInstanceVariablesDirectly;
+ (BOOL)automaticallyNotifiesObserversForKey:(NSString*)key;
- (void)_sliderAction:(id)sender;
- (id)initWithFrame:(NSRect)frameRect;
- (id)initWithFrame:(NSRect)frameRect scale:(double)scale;
- (void)scrollWheel:(NSEvent*)event; // added after SSDK was dumped
- (void)setValue:(id)value forKey:(NSString*)key;
- (id)valueForKey:(NSString*)key;
@end
