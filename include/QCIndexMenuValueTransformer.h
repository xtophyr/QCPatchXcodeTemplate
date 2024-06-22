// This transformer is used for QCIndexPort inspectors, transforming the popup menu items to selected indices.
// it handles @"-" entries as separators, adjusting the index value to accomodate them.

@interface QCIndexMenuValueTransformer : NSValueTransformer
{
	NSArray *_items;	// 4 = 0x4
}

+ (Class)transformedValueClass;
+ (BOOL)allowsReverseTransformation;
+ (instancetype)transformerWithItems:(NSArray<NSString*>*)items;
- (id)initWithItems:(NSArray<NSString*>*)items;
- (void)dealloc;
- (NSNumber*)transformedValue:(NSNumber*)value;
- (NSNumber*)reverseTransformedValue:(NSNumber*)value;
@end
