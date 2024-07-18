@class QCPatch, QCRenderingPatch;

@interface QCInteractionManager : NSObject
{
	QCContactInfo _contacts[64];
	CGFloat _rotation;
	CGFloat _rotationOffset;
	CGFloat _scaleX;
	CGFloat _scaleOffsetX;
	CGFloat _scaleY;
	CGFloat _scaleOffsetY;
	CGPoint _translation;
	CGPoint _translationOffs
	CGPoint _origin;
	NSUInteger _activeContactCount;
	NSUInteger _maxActiveContacts;
	NSUInteger _flags;
	NSUInteger _timestamp;
	NSUInteger _previousTimestamp;
	BOOL _updated;
    BOOL _exposeScale;
	BOOL _exposeRotation;
	BOOL _allowNonUniformScaling;
	struct _QCDod *_roi;
	CGAffineTransform _transform;
	QCRenderingPatch *_renderingPatch;
	QCPatch *_parent;
	void *_unused[6];
}
@property (readonly,assign) BOOL translating;
@property (readonly,assign) BOOL scaling;
@property (readonly,assign) BOOL rotating;
@property (readonly,assign) NSArray *activeContacts;
@property (readonly,assign) CGFloat renderingDepth;
@property (readonly,assign) NSUInteger activeContactCount;
@property (readwrite,assign) BOOL allowNonUniformScaling;
@property (readwrite,assign) BOOL exposeRotation;
@property (readwrite,assign) BOOL exposeScale;
@property (readonly,assign) BOOL updated;
@property (readonly,assign) CGAffineTransform transform;
@property (readonly,assign) CGFloat scaleY;
@property (readonly,assign) CGFloat scaleX;
@property (readonly,assign) CGFloat rotation;
@property (readonly,assign) CGPoint origin;
@property (readonly,assign) CGPoint translation;

+ (NSUInteger)maxActiveContacts;
- (void)reset;
- (void)setRenderingPatch:(id)fp8;
- (id)init;
- (id)initWithParentPatch:(id)fp8;
- (void)_computeAffineTransform;
- (BOOL)hitTest:(CGPoint)fp8;
- (void)setContactX:(CGFloat)fp8 Y:(CGFloat)fp12 state:(int)fp16 forIndex:(NSUInteger)fp20;
- (void)setContactOffsetX:(CGFloat)fp8 Y:(CGFloat)fp12;
- (void)addDeltaContactX:(CGFloat)fp8 Y:(CGFloat)fp12 forIndex:(NSUInteger)fp16;
- (void)setScaleX:(CGFloat)fp8 Y:(CGFloat)fp12 state:(int)fp16;
- (void)setScaleOffsetX:(CGFloat)fp8 Y:(CGFloat)fp12;
- (void)addDeltaScale:(CGFloat)fp8;
- (void)setRotation:(CGFloat)fp8 state:(int)fp12;
- (void)setRotationOffset:(CGFloat)fp8;
- (void)addDeltaRotation:(CGFloat)fp8;
- (CGPoint)contactForIndex:(NSUInteger)fp8;
- (BOOL)translating;
- (BOOL)scaling;
- (BOOL)rotating;
- (CGPoint)translation;
- (CGFloat)scaleX;
- (CGFloat)scaleY;
- (CGFloat)rotation;
- (CGPoint)origin;
- (CGAffineTransform)transform;
- (CGFloat)renderingDepth;
- (NSArray*)activeContacts;
- (void)setExposeRotation:(BOOL)fp8;
- (NSUInteger)activeContactCount;
- (BOOL)allowNonUniformScaling;
- (void)setAllowNonUniformScaling:(BOOL)fp8;
- (BOOL)exposeRotation;
- (BOOL)exposeScale;
- (void)setExposeScale:(BOOL)fp8;
- (BOOL)updated;
@end

@interface QCInteractionManager (Private)
- (BOOL)_selected;
- (BOOL)_updated;
@end
