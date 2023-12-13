/*-------------------------------------------------------*/
/* MATH.H : standard mathmatic functions                 */
/* Copyright (c) Franklin Software, Inc 1993-1997        */
/* Rev:  1.12 - SWB - 25.02.97                           */
/*       Added missing labs() definition                 */
/*-------------------------------------------------------*/
#ifndef  _MATH_H_
#define  _MATH_H_

#if (!defined(__C51V6__) && !defined(__CXA__))
#ifndef generic
#define generic
#endif
#endif

//------------------------------------------------------------------------------
// For C51 compiler only
//------------------------------------------------------------------------------
#ifdef __C51__

// IEEE floating point
#if __FLOATTYPE__ == 1
	// long double constant definition
	#define M_EL          2.718281828459F
	#define M_LOG2EL      1.442695040888F
	#define M_LOG10EL    0.4342944819032F
	#define M_LN2L       0.6931471805599F
	#define M_LN10L       2.302585092994F
	#define M_PIL         3.141592653589F
	#define M_PI_2L       1.570796326794F
	#define M_PI_4L      0.7853981633974F
	#define M_1_PIL      0.3183098861837F
	#define M_2_PIL      0.6366197723675F
	#define M_1_SQRTPIL  0.5641895835477F
	#define M_2_SQRTPIL   1.128379167095F
	#define M_SQRT2L      1.414213562373F
	#define M_SQRT_2L    0.7071067811865F
	// double constant definition
	#define M_E           2.718281828459F
	#define M_LOG2E       1.442695040888F
	#define M_LOG10E     0.4342944819032F
	#define M_LN2        0.6931471805599F
	#define M_LN10        2.302585092994F
	#define M_PI          3.141592653589F
	#define M_PI_2        1.570796326794F
	#define M_PI_4       0.7853981633974F
	#define M_1_PI       0.3183098861837F
	#define M_2_PI       0.6366197723675F
	#define M_1_SQRTPI   0.5641895835477F
	#define M_2_SQRTPI    1.128379167095F
	#define M_SQRT2       1.414213562373F
	#define M_SQRT_2     0.7071067811865F
	// float constant definition
	#define M_EF          2.718281828459F
	#define M_LOG2EF      1.442695040888F
	#define M_LOG10EF    0.4342944819032F
	#define M_LN2F       0.6931471805599F
	#define M_LN10F       2.302585092994F
	#define M_PIF         3.141592653589F
	#define M_PI_2F       1.570796326794F
	#define M_PI_4F      0.7853981633974F
	#define M_1_PIF      0.3183098861837F
	#define M_2_PIF      0.6366197723675F
	#define M_1_SQRTPIF  0.5641895835477F
	#define M_2_SQRTPIF   1.128379167095F
	#define M_SQRT2F      1.414213562373F
	#define M_SQRT_2F    0.7071067811865F
	// double prototypes redefinition
	#define acosf	acos
	#define asinf	asin
	#define atanf	atan
	#define atan2f	atan2
	#define ceilf	ceil
	#define fabsf	fabs
	#define floorf	floor
	#define fmodf	fmod
	#define expf	exp
	#define logf	log
	#define log10f	log10
	#define modff	modf
	#define frexpf	frexp
	#define ldexpf	ldexp
	#define sinf	sin
	#define cosf	cos
	#define tanf	tan
	#define sinhf	sinh
	#define coshf	cosh
	#define tanhf	tanh
	#define sqrtf	sqrt
	#define powf	pow
	#define fcheckf	fcheck
	// long double prototypes redefinition
	#define acosl	acos
	#define asinl	asin
	#define atanl	atan
	#define atan2l	atan2
	#define ceill	ceil
	#define fabsl	fabs
	#define floorl	floor
	#define fmodl	fmod
	#define expl	exp
	#define logl	log
	#define log10l	log10
	#define modfl	modf
	#define frexpl	frexp
	#define ldexpl	ldexp
	#define sinl	sin
	#define cosl	cos
	#define tanl	tan
	#define sinhl	sinh
	#define coshl	cosh
	#define tanhl	tanh
	#define sqrtl	sqrt
	#define powl	pow
	#define fcheckl	fcheck

// BCD floating point
#elif __FLOATTYPE__ == 2
#	if __FLOATOPTION__ == 0		// all types
	// long double onstant definition
	#define M_EL          2.718281828459L
	#define M_LOG2EL      1.442695040888L
	#define M_LOG10EL    0.4342944819032L
	#define M_LN2L       0.6931471805599L
	#define M_LN10L       2.302585092994L
	#define M_PIL         3.141592653589L
	#define M_PI_2L       1.570796326794L
	#define M_PI_4L      0.7853981633974L
	#define M_1_PIL      0.3183098861837L
	#define M_2_PIL      0.6366197723675L
	#define M_1_SQRTPIL  0.5641895835477L
	#define M_2_SQRTPIL   1.128379167095L
	#define M_SQRT2L      1.414213562373L
	#define M_SQRT_2L    0.7071067811865L
	// double constant definition
	#define M_E            2.718281828459
	#define M_LOG2E        1.442695040888
	#define M_LOG10E      0.4342944819032
	#define M_LN2         0.6931471805599
	#define M_LN10         2.302585092994
	#define M_PI           3.141592653589
	#define M_PI_2         1.570796326794
	#define M_PI_4        0.7853981633974
	#define M_1_PI        0.3183098861837
	#define M_2_PI        0.6366197723675
	#define M_1_SQRTPI    0.5641895835477
	#define M_2_SQRTPI     1.128379167095
	#define M_SQRT2        1.414213562373
	#define M_SQRT_2      0.7071067811865
	// float constant definition       
	#define M_EF          2.718281828459F
	#define M_LOG2EF      1.442695040888F
	#define M_LOG10EF    0.4342944819032F
	#define M_LN2F       0.6931471805599F
	#define M_LN10F       2.302585092994F
	#define M_PIF         3.141592653589F
	#define M_PI_2F       1.570796326794F
	#define M_PI_4F      0.7853981633974F
	#define M_1_PIF      0.3183098861837F
	#define M_2_PIF      0.6366197723675F
	#define M_1_SQRTPIF  0.5641895835477F
	#define M_2_SQRTPIF   1.128379167095F
	#define M_SQRT2F      1.414213562373F
	#define M_SQRT_2F    0.7071067811865F
#	elif __FLOATOPTION__ == 1 	// All floating points assumed as BCD float type
	// long double constant definition
	#define M_EL          2.718281828459F
	#define M_LOG2EL      1.442695040888F
	#define M_LOG10EL    0.4342944819032F
	#define M_LN2L       0.6931471805599F
	#define M_LN10L       2.302585092994F
	#define M_PIL         3.141592653589F
	#define M_PI_2L       1.570796326794F
	#define M_PI_4L      0.7853981633974F
	#define M_1_PIL      0.3183098861837F
	#define M_2_PIL      0.6366197723675F
	#define M_1_SQRTPIL  0.5641895835477F
	#define M_2_SQRTPIL   1.128379167095F
	#define M_SQRT2L      1.414213562373F
	#define M_SQRT_2L    0.7071067811865F
	// double constant definition
	#define M_E           2.718281828459F
	#define M_LOG2E       1.442695040888F
	#define M_LOG10E     0.4342944819032F
	#define M_LN2        0.6931471805599F
	#define M_LN10        2.302585092994F
	#define M_PI          3.141592653589F
	#define M_PI_2        1.570796326794F
	#define M_PI_4       0.7853981633974F
	#define M_1_PI       0.3183098861837F
	#define M_2_PI       0.6366197723675F
	#define M_1_SQRTPI   0.5641895835477F
	#define M_2_SQRTPI    1.128379167095F
	#define M_SQRT2       1.414213562373F
	#define M_SQRT_2     0.7071067811865F
	// float constant definition       
	#define M_EF          2.718281828459F
	#define M_LOG2EF      1.442695040888F
	#define M_LOG10EF    0.4342944819032F
	#define M_LN2F       0.6931471805599F
	#define M_LN10F       2.302585092994F
	#define M_PIF         3.141592653589F
	#define M_PI_2F       1.570796326794F
	#define M_PI_4F      0.7853981633974F
	#define M_1_PIF      0.3183098861837F
	#define M_2_PIF      0.6366197723675F
	#define M_1_SQRTPIF  0.5641895835477F
	#define M_2_SQRTPIF   1.128379167095F
	#define M_SQRT2F      1.414213562373F
	#define M_SQRT_2F    0.7071067811865F
	// BCD double prototypes redefinition
	#define acos	acosf
	#define asin	asinf
	#define atan	atanf
	#define atan2	atan2f
	#define ceil	ceilf
	#define fabs	fabsf
	#define floor	floorf
	#define fmod	fmodf
	#define exp	expf
	#define log	logf
	#define log10	log10f
	#define modf	modff
	#define frexp	frexpf
	#define ldexp	ldexpf
	#define sin	sinf
	#define cos	cosf
	#define tan	tanf
	#define sinh	sinhf
	#define cosh	coshf
	#define tanh	tanhf
	#define sqrt	sqrtf
	#define pow	powf
	#define fcheck	fcheckf
	// BCD long double prototypes redefinition
	#define acosl	acosf
	#define asinl	asinf
	#define atanl	atanf
	#define atan2l	atan2f
	#define ceill	ceilf
	#define fabsl	fabsf
	#define floorl	floorf
	#define fmodl	fmodf
	#define expl	expf
	#define logl	logf
	#define log10l	log10f
	#define modfl	modff
	#define frexpl	frexpf
	#define ldexpl	ldexpf
	#define sinl	sinf
	#define cosl	cosf
	#define tanl	tanf
	#define sinhl	sinhf
	#define coshl	coshf
	#define tanhl	tanhf
	#define sqrtl	sqrtf
	#define powl	powf
	#define fcheckl	fcheckf
#	elif __FLOATOPTION__ == 2 	// All floating points assumed as BCD double type
	// long double constant definition
	#define M_EL          2.718281828459
	#define M_LOG2EL      1.442695040888
	#define M_LOG10EL    0.4342944819032
	#define M_LN2L       0.6931471805599
	#define M_LN10L       2.302585092994
	#define M_PIL         3.141592653589
	#define M_PI_2L       1.570796326794
	#define M_PI_4L      0.7853981633974
	#define M_1_PIL      0.3183098861837
	#define M_2_PIL      0.6366197723675
	#define M_1_SQRTPIL  0.5641895835477
	#define M_2_SQRTPIL   1.128379167095
	#define M_SQRT2L      1.414213562373
	#define M_SQRT_2L    0.7071067811865
	// double constant definition       
	#define M_E           2.718281828459
	#define M_LOG2E       1.442695040888
	#define M_LOG10E     0.4342944819032
	#define M_LN2        0.6931471805599
	#define M_LN10        2.302585092994
	#define M_PI          3.141592653589
	#define M_PI_2        1.570796326794
	#define M_PI_4       0.7853981633974
	#define M_1_PI       0.3183098861837
	#define M_2_PI       0.6366197723675
	#define M_1_SQRTPI   0.5641895835477
	#define M_2_SQRTPI    1.128379167095
	#define M_SQRT2       1.414213562373
	#define M_SQRT_2     0.7071067811865
	// float constant definition       
	#define M_EF          2.718281828459
	#define M_LOG2EF      1.442695040888
	#define M_LOG10EF    0.4342944819032
	#define M_LN2F       0.6931471805599
	#define M_LN10F       2.302585092994
	#define M_PIF         3.141592653589
	#define M_PI_2F       1.570796326794
	#define M_PI_4F      0.7853981633974
	#define M_1_PIF      0.3183098861837
	#define M_2_PIF      0.6366197723675
	#define M_1_SQRTPIF  0.5641895835477
	#define M_2_SQRTPIF   1.128379167095
	#define M_SQRT2F      1.414213562373
	#define M_SQRT_2F    0.7071067811865
	// BCD float prototypes redefinition
	#define acosf	acos
	#define asinf	asin
	#define atanf	atan
	#define atan2f	atan2
	#define ceilf	ceil
	#define fabsf	fabs
	#define floorf	floor
	#define fmodf	fmod
	#define expf	exp
	#define logf	log
	#define log10f	log10
	#define modff	modf
	#define frexpf	frexp
	#define ldexpf	ldexp
	#define sinf	sin
	#define cosf	cos
	#define tanf	tan
	#define sinhf	sinh
	#define coshf	cosh
	#define tanhf	tanh
	#define sqrtf	sqrt
	#define powf	pow
	#define fcheckf	fcheck
	// BCD long double prototypes redefinition
	#define acosl	acos
	#define asinl	asin
	#define atanl	atan
	#define atan2l	atan2
	#define ceill	ceil
	#define fabsl	fabs
	#define floorl	floor
	#define fmodl	fmod
	#define expl	exp
	#define logl	log
	#define log10l	log10
	#define modfl	modf
	#define frexpl	frexp
	#define ldexpl	ldexp
	#define sinl	sin
	#define cosl	cos
	#define tanl	tan
	#define sinhl	sinh
	#define coshl	cosh
	#define tanhl	tanh
	#define sqrtl	sqrt
	#define powl	pow
	#define fcheckl	fcheck
#	else 				// All floating points assumed as BCD long double type
	// long double constant definition
	#define M_EL          2.718281828459L
	#define M_LOG2EL      1.442695040888L
	#define M_LOG10EL    0.4342944819032L
	#define M_LN2L       0.6931471805599L
	#define M_LN10L       2.302585092994L
	#define M_PIL         3.141592653589L
	#define M_PI_2L       1.570796326794L
	#define M_PI_4L      0.7853981633974L
	#define M_1_PIL      0.3183098861837L
	#define M_2_PIL      0.6366197723675L
	#define M_1_SQRTPIL  0.5641895835477L
	#define M_2_SQRTPIL   1.128379167095L
	#define M_SQRT2L      1.414213562373L
	#define M_SQRT_2L    0.7071067811865L
	// double constant definition
	#define M_E           2.718281828459L
	#define M_LOG2E       1.442695040888L
	#define M_LOG10E     0.4342944819032L
	#define M_LN2        0.6931471805599L
	#define M_LN10        2.302585092994L
	#define M_PI          3.141592653589L
	#define M_PI_2        1.570796326794L
	#define M_PI_4       0.7853981633974L
	#define M_1_PI       0.3183098861837L
	#define M_2_PI       0.6366197723675L
	#define M_1_SQRTPI   0.5641895835477L
	#define M_2_SQRTPI    1.128379167095L
	#define M_SQRT2       1.414213562373L
	#define M_SQRT_2     0.7071067811865L
	// float constant definition
	#define M_EF          2.718281828459L
	#define M_LOG2EF      1.442695040888L
	#define M_LOG10EF    0.4342944819032L
	#define M_LN2F       0.6931471805599L
	#define M_LN10F       2.302585092994L
	#define M_PIF         3.141592653589L
	#define M_PI_2F       1.570796326794L
	#define M_PI_4F      0.7853981633974L
	#define M_1_PIF      0.3183098861837L
	#define M_2_PIF      0.6366197723675L
	#define M_1_SQRTPIF  0.5641895835477L
	#define M_2_SQRTPIF   1.128379167095L
	#define M_SQRT2F      1.414213562373L
	#define M_SQRT_2F    0.7071067811865L
	// BCD float prototypes redefinition
	#define acosf	acosl
	#define asinf	asinl
	#define atanf	atanl
	#define atan2f	atan2l
	#define ceilf	ceill
	#define fabsf	fabsl
	#define floorf	floorl
	#define fmodf	fmodl
	#define expf	expl
	#define logf	logl
	#define log10f	log10l
	#define modff	modfl
	#define frexpf	frexpl
	#define ldexpf	ldexpl
	#define sinf	sinl
	#define cosf	cosl
	#define tanf	tanl
	#define sinhf	sinhl
	#define coshf	coshl
	#define tanhf	tanhl
	#define sqrtf	sqrtl
	#define powf	powl
	#define fcheckf	fcheckl
	// BCD double prototypes redefinition
	#define acos	acosl
	#define asin	asinl
	#define atan	atanl
	#define atan2	atan2l
	#define ceil	ceill
	#define fabs	fabsl
	#define floor	floorl
	#define fmod	fmodl
	#define exp	expl
	#define log	logl
	#define log10	log10l
	#define modf	modfl
	#define frexp	frexpl
	#define ldexp	ldexpl
	#define sin	sinl
	#define cos	cosl
	#define tan	tanl
	#define sinh	sinhl
	#define cosh	coshl
	#define tanh	tanhl
	#define sqrt	sqrtl
	#define pow	powl
	#define fcheck	fcheckl
#	endif
#endif

#endif	// __C51__ definition
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// For CXA compiler only
//------------------------------------------------------------------------------
#ifdef __CXA__
	// Only IEEE floating point is available at the moment
	#define M_EF          2.718281828459F
	#define M_LOG2EF      1.442695040888F
	#define M_LOG10EF    0.4342944819032F
	#define M_LN2F       0.6931471805599F
	#define M_LN10F       2.302585092994F
	#define M_PIF         3.141592653589F
	#define M_PI_2F       1.570796326794F
	#define M_PI_4F      0.7853981633974F
	#define M_1_PIF      0.3183098861837F
	#define M_2_PIF      0.6366197723675F
	#define M_1_SQRTPIF  0.5641895835477F
	#define M_2_SQRTPIF   1.128379167095F
	#define M_SQRT2F      1.414213562373F
	#define M_SQRT_2F    0.7071067811865F
	// double prototypes redefinition
	#define acosf	acos
	#define asinf	asin
	#define atanf	atan
	#define atan2f	atan2
	#define ceilf	ceil
	#define fabsf	fabs
	#define floorf	floor
	#define fmodf	fmod
	#define expf	exp
	#define logf	log
	#define log10f	log10
	#define modff	modf
	#define frexpf	frexp
	#define ldexpf	ldexp
	#define sinf	sin
	#define cosf	cos
	#define tanf	tan
	#define sinhf	sinh
	#define coshf	cosh
	#define tanhf	tanh
	#define sqrtf	sqrt
	#define powf	pow
	#define fcheckf	fcheck
	// long double prototypes redefinition
	#define acosl	acos
	#define asinl	asin
	#define atanl	atan
	#define atan2l	atan2
	#define ceill	ceil
	#define fabsl	fabs
	#define floorl	floor
	#define fmodl	fmod
	#define expl	exp
	#define logl	log
	#define log10l	log10
	#define modfl	modf
	#define frexpl	frexp
	#define ldexpl	ldexp
	#define sinl	sin
	#define cosl	cos
	#define tanl	tan
	#define sinhl	sinh
	#define coshl	cosh
	#define tanhl	tanh
	#define sqrtl	sqrt
	#define powl	pow
	#define fcheckl	fcheck
#endif	// __CXA__ definition


//------------------------------------------------------------------------------
// Mathmatical function prototypes for both compilers
//------------------------------------------------------------------------------
#pragma SAVE
#pragma GENERIC

#ifndef __CXA__
#pragma NOAREGS
#pragma REGPARMS
#else
#define reentrant
#endif

extern int 	abs (int i1) reentrant;
extern long	labs(long  val) reentrant;

extern float  acosf  (float dfp) reentrant;
extern float  asinf  (float f1) reentrant;
extern float  atanf  (float f1) reentrant;
extern float  atan2f (float f1, float f2) reentrant;

extern float  ceilf  (float f1) reentrant;
extern float  fabsf  (float f1) reentrant;
extern float  floorf (float f1) reentrant;
extern float  fmodf  (float f1, float f2) reentrant;

extern float  expf   (float f1) reentrant;
extern float  logf   (float f1) reentrant;
extern float  log10f (float f1) reentrant;
extern float  modff  (float f1, float generic *fp2) reentrant;
extern float  frexpf (float f1, int  generic *pexp) reentrant;
extern float  ldexpf (float f1, int exp) reentrant;

extern float  sinf   (float f1) reentrant;
extern float  cosf   (float f1) reentrant;
extern float  tanf   (float f1) reentrant;

extern float  sinhf  (float f1) reentrant;
extern float  coshf  (float f1) reentrant;
extern float  tanhf  (float f1) reentrant;

extern float  sqrtf  (float f1) reentrant;
extern float  powf   (float f1, float f2) reentrant;

extern char   fcheckf (float f1) reentrant;

extern double  acos  (double dfp) reentrant;
extern double  asin  (double f1) reentrant;
extern double  atan  (double f1) reentrant;
extern double  atan2 (double f1, double f2) reentrant;

extern double  ceil  (double f1) reentrant;
extern double  fabs  (double f1) reentrant;
extern double  floor (double f1) reentrant;
extern double  fmod  (double f1, double f2) reentrant;

extern double  exp   (double f1) reentrant;
extern double  log   (double f1) reentrant;
extern double  log10 (double f1) reentrant;
extern double  modf  (double f1, double  generic *fp2) reentrant;
extern double  frexp (double f1, int  generic *pexp) reentrant;
extern double  ldexp (double f1, int exp) reentrant;

extern double  sin   (double f1) reentrant;
extern double  cos   (double f1) reentrant;
extern double  tan   (double f1) reentrant;

extern double  sinh  (double f1) reentrant;
extern double  cosh  (double f1) reentrant;
extern double  tanh  (double f1) reentrant;

extern double  sqrt  (double f1) reentrant;
extern double  pow   (double f1, double f2) reentrant;

extern char fcheck (double f1) reentrant;

extern long double  acosl  (long double dfp) reentrant;
extern long double  asinl  (long double f1) reentrant;
extern long double  atanl  (long double f1) reentrant;
extern long double  atan2l (long double f1, long double f2) reentrant;

extern long double  ceill  (long double f1) reentrant;
extern long double  fabsl  (long double f1) reentrant;
extern long double  floorl (long double f1) reentrant;
extern long double  fmodl  (long double f1, long double f2) reentrant;

extern long double  expl   (long double f1) reentrant;
extern long double  logl   (long double f1) reentrant;
extern long double  log10l (long double f1) reentrant;
extern long double  modfl  (long double f1, long double  generic *fp2) reentrant;
extern long double  frexpl (long double f1, int  generic *pexp) reentrant;
extern long double  ldexpl (long double f1, int exp) reentrant;

extern long double  sinl   (long double f1) reentrant;
extern long double  cosl   (long double f1) reentrant;
extern long double  tanl   (long double f1) reentrant;

extern long double  sinhl  (long double f1) reentrant;
extern long double  coshl  (long double f1) reentrant;
extern long double  tanhl  (long double f1) reentrant;

extern long double  sqrtl  (long double f1) reentrant;
extern long double  powl   (long double f1, long double f2) reentrant;

extern char fcheckl (long double f1) reentrant;
#pragma RESTORE

#define RAND_MAX 65535


#endif

