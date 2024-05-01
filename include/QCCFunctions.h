// TODO: these aren't really void (void) functions -- need to spend some time working out what they really take/return.
// TODO: find functions added in 10.6 (this probably isn't important in 2024...  there may be new functions added though)

typedef void (*MessageCallback)(NSString *_Nullable nodeIdentifier, NSString * _Nonnull formatString, void * _Nullable refCon);

NSMutableArray* GFArrayFromArgumentList(void); // I think this takes var args
NSArray *GFBacktrace(void);

NSInteger GFDebuggingLevel(void);    // returns UserDefaults value GFDebuggingLevel

/* GFLog and GFDebug are essentally the same, Debug messages go to the Debug Message Callback
    while Log messages go to the Log Message Callback. */
void GFDebug(NSString *formatString, ...);
void GFLog  (NSString *formatString, ...);

void GFGetDebugMessageCallback(MessageCallback *_Nullable cb, void **_Nullable ctx);   // safe to pass null for either
void GFGetLogMessageCallback  (MessageCallback *_Nullable cb, void **_Nullable ctx);   // safe to pass null for either
void GFSetDebugMessageCallback(MessageCallback _Nullable cb,  void * _Nullable ctx);   // safe to pass null for either (callback will be skipped)
void GFSetLogMessageCallback  (MessageCallback _Nullable cb,  void * _Nullable ctx);   // safe to pass null for either (callback will be skipped)

// these aren't quite right yet.
void GFException(NSString *debugFormatString, NSString *exceptionFormatString, ...); // takes 2 integer args and some var-args stuff
void GFThrowException(void);

BOOL GFFilterStringsWithKeywords(NSArray<NSString*> *strings, NSArray<NSString*> *keywords);
id GFKeywordsFromSearchString(id something);
void GFNameForNode(GFNode *n);  // will return n->userInfo->@"name" if set, else p->attributes->@"name" if set, else __ClassNameForNode (private function)
void GFNameForPort(QCPort *p);  // will return p->userInfo->@"name" if set, else p->attributes->@"name" if set, else p->key


int QCAddCompositionTrackToMovie(void); // returns 0 (14.4.1)
void QCAddXMLElementsToStructure(void); // returns void, takes 2 object-ish args
int QCAppendCompositionSampleToTrack(void); // returns 0 (14.4.1)
BOOL QCCompositionCompliesToProtocol(QCComposition *composition, NSString *protocol); // not sure about second arg
void QCCompositionFromData(void);
void QCCompositionFromFile(void);
int QCCompositionFromMovieFile(void);  // returns nil (14.4.1)
void QCCompositionFromPatch(void);
void QCCompositionToData(void);
void QCCompositionToFile(void);
void QCCompositionToMovieFile(void);
int QCCompositionsFromMovieFile(void);  // returns nil (14.4.1)
void QCComputeAspectRatioBounds(void);
void QCComputeProportionalBounds(void);
int QCCountCompositionTracksInMovie(void);  // returns 0 (14.4.1)
void QCDataFromComposition(void);
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

double QCHostTime(void);
void QCInfoFromComposition(void);

// MD5s are used as a key for QCCache.  This is generally an abomination.
QCMD5Sum QCMD5FromData(NSData *data);  // this just shuttles around 16 bytes of md5sum data in an NSData (doesn't hash the data)
QCMD5Sum QCMD5FromString(NSString *string); // parses string for md5 data (doesn't hash the string)
void QCMD5ListToString(void); // added some time after SSDK was dumped
QCMD5Sum QCMD5ToData(void);
QCMD5Sum QCMD5ToString(void);
QCMD5Sum QCMD5WithBytes(const void *data, CC_LONG len);    // args sent to CC_MD5 more or less as-is
QCMD5Sum QCMD5WithColorSpace(void);
QCMD5Sum QCMD5WithDoubles(void);
QCMD5Sum QCMD5WithIntegers(void);
QCMD5Sum QCMD5WithObject(void);
void QCMD5WithOptions(void); // added some time after SSDK was dumped
QCMD5Sum QCMD5WithPointer(void);
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

void QCQuaternion_Add(void); // not used in QC
void QCQuaternion_Clear(QCVector4*);
void QCQuaternion_Conjugate(void); // not used in QC
void QCQuaternion_Copy(void); // not used in QC
void QCQuaternion_Divide(void); // not used in QC
void QCQuaternion_Dot(void); // not used in QC
void QCQuaternion_Exp(void); // not used in QC
void QCQuaternion_GetMatrix(void);
void QCQuaternion_GetRotationAngles(void); // not used in QC
void QCQuaternion_GetRotationAxisAndAngle(void);
void QCQuaternion_Inverse(void); // not used in QC
void QCQuaternion_Length(void); // not used in QC
void QCQuaternion_LinearInterpolation(void); // not used in QC
void QCQuaternion_Log(void);
void QCQuaternion_LogDifference(void); // not used in QC
void QCQuaternion_Multiply(void);
void QCQuaternion_Normalize(void);
void QCQuaternion_ScaleAngle(void); // not used in QC
void QCQuaternion_SetFromMatrix(void);
void QCQuaternion_SetFromRotationAngles(void); // not used in QC
void QCQuaternion_SetFromRotationAxisAndAngle(void); // used in QCTrackBall
void QCQuaternion_SetFromVectors(void); // not used in QC
void QCQuaternion_SphericalLinearInterpolation(void); // not used in QC
void QCQuaternion_Square(void); // not used in QC
void QCQuaternion_SquareRoot(void); // not used in QC
void QCQuaternion_Substract(void);	// not used in QC

void QCResolveAliasPath(void);
void QCRestorePatchInputParameters(void);
void QCSavePatchInputParameters(void);
void QCStateFromPath(void);
void QCPathFromState(void);

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

void QCVisualizerIPCClient_End(void);
void QCVisualizerIPCClient_GetAudioInformation(void);
BOOL QCVisualizerIPCClient_IsRunning(void);
BOOL QCVisualizerIPCClient_Start(void);
uint32_t QCVisualizerIPCServer_End(void);   // returns __runningCount (0 when none left), maybe by accident
BOOL QCVisualizerIPCServer_HasClients(void);
BOOL QCVisualizerIPCServer_IsRunning(void);
void QCVisualizerIPCServer_SendAudioInformation(void);
void QCVisualizerIPCServer_SendTrackInformation(void);
void QCVisualizerIPCServer_Start(void);
