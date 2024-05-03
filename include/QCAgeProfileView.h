

@interface QCAgeProfileView : NSView
{
	void *_unused[4];	// 80 = 0x50
}

- (NSUInteger)nameCount;            //
- (id)nameForIndex:(NSUInteger)fp8; //  these all throw an internal inconsistency exception, "Function not implemented"
- (void)setSelectedCache:(id)fp8;   //  so this is probably a pure virtual class.
- (id)selectedCache;                //
@end
