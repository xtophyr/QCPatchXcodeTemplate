
#import "QCPortView.h"

@class QCCGLContext;

@interface QCPortGLView : QCPortView
{
	QCCGLContext *_cglContext;
	NSOpenGLContext *_glContext;
}

- (void)_startRendering:(NSNotification*)notification;
- (void)_stopRendering:(NSNotification*)notification;
- (id)initWithPort:(QCPort*)port;
- (void)finalize;
- (void)dealloc;
- (void)lockFocus;
- (void)drawRect:(NSRect)rect;
- (void)setHidden:(BOOL)flag;
- (id)cglContext;
- (BOOL)wantsBestResolutionOpenGLSurface;

@end
