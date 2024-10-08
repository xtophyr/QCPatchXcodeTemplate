extern NSString * const QCCompositionRepositoryDidUpdateNotification;

extern NSString * const QCCompositionProtocolGraphicAnimation;
extern NSString * const QCCompositionProtocolGraphicTransition;
extern NSString * const QCCompositionProtocolImageFilter;
extern NSString * const QCCompositionProtocolMusicVisualizer;
extern NSString * const QCCompositionProtocolPhotoVisualizer;
extern NSString * const QCCompositionProtocolRSSVisualizer;
extern NSString * const QCCompositionProtocolScreenSaver;

@interface QCCompositionRepository : NSObject
{
@private
    dispatch_queue_t                    cq;
}

// this class seems wildly different from how it looks in the public header.  since it can't be subclassed, public headers are likely quite stale.
/*@interface QCCompositionRepository : NSObject
{
	pthread_mutex_t _mutex;	// 4 = 0x4
	CFDictionaryRef _compositions;	// 48 = 0x30
	NSMutableDictionary *_protocols;	// 52 = 0x34
	NSMutableArray *_directories;	// 56 = 0x38
	BOOL _safeMode;	// 60 = 0x3c
	NSString *_requiredProtocol;	// 64 = 0x40
}*/

+ (id)allocWithZone:(NSZone *)zone;     // // ensures no subclasses of QCCompositionRepository
+ (void)initialize;
+ (id)defaultSortDescriptors;
+ (id)identityComposition;
+ (QCCompositionRepository*)sharedCompositionRepository;
+ (id)sharedCompositionRepository:(BOOL)noAutoUpdate; // calls -...WithOptions: with @"noAutoUpdate" key set
+ (id)sharedCompositionRepositoryWithOptions:(NSDictionary*)options;
+ (id)sharedCompositionRepositoryWithRequiredProtocol:(id)fp8;
- (id)_cacheFileName;
- (BOOL)_writeCacheFile:(id)fp8;
- (id)_readCacheFile;
- (id)_cachedCompositions:(CFDictionaryRef)fp8;
- (BOOL)_updateCompositions:(CFDictionaryRef)fp8;
- (void)_initCompositionGCDSources;
- (void)__swapCompositions:(id)fp8;
- (void)_loadAllCompositions;
- (void)_registerProtocols;
- (id)initWithOptions:(id)fp8;
- (id)compositionWithIdentifier:(NSString*)identifier;
- (id)compositionsWithProtocols:(NSArray*)protocols andAttributes:(NSDictionary*)attributes sortedBy:(id)fp16;
- (NSArray*)compositionsWithProtocols:(NSArray*)protocols andAttributes:(NSDictionary*)attributes;
- (NSArray*)allCompositions;
- (void)registerProtocol:(id)fp8 withDescription:(id)fp12;
- (NSArray*)registeredProtocols;
- (id)descriptionForProtocol:(id)fp8;
- (BOOL)doesPatch:(id)fp8 conformToProtocol:(id)fp12;
- (NSString*)description;

@end
