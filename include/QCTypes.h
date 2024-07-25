

@class QCArrayBufferObject, QCArray, QCStream;

// FIXME: are the floats still float in 64-bit, or are they doubles now?
// FIXME: are the ints still ints, or are they longs now?

struct QCResourceInfo;

typedef struct _BackgroundInfo {
	NSColor *_field1;       // 0x00
	unsigned int _field2;   // 0x08
	float _field3;          //
	float _field4;          //
	unsigned int _field5;   //
	char _field6;           //
} BackgroundInfo;

// This is private (but publicly declared in darwin source)
//typedef struct __CFRuntimeBase CFRuntimeBase;
// Note: there's a trick with CFUUID to get CFRuntimeBase (at least the size)
// See https://gist.github.com/NSProgrammer/8c2ce755d15777e62079788a7d788394

// until CFRuntimeBase is defined, we just use an anonymous struct
struct _QCC3DMesh;/* {
	CFRuntimeBase _field1;
	struct __C3DMesh *_field2;
	QCArrayBufferObject *_field3[26];
	unsigned int _field4;
};*/

typedef struct _QCCacheProfileInfo {
	NSUInteger _field1;
    NSUInteger _field2;
} QCCacheProfileInfo;

typedef struct _QCContactInfo {
	CGFloat x;
    CGFloat y;
    CGFloat prev_x;
    CGFloat prev_y;
	int state;
} QCContactInfo;

struct _QCDod;  // QCDod is a CF type, so proper name is probably QCDodRef

typedef struct _QCDod
{
    uintptr_t   _cfisa;     // CF, don't touch
    uint8_t     _cfinfo[4]; // CF, don't touch
    uint32_t    _rc;        // CF, don't touch
    CGPoint    *points;
    CGRect      bounds;
    uint64_t    count;      // current index in points array
    uint64_t    pointsSize; // allocation size for *points (in CGPoint, not bytes)
    BOOL        convextFlag;
} QCDod;

typedef struct _QCExecutionInfo {
    void *_field1;
    void *_field2;
    void *_field3;  // QCExecutionPortArray
    void *_field4;
    void *_field5;
    void *_field6;
} QCExecutionInfo;

typedef struct _QCExecutionArray {
	QCExecutionInfo **infos; // array of QCExecutionInfos
    NSUInteger used;
    NSUInteger capacity;
} QCExecutionArray;

typedef struct _QCExecutionStride {
    NSUInteger *_field1;
    NSUInteger _field2;
    NSUInteger _field3;
    NSUInteger _field4;
} QCExecutionStride;

typedef struct _QCIterationManager {
	QCArray *_field1;
	QCArray *_field2;
    NSUInteger _currentIteration;
    NSUInteger _maxIterations;
    NSUInteger _field5; //
    NSUInteger _field6; // something to do with iterator depth (nested iterators)
} QCIterationManager;

typedef struct _QCIterationStack {
    NSUInteger *_field1;
    NSUInteger *_field2;
    NSUInteger _field3;
    NSUInteger _field4;
    NSUInteger _field5;
} QCIterationStack;

typedef struct _QCMeshBoundingBox {
	struct {
		float _field1;
		float _field2;
		float _field3;
	} _field1;
	struct {
		float _field1;
		float _field2;
		float _field3;
	} _field2;
} QCMeshBoundingBox;

typedef struct _QCMeshInternal {
	QCStream *_field1[5];
	union {
		float componentSize;
		struct {
            NSUInteger width;
            NSUInteger height;
            NSUInteger depth;
		} volumeSize;
	} _field2;
} QCMeshInternal;

typedef struct _QCPatchExecutionInfo {
	double _field1;
    NSUInteger _field2;
	double _field3;
	double _field4;
	QCArray *_field5;
	char _field6;
	char _field7;   // this field might disable nextExecutionTime optimizations
} QCPatchExecutionInfo;

struct __C3DEngineContext;
struct __C3DImage;
struct __C3DMesh;
struct __C3DTextureSampler;

struct __Spline {
	double *_field1;
	double *_field2;
	NSInteger _field3;
	double *_field4;
    NSInteger _field5;
    NSInteger _field6;
};

typedef struct {
	unsigned char bytes[16];
} QCMD5Sum;

typedef struct {
	int saveSize;
	int saveType;
	int saveStride;
	unsigned char saveEnabled;
	unsigned char ptrHasChanged;
	void *savePointer;
	void *unused[4];
} CDAnonymousStruct2; // related to QCArray and QCArrayBuffer

typedef struct {
	CGFloat x;
    CGFloat y;
    CGFloat z;
} QCVector3;

// TODO: There are many possible variations of this, maybe union a few useful ones (same for vectors)
typedef struct {
    double m[16];
} QCMatrix;

typedef struct {
	unsigned char _field1;
	int _field2;
	int _field3;
	void *_field4[4];
} CDAnonymousStruct5; // related to QCArrayTexture3D

typedef struct {
	CGFloat _field1;
	CGFloat _field2;
	CGFloat _field3;
	CGFloat _field4;
	CGFloat _field5;
	CGFloat _field6;
	CGFloat _field7;
	CGFloat _field8;
	float _field9;
	NSInteger _field10;
	float _field11;
	float _field12;
	float _field13;
	float _field14;
	float _field15;
	float _field16;
	float _field17;
	float _field18;
	CGFloat _field19;
	CGFloat _field20;
	CGFloat _field21;
	CGFloat _field22;
	float _field23;
} CDAnonymousStruct7; // related to QCParticleSystem

typedef struct {
	double _field1;
	double _field2;
} CDAnonymousStruct8;

typedef struct {
	struct {
		double _field1;
		double _field2;
	} _field1;
	struct {
		double _field1;
		double _field2;
	} _field2;
	struct {
		double _field1;
		double _field2;
	} _field3;
	struct {
		char _field1;
		struct {
			double _field1;
			double _field2;
		} _field2[4];
		double _field3;
		double _field4;
		double _field5;
		double _field6;
		double _field7;
		double _field8;
	} _field4;
	char _field5;
	char _field6;
} CDAnonymousStruct9; // related to QCKeyFrameList

typedef struct {
	CGFloat x;
    CGFloat y;
    CGFloat z;
    CGFloat w;
} QCVector4;

typedef struct {
	char useMatrix;
	unsigned char wasEnabled;
	int boundTexture;
	void *unused[4];
} CDAnonymousStruct12; // related to QCImagePort_Cache, QCPlugInInputImage, and QCImageTextureBuffer

