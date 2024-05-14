@class GFGraph, GFPort;

@interface GFConnection : NSObject <GFBase>
{
	GFGraph *_owner;	// 4 = 0x4
	GFPort *_sourcePort;	// 8 = 0x8
	GFPort *_destPort;	// 12 = 0xc
	NSDictionary *_attributes;	// 16 = 0x10
	NSMutableDictionary *_userInfo;	// 20 = 0x14
	void *_unused[4];	// 24 = 0x18
}

- (id)init; // -initWithGrap:... nil, nil, nil, nil, immediately throws an exception.
- (id)initWithGraph:(GFGraph*)graph sourcePort:(GFPort* _Nonnull)src destinationPort:(GFPort* _Nonnull)dst arguments:(NSDictionary* _Nullable)args NS_DESIGNATED_INITIALIZER;
- (void)dealloc;

- (void)connectionWillDeleteFromGraph;  // releases _sourcePort and _destPort, sets them and _owner to nil.  exception thrown if _owner is already nil
- (GFPort*)sourcePort;
- (GFPort*)destinationPort;
- (NSDictionary*)attributes;
- (NSMutableDictionary*)userInfo;
- (GFGraph*)graph;
- (NSMutableDictionary*)state;          // serializes the connection
- (BOOL)setState:(NSDictionary*)state;  // restores the connection from serialization, returns YES
- (void)stateUpdated;
- (NSString*)description;
- (NSString*)key;       // returns _owner's key for this connection

@end
