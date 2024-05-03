// Flags (incomplete)
// 0x1
// 0x2
// 0x4
// 0x8 -> retain (flag unset) vs copy (flag set) of values
// 0x10
// 0x20
// 0x40 -> kCFAllocator (unset) vs malloc (set)  for arrayOfKeys, for example
// 0x102 (?) is tested against sometimes to drive retain/release messages around mutations
// sometimees _flags is AND'd with 0x42, and then checked for 0x2, if it fails, inconsistent state exception
// -initWithCapacity: uses 0x16 as the default flags

@interface GFList : NSObject <NSCopying, NSFastEnumeration>
{
	NSUInteger  _flags;
	NSUInteger  _capacity;
	NSUInteger  _count;
	id          *_values;   // free'd in dealloc
	NSUInteger  *_hashValues;// free'd in dealloc
	id          *_keys;     // free'd in dealloc
    NSUInteger  *_hashKeys; // free'd in dealloc
}

+ (id)list;
- (id)init;
- (id)initWithCapacity:(NSUInteger)capacity; // capacity is initial capacity, the list resizes upward as needed.
- (id)initWithCapacity:(NSUInteger)capacity optionFlags:(NSUInteger)flags;
- (void)dealloc;
- (id)initWithList:(GFList *)list;
- (id)initWithObjects:(id)fp8 keys:(id)fp12 optionFlags:(NSUInteger)flags;
- (id)copyWithZone:(NSZone *)zone;
- (NSUInteger)optionFlags;  // same as -flags
- (NSUInteger)count;
- (NSUInteger)flags;
- (void)setObject:(id)object forKey:(id)key;
- (void)insertObject:(id)object atIndex:(NSUInteger)index forKey:(id)key;
- (void)addObject:(id)object forKey:(NSString *)key;
- (void)addEntriesFromList:(GFList*)list;
- (void)addEntriesFromDictionary:(NSDictionary*)dictionary;
- (void)removeAllObjects;
- (void)removeObject:(id)object;
- (void)removeObjectForKey:(id)key;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (id)objectForKey:(NSString *)key;
- (NSString *)keyForObject:(id)object;
- (id)objectAtIndex:(NSUInteger)index;
- (NSUInteger)indexOfObject:(id)object;		// NSNotFound if DNE
- (NSString *)keyAtIndex:(NSUInteger)index;
- (NSUInteger)indexOfKey:(NSString *)key;	// NSNotFound if DNE
- (NSString*)description;
- (NSArray*)arrayOfKeys;
- (NSArray*)arrayOfObjects;
- (NSSet*)setOfObjects;
- (NSSet*)setOfKeys;
- (NSDictionary*)dictionary;
- (void)moveIndex:(NSUInteger)sourceIndex toIndex:(NSUInteger)destIndex;
- (void)setObject:(id)object atIndex:(NSUInteger)index;
- (void)setKey:(id)fp8 atIndex:(NSUInteger)index;
- (void)setIndex:(NSUInteger)index ofObject:(id)object;
- (void)setIndex:(NSUInteger)index ofKey:(id)key;
- (void)swapIndex:(NSUInteger)indexA withIndex:(NSUInteger)indexB;
- (void)makeObjectsPerformSelector:(SEL)fp8;
- (void)makeObjectsPerformSelector:(SEL)fp8 withObject:(id)fp12;
- (void)sortUsingFunction:(void *)fp8 context:(void *)ctx;
- (void)reverse;
- (void)applyFunction:(void *)fp8 context:(void *)ctx;
- (const id *)_values;
- (const id *)_keys;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state objects:(id *)objects count:(NSUInteger)count;

@end
