@interface QCBillboard : QCRenderingPatch
{
	QCOpenGLPort_Image *inputImage;	// 176 = 0xb0
	QCOpenGLPort_Image *inputMask;	// 180 = 0xb4
	QCNumberPort *inputX;	// 184 = 0xb8
	QCNumberPort *inputY;	// 188 = 0xbc
	QCNumberPort *inputRotation;	// 192 = 0xc0
	QCOpenGLPort_Color *inputColor;	// 196 = 0xc4
	QCOpenGLPort_Blending *inputBlending;	// 200 = 0xc8
	QCBooleanPort *inputPixelAligned;	// 204 = 0xcc
	BOOL _directCIRendering;	// 208 = 0xd0
	BOOL _optimizedCropping;	// 209 = 0xd1
	int _sizeMode;	// 212 = 0xd4
	QCNumberPort *_widthPort;	// 216 = 0xd8
	QCNumberPort *_heightPort;	// 220 = 0xdc
	CIImage *_ciImage;	// 224 = 0xe0
	CIFilter *_colorFilter;	// 228 = 0xe4
	CIFilter *_maskFilter;	// 232 = 0xe8
}

+ (BOOL)isSafe;
+ (NSUInteger)stateVersionWithIdentifier:(NSString*)identifier;
+ (QCPatchExecutionMode)executionModeWithIdentifier:(NSString*)identifier;
+ (BOOL)allowsSubpatchesWithIdentifier:(NSString*)identifier;
+ (BOOL)allowsInteraction;
+ (id)stateKeysWithIdentifier:(NSString*)identifier;
+ (id)serializedStateKeysWithIdentifier:(NSString*)identifier;
- (id)initWithIdentifier:(NSString*)identifier;
- (void)receiveMessage:(id)fp8 name:(id)fp12 attributes:(id)fp16;
- (BOOL)setup:(QCOpenGLContext *)context;
- (BOOL)automaticStateSet:(id)fp8;
- (BOOL)allowsScissors:(id)fp8;
- (struct _QCDod *)createDodForContext:(id)fp8;
- (CGPoint)position;
- (void)setPosition:(CGPoint)position;
- (CGFloat)rotation;
- (void)setRotation:(CGFloat)rotation;
- (CGFloat)scaleX;
- (CGFloat)scaleY;
- (void)setScaleX:(CGFloat)scaleX;
- (void)setScaleY:(CGFloat)scaleY;
- (BOOL)execute:(QCOpenGLContext*)context time:(double)time arguments:(NSDictionary*)args;
- (void)cleanup:(QCOpenGLContext *)context;
- (void)setSizeMode:(int)sizeMode;
- (int)sizeMode;
- (NSDictionary*)state;
- (BOOL)setState:(NSDictionary*)state;
@end

@interface QCBillboard (QCInspector)
+ (Class)inspectorClassWithIdentifier:(NSString*)identifier;
@end
