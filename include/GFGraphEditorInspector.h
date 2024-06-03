

@class GFGraphEditorView, GFGraphView, GFInspectorWindow, GFList, GFNode;

// UI is backed by GFGraphEditorInspector.nib

@interface GFGraphEditorInspector : NSObject
{
	GFInspectorWindow *_window;	//
	NSPopUpButton *_menu;	    // the popup for the inspector panes
	NSTextField *_text;	        // Not Applicable text(?).  hidden / unhidden in -_loadViews:clearUndoManager: as needed.
	GFList *_views;	            // list of inspector panes
	GFList *_viewSizes;	        // list of NSValues of NSSize for resizable inspector panes
	NSView *_currentView;	    // currently active/visible pane for the inspector
	GFGraphEditorView *_graphEditor;
	GFNode *_targetNode;	    // current node the inspector is inspecting
	GFGraphView *_targetGraphView;
	CFDictionaryRef _savedDimensions;	// _savedDimensions is only set temporarily in _reloadInspector, and used in _loadViews:clearUndoManager (which -_reloadInspector calls).  This is a sign of poor factoring.
	void *_unused[2];
}

+ (id)sharedInspector;
- (id)init;
- (void)dealloc;
- (void)cancelOperation:(id)sender;
- (void)windowWillClose:(NSNotification *)notification;
- (void)show;
- (void)hide;
- (BOOL)isVisible;
- (void)__invalidateInspector:(NSNotification*)notification;
- (void)setGraphEditor:(GFGraphEditorView*)graphEditor;
- (GFGraphEditorView*)graphEditor;

@end

@interface GFGraphEditorInspector (Private)
- (id)_window;
- (void)_menuSelect:(id)sender;
- (void)_previousPanel:(id)sender;  // previous and nextPanel are driven by the < and > buttons at the top of the inspector
- (void)_nextPanel:(id)sender;      //
- (void)_loadViews:(GFList*)viewList clearUndoManager:(BOOL)flag;   // viewList contains the panes for the inspector (Input Parameters, Settings, Published Ports)
- (void)_reloadInspector;
@end
