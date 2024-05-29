/* This is also a public header in QC framework */

extern NSString * const QCCompositionPickerViewDidSelectCompositionNotification;
extern NSString * const QCCompositionPickerViewWillSelectCompositionNotification;

typedef struct __QCCompositionPickerViewPrivate {   // 0x30 = 48 bytes
    // offset 0x00
    // offset 0x08
    // offset 0x10
    // offset 0x18 - id delegate
    // offset 0x20
    // offset 0x28
} QCCompositionPickerViewPrivate;

@interface QCCompositionPickerView : NSView
{
	void *_QCCompositionPickerViewPrivate;	// 80 = 0x50
}

- (void)updateState:(int)fp8;
- (void)_windowDidOrderOffScreen:(id)fp8;
- (void)_windowDidOrderOnScreen:(id)fp8;
- (void)_appActive:(id)fp8;
- (void)_appInactive:(id)fp8;
- (void)_windowWillClose:(NSNotification *)notification;
- (void)viewDidMoveToWindow;
- (BOOL)acceptsFirstMouse:(NSEvent*)theEvent;
- (BOOL)acceptsFirstResponder;
- (BOOL)becomeFirstResponder;
- (BOOL)resignFirstResponder;
- (void)mouseDown:(NSEvent*)theEvent;
- (void)keyDown:(NSEvent*)theEvent;
- (void)swipeWithEvent:(NSEvent*)theEvent;
- (void)setCompositionsFromRepositoryWithProtocol:(NSString*)protocol andAttributes:(NSDictionary*)attributes;
- (void)setCompositionsFromRepositoryWithProtocol:(NSString*)protocol andAttributes:(NSDictionary*)attributes sortedBy:(id)fp16;
- (void)drawRect:(NSRect)fp8;
- (void)_finishInitialization;
- (id)initWithFrame:(NSRect)frame options:(id)fp24;
- (id)initWithCoder:(NSCoder *)aDecoder;
- (void)encodeWithCoder:(NSCoder *)aCoder;
- (void)finalize;
- (void)dealloc;
- (void)setFillsPicker:(BOOL)flag;
- (BOOL)fillsPicker;
- (void)setAllowsLayoutAnimations:(BOOL)flag;
- (BOOL)allowsLayoutAnimations;
- (void)setSelectionZoomRect:(NSRect)fp8;
- (NSRect)selectionZoomRect;
- (void)setCellBackgroundColor:(NSColor*)color;
- (NSColor*)cellBackgroundColor;
- (NSSize)cellSize;
- (id)initWithFrame:(NSRect)fp8;
- (id)compositions;
- (void)setDelegate:(id)delegate;
- (id)delegate;
- (void)setDefaultValue:(id)value forInputKey:(NSString*)key;
- (void)resetDefaultInputValues;
- (void)setShowsCompositionNames:(BOOL)flag;
- (BOOL)showsCompositionNames;
- (void)setCompositionAspectRatio:(NSSize)radio;
- (NSSize)compositionAspectRatio;
- (void)setAllowsEmptySelection:(BOOL)flag;
- (BOOL)allowsEmptySelection;
- (void)setSelectedComposition:(QCComposition*)composition;
- (QCComposition*)selectedComposition;
- (void)startAnimation:(id)sender;
- (void)stopAnimation:(id)sender;
- (BOOL)isAnimating;
- (void)setMaxAnimationFrameRate:(float)maxFPS;
- (float)maxAnimationFrameRate;
- (void)setBackgroundColor:(NSColor*)color;
- (NSColor*)backgroundColor;
- (void)setDrawsBackground:(BOOL)flag;
- (BOOL)drawsBackground;
- (void)setBorderType:(NSBorderType)borderType;
- (NSBorderType)borderType;
- (void)setZoomsOnSelection:(BOOL)flag;
- (BOOL)zoomsOnSelection;
- (void)setAllowsIdentitySelection:(BOOL)flag;
- (BOOL)allowsIdentitySelection;
- (NSUInteger)numberOfColumns;
- (void)setNumberOfColumns:(NSUInteger)numberOfColumns;
- (NSUInteger)numberOfRows;
- (void)setNumberOfRows:(NSUInteger)numberOfRows;
- (BOOL)setValue:(id)fp8 forInputKey:(id)fp12 composition:(id)fp16;
- (void)setFlipCellsHorizontally:(BOOL)flag;
- (BOOL)flipCellsHorizontally;
- (void)setOptimizesParameters:(BOOL)flag;
- (BOOL)optimizesParameters;
@end

@interface QCCompositionPickerView (InternalPickerViewControllerDelegate)
- (void)fireDidStartAnimating;
- (void)fireWillStopAnimating;
- (void)fireWillSelectComposition:(id)fp8;
- (void)fireDidSelectComposition;
- (void)fireDidLoadComposition:(id)fp8;
- (BOOL)fireKeyDown:(id)fp8;
@end

@interface QCCompositionPickerView (DragNDrop)
- (BOOL)prepareForDragOperation:(id <NSDraggingInfo>)sender;
- (NSDragOperation)draggingUpdated:(id <NSDraggingInfo>)sender;
- (NSDragOperation)draggingEntered:(id <NSDraggingInfo>)sender;
- (BOOL)performDragOperation:(id <NSDraggingInfo>)sender;
@end
