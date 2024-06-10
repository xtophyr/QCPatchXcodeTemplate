#import "GFGraphEditorView.h"

@interface QCPatchEditorView : GFGraphEditorView
{
	BOOL _visualDebugging;	// 104 = 0x68
	void *_unused2[4];	// 108 = 0x6c
}

+ (void)initialize;
- (Class)valueClassForBinding:(NSBindingName)binding;
- (void)dealloc;
- (void)showInspector:(id)sender;

@end

@interface QCPatchEditorView (Private)
- (void)__redrawBounds:(NSNotification*)notification;
- (void)__patchExecuted:(NSNotification*)notification;
- (void)__patchActivated:(NSNotification*)notification;
- (void)__patchStarted:(NSNotification*)notification;
- (void)setVisualizePatchExecution:(BOOL)flag;
- (BOOL)visualizePatchExecution;
@end

@interface QCPatchEditorView (Wrappers)
+ (id)drawingCache;
- (void)setPatch:(id)patch;
- (id)patch;
- (void)setPatchManager:(id)patchManager;
- (id)patchManager;
@end
