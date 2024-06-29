// _region is a quite likely a CGSRegionRef, a scanline-coherent shape object based on "Scanline Coherent Shape Algebra"
// used mainly in CoreGraphics framework and in the WindowServer/SkyLight.  It's a CF Object.  All SPI there.

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
- (CGRect)CGRect;
- (id)initWithCGSRegion:(void *)cgsRegion;
- (void *)CGSRegion;
- (id)initWithRect:(NSRect)rect;
- (NSRect)bounds;
- (BOOL)isEmpty;
- (BOOL)isInfinite;
- (BOOL)isRectangular;
- (BOOL)containsPoint:(NSPoint)point;
- (BOOL)containsRect:(NSRect)rect;
- (BOOL)containsRegion:(id)region;
- (BOOL)intersectsRect:(NSRect)rect;
- (BOOL)intersectsRegion:(id)region;
- (id)listRects;
- (id)pixelBufferRepresentation;
- (void *)enumerateRects:(void *)fp8 outRect:(NSRect *)fp12;
- (id)transformWith:(CGAffineTransform *)tranform;
- (id)transformBy:(id)fp8;
- (id)offsetByX:(CGFloat)dx Y:(CGFloat)dy;
- (id)scaleByX:(CGFloat)sx Y:(CGFloat)sy;
- (id)rotateByDegrees:(CGFloat)degrees;
- (id)insetByX:(CGFloat)x Y:(CGFloat)y;
- (id)unionWithRect:(NSRect)rect;
- (id)intersectWithRect:(NSRect)rect;
- (id)subtractRect:(NSRect)rect;
- (id)unionWithRegion:(id)region;
- (id)intersectWithRegion:(id)region;
- (id)subtractRegion:(id)region;
- (NSString*)description;
@end

@interface QCRegion (CIFilterShape)
+ (id)regionWithCIFilterShape:(id)filterShape;
- (id)initWithCIFilterShape:(id)filterShape;
- (id)CIFilterShape;
@end
