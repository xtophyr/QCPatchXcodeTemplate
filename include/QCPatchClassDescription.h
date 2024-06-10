
#import "GFNodeClassDescription.h"

@interface QCPatchClassDescription : GFNodeClassDescription
{
	CFArrayRef _stateKeysCache;	// 76 = 0x4c
	CFDictionaryRef _stateKeysCaches;	// 80 = 0x50
}

- (id)stateKeysForIdentifier:(NSString*)identifier;
- (void)dealloc;

@end
