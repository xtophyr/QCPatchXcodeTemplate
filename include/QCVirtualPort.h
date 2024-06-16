
#import "QCPort.h"

@interface QCVirtualPort : QCPort
{
	id _value;	// 104 = 0x68
	NSUInteger _lastFlagUpdateFrameID;	// 108 = 0x6c
	void *_unused3[3];	// 112 = 0x70
}

+ (Class)baseClass;                     // returns [QCVirtualPort class]
- (id)rawValue;                         // same as -value
- (void)setRawValue:(id)rawValue;
- (BOOL)acceptValuesOfClass:(Class)cls; // returns NO
- (Class)valueClass;                    // returns nil
- (id)stateValue;                       // returns nil
- (BOOL)setStateValue:(id)stateValue;   // returns NO

@end

@interface QCVirtualPort (Tooltip)
- (id)tooltipString;
@end

@interface QCVirtualPort (Override)
- (id)initWithNode:(GFNode*)node arguments:(NSDictionary*)args;
- (void)dealloc;
- (id)value;
- (BOOL)setValue:(id)value;             // returns NO
- (BOOL)canConnectToPort:(QCPort*)port; // returns YES
- (BOOL)takeValue:(id)value fromPort:(QCPort*)port;
@end
