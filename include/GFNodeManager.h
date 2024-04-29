extern NSString * const GFNodeManagerDidUpdateNotification;

struct GFNodeInfo {
    NSString *fullName;     // 0x00 name class[:identifier] (e.g., @"QCTimeLine" or @"QCStringFormat:printer" or @"/units to pixels")
    id constructor;         // 0x08 "constructor" class (e.g., QCStringFormat) - can be a not-patch, like QCNodeManager for virtual patches
    SEL instantiate;        // 0x10 instantiate selector e.g. @selector(newWithIdentifier:) - sent to constructor
    SEL attributes;         // 0x18 attributes selector e.g. @selector(_publicAttributesWithIdentifier:) - sent to constructor
    NSString *identifier;   // 0x20 "path" or identifier (e.g., @"key" for QCStructureMember:Key) or CIFilterClassName or composition path for virtual patches
    NSDictionary *_field6;  // 0x28 always null? maybe "info"?
}; // info about a single patch/node (including virtual patches)

@interface GFNodeManager : NSObject
{
	NSString *_namespace;	    // 8 = 0x8
	pthread_mutex_t _mutex;	    // 16 = 0x10
	CFDictionaryRef _registry;	// 80 = 0x50
	NSUInteger _infoListSize;	//  88 = 0x58   // number of elements in _infoList (allocated, not necessarily used)
	struct GFNodeInfo *_infoList;	// 96 = 0x60
	void *_unused[4];	        // 104 = 0x68
}

+ (void)initialize;
+ (BOOL)trylock;	// never called in QC framework
+ (void)lock;
+ (void)unlock;
+ (void)checkIdentifier:(id)fp8;
+ (id)managerForNodeNamespace:(NSString*)nodeNamespace;	// @"com.apple.QuartzComposer" is the default
+ (id)instantiateNodeWithName:(id)fp8;
+ (id)instantiateNodeWithClassName:(id)fp8 identifier:(NSString*)identifier;
- (id)init;
- (id)initWithNamespace:(NSString*)nodeNamespace;
- (NSString*)nodeNamespace;
- (id)nodeAttributesWithName:(id)fp8;
- (id)nodeInstanceWithName:(id)fp8;
- (id)instantiateNodeWithName:(id)fp8;
- (void)registerNodeWithClass:(Class)nodeClass;	// equivalent to -[registerNodeWithClass: identifier:nil]
- (void)registerNodeWithClass:(Class)nodeClass identifier:(NSString*)identifier;
- (id)_nodeFromArchive:(id)fp8;
- (id)_attributesFromArchive:(id)fp8;
- (void)registerNode:(id)fp8 withName:(id)fp12;
- (void)registerNodeWithName:(id)fp8 constructor:(id)fp12 instantiateSelector:(SEL)fp16 attributesSelector:(SEL)fp20 info:(id)fp24;
- (void)unregisterNodeWithName:(id)fp8;
- (BOOL)isNodeRegisteredWithName:(id)fp8;
- (NSArray*)nodeNames;
- (NSArray*)nodeNamesContainingAttributes:(id)fp8;
- (NSArray*)nodeNamesMatchingAttributes:(id)fp8;
- (NSArray*)nodeNamesExcludingAttributes:(id)fp8;
- (id)nodeNameWithClassName:(id)fp8 identifier:(NSString*)identifier;
- (void)applyFunction:(void *)fp8 context:(void *)ctx;
- (NSString*)description;
@end

@interface GFNodeManager (PlugIns)
- (void)loadPlugInAtPath:(NSString*)path;
- (void)loadPlugInsInFolder:(NSString*)path withExtensions:(NSArray*)extensions;
- (void)loadPlugInsInLibrary:(id)fp8 withExtensions:(NSArray*)extensions;
@end
