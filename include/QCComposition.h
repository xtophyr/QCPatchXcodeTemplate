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
	NSArray *_protocols;
	NSDictionary *_attributes;
	NSArray *_inputKeys;
	NSArray *_outputKeys;
	id _backing;            // one of NSString*, NSData*, NSDictionary*, NSURL*, else InternalInconsistencyException
	NSString *_identifier;
	double _timestamp;
	BOOL _stateOK;
}

- (void)initialize; // locks GFNodeManager, then invokes [QCImage class].  seems like a hackaround.  added after SSDK was dumped.
+ (id)allocWithZone:(NSZone *)zone;                 // ensures no subclasses of QCComposition
+ (id)compositionWithURL:(NSURL*)compositionURL;    // added some time after SSDK was dumped
+ (id)compositionWithFile:(NSString*)filePath;
+ (id)compositionWithData:(NSData*)compositionData;
- (id)copyWithZone:(NSZone *)zone;
- (id)_makePatch;
- (id)_initWithBacking:(id)backing; // one of the supported backing types (see _backing ivar)
- (id)initWithComposition:(QCComposition*)composition;
- (id)initWithPatchName:(NSString*)patchName;
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
+ (BOOL)isCompositionIdentity:(QCComposition*)composition;  // QCCompositionRepository can make an "identity" composition (does nothing).  This tests for equality against that.  used by QCCompositionPickerController
@end

@interface QCComposition (QCCompositionRepository)
- (id)init;
- (id)initWithCompositionFile:(NSString*)path safeMode:(BOOL)safeMode requiredProtocol:(id)protocol;
- (double)_timestamp;
- (BOOL)_stateOK;
- (void)_reclaimResources;  // tosses _outputKeys and _protocols (driven by QCCompositionRepository -reclaimResources, which in turn is driven by QCCompositionPickerPanel -close).
- (NSString*)identifier;
- (void)encodeWithCoder:(NSCoder *)aCoder;
- (id)initWithCoder:(NSCoder *)aDecoder;
@end
