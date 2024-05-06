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

+ (void)initialize; // sets up a recursive mutex (PTHREAD_RECURSIVE_MUTEX_INITIALIZER didn't exist back then I guess)
+ (BOOL)trylock;	// never called in QC framework
+ (void)lock;
+ (void)unlock;
/* This will throw an exception (!) if identifier contains forbidden characters.  Allowed characters are a-z, A-Z, 0-9, '-', and '_' */
+ (void)checkIdentifier:(NSString*)identifier;
+ (id)managerForNodeNamespace:(NSString*)nodeNamespace;	// @"com.apple.QuartzComposer" is the default
+ (id)instantiateNodeWithName:(NSString*)name;
+ (id)instantiateNodeWithClassName:(id)fp8 identifier:(NSString*)identifier;
- (id)init; // calls -initWithNamespace:nil (which immediately throws an exception)
- (id)initWithNamespace:(NSString*)nodeNamespace NS_DESIGNATED_INITIALIZER;
- (NSString*)nodeNamespace;
- (id)nodeAttributesWithName:(id)fp8;
- (id)nodeInstanceWithName:(id)fp8; // deprecated -> -instantiateNodeWithName:
- (id)instantiateNodeWithName:(NSString*)name;
- (void)registerNodeWithClass:(Class)nodeClass;	// equivalent to -[registerNodeWithClass: identifier:nil]
- (void)registerNodeWithClass:(Class)nodeClass identifier:(NSString*)identifier;
- (id)_nodeFromArchive:(id)fp8;
- (id)_attributesFromArchive:(id)fp8;
- (void)registerNode:(id)fp8 withName:(NSString*)name;
- (void)registerNodeWithName:(NSString*)name constructor:(id)ctorClass instantiateSelector:(SEL)instantiate attributesSelector:(SEL)attributes info:(id)fp24;
- (void)unregisterNodeWithName:(NSString*)name;
- (BOOL)isNodeRegisteredWithName:(NSString*)name;
- (NSArray*)nodeNames;
- (NSArray*)nodeNamesContainingAttributes:(id)fp8;
- (NSArray*)nodeNamesMatchingAttributes:(id)fp8;
- (NSArray*)nodeNamesExcludingAttributes:(id)fp8;
- (id)nodeNameWithClassName:(id)fp8 identifier:(NSString*)identifier;
//- (void)applyFunction:(void *)fp8 context:(void *)ctx;  // this no longer exists as of 14.4.1
- (void)enumerateNodesUsingBlock:(void(^)(NSString *fullName, id constructor, NSString *path, NSDictionary *attributes))block; // probably replaced applyFunction.  fullName is classname:identifier, path can be nil
- (NSString*)description;
@end

@interface GFNodeManager (PlugIns)
- (void)loadPlugInAtPath:(NSString*)path;
- (void)loadPlugInsInFolder:(NSString*)path withExtensions:(NSArray*)extensions;
- (void)loadPlugInsInLibrary:(id)fp8 withExtensions:(NSArray*)extensions;
@end
