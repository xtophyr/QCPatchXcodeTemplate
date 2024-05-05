
// Under the covers this uses an NSMutableDictionary to pair GFNodeClassDescriptions (values) with Classes (keys)
// it is _not_ thread safe, there are no attempts made at synchronization.
// +registerClassDescription is invoked for essentially every QCPatch class (subclasses included)
@interface GFNodeClassDescriptionRegistry : NSObject

+ (GFNodeClassDescription*)classDescriptionForClass:(Class)cls;
+ (void)registerClassDescription:(GFNodeClassDescription*)classDescription forClass:(Class)cls;

@end
