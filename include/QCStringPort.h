
#import "QCPort.h"

@interface QCStringPort : QCPort
{
	NSString *_string;
    int _editorType;    // valid values are 0 and 1, no obvious differences between the two though.
	void *_unused3[3];
}

- (NSString*)stringValue;
- (void)setStringValue:(NSString*)stringValue;

@end

@interface QCStringPort (Override)
+ (Class)baseClass;
- (id)initWithNode:(id)fp8 arguments:(id)fp12;
- (void)dealloc;
- (id)value;
- (BOOL)setValue:(id)fp8;
- (BOOL)acceptValuesOfClass:(Class)valueClass;
- (BOOL)takeValue:(id)fp8 fromPort:(id)fp12;
- (Class)valueClass;
- (id)stateValue;
- (BOOL)setStateValue:(id)fp8;
@end

@interface QCStringPort (ParameterView)
- (id)setupParameterView;
- (void)resetParameterView:(id)fp8;
- (int)editorType;
- (void)setEditorTyoe:(int)type;    // exception if type is >1
@end

@interface QCStringPort (QCProFX)
- (QCMD5Sum)md5WithTime:(double)time arguments:(id)fp16;
@end

@interface QCStringPort (Tooltip)
- (id)tooltipString;
@end

@interface QCStringPort (ValueEditing)
- (void)editValueWithEvent:(NSEvent*)event inView:(id)fp12 atPoint:(NSPoint)point;
@end
