// TODO: some stuff was added here in 10.6 -- guard it out

@interface QCContext : NSObject
{
	QCIterationManager *_iterationManager;
	NSMutableDictionary *_optimizedRendering;   // this is initialized to a GFList (!) and treated as such (fooForKey: methods sent)
	NSDictionary *_options;
	NSMutableDictionary *_userInfo;
	CFSetRef _renderingPatches;
	id _proExtension;       // QCContextProExtension
	void *_unused[1];
}

+ (void)initialize;
+ (Class)renderStateClass;
- (void)_drawDirtyRectForPatch:(QCPatch*)patch;
- (id)init;
- (id)initWithOptions:(NSDictionary*)options;
- (void)finalize;
- (void)dealloc;
- (NSDictionary*)options;
- (NSMutableDictionary*)userInfo;
- (BOOL)startRenderingPatch:(QCPatch*)patch options:(id)options;
- (void)pauseRenderingPatch:(QCPatch*)patch;
- (double)nextExecutionTimeForPatch:(QCPatch*)patch time:(double)time arguments:(NSDictionary*)args;
- (BOOL)renderPatch:(QCPatch*)patch time:(double)time arguments:(NSDictionary*)args;
- (void)resumeRenderingPatch:(QCPatch*)patch;
- (void)stopRenderingPatch:(QCPatch*)patch;
- (NSArray*)renderingPatches;
- (BOOL)willPushRenderState:(id)unused;
- (void)didPushRenderState:(id)unused;
- (void)willPopRenderState:(id)unused;
- (void)didPopRenderState:(id)unused;
- (void)sendRenderState:(QCRenderState*)state didChangeMessage:(NSString*)message withAttributes:(id)attributes;
- (NSString*)description;
- (BOOL)prerenderPatch:(QCPatch*)patch time:(double)time imageSizeHint:(NSSize)sizeHint arguments:(NSDictionary*)arguments;

@end

@interface QCContext (QCProFX)
- (double)scaleValue:(double)value;
- (void)setScale:(double)scale;
@end
