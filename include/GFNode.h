#if MAC_OS_X_VERSION_MAX_ALLOWED < 1060
	#define NS_FORMAT_FUNCTION(F,A)
#endif

@class GFGraph, GFList, GFNodeClassDescription;

/* _flags for GFNode:
        TBD
 */

@interface GFNode : NSObject <GFBase, NSCoding, NSCopying>
{
	GFList *_inputPorts;	// 4 = 0x4
	GFList *_outputPorts;	// 8 = 0x8
	GFGraph *_parent;	// 12 = 0xc
	NSUInteger _flags;	// 16 = 0x10
	NSString *_identifier;	// 20 = 0x14
	NSMutableDictionary *_userInfo;	// 24 = 0x18
	NSUInteger _notificationsDisabled;	// 28 = 0x1c
	NSUInteger _notificationsPaused;	// 32 = 0x20
	GFList *_notificationsQueue;	// 36 = 0x24
	GFNodeClassDescription *_classDescription;	// 40 = 0x28
	NSUndoManager *_undoManager;	// 44 = 0x2c
	void *_unused[2];	// 48 = 0x30
}

+ (void)initialize;
+ (id)xmlAttributesWithIdentifier:(NSString*)identifier;
+ (id)attributesWithIdentifier:(NSString*)identifier;
+ (NSUInteger)stateVersionWithIdentifier:(NSString*)identifier;
+ (BOOL)shouldCreateIvarPorts;
+ (BOOL)shouldLoadAttributes;
+ (id)nodeWithIdentifier:(NSString*)identifier;
- (NSUInteger)versionFromState:(id)state;
- (id)init;
- (void)__setValue:(id)value forIvar:(const char *)ivarName;
- (id)initWithIdentifier:(NSString*)identifier;
- (void)dealloc;
- (NSString*)identifier;
- (NSDictionary*)argumentsForIvarPortWithKey:(NSString*)key;
- (GFPort*)createInputPortWithArguments:(NSDictionary*)args forKey:(NSString*)key;
- (GFPort*)createOutputPortWithArguments:(NSDictionary*)args forKey:(NSString*)key;
- (void)setInputPortOrder:(NSUInteger)fp8 forKey:(NSString*)key;
- (void)setOutputPortOrder:(NSUInteger)fp8 forKey:(NSString*)key;
- (void)deleteInputPortForKey:(NSString*)key;
- (void)deleteOutputPortForKey:(NSString*)key;
- (NSMutableDictionary *)userInfo;
- (NSArray *)inputPorts;
- (NSArray *)outputPorts;
- (void)applyFunctionOnInputPorts:(void(*)(id port, void *ctx))func context:(void *)context;
- (void)enumerateInputPortsWithOptions:(NSUInteger)options usingBlock:(void*)block; // added after SSDK was dumped
- (void)applyFunctionOnOutputPorts:(void(*)(id port, void *ctx))func context:(void *)context;
- (void)enumerateOutputPortsWithOptions:(NSUInteger)options usingBlock:(void*)block; // added after SSDK was dumped
- (void)enumeratePortsWithOptions:(NSUInteger)options usingBlock:(void*)block; // added after SSDK was dumped
- (NSArray *)ivarInputPorts;
- (NSArray *)ivarOutputPorts;
- (NSArray *)customInputPorts;
- (NSArray *)customOutputPorts;
- (BOOL)saveCustomInputPortStates:(id)fp8 toState:(NSMutableDictionary*)state;
- (BOOL)saveCustomOutputPortStates:(id)fp8 toState:(NSMutableDictionary*)state;
- (BOOL)restoreCustomInputPortStates:(id)fp8 fromState:(NSDictionary*)state;
- (BOOL)restoreCustomOutputPortStates:(id)fp8 fromState:(NSDictionary*)state;
- (NSDictionary *)xmlAttributes;
- (NSDictionary*)attributes;
- (NSUndoManager*)undoManager;
- (void)setUndoManager:(NSUndoManager*)undoManager;
- (NSString*)description;
- (NSDictionary*)state;
- (BOOL)setState:(NSDictionary*)state;
- (void)encodeWithCoder:(NSCoder*)aCoder;
- (id)initWithCoder:(NSCoder*)aDeoder;
- (id)copyWithZone:(NSZone *)zone;
- (id)portForKey:(NSString*)key;
- (NSString*)keyForPort:(GFPort*)port;
- (int)directionForPort:(GFPort*)port;    // inputs return -1, outputs return 1, invalid returns 0
- (id)graph;    // _parent
- (void)pauseNotifications;
- (void)resumeNotifications;
- (void)stateUpdated;
- (void)logMessage:(NSString *)format, ... NS_FORMAT_FUNCTION(1,2);
- (void)debugMessage:(NSString*)message; // TODO: this one is maybe var args after all...
- (NSString*)key;
- (void)nodeDidAddToGraph:(id)fp8;
- (void)nodeWillRemoveFromGraph;
- (void)__setUndoableValue:(id)fp8 forKeyPath:(NSString*)keyPath updatesState:(id)fp16;
- (void)setUndoableValue:(id)fp8 forKeyPath:(NSString*)keyPath updatesState:(BOOL)flag;

@end

@interface GFNode (GFNodeActor)
- (GFNodeActor*)nodeActorForView:(NSView*)view;
@end

@interface GFNode (Private)
+ (id)newWithIdentifier:(NSString*)identifier;
+ (Class)nodeClassDescriptionClass;
+ (Class)_listClass;
+ (NSString*)_keyFromName:(NSString*)name;
- (GFNodeClassDescription*)nodeClassDescription;
- (void)disableNotifications;
- (void)enableNotifications;
- (NSString*)debugPath;
- (id)_getUserInfo:(NSString*)key;  // returns object from _userInfo for key, recursing parent's userInfo if not found
- (void)_logMessage:(NSString*)message; // this one doesn't handle format strings
- (GFList*)_inputPorts;
- (GFList*)_outputPorts;
- (NSString*)_baseKey;
- (BOOL)_isPortKeyInUse:(NSString*)key;
- (NSString*)_uniqueInputPortKey;
- (NSString*)_uniqueOutputPortKey;
- (void)_portsUpdated;
- (void)_postNotification:(NSString*)notification sender:(id)sender;
- (id)_stateForPorts:(id)ports;
- (BOOL)_setState:(id)state forPorts:(id)ports;
- (id)_portsFromList:(GFList*)portList withSetFlags:(NSUInteger)fp12 unsetFlags:(NSUInteger)fp16;
- (id)_userInfo;
@end
