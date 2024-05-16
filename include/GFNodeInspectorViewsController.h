
// GFNodeInspectorViewsController is used behind the scenes in GFNodeActor.
// its UI elements are backed by GFNodeActorInspectorViews.nib

@class GFNode;

@interface GFNodeInspectorViewsController : NSObject
{
	NSView *_informationView;	// 4 = 0x4
	NSTextField *_titleField;	// 8 = 0x8
	NSTextField *_noteField;	// 12 = 0xc
	NSTextField *_nameField;	// 16 = 0x10
	NSTextField *_descriptionField;	// 20 = 0x14
	GFNode *_targetNode;	// 24 = 0x18
}

+ (id)sharedController;
- (id)init;
- (void)resetTitle:(id)sender;
- (void)titleEdited:(id)sender;
- (void)noteEdited:(id)sender;
- (void)__stateUpdated:(id)sender;
- (id)setupViewsForNode:(id)node;
- (void)resetInspectorViews;

@end
