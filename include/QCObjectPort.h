#import "QCVirtualPort.h"

@interface QCObjectPort : QCVirtualPort
{
	void *_unused4[5];	// 128 = 0x80
}

+ (id)allocWithZone:(NSZone *)zone;     // ensures there are only subclasses - this class cannot be instantiated directly.
- (Class)objectClass;
- (id)object;
- (BOOL)setObject:(id)objectValue;
@end

@interface QCObjectPort (Override)
- (id)initWithNode:(QCPatch*)owner arguments:(NSDictionary*)args;
- (Class)valueClass;
- (BOOL)setValue:(id)fp8;
- (BOOL)acceptValuesOfClass:(Class)valueClass;
- (BOOL)canConnectToPort:(QCPort*)port;
- (BOOL)takeValue:(id)fp8 fromPort:(QCPort*)port;
- (NSString*)description;
@end
