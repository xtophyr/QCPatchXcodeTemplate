@interface QCStreamProvider : NSObject <QCStreamProvider>
{
	NSUInteger _identifier;	// 4 = 0x4
	NSUInteger _defaultWidth;	// 8 = 0x8
	NSUInteger _defaultHeight;	// 12 = 0xc
	NSUInteger _defaultDepth;	// 16 = 0x10
	void *_unused[4];	// 20 = 0x14
}
@property (readonly,assign) BOOL supportsConversion;
@property (readonly,assign) int type;
@property (readonly,assign) QCPixelFormat *pixelFormat;
@property (readonly,assign) NSUInteger pixelsDeep;
@property (readonly,assign) NSUInteger pixelsHigh;
@property (readonly,assign) NSUInteger pixelsWide;
@property (readonly,assign) NSUInteger elementSize;
@property (readonly,assign) NSUInteger count;

+ (BOOL)isCompatibleWithSource:(id)fp8 sourceMD5:(QCMD5Sum *)fp12;  // NSInternalInconsistencyException : Function not implemented
+ (id)createProviderWithSource:(id)fp8 options:(id)fp12;    // NSInternalInconsistencyException : Function not implemented
- (id)init;
- (QCMD5Sum)providerMD5;
- (NSUInteger)count;        // NSInternalInconsistencyException : Function not implemented
- (NSUInteger)elementSize;  // NSInternalInconsistencyException : Function not implemented
- (int)type;                // NSInternalInconsistencyException : Function not implemented
- (void)_setDefaultWidth:(NSUInteger)fp8;
- (void)_setDefaultHeight:(NSUInteger)fp8;
- (void)_setDefaultDepth:(NSUInteger)fp8;
- (NSUInteger)pixelsWide;
- (NSUInteger)pixelsHigh;
- (NSUInteger)pixelsDeep;
- (QCPixelFormat*)pixelFormat;  // NSInternalInconsistencyException : Function not implemented
- (BOOL)supportsConversion;
- (id)sourceRepresentationType;
- (id)sourceRepresentation;
- (id)createArrayMemObjectForManager:(id)fp8 withCount:(NSUInteger)fp12 elementSize:(NSUInteger)fp16 type:(int)fp20 options:(id)fp24;
- (id)createImage2DMemObjectForManager:(id)fp8 withFormat:(id)fp12 options:(id)fp16;
- (NSString*)description;

@end
