
#import "QCPatchActor.h"

@interface QCMiniPatchActor : QCPatchActor
{
	void *_unused3[4];	// 84 = 0x54
}

- (NSSize)sizeForNode:(id)fp8;
- (void)_drawNameForPort:(id)fp8 node:(id)fp12 atPoint:(NSPoint)fp16 bounds:(NSRect)bounds inContext:(CGContextRef)fp40;
- (void)_drawBackgroundGradientLayerForNode:(id)fp8 bounds:(NSRect)bounds reflectionHeight:(CGFloat)fp28 inContext:(CGContextRef)fp32;
- (BOOL)pointInTitleRect:(NSPoint)fp8 inNode:(id)fp16 bounds:(NSRect)bounds;
- (NSPoint)pointForPort:(id)fp8 inNode:(id)fp12 bounds:(NSRect)bounds;
- (void)_drawTitleForNode:(id)fp8 bounds:(NSRect)bounds inContext:(CGContextRef)fp28;
- (void)setTitle:(NSString*)title forNode:(id)fp12;

@end
