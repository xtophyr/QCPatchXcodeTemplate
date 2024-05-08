extern NSString * const QCCompositionAttributeApplePrivateKey;
extern NSString * const QCCompositionAttributeBuiltInKey;
extern NSString * const QCCompositionAttributeCategoryKey;
extern NSString * const QCCompositionAttributeCopyrightKey;
extern NSString * const QCCompositionAttributeDescriptionKey;
extern NSString * const QCCompositionAttributeExcludedHostsKey;
extern NSString * const QCCompositionAttributeExclusiveHostsKey;
extern NSString * const QCCompositionAttributeHasConsumersKey;
extern NSString * const QCCompositionAttributeIsTimeDependentKey;
extern NSString * const QCCompositionAttributeNameKey;
extern NSString * const QCCompositionAttributeProtocolsKey;
extern NSString * const QCCompositionAttributeSourceKey;
extern NSString * const QCCompositionAttributeThumbnailDataKey;
extern NSString * const QCCompositionCategoryDistortion;
extern NSString * const QCCompositionCategoryStylize;
extern NSString * const QCCompositionCategoryUtility;

@interface QCComposition : NSObject <NSCopying>
{
	NSArray *_protocols;	// 4 = 0x4
	NSDictionary *_attributes;	// 8 = 0x8
	NSArray *_inputKeys;	// 12 = 0xc
	NSArray *_outputKeys;	// 16 = 0x10
	id _backing;	// 20 = 0x14    // one of NSString*, NSData*, NSDictionary*, NSURL*, else InternalInconsistencyException
	NSString *_identifier;	// 24 = 0x18
	double _timestamp;	// 28 = 0x1c
	BOOL _stateOK;	// 36 = 0x24
}

- (void)initialize; // locks GFNodeManager, then invokes [QCImage class].  seems like a hackaround.  added after SSDK was dumped.
+ (id)allocWithZone:(NSZone *)zone;                 // ensures no subclasses of QCComposition
+ (id)compositionWithURL:(NSURL*)compositionURL;    // added some time after SSDK was dumped
+ (id)compositionWithFile:(NSString*)filePath;
+ (id)compositionWithData:(NSData*)compositionData;
- (id)copyWithZone:(NSZone *)zone;
- (id)_makePatch;
- (id)_initWithBacking:(id)backing; // one of the supported backing types (see _backing ivar)
- (id)initWithComposition:(id)fp8;
- (id)initWithPatchName:(id)fp8;
- (void)dealloc;
- (id)defaultInputParameters;
- (id)composition;
- (id)patch;
- (NSArray*)protocols;
- (NSDictionary*)attributes;
- (NSArray*)inputKeys;
- (NSArray*)outputKeys;
- (id)filePath;
- (id)_backing;
- (NSString*)description;

@end

@interface QCComposition (InternalExtensions)
+ (BOOL)isCompositionIdentity:(id)fp8;  // QCCompositionRepository can make an "identity" composition (does nothing).  This tests for equality against that.  used by QCCompositionPickerController
@end

@interface QCComposition (QCCompositionRepository)
- (id)init;
- (id)initWithCompositionFile:(id)fp8 safeMode:(BOOL)safeMode requiredProtocol:(id)protocol;
- (double)_timestamp;
- (BOOL)_stateOK;
- (NSString*)identifier;
- (void)encodeWithCoder:(NSCoder *)aCoder;
- (id)initWithCoder:(NSCoder *)aDecoder;
@end
