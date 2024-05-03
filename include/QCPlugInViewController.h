@interface QCPlugInViewController : NSViewController
{
	void *_private;	// might be unused
}

- (id)initWithPlugIn:(id)plugin viewNibName:(NSString*)nibName;
- (id)plugIn;
- (id)initWithNibName:(NSString*)nibName bundle:(NSBundle*)bundle; // NSInternalInconsistencyException : "Function not implemented"
- (NSString*)description;
@end
