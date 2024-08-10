#import "QCResource.h"

@class QCPixelFormat;

@interface QCImageBuffer : QCResource
{
	NSUInteger _identifier;	// 28 = 0x1c
	int _status;	// 32 = 0x20
	CGColorSpaceRef _colorspace;	// 36 = 0x24
	QCPixelFormat *_format;	// 40 = 0x28
	NSUInteger _width;	// 44 = 0x2c
	NSUInteger _height;	// 48 = 0x30
	BOOL _flipped;	// 52 = 0x34
	void *_backing;	// 56 = 0x38
	void (*_backingCallback)(void *backing, void *ctx);	// 60 = 0x3c
	void *_backingInfo;	// 64 = 0x40
	double _cost;	// 68 = 0x44
	NSUInteger _cacheRetainCount;	// 76 = 0x4c
	CFArrayRef _caches;	// 80 = 0x50
	pthread_mutex_t _cachesMutex;	// 84 = 0x54
	void *_unused1[4];	// 128 = 0x80
}

+ (id)allocWithZone:(NSZone *)zone;     // ensures there are only subclasses - this class cannot be instantiated directly.
+ (void)initialize;
- (id)initWithFormat:(QCPixelFormat*)format pixelsWide:(NSUInteger)width pixelsHigh:(NSUInteger)height options:(NSDictionary*)options;
- (id)copyWithZone_GCCacheResource:(NSZone *)zone;
- (void)_finalize_QCImageBuffer;
- (void)finalize;
- (void)dealloc;
- (NSUInteger)identifier;
- (int)status;
- (id)pixelFormat;
- (CGColorSpaceRef)colorSpace;
- (NSUInteger)pixelsWide;
- (NSUInteger)pixelsHigh;
- (BOOL)isFlipped;
- (BOOL)beginUpdateBuffer:(BOOL)flipped;
- (BOOL)beginUpdateBuffer:(BOOL)flipped colorSpace:(CGColorSpaceRef)colorspace;
- (void)endUpdateBuffer:(BOOL)flag;
- (void)setBacking:(void *)backing releaseCallback:(void *)backingReleaseCallback releaseInfo:(void *)backingReleaseCtx;
- (void *)backing;
- (void *)backingReleaseCallback;
- (void *)backingReleaseInfo;
- (void)willRecycleResource:(id)sender;
- (BOOL)didRecycleResource:(id)sender;
- (NSString*)description;
@end

@interface QCImageBuffer (Extensions)
- (NSRect)bounds;
- (id)pixelBufferRepresentation;
- (NSUInteger)byteSize;
- (void)setCost:(double)cost;
- (double)cost;
- (id)cacheRetain:(id)fp8;
- (void)cacheRelease:(id)fp8;
- (NSUInteger)cacheRetainCount;
- (void)removeFromAllCachesExcept:(id)fp8;
- (void)_invalidateData;
- (BOOL)writeToFile:(id)fp8;
- (void)clearBuffer;
@end
