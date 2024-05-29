


@class QCKeyFrameEditorWindow;

@interface QCKeyFrameEditor : NSObject
{
	NSView *view;	// 4 = 0x4
	NSTextField *tField;	// 8 = 0x8
	NSTextField *vField;	// 12 = 0xc
	QCKeyFrameEditorWindow *_window;	// 16 = 0x10
}

- (void)dealloc;
- (void)awakeFromNib;
- (BOOL)runEditorForTimeLine:(id)fp8 atKeyFrame:(NSInteger)keyFrame forTimeLine:(NSInteger)timeline controlType:(int)fp20 inView:(id)view atPoint:(NSPoint)fp28;
- (void)cancel:(id)sender;
- (void)done:(id)sender;

@end
