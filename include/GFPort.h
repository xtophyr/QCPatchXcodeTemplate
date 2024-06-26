@class GFNode;

extern NSString * const GFPortsLayoutDidChangeNotification;

/* GFPort flags:  These are used in hundreds of places, so it'll probably take a while to catalog everything
 0x80000 - is OR'd in various mesh-centric functions -[QCMeshRenderer execute:time:arguments:], QCStreamManager, 
 */

@interface GFPort : NSObject <GFBase>
{
	NSUInteger _flags;	// 4 = 0x4
	GFNode *_owner;	// 8 = 0x8
	GFPort *_originalPort;	// 12 = 0xc
	NSDictionary *_attributes;	// 16 = 0x10
	NSMutableDictionary *_userInfo;	// 20 = 0x14
    GFPort *_rootPort;  // added after SSDK was dumped
	void *_unused[3];	// 24 = 0x18
}

- (id)init;
- (id)initWithNode:(GFNode*)node arguments:(NSDictionary*)args;
- (void)dealloc;
- (void)portWillDeleteFromNode;
- (GFNode*)node;
- (NSDictionary*)attributes;
- (NSMutableDictionary*)userInfo;
- (NSDictionary*)state;
- (BOOL)setState:(NSDictionary*)state;
- (void)stateUpdated;
- (NSString *)description;
- (NSString *)key;
- (GFPort*)originalPort;
@end

@interface GFPort (GFNodeActor)
- (NSString*)tooltipString;
- (id)setupTooltipView;
- (void)resetTooltipView;
@end

@interface GFPort (MessageForwarding)
- (BOOL)respondsToSelector:(SEL)selector;
- (NSMethodSignature*)methodSignatureForSelector:(SEL)selector;
- (void)forwardInvocation:(NSInvocation*)anInvocation;
@end

@interface GFPort (Private)
- (NSUInteger)_flags;
- (void)_setFlags:(NSUInteger)flags;
- (void)_unsetFlags:(NSUInteger)flags;
- (NSMutableDictionary*)_userInfo;
@end

@interface GFPort (ProxyNameEditing)
- (NSString*)editName:(NSString*)portName inView:(NSView*)view;
@end
