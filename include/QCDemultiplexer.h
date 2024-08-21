@interface QCDemultiplexer : QCPatch
{
	QCIndexPort *inputIndex;
	NSMutableArray *_outPorts;
	QCPort *_inPort;
	QCPort *_resetPort;
}

+ (BOOL)allowsSubpatchesWithIdentifier:(id)identifier;
+ (id)stateKeysWithIdentifier:(id)identifier;
+ (id)serializedStateKeysWithIdentifier:(id)identifier;
+ (BOOL)isSafe;
- (id)initWithIdentifier:(id)identifier;
- (NSUInteger)outputCount;
- (void)setOutputCount:(NSUInteger)count;
- (Class)portClass;
- (void)setPortClass:(Class)cls;
- (void)setResetOutputs:(BOOL)flag;
- (BOOL)resetOutputs;
- (void)dealloc;
- (NSDictionary*)state;
- (BOOL)setState:(NSDictionary*)state;
- (BOOL)execute:(QCOpenGLContext*)context time:(double)time arguments:(NSDictionary*)args;

@end

@interface QCDemultiplexer (QCInspector)
+ (Class)inspectorClassWithIdentifier:(id)identifier;
@end
