// TODO: these aren't really void (void) functions -- need to spend some time working out what they really take/return.
// TODO: find functions added in 10.6 (this probably isn't important in 2024...  there may be new functions added though)

typedef void (*MessageCallback)(NSString *_Nullable nodeIdentifier, NSString * _Nonnull formatString, void * _Nullable refCon);

// This is used by QCStructure -initWithMembers: and -initWithMembersAndKeys:
// builds an NSMutableArray filled with first, and then the items in list.  list is nil-terminated.
// There might be a special mode where small integers are also used (the code checks list elements against 0x28 (40)).
NSMutableArray* GFArrayFromArgumentList(id first, id *list);

// each element of the returned array is a symbolicated string of the backtrace.  Symbolication is done by the private CoreSymbolication
// framework, so they're usually higher-quality than dladdr-based symbolications available to the public.
NSArray* GFBacktrace(void);

// DebuggingLevel appears to be more like Flags, where various bits are tested to control logging.  TODO: categorize the various bits
// 0x001 -
// 0x002 -
// 0x004 -
// 0x008 -
NSInteger GFDebuggingLevel(void);    // returns UserDefaults value GFDebuggingLevel

/* GFLog and GFDebug are essentally the same, Debug messages go to the Debug Message Callback
    while Log messages go to the Log Message Callback. */
void GFDebug(NSString *formatString, ...) NS_FORMAT_FUNCTION(1,2) NS_NO_TAIL_CALL;
void GFLog  (NSString *formatString, ...) NS_FORMAT_FUNCTION(1,2) NS_NO_TAIL_CALL;

void GFGetDebugMessageCallback(MessageCallback *_Nullable cb, void **_Nullable ctx);   // safe to pass null for either
void GFGetLogMessageCallback  (MessageCallback *_Nullable cb, void **_Nullable ctx);   // safe to pass null for either
void GFSetDebugMessageCallback(MessageCallback _Nullable cb,  void * _Nullable ctx);   // safe to pass null for either (callback will be skipped)
void GFSetLogMessageCallback  (MessageCallback _Nullable cb,  void * _Nullable ctx);   // safe to pass null for either (callback will be skipped)

/*  GFException unconditionally throws an exception.  The message will include a backtrace from GFBacktrace() if GFDebuggingLevel() is non-zero.
    GFThrowException calls GFException, and prefixes the message with the object class name and selector string */
void GFException(NSExceptionName name, NSString *messageFormatString, ...); // raises/throws an exception
void GFThrowException(id object, SEL selector, NSExceptionName name, NSString *messageFormatString, ...); // raises/throws an exception decorated with object's class and selector to look like a message send (e.g., +[NSObject someClassMethod:])


/* These appear to be used only by GFNodeManager under -_refreshList, and are probably functionally unused? */
/* might have been a primitive precursor to patcherator search? */
// returns true if each of Keywords is contained in Strings.  Strings are compared case-insensitive, and substrings match (so @"is" matches @"this")
// order is important -- @[@"is"], @[@"this"] doesn't match, but @[@"this"], @[@"is"] does.
BOOL GFFilterStringsWithKeywords(NSArray<NSString*> *strings, NSArray<NSString*> *keywords);
// returns a de-duplicated array of words in string.  @"this this is a search string" -> @[@"this",@"is",@"a",@"search",@"string"]
NSArray *GFKeywordsFromSearchString(NSString *string);


NSString* GFNameForNode(GFNode *n);  // will return n->userInfo->@"name" if set, else p->attributes->@"name" if set, else __ClassNameForNode (private function)
NSString* GFNameForPort(QCPort *p);  // will return p->userInfo->@"name" if set, else p->attributes->@"name" if set, else p->key


int QCAddCompositionTrackToMovie(void); // returns 0 (14.4.1)
void QCAddXMLElementsToStructure(void); // returns void, takes 2 object-ish args
int QCAppendCompositionSampleToTrack(void); // returns 0 (14.4.1)
BOOL QCCompositionCompliesToProtocol(QCComposition *composition, NSString *protocol); // not sure about second arg
void QCCompositionFromData(void);
void QCCompositionFromFile(void);
int QCCompositionFromMovieFile(void);  // returns nil (14.4.1)
void QCCompositionFromPatch(void); // deprecated
NSData* QCCompositionToData(NSDictionary *compositionDictionary); // serializes a filtered copy of compositionDictionary
void QCCompositionToFile(void);
void QCCompositionToMovieFile(void);
int QCCompositionsFromMovieFile(void);  // returns nil (14.4.1)
void QCComputeAspectRatioBounds(void);
void QCComputeProportionalBounds(void);
int QCCountCompositionTracksInMovie(void);  // returns 0 (14.4.1)
void QCDataFromComposition(void); // "deprecated" form of QCCompositionToData
BOOL QCFileIsComposition(NSString *path);   // this probably accepts NSURL too - it just does -pathExtension to check for qtz or xml
BOOL QCGLExtensionSupported(id cglContext, const char *extension);

void QCGLMakeTransformationMatrix(CGFloat*,CGFloat xRotation,CGFloat yRotation,CGFloat zRotation,CGFloat xTranslation,CGFloat yTranslation,CGFloat zTranslation);

int QCGetCompositionTrackAtIndex(void); // returns 0 (14.4.1)

/* possible spaces returned:
    kCGColorSpaceGenericGray
    kCGColorSpaceGenericCMYK
    kCGColorSpaceGenericRGB
    kCGColorSpaceGenericRGBLinear
    the main display's colorspace
    others ?
 */
CGColorSpaceRef QCGetIndexedColorSpace(int index); // indexes are 0 - 12 or so

/* returns mach_absolute_time() with the usual mach_timebase_info fixups (scale by numer/denom) */
double QCHostTime(void);
/* filters compositionDictionary, removing some internal keys.  returns a new dict, leaves the original unmodified. */
NSDictionary* QCInfoFromComposition(NSDictionary*compositionDictionary);

// MD5s are used as a key for QCCache.  This is generally an abomination.
QCMD5Sum QCMD5FromData(NSData *data);  // this just shuttles around 16 bytes of md5sum data in an NSData (doesn't hash the data)
QCMD5Sum QCMD5FromString(NSString *string); // parses string for md5 data (doesn't hash the string)
void QCMD5ListToString(void); // added some time after SSDK was dumped
NSData* QCMD5ToData(const void *bytes, NSUInteger length);
NSString* QCMD5ToString(QCMD5Sum * _Nullable md5);
QCMD5Sum QCMD5WithBytes(const void *data, CC_LONG len);    // args sent to CC_MD5 more or less as-is
QCMD5Sum QCMD5WithColorSpace(CGColorSpaceRef cs);
QCMD5Sum QCMD5WithDoubles(void);
QCMD5Sum QCMD5WithIntegers(void);
QCMD5Sum QCMD5WithObject(void);
void QCMD5WithOptions(void); // added some time after SSDK was dumped
QCMD5Sum QCMD5WithPointer(void *ptr);
QCMD5Sum QCMD5WithString(NSString *string);    // hashes string

// TODO: should probably break this out into a separate header with better documentation

void QCMatrix_Clear(QCMatrix *m);   // initializes to identity matrix (4x4)
void QCMatrix_SetIdentity(QCMatrix *m); // same as above, added some time after SSDK was dumped
void QCMatrix_ConcatenateWithMatrix(void);
void QCMatrix_Copy(const QCMatrix *source, QCMatrix *dest);   // copies source to dest
BOOL QCMatrix_EqualsMatrix(const QCMatrix *x, const QCMatrix *y); // added some time after SSDK was dumped
double QCMatrix_Determinant(QCMatrix *matrix); // returns the determinant of matrix
void QCMatrix_FullDeterminant(void); // added some time after SSDK was dumped
void QCMatrix_GetRotationAngles(QCMatrix *matrix, CGFloat *x, CGFloat *y, CGFloat *z);
void QCMatrix_GetRotationAxisAndAngle(void);
void QCMatrix_GetVectorW(const QCMatrix *m, QCVector3 *vec); // sets vec to 4th row of matrix (omits last column)
void QCMatrix_GetVectorX(const QCMatrix *m, QCVector3 *vec); // sets vec to 1st row of matrix (omits last column)
void QCMatrix_GetVectorY(const QCMatrix *m, QCVector3 *vec); // sets vec to 2nd row of matrix (omits last column)
void QCMatrix_GetVectorZ(const QCMatrix *m, QCVector3 *vec); // sets vec to 3rd row of matrix (omits last column)
void QCMatrix_Invert(void); // added some time after SSDK was dumped
BOOL QCMatrix_IsIdentity(const QCMatrix *matrix); // returns true iff matrix is identity matrix
void QCMatrix_MultiplyByMatrix(CGFloat left[16], CGFloat right[16], CGFloat product[16]);
void QCMatrix_Negate(void);
void QCMatrix_Project(void); // added some time after SSDK was dumped
void QCMatrix_RotateQuaternion(void); // added some time after SSDK was dumped
void QCMatrix_RotateVector(void);
void QCMatrix_SetRotationAroundAxisX(void);
void QCMatrix_SetRotationAroundAxisY(void);
void QCMatrix_SetRotationAroundAxisZ(void);
void QCMatrix_SetRotationFromAngles(void);
void QCMatrix_SetRotationFromAxisAndAngle(void);
void QCMatrix_SetRotationFromVectors(void);
void QCMatrix_SetScale(void);
void QCMatrix_SetScaleUniform(void);
void QCMatrix_SetTranslation(void);
void QCMatrix_TransformQuaternion(void); // added some time after SSDK was dumped
void QCMatrix_TransformVector(void);

void QCPatchFromComposition(void);
void QCPatchFromCompositionWithOptions(void);
void QCPatchToComposition(void);
void QCPatchToFlattenedComposition(void);

void QCProFX(void); // takes void, returns void
void QCProFXRegisterAllocationCallbacks(void); // takes 2 function pointer args, QCImagePixelBuffer alloc and dealloc

void QCQuaternion_Add(const QCVector4 *u, const QCVector4 *v, QCVector4 *result); // not used in QC
void QCQuaternion_Clear(QCVector4 *vec);    // sets vec to  0,0,0,1
void QCQuaternion_Conjugate(const QCVector4 *source, QCVector4 *dest); // not used in QC, copies source to dest and flips the sign on x, y, and z (not w)
void QCQuaternion_Copy(const QCVector4 *source, QCVector4 *dest); // not used in QC, copies source to dest
void QCQuaternion_Divide(const QCVector4 *u, const QCVector4 *v, QCVector4 *result); // not used in QC
double QCQuaternion_Dot(const QCVector4 *u, const QCVector4 *v); // not used in QC
void QCQuaternion_Exp(const QCVector4 *u, QCVector4 *result); // not used in QC
void QCQuaternion_GetMatrix(void);
void QCQuaternion_GetRotationAngles(void); // not used in QC
void QCQuaternion_GetRotationAxisAndAngle(const QCVector4 *u, QCVector3 *axis, double *degrees);
void QCQuaternion_Inverse(const QCVector4 *u, QCVector4 *result); // not used in QC
double QCQuaternion_Length(const QCVector4 *u); // not used in QC
void QCQuaternion_LinearInterpolation(const QCVector4 *a, const QCVector4 *b, double alpha, QCVector4 *result); // not used in QC
void QCQuaternion_Log(const QCVector4 *u, QCVector4 *result);
void QCQuaternion_LogDifference(const QCVector4 *u, const QCVector4 *scale, QCVector4 *result); // not used in QC (unsure of scale arg)
void QCQuaternion_Multiply(const QCVector4 *u, const QCVector4 *v, QCVector4 *result);
void QCQuaternion_Normalize(const QCVector4 *u, QCVector4 *result);
void QCQuaternion_ScaleAngle(const QCVector4 *u, double scale, QCVector4 *result); // not used in QC
void QCQuaternion_SetFromMatrix(QCVector4 *result, const QCMatrix *m);
void QCQuaternion_SetFromRotationAngles(QCVector4 *result, double xDegrees, double yDegrees, double zDegrees); // not used in QC
void QCQuaternion_SetFromRotationAxisAndAngle(QCVector4 *result, const QCVector3 *axis, double degrees); // used in QCTrackBall
void QCQuaternion_SetFromVectors(void); // not used in QC
void QCQuaternion_SphericalLinearInterpolation(const QCVector4 *a, const QCVector4 *b, double alpha, QCVector4 *result); // not used in QC
void QCQuaternion_Square(const QCVector4 *u, QCVector4 *result); // not used in QC
void QCQuaternion_SquareRoot(const QCVector4 *u, QCVector4 *result); // not used in QC
void QCQuaternion_Substract(const QCVector4 *u, const QCVector4 *v, QCVector4 *result);	// not used in QC

void QCResolveAliasPath(void);
void QCRestorePatchInputParameters(void);
void QCSavePatchInputParameters(void);

// these don't appear to do anything useful, and aren't used in the QC framework or the editor app.
id QCStateFromPath(id path); // sends -length to path, and returns path if length is non-zero, else returns nil // not used in QC
id QCPathFromState(id state); // returns state (does nothing) // not used in QC

// only Vec3 here -- vec4 is probably just QCQuaternion?
void QCVector_Add(const QCVector3 *u, const QCVector3 *v, QCVector3 *result);	// not used in QC
void QCVector_CrossProduct(const QCVector3 *u, const QCVector3 *v, QCVector3 *result);
double QCVector_DotProduct(const QCVector3 *u, const QCVector3 *v);
BOOL QCVector_EqualsVector(const QCVector3 *a, const QCVector3 *b); // added some time after SSDK was dumped -- not used in QC
double QCVector_Length(const QCVector3 *vector);
void QCVector_LinearInterpolation(const QCVector3 *a, const QCVector3 *b, double alpha, QCVector3 *result);	// not used in QC
QCVector3 QCVector_Make(double x, double y, double z); // added some time after SSDK was dumped -- not used in QC
void QCVector_Normalize(const QCVector3 *vec, QCVector3 *result);	// not used in QC
void QCVector_Scale(CGFloat scale, const QCVector3 *vector, QCVector3 *result);
void QCVector_Substract(const QCVector3 *u, const QCVector3 *v, QCVector3 *result);	// not used in QC

void QCVisualizerIPCClient_End(void); // void / void
void *QCVisualizerIPCClient_GetAudioInformation(void); // return type to be determined, can be NULL
BOOL QCVisualizerIPCClient_IsRunning(void);
BOOL QCVisualizerIPCClient_Start(void);
uint32_t QCVisualizerIPCServer_End(void);   // returns __runningCount (0 when none left), maybe by accident
BOOL QCVisualizerIPCServer_HasClients(void);
BOOL QCVisualizerIPCServer_IsRunning(void);
void QCVisualizerIPCServer_SendAudioInformation(void *); // argument type to be determined, maybe 7 uint64_t's in size
void QCVisualizerIPCServer_SendTrackInformation(void *); // some CF type that can be CFRetained/CFReleased and posted as a notification
BOOL QCVisualizerIPCServer_Start(void); // returns non-zero on success, 0 on failure
