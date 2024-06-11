
#import "GFPort.h"

@class QCProxyPort, QCPatch;

@interface QCPort : GFPort
{
	Class _baseClass;
	QCPort *_connectedPort;
	QCProxyPort *_proxyPort;
	NSUInteger _timestamp;
	NSUInteger _previousTimestamp;
	NSUInteger _iteration;
	NSUInteger _previousIteration;
    BOOL _updated;
	NSString *_keyCache;
	int _direction;
	NSUInteger _connectedPortTimestamp;
	NSUInteger _kindAndUnits;   // bottom 16 bits are units, "top" 16 bits are kind, both populated by args["attributes"]["kind" | "units"] in -init.
                                // these are exposed through -kind and -units, which are apparently only used in QCProFX stuff?
	void *_observationInfo;
	id _proExtension;
	void *_unused2[2];
}

+ (id)allocWithZone:(NSZone *)zone; // ensures there are only subclasses - this class cannot be instantiated directly.
+ (BOOL)accessInstanceVariablesDirectly;
+ (BOOL)automaticallyNotifiesObserversForKey:(NSString*)key;
+ (Class)baseClass;     // NSInternalInconsistencyException : Function not implemented
- (id)initWithNode:(id)fp8 arguments:(NSDictionary*)args;
- (void)dealloc;
- (int)kind;    // bits 16 - 31 of _kindAndUnits
- (int)units;   // bits  0 - 15 of _kindAndUnits
- (void)_clearCachedKey;
- (NSString *)key;
- (void)portWillDeleteFromNode;
- (id)value;                // NSInternalInconsistencyException : Function not implemented
- (BOOL)setValue:(id)fp8;   // NSInternalInconsistencyException : Function not implemented
- (BOOL)acceptValuesOfClass:(Class)fp8; // NSInternalInconsistencyException : Function not implemented
- (Class)valueClass;        // NSInternalInconsistencyException : Function not implemented
- (BOOL)canConnectToPort:(id)fp8;
- (BOOL)takeValue:(id)fp8 fromPort:(id)fp12;
- (QCPatch *)parentPatch;
- (BOOL)wasUpdated;
- (NSUInteger)_timestamp;
- (void)willChangeValue;
- (void)didChangeValue;
- (id)stateValue;               // NSInternalInconsistencyException : Function not implemented
- (BOOL)setStateValue:(id)fp8;  // NSInternalInconsistencyException : Function not implemented
- (NSDictionary*)state;
- (BOOL)setState:(NSDictionary*)state;
- (BOOL)_execute:(double)time arguments:(NSDictionary*)args;
- (void)_resetUpdate;
- (id)proxyPort;
- (void)_setProxyPort:(QCPort *)port;
- (id)connectedPort;
- (void)_setConnectedPort:(QCPort *)port;
- (void)_setDirection:(int)fp8;
- (int)direction;
- (Class)baseClass;
- (void)_setBaseClass:(Class)fp8;
- (NSString*)description;
- (id)valueForKey:(id)fp8;
- (void)setValue:(id)fp8 forKey:(id)fp12;
- (void)addObserver:(id)fp8 forKeyPath:(id)fp12 options:(NSUInteger)fp16 context:(void *)fp20;
- (void)removeObserver:(id)fp8 forKeyPath:(id)fp12;
- (void)setObservationInfo:(void *)fp8;
- (void *)observationInfo;
- (id)_argumentsFromAttributesKey:(id)fp8 originalArguments:(id)fp12;

@end

@interface QCPort (ParameterView)
- (id)setupParameterView;
- (void)resetParameterView:(id)fp8; // NSInternalInconsistencyException : Function not implemented
@end

@interface QCPort (QCPortView)
- (void)drawPortView:(id)fp8;       // NSInternalInconsistencyException : Function not implemented
@end

@interface QCPort (QCProFX)
+ (id)findOriginalPort:(id)fp8;
- (id)getConnectedOriginalPort;
- (QCMD5Sum)md5WithTime:(double)time arguments:(id)fp16;
@end

@interface QCPort (TooltipExtensionView)
- (id)tooltipExtensionView;
- (NSSize)tooltipExtensionViewSize:(id)fp8; // NSInternalInconsistencyException : Function not implemented
- (id)tooltipString;
- (id)setupTooltipView;
- (void)resetTooltipView;
@end

@interface QCPort (ValueEditing)
- (void)editValueWithEvent:(id)fp8 inView:(id)fp12 atPoint:(NSPoint)fp16;
@end
