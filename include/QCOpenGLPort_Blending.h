#import "QCIndexPort.h"

@interface QCOpenGLPort_Blending : QCIndexPort <QCOpenGLPort>
{
	unsigned char _enabled;	// 128 = 0x80
	unsigned char _testingEnabled;	// 129 = 0x81
	GLint _sourceFunction;	// 132 = 0x84
	GLint _destFunction;	// 136 = 0x88
	GLint _alphaFunc;	// 140 = 0x8c
	CGFloat _alphaRef;	// 144 = 0x90
	void *_unused4[1];	// 148 = 0x94
}

- (id)initWithNode:(GFNode*)node arguments:(NSDictionary*)args;
- (void)setOnOpenGLContext:(QCOpenGLContext*)context;
- (void)unsetOnOpenGLContext:(QCOpenGLContext*)context;
@end
