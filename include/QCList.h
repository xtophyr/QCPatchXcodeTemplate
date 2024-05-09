#import "GFList.h"

// QCList is semantically identical to GFList, with KVO additions (-willChangeValueForKey:/-didChangeValueForKey: messages around mutations)

@interface QCList : GFList
+ (BOOL)accessInstanceVariablesDirectly;            // NO
+ (BOOL)automaticallyNotifiesObserversForKey:(id)key;   // NO
- (void)setObject:(id)object forKey:(NSString*)key;
- (void)insertObject:(id)object atIndex:(NSUInteger)index forKey:(NSString*)key;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)removeAllObjects;
- (id)valueForKey:(NSString*)key;
- (void)setObject:(NSString*)key atIndex:(NSUInteger)index;
- (void)setKey:(NSString*)key atIndex:(NSUInteger)index;
@end
