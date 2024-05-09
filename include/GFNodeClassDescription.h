
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
- (void)_initializeAttributes;  // by default, attributes aren't loaded/initialized.  This drives the loading/initialization.

// the "xml" here refers to the xml files in /S/L/F/Quartz.framework/Frameworks/QuartzComposer.framework/Versions/A/Resources/*.xml
- (NSDictionary*)xmlAttributes; // similar to the dict seen higher up in -[QCPatch patchAttributesWithName:]? (maybe filtered by then)
// historical note:  these used to be real text-based xml files.  This was changed (around 10.7?) to be a binary plist to save loading time and disk space, but the file extension didn't change.

- (id)xmlAttributesForNodeIdentifier:(NSString*)identifier;
- (id)attributesForNodeIdentifier:(NSString*)identifier;
- (id)attributesForInputPort:(NSString*)port nodeIdentifier:(NSString*)identifier;
- (id)attributesForOutputPort:(NSString*)port nodeIdentifier:(NSString*)identifier;
- (GFList*)ivarInputPorts;  // returns raw pointer to _inputs
- (GFList*)ivarOutputPorts; // returns raw pointer to _outputs
- (void)dealloc;
@end
