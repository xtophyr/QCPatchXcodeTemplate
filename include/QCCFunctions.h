// TODO: these aren't really void (void) functions -- need to spend some time working out what they really take/return.
// TODO: find functions added in 10.6 (this probably isn't important in 2024...  there may be new functions added though)

NSMutableArray* GFArrayFromArgumentList(void); // I think this takes var args
NSArray *GFBacktrace(void);
void GFDebug(NSString *formatString, ...);
NSInteger GFDebuggingLevel(void);	// returns UserDefaults value GFDebuggingLevel
void GFException(NSString *debugFormatString, NSString *exceptionFormatString, ...); // takes 2 integer args and some var-args stuff
void GFFilterStringsWithKeywords(void);
void GFGetDebugMessageCallback(void);   // takes 2 nullable args to return 2 function pointers (callback, refcon)
void GFGetLogMessageCallback(void);     // takes 2 nullable args to return 2 function pointers (callback, refcon)
void GFKeywordsFromSearchString(void);
void GFLog(NSString*format, ...);
void GFNameForNode(GFNode *n);  // will return n->userInfo->@"name" if set, else p->attributes->@"name" if set, else __ClassNameForNode (private function)
void GFNameForPort(QCPort *p);  // will return p->userInfo->@"name" if set, else p->attributes->@"name" if set, else p->key
void GFSetDebugMessageCallback(void);   // takes 2 function pointer args
void GFSetLogMessageCallback(void); // takes 2 function pointer args
void GFThrowException(void);

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

typedef struct {
    unsigned char md5sum[16];
} QCMD5;

QCMD5 QCMD5FromData(NSData *data);  // this just shuttles around 16 bytes of md5sum data in an NSData (doesn't hash the data)
QCMD5 QCMD5FromString(NSString *string); // parses string for md5 data (doesn't hash the string)
QCMD5 QCMD5ToData(void);
QCMD5 QCMD5ToString(void);
QCMD5 QCMD5WithBytes(const void *data, CC_LONG len);    // args sent to CC_MD5 more or less as-is
QCMD5 QCMD5WithColorSpace(void);
QCMD5 QCMD5WithDoubles(void);
QCMD5 QCMD5WithIntegers(void);
QCMD5 QCMD5WithObject(void);
QCMD5 QCMD5WithPointer(void);
QCMD5 QCMD5WithString(NSString *string);    // hashes string

// TODO: probably make a QC matrix type rather than CGFloat[16]?
void QCMatrix_Clear(CGFloat[16]);
void QCMatrix_ConcatenateWithMatrix(void);
void QCMatrix_Copy(void);
void QCMatrix_Determinant(void);
void QCMatrix_GetRotationAngles(CGFloat[16], CGFloat *x, CGFloat *y, CGFloat *z);
void QCMatrix_GetRotationAxisAndAngle(void);
void QCMatrix_GetVectorW(void);
void QCMatrix_GetVectorX(void);
void QCMatrix_GetVectorY(void);
void QCMatrix_GetVectorZ(void);
void QCMatrix_IsIdentity(void);
void QCMatrix_MultiplyByMatrix(CGFloat left[16], CGFloat right[16], CGFloat product[16]);
void QCMatrix_Negate(void);
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
void QCMatrix_TransformVector(void);

void QCPatchFromComposition(void);
void QCPatchFromCompositionWithOptions(void);
void QCPatchToComposition(void);
void QCPatchToFlattenedComposition(void);

void QCPathFromState(void);

void QCProFX(void); // takes void, returns void
void QCProFXRegisterAllocationCallbacks(void); // takes 2 function pointer args, QCImagePixelBuffer alloc and dealloc

void QCQuaternion_Add(void);
void QCQuaternion_Clear(QCVector4*);
void QCQuaternion_Conjugate(void);
void QCQuaternion_Copy(void);
void QCQuaternion_Divide(void);
void QCQuaternion_Dot(void);
void QCQuaternion_Exp(void);
void QCQuaternion_GetMatrix(void);
void QCQuaternion_GetRotationAngles(void);
void QCQuaternion_GetRotationAxisAndAngle(void);
void QCQuaternion_Inverse(void);
void QCQuaternion_Length(void);
void QCQuaternion_LinearInterpolation(void);
void QCQuaternion_Log(void);
void QCQuaternion_LogDifference(void);
void QCQuaternion_Multiply(void);
void QCQuaternion_Normalize(void);
void QCQuaternion_ScaleAngle(void);
void QCQuaternion_SetFromMatrix(void);
void QCQuaternion_SetFromRotationAngles(void);
void QCQuaternion_SetFromRotationAxisAndAngle(void);
void QCQuaternion_SetFromVectors(void);
void QCQuaternion_SphericalLinearInterpolation(void);
void QCQuaternion_Square(void);
void QCQuaternion_SquareRoot(void);
void QCQuaternion_Substract(void);	// Not actually used in QC (!)

void QCResolveAliasPath(void);
void QCRestorePatchInputParameters(void);
void QCSavePatchInputParameters(void);
void QCStateFromPath(void);

void QCVector_Add(QCVector3 *u, QCVector3 *v, QCVector3 *result);	// Not actually used in QC (!)
void QCVector_CrossProduct(QCVector3 *u, QCVector3 *v, QCVector3 *result);
double QCVector_DotProduct(QCVector3 *u, QCVector3 *v);
double QCVector_Length(QCVector3 *vector);
void QCVector_LinearInterpolation(void);	// Not actually used in QC (!)
void QCVector_Normalize(QCVector3 *vector);	// Not actually used in QC (!)
void QCVector_Scale(CGFloat scale, QCVector3 *vector, QCVector3 *result);
void QCVector_Substract(QCVector3 *u, QCVector3 *v, QCVector3 *result);	// Not actually used in QC (!)

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
