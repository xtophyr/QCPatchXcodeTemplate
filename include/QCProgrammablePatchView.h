#import "QCSourceTextView.h"

@class QCProgrammablePatch;

@interface QCProgrammablePatchView : QCSourceTextView
{
	IBOutlet NSTextField *_statusField;	// 128 = 0x80
	IBOutlet NSImageView *_statusImage;	// 132 = 0x84
	NSString *_sourceType;	// 136 = 0x88
	QCProgrammablePatch *_targetPatch;	// 140 = 0x8c
	NSUndoManager *_undoManager;	// 144 = 0x90
	NSTimer *_typingTimer;	// 148 = 0x94
	BOOL _disableUpdate;	// 152 = 0x98
	void *_unused2[3];	// 156 = 0x9c
}

+ (void)initialize;
+ (id)_keywordsFromString:(NSString*)keywords;// whitespace-separated list
+ (id)_keywordsAndColorsFromXML:(id)fp8;
- (id)initWithFrame:(NSRect)frameRect;
- (id)initWithCoder:(NSCoder *)aDecoder;
- (void)dealloc;
- (void)_setCompileResult:(id)fp8;
- (void)_patchUpdated:(id)fp8;
- (void)_setUndoManager:(NSUndoManager*)undoManager;
- (void)undo:(id)sender;
- (void)redo:(id)sender;
- (BOOL)validateMenuItem:(NSMenuItem*)menuItem;
- (void)setProgrammablePatch:(QCProgrammablePatch*)patch sourceType:(NSString*)sourceType; // sourceType is a string like @"vertexShader" or @"fragmentShader"
- (void)setStatusField:(NSTextField*)textField;
- (NSTextField*)statusField;
- (void)_updateSource:(id)fp8;
- (void)textDidChange:(NSNotification*)notification;
- (void)setStatusImage:(NSImageView*)imageView;
- (NSImageView*)statusImage;
@end
