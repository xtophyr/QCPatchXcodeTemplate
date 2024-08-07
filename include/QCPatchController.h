
@class QCPatch;

typedef struct _QCPatchControllerPrivate {
    QCPatch *patch;
} QCPatchControllerPrivate;

@interface QCPatchController : NSController
{
    void *_QCPatchControllerPrivate;
}

+ (BOOL)accessInstanceVariablesDirectly;
+ (BOOL)automaticallyNotifiesObserversForKey:(NSString*)key;

- (void)encodeWithCoder:(NSCoder *)aCoder;
- (id)initWithCoder:(NSCoder *)aDecoder;
- (id)init;
- (void)dealloc;

- (void)setPatch:(id)fp8;
- (id)patch;
- (void)_real_willChangeValueForKey:(NSString*)key;
- (void)_real_didChangeValueForKey:(NSString*)key;

@end
