@interface QCMathematicalExpression : NSObject
{
    // this uses a C++-based evaluator, with Parser:: and FunctionInterpreter:: being some namespaces that crop up.
	void *_interpreter;	// 4 = 0x4
}

+ (double)evaluateString:(NSString *)expression;

- (id)init;
- (id)initWithString:(NSString *)expression error:(const NSString **)error;
- (void)finalize;
- (void)dealloc;

- (NSArray *)variables;	// array of NSStrings
- (void)setVariable:(double)value atIndex:(NSUInteger)index;
- (double)variableAtIndex:(NSUInteger)index;

- (double)evaluate;
@end
