@interface QCTimeLineLegendColorWell : NSColorWell
- (BOOL)acceptsFirstMouse:(NSEvent*)theEvent;   // returns YES
- (void)mouseDown:(NSEvent*)theEvent;
@end
