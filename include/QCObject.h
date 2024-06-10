@interface QCObject : NSObject
{
	CFDictionaryRef _staticMetadata;	// 4 = 0x4
	CFDictionaryRef _forwardMetadata;	// 8 = 0x8
	void *_unused[4];	// 12 = 0xc
}

+ (id)allocWithZone:(NSZone *)zone; // ensures there are only subclasses - this class cannot be instantiated directly.
- (void)finalize;
- (void)dealloc;
- (void)setMetadata:(id)object forKey:(NSString*)key shouldForward:(BOOL)shouldForward;
- (void)removeMetadataForKey:(NSString*)key;
- (void)removeAllMetadata;
- (id)metadataForKey:(NSString*)key;
- (CFDictionaryRef)_forwardMetadata;
- (void)forwardMetadataToObject:(id)object;
- (id)allMetadata;
- (id)allStaticMetadata;
- (id)allForwardedMetadata;
@end
