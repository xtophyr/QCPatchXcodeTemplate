@interface QCZoomView : NSView
{
	NSPoint _cachedCenter;	// 80 = 0x50
	CGFloat _cachedZoomFactorX;	// 88 = 0x58
	CGFloat _cachedZoomFactorY;	// 92 = 0x5c
	CGFloat _zoomFactorX;	// 96 = 0x60
	CGFloat _zoomFactorY;	// 100 = 0x64
	void *_unused[4];	// 104 = 0x68
}

- (id)initWithFrame:(NSRect)frame;
- (void)scrollWheel:(NSEvent*)event;
- (BOOL)autoscroll:(NSEvent*)event;
- (void)viewDidMoveToSuperview;
- (NSRect)maxBounds;        // NSInternalInconsistencyException : "Function not implemented"
- (NSRect)selectionBounds;  // NSInternalInconsistencyException : "Function not implemented"
- (BOOL)allowsNonSquareZooming;
- (CGFloat)resizeHotzoneWidth;
- (CGFloat)incrementalZoomAmount;
- (CGFloat)minX;
- (CGFloat)maxX;
- (CGFloat)minY;
- (CGFloat)maxY;
- (CGFloat)zoomFactorX;
- (CGFloat)zoomFactorY;
- (void)setZoomFactorX:(CGFloat)zoomFactorX;
- (void)setZoomFactorY:(CGFloat)zoomFactorY;
- (void)zoomToFitSelection;
- (void)zoomToFitAll;
- (BOOL)zoomStateCached;
- (void)cacheZoomState;
- (void)restoreZoomState;
- (void)zoomInX;
- (void)zoomInY;
- (void)zoomOutX;
- (void)zoomOutY;
@end

@interface QCZoomView (Private)
- (NSPoint)_centerPoint;
- (void)_setCenterPoint:(NSPoint)center;
- (void)_setZoomFactorX:(CGFloat)zoomFactorX factorY:(CGFloat)zoomFactorY centerPoint:(NSPoint)center;
- (void)_zoomWithSpeedFactorForX:(CGFloat)fp8 speedFactorForY:(CGFloat)fp12;
- (void)_zoomToFitRect:(NSRect)rect;
- (void)_adjustFrame;
- (void)__frameChanged:(NSNotification*)notification;
@end
