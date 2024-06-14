#import "GFConnection.h"

@interface QCLink : GFConnection
{
	id _proExtension;   // unused (references QCLinkExtensionClass, which is never written)
	void *_unused2[3];
}

+ (BOOL)accessInstanceVariablesDirectly;
+ (BOOL)automaticallyNotifiesObserversForKey:(NSString*)key;
- (id)sourcePatch;
- (id)destinationPatch;
- (id)parentPatch;
@end

@interface QCLink (Override)
- (id)initWithGraph:(GFGraph*)graph sourcePort:(QCPort*)sourcePort destinationPort:(QCPort*)destPort arguments:(NSDictionary*)args;
- (void)dealloc;
- (void)connectionWillDeleteFromGraph;
@end
