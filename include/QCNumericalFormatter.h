
// Used in inspectors for QCNumberPorts

@interface QCNumericalFormatter : NSFormatter
{
	BOOL _allowsFloats;
	double _min;
	double _max;
}

- (id)init;
- (void)setAllowsFloats:(BOOL)flag;
- (BOOL)allowsFloats;
- (double)minimum;
- (void)setMinimum:(double)minimum;
- (double)maximum;
- (void)setMaximum:(double)maximum;
- (BOOL)getObjectValue:(id *)value forString:(NSString*)string errorDescription:(id *)error;
- (id)stringForObjectValue:(id)value;

@end
