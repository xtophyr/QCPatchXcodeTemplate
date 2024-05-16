// GFSettingsColumn is used to swap table column cells in the private preferences.
// cell-based table views are discouraged these days, so this pattern is less common.

@interface GFSettingsColumn : NSTableColumn
- (id)dataCellForRow:(NSInteger)row;
@end
