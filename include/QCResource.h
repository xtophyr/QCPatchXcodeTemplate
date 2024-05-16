


@interface QCResource : NSObject
{
	int _retainCount;	// 4 = 0x4
	void *_pool;	// 8 = 0x8
	void *_unused[4];	// 12 = 0xc
}

+ (id)allocWithZone:(NSZone *)zone;     // ensures there are only subclasses - this class cannot be instantiated directly.
- (id)copyWithZone_GCCacheResource:(NSZone *)zone;
- (id)retain;
- (oneway void)release;
- (NSUInteger)retainCount;
- (void)setResourcePool:(id)fp8;
- (id)resourcePool;
- (void)willRecycleResource:(QCCache*)cache;
- (BOOL)didRecycleResource:(QCCache*)cache;
- (NSString*)description;

@end
