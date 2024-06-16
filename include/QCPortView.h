

@class QCPort;

@interface QCPortView : NSView
{
	QCPort *_port;	// 80 = 0x50
}

- (id)initWithFrame:(NSRect)frame;
- (id)initWithPort:(QCPort*)port NS_DESIGNATED_INITIALIZER;
- (void)dealloc;
- (id)port;
- (void)drawRect:(NSRect)rect;
@end
