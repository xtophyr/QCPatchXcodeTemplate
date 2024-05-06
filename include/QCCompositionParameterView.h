/* This is also a public header in QC framework */

typedef struct __QCCompositionParameterViewPrivate {   // 0x28 = 40 bytes
    // offset 0x00
    // offset 0x08
    // offset 0x10
    // offset 0x18
    // offset 0x20
} QCCompositionParameterViewPrivate;

@interface QCCompositionParameterView : NSView
{
	void *_QCCompositionParameterViewPrivate;	// 80 = 0x50
}

- (void)observeValueForKeyPath:(NSString*)path ofObject:(id)object change:(NSDictionary*)change context:(void *)context;
- (void)_setPatch:(id)patch;
- (void)__patchUpdated:(id)fp8;
- (void)setCompositionRenderer:(id<QCCompositionRenderer>)renderer;
- (id<QCCompositionRenderer>)compositionRenderer;
- (BOOL)hasParameters;
- (void)setBackgroundColor:(NSColor*)color;
- (NSColor*)backgroundColor;
- (void)setDrawsBackground:(BOOL)flag;
- (BOOL)drawsBackground;
- (void)setBorderType:(NSBorderType)borderType;
- (NSBorderType)borderType;
- (void)setDelegate:(id)delegate;
- (id)delegate;
- (void)_finishInitialization;
- (id)initWithFrame:(NSRect)frame;
- (void)finalize;
- (void)dealloc;
- (void)encodeWithCoder:(NSCoder *)aCoder;
- (id)initWithCoder:(NSCoder *)aDecoder;
@end
