
@class GFList;

@interface GFNodeClassDescription : NSObject
{
	Class _class;	// 4 = 0x4
	pthread_mutex_t _mutex;	// 8 = 0x8  // this appears to only lock in -_initializeAttributes, isn't free'd in -dealloc
	GFList *_inputs;	// 52 = 0x34
	GFList *_outputs;	// 56 = 0x38
	BOOL _attributesInitialized;	// 60 = 0x3c
	NSMutableDictionary *_attributes;	// 64 = 0x40
	NSMutableDictionary *_identifierAttributes;	// 68 = 0x44
	NSMutableDictionary *_userInfo;	// 72 = 0x48    // unused (not even -release'd in dealloc)
}

- (id)initWithNodeClass:(Class)cls;
- (Class)nodeClass;
- (void)_initializeAttributes;
- (id)xmlAttributes;
- (id)xmlAttributesForNodeIdentifier:(NSString*)identifier;
- (id)attributesForNodeIdentifier:(NSString*)identifier;
- (id)attributesForInputPort:(id)fp8 nodeIdentifier:(NSString*)identifier;
- (id)attributesForOutputPort:(id)fp8 nodeIdentifier:(NSString*)identifier;
- (GFList*)ivarInputPorts;  // returns raw pointer to _inputs
- (GFList*)ivarOutputPorts; // returns raw pointer to _outputs
- (void)dealloc;
@end
