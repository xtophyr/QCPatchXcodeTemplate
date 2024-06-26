// Flags (incomplete)
// 0x1 -> objects are unique (no dups) -- send -release to key (removeObjectAtIndex:, removeAllObjects).  also sends retain/release to object (the argument!) in removeObject: (keep alive?) --- oh, in insertObject:atIndex:forKey: we get some exception messages to verify uniqueness.
// 0x2 - keys are unique (insertObject:atIndex:forKey: has an exception to verify this)
// 0x4
// 0x8 -> retain (flag unset) object vs copy object (flag set) of values
// 0x10 -> hash _keys array ("speeds up" indexOfKey:)
// 0x20 -> hash _values array ("speeds up" indexOfObject:)
// 0x40 -> kCFAllocator (unset) vs malloc (set)  for arrayOfKeys, for example
// 0x102 (?) is tested against sometimes to drive retain/release messages around mutations
// sometimees _flags is AND'd with 0x42, and then checked for 0x2, if it fails, inconsistent state exception
// -initWithCapacity: uses 0x16 as the default flags
//
// empirical flag notes:
// keys are retained when _flags & 0x4 is set, or when _flags & 0x100 is not set (insertObject:atIndex:forKey:)
// removeObjectForKey: tests _flags against 0x102, and retains key before mutation if non-zero, then releases key.  if _flags & 2 is set, it bails out after a match (so maybe 0x2 means unique keys?)
// indexOfKey: also tests _flags against 0x40, and won't search if it's not set.
// setObject:atIndex: tests if byte -1 (0xff) is less than flags, will throw an exception if null is passed in.
// setKey:atIndex: tests against 0x40, exception if key is null.


@interface GFList : NSObject <NSCopying, NSFastEnumeration>
{
	NSUInteger  _flags;
	NSUInteger  _capacity;  // _capacity has a minimum of 8 - ask for less and you get bumped up to 8 anyway.  grows in increments of 8 too.
	NSUInteger  _count;
	id          *_values;   // free'd in dealloc
	NSUInteger  *_hashValues;// free'd in dealloc
	id          *_keys;     // free'd in dealloc
    NSUInteger  *_hashKeys; // free'd in dealloc
}

+ (id)list;
- (id)init;
- (id)initWithCapacity:(NSUInteger)capacity; // capacity is initial capacity, the list resizes upward as needed.
- (id)initWithCapacity:(NSUInteger)capacity optionFlags:(NSUInteger)flags NS_DESIGNATED_INITIALIZER;
- (void)dealloc;
- (id)initWithList:(GFList *)list;
- (id)initWithObjects:(NSArray*)objects keys:(NSArray*)keys optionFlags:(NSUInteger)flags;
- (id)copyWithZone:(NSZone *)zone;
- (NSUInteger)optionFlags;  // same as -flags
- (NSUInteger)count;
- (NSUInteger)flags;
- (void)setObject:(id)object forKey:(id)key;    // inserts object/key if key isn't found, removes key if object is null
- (void)insertObject:(id)object atIndex:(NSUInteger)index forKey:(id)key;
- (void)addObject:(id)object forKey:(NSString *)key;    // insertObject:object atIndex:_count forKey:key
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
- (void)setKey:(id)key atIndex:(NSUInteger)index;
- (void)setIndex:(NSUInteger)index ofObject:(id)object;
- (void)setIndex:(NSUInteger)index ofKey:(id)key;
- (void)swapIndex:(NSUInteger)indexA withIndex:(NSUInteger)indexB;
- (void)makeObjectsPerformSelector:(SEL)selector;
- (void)makeObjectsPerformSelector:(SEL)selector withObject:(id)object;

// these sort using a home-rolled quicksort implementation (_QuickSort and _QuickSort_b).  Both flavors drive swapIndex:withIndex:
// It's home-rolled so it can drive -swapIndex:withIndex: so that the 4 arrays (keys, values, hashes) stay correlated.
- (void)sortUsingFunction:(NSComparisonResult (*)(id valueL, id keyL, id valueR, id keyR, void *ctx))compare context:(void *)ctx; // this might be unused now in favor of the block variant below
- (void)sortUsingComparator:(NSComparisonResult(^)(id valueL, id keyL, id valueR, id keyR))compare; // added some time after SSDK was dumped

- (void)reverse;

// applier function takes (value, key, context), returns void, no method to terminate enumeration early
- (void)applyFunction:(void(*)(id obj, id key, void *ctx))applierFunc context:(void *)ctx;
- (const id *)_values;
- (const id *)_keys;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state objects:(id *)objects count:(NSUInteger)count;

// follows standard NSEnumerationOptions semantics - concurrent, forward, reverse
// if there are fewer than 32 items in the list, concurrent enumeration is silently downgraded serial
// TODO: figure out the block signature (probably returns void, takes key and object)
- (void)enumerateKeysAndObjectsWithOptions:(NSEnumerationOptions)options usingBlock:(void(^)(id key, id obj, BOOL *stop))block; // added since SSDK was dumped
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)options usingBlock:(void(^)(id obj, size_t iteration, BOOL *stop))block;; // added since the SSDK was dumped
@end
