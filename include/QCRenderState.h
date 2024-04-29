


@class QCContext, QCPatch;

@interface QCRenderState : NSObject
{
	QCPatch *_patch;	// 4 = 0x4
	QCContext *_context;	// 8 = 0x8
	void *_unused[4];	// 12 = 0xc
}

- (id)initWithContext:(QCContext* _Nonnull)context patch:(QCPatch*_Nonnull)patch;
- (void)dealloc;
- (QCPatch*)patch;
- (QCContext*)context;

@end
