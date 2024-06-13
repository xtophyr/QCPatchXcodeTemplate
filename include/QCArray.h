// _type field: (see QCArrayTypeSize() and _StringFromArrayType())
/*  Most of these aren't used, but they're named in StringFromArrayType.
 
        64 bit:     32 bit:     (while 32 bit is dead, it leaks information about CGFloat-style size-changing types or pointers)
    0:  0           0   undefined
    1:  1           1   BOOL            // QCCounter uses this for its _last* Arrays
    2:  1           1   unsigned char
    3:  1           1   char
    4:  2           2   unsigned short
    5:  2           2   short
    6:  4           4   unsigned int    // QCCounter uses this for its _value Array
    7:  4           4   int
    8:  8           4   unsigned long
    9:  8           4   long
    A:  4           4   float
    B:  8           8   double          -- (QCSmooth, QCMouseInteraction)
    C:  8           4   pointer         -- QCImagePort_Cache uses type 0xc
 */

/*  _status field:
    This appears to assume one of 3 values:  0, 1, and 2.
        0 is the default/initialized state
        1 is set after -beginUpdateArray
        2 is set after -endUpdateArray
        1 appears to be a "being updated" value, where -NSArrayRepresentation will throw.
 */

/* _backingCallback returns void and takes void *_array and void *_backingInfo as arguments.  _backingInfo is essentially "void *context" for the callback. */
/* the callback is called in -finalize_QCArray, and is called if it's not null.  this in turn is driven by -dealloc (and -finalize if GC was still a thing) */

typedef void (*releaseCallback)(void *array, void *info);

@interface QCArray : NSObject
{
	void *_array;
	int _type;
	NSUInteger _count;
	NSUInteger _elementSize;
	int _status;
	releaseCallback _backingCallback;
	void *_backingInfo;
	void *_unused[4];
}

@property (readonly,assign) NSUInteger byteSize;
@property (readonly,assign) NSArray *NSArrayRepresentation;
@property (readonly,assign) int status;
@property (readwrite,assign) NSUInteger elementSize;    // setting elementSize will change _count to fit the existing allocation size
@property (readonly,assign) int type;
@property (readwrite,assign) NSUInteger count;  // setting count will realloc() _array accordingly to still hold _count elements
@property (readonly,assign) void *array;

- (NSUInteger)bytesPerValue;
- (id)initWithBaseAddress:(void *)base releaseCallback:(void(*)(void *array, void* context))callback releaseInfo:(void *)context count:(NSUInteger)count elementSize:(NSUInteger)size type:(int)type;
- (id)initWithCount:(NSUInteger)count elementSize:(NSUInteger)size type:(int)type;
- (void)finalize_QCArray;
- (void)finalize;
- (void)dealloc;
- (NSString*)description;
- (BOOL)isEqualToArray:(QCArray*)array;
- (void)_setArray:(void *)newArray free:(BOOL)flag; // this replaces _array with newArray, and free()s the old array if flag is set
- (BOOL)beginUpdateArray;
- (void)endUpdateArray;
- (NSUInteger)byteSize;
- (void)setCount:(NSUInteger)count;
- (void)setElementSize:(NSUInteger)elementSize;
- (NSArray*)NSArrayRepresentation;
- (int)status;
- (NSUInteger)elementSize;
- (int)type;
- (NSUInteger)count;
- (void *)array;
@end

@interface QCArray (Extensions)
- (void)bindArrayToContext:(id)fp8 clientState:(int)fp12 savedState:(CDAnonymousStruct2 *)fp16;
- (void)unbindArrayFromContext:(id)fp8 clientState:(int)fp12 savedState:(CDAnonymousStruct2 *)fp16;
- (void)drawArrayWithContext:(id)fp8 glMode:(int)fp12 indices:(id)fp16;
@end
