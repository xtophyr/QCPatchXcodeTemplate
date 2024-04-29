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
- (void)_setPatch:(id)fp8;
- (void)__patchUpdated:(id)fp8;
- (void)setCompositionRenderer:(id)fp8;
- (id)compositionRenderer;
- (BOOL)hasParameters;
- (void)setBackgroundColor:(id)fp8;
- (id)backgroundColor;
- (void)setDrawsBackground:(BOOL)fp8;
- (BOOL)drawsBackground;
- (void)setBorderType:(NSBorderType)fp8;
- (NSBorderType)borderType;
- (void)setDelegate:(id)fp8;
- (id)delegate;
- (void)_finishInitialization;
- (id)initWithFrame:(NSRect)fp8;
- (void)finalize;
- (void)dealloc;
- (void)encodeWithCoder:(NSCoder *)aCoder;
- (id)initWithCoder:(NSCoder *)aDecoder;
@end
