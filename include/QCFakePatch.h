/*
 QCFakePatch is used in QCPatchView _createSubgraphFromSelection:, possibly as a placeholder
 */

@interface QCFakePatch : QCPatch
+ (BOOL)isSafe;
+ (QCPatchExecutionMode)executionModeWithIdentifier:(id)identifier;
+ (int)timeModeWithIdentifier:(id)identifier;
+ (BOOL)allowsSubpatchesWithIdentifier:(id)identifier;
@end
