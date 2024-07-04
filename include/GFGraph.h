extern NSString * const GFGraphLayoutDidChangeNotification;
extern NSString * const GFStateDidChangeNotification;
extern NSString * const GFStateDidFinishLoadingNotification;

@interface GFGraph : GFNode
{
	GFList *_nodes;	// 56 = 0x38
	GFList *_connections;	// 60 = 0x3c
	BOOL _finalizing;	// 64 = 0x40    // set in dealloc, where connections and nodes released
    pthread_mutex_t *_graphLock;
	void *_unused2[3];	// 68 = 0x44
}

+ (Class)baseClass;
+ (Class)proxyPortClass;
+ (Class)connectionClass;   // returns GFConnection class
- (void)dealloc;
- (BOOL)canAddNode:(GFNode*)node;
- (BOOL)addNode:(GFNode*)node forKey:(NSString*)key;
- (BOOL)addNode:(GFNode*)node;
- (void)removeNodeForKey:(NSString*)key;
- (void)removeNode:(GFNode*)node;
- (void)applyFunctionOnNodes:(void *)func context:(void *)ctx;
- (void)enumerateNodesWithOptions:(NSUInteger)options usingBlock:(void*)block;
- (NSArray *)nodes;	// subpatches
- (void)setLock:(opaque_pthread_mutex_t *)lock; // added after SSDK was dumped - this seems fragile
- (void)applyFunctionOnConnections:(void *)func context:(void *)ctx;
- (void)enumerateConnectionsWithOptions:(NSUInteger)options usingBlock:(void*)block; // added after SSDK was dumped
- (BOOL)canCreateConnectionFromPort:(GFPort*)sourcePort toPort:(GFPort*)destPort;
- (id)createConnectionFromPort:(GFPort*)sourcePort toPort:(GFPort*)destPort forKey:(NSString*)key;
- (id)createConnectionFromPort:(GFPort*)sourcePort toPort:(GFPort*)destPort;

// source and dest array are 2-element arrays containing a port node [index 0] and a port key [index 1].  used to undo deleting a connection.
- (void)__createConnectionFrom:(NSArray*)source to:(NSArray*)dest forKey:(NSString*)key withUserInfo:(NSMutableDictionary*)userInfo;
- (void)deleteConnectionForKey:(NSString*)key;
- (void)deleteConnection:(GFConnection*)connection;
- (NSArray*)connections;
- (GFNode*)nodeForKey:(NSString*)key;
- (NSString*)keyForNode:(GFNode*)node;
- (GFConnection*)connectionForKey:(NSString*)key;
- (NSString*)keyForConnection:(GFConnection*)connection;
- (NSString*)pathForNode:(GFNode*)node;
- (GFNode*)nodeForPath:(NSString*)path;
- (NSString*)pathForPort:(GFPort*)port;
- (GFPort*)portForPath:(NSString*)path;
- (BOOL)canCreateProxyPortWithOriginalPort:(GFPort*)port;
- (GFPort*)createProxyPortWithOriginalPort:(GFPort*)port forKey:(NSString*)key;
- (GFPort*)createProxyPortWithOriginalPort:(GFPort*)port;
- (void)__createProxyPortWithNode:(GFNode*)node portKey:(NSString*)portKey forKey:(NSString*)key withUserInfo:(id)userInfo;
- (void)deleteInputPortForKey:(NSString*)key;
- (void)deleteOutputPortForKey:(NSString*)key;
- (void)deleteProxyPortForKey:(NSString*)key;
- (void)deleteProxyPortWithOriginalPort:(GFPort*)port;
- (GFPort*)proxyPortForOriginalPort:(GFPort*)port;
- (id)proxyInputPorts;
- (id)proxyOutputPorts;
- (NSDictionary*)state;
- (BOOL)setState:(NSDictionary*)state;
- (void)setUndoManager:(NSUndoManager*)undoManager;

@end

@interface GFGraph (GFGraphView)
- (Class)graphViewClass;
@end

@interface GFGraph (Notes)
/* the note dictionary has 3 keys:  @"string", @"bounds", and @"color" */
// index is an NSNumber for serialization purposes?
- (void)_setNote:(NSDictionary*)note atIndex:(NSNumber*)index;
@end

@interface GFGraph (Private)
- (NSString*)_uniqueProxyPortKeyFromPort:(GFPort*)port;
- (BOOL)_finalizing;
- (BOOL)_isNodeKeyInUse:(NSString*)key;
- (NSString*)_uniqueKeyFromNode:(GFNode*)node;
- (BOOL)_isConnectionKeyInUse:(NSString*)key;
- (NSString*)_uniqueConnectionKey;
- (GFList*)_connections;
- (GFList*)_nodes;
- (void)_willDeleteNodeInputPort:(id)port;
- (void)_willDeleteNodeOutputPort:(id)port;
- (void)_layoutUpdated;
- (BOOL)_saveState:(id)fp8 filterTarget:(id)target filterAction:(SEL)filter flatten:(BOOL)shouldFlatten;
- (BOOL)_loadState:(id)fp8;
@end

@interface GFGraph (ProxyPortKeyFromName)
- (NSString*)uniqueProxyPortKeyFromName:(NSString*)name;
@end
