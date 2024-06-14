


@class QCContext, QCPatch;

// This is a lightweight base class that associates a context with a root patch of a composition for rendering.
// init will throw an exception if either context or patch are nil.  context is retained, patch is not.
// In normal usage, this is driven as the superclass of QCOpenGLRenderState and QCGraphicsRenderState.

@interface QCRenderState : NSObject
{
	QCPatch *_patch;
	QCContext *_context;
	void *_unused[4];
}

- (id)initWithContext:(QCContext* _Nonnull)context patch:(QCPatch*_Nonnull)patch;
- (void)dealloc;
- (QCPatch*)patch;
- (QCContext*)context;

@end
