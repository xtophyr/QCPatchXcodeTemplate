// _region is a quite likely a CGSRegionRef, a scanline-coherent shape object based on "Scanline Coherent Shape Algebra"
// used mainly in CoreGraphics framework and in the WindowServer/SkyLight.  It's a CF Object.  All SPI there.

// infinite and empty regions are global singletons.
// It looks like _region is set to point to self for infinite, and points to _bounds for empty, as a sort of sentinel.

@interface QCRegion : NSObject
{
	CGRect _bounds;	// 4 = 0x4
	void *_region;	// 20 = 0x14
	void *_unused[4];	// 24 = 0x18
}

+ (void)initialize;
+ (id)emptyRegion;
+ (id)infiniteRegion;
+ (id)regionWithCGRect:(CGRect)rect;
+ (id)regionWithCGSRegion:(void *)cgsRegion;
+ (id)regionWithRect:(NSRect)rect;
- (void)finalize;
- (void)dealloc;
- (id)initWithCGRect:(CGRect)rect;
- (CGRect)CGRect;   // returns CGNullRect for empty rect
- (id)initWithCGSRegion:(void *)cgsRegion;
- (void *)CGSRegion;
- (id)initWithRect:(NSRect)rect;
- (NSRect)bounds;   // bounds is like -CGRect, but will throw for infiniteRegion (rather than returning CGRectInfinite like -CGRect does), and NSZeroRect for empty (not CGNullRect)
- (BOOL)isEmpty;
- (BOOL)isInfinite;
- (BOOL)isRectangular;
- (BOOL)containsPoint:(NSPoint)point;
- (BOOL)containsRect:(NSRect)rect;
- (BOOL)containsRegion:(QCRegion*)region;
- (BOOL)intersectsRect:(NSRect)rect;
- (BOOL)intersectsRegion:(QCRegion*)region;
- (NSString*)listRects;
- (id)pixelBufferRepresentation;

/* to use the enumerator, send in NULL for enumerator, and it'll return a pointer to feed in to subsequent calls, one for each rect. */
/*
        void *enumerator = [region enumerateRects:NULL outRect:&rect];
        if (enumerator)
            do {
                // do something with rect
                enumerator = [region enumerateRects:enumerator outRect:&rect];  // get next rect
            } while (enumerator);
 */
- (void *)enumerateRects:(void *)enumerator outRect:(NSRect *)outRect;

- (id)transformWith:(CGAffineTransform *)tranform;
- (id)transformBy:(NSAffineTransform*)transform;
- (id)offsetByX:(CGFloat)dx Y:(CGFloat)dy;
- (id)scaleByX:(CGFloat)sx Y:(CGFloat)sy;
- (id)rotateByDegrees:(CGFloat)degrees;
- (id)insetByX:(CGFloat)x Y:(CGFloat)y;
- (id)unionWithRect:(NSRect)rect;
- (id)intersectWithRect:(NSRect)rect;
- (id)subtractRect:(NSRect)rect;
- (id)unionWithRegion:(QCRegion*)region;
- (id)intersectWithRegion:(QCRegion*)region;
- (id)subtractRegion:(QCRegion*)region;
- (NSString*)description;
@end

@interface QCRegion (CIFilterShape)
+ (id)regionWithCIFilterShape:(id)filterShape;
- (id)initWithCIFilterShape:(id)filterShape;
- (id)CIFilterShape;
@end
