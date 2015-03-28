#include "pch.h"
#include <GL/glu.h>

/* GL Errors */
#define GL_NO_ERROR 				0x0
#define GL_INVALID_ENUM				0x0500
#define GL_INVALID_VALUE			0x0501
#define GL_INVALID_OPERATION		0x0502
#define GL_STACK_OVERFLOW			0x0503
#define GL_STACK_UNDERFLOW			0x0504
#define GL_OUT_OF_MEMORY			0x0505

static unsigned char* __gluNurbsErrors [] =
{
	(unsigned char*) " ",
	(unsigned char*) "spline order un-supported",
	(unsigned char*) "too few knots",
	(unsigned char*) "valid knot range is empty",
	(unsigned char*) "decreasing knot sequence knot",
	(unsigned char*) "knot multiplicity greater than order of spline",
	(unsigned char*) "gluEndCurve() must follow gluBeginCurve()",
	(unsigned char*) "gluBeginCurve() must precede gluEndCurve()",
	(unsigned char*) "missing or extra geometric data",
	(unsigned char*) "can't draw piecewise linear trimming curves",
	(unsigned char*) "missing or extra domain data",
	(unsigned char*) "missing or extra domain data",
	(unsigned char*) "gluEndTrim() must precede gluEndSurface()",
	(unsigned char*) "gluBeginSurface() must precede gluEndSurface()",
	(unsigned char*) "curve of improper type passed as trim curve",
	(unsigned char*) "gluBeginSurface() must precede gluBeginTrim()",
	(unsigned char*) "gluEndTrim() must follow gluBeginTrim()",
	(unsigned char*) "gluBeginTrim() must precede gluEndTrim()",
	(unsigned char*) "invalid or missing trim curve",
	(unsigned char*) "gluBeginTrim() must precede gluPwlCurve()",
	(unsigned char*) "piecewise linear trimming curve referenced twice",
	(unsigned char*) "piecewise linear trimming curve and nurbs curve mixed",
	(unsigned char*) "improper usage of trim data type",
	(unsigned char*) "nurbs curve referenced twice",
	(unsigned char*) "nurbs curve and piecewise linear trimming curve mixed",
	(unsigned char*) "nurbs surface referenced twice",
	(unsigned char*) "invalid property",
	(unsigned char*) "gluEndSurface() must follow gluBeginSurface()",
	(unsigned char*) "intersecting or misoriented trim curves",
	(unsigned char*) "intersecting trim curves",
	(unsigned char*) "UNUSED",
	(unsigned char*) "unconnected trim curves",
	(unsigned char*) "unknown knot error",
	(unsigned char*) "negative vertex count encountered",
	(unsigned char*) "negative byte-stride encounteed",
	(unsigned char*) "unknown type descriptor",
	(unsigned char*) "null control point reference",
	(unsigned char*) "duplicate point on piecewise linear trimming curve",
};
const unsigned char* __gluNURBSErrorString(int errnum)
{
	return __gluNurbsErrors[errnum];
}

static unsigned char* __gluTessErrors [] =
{
	(unsigned char*) " ",
	(unsigned char*) "gluTessBeginPolygon() must precede a gluTessEndPolygon()",
	(unsigned char*) "gluTessBeginContour() must precede a gluTessEndContour()",
	(unsigned char*) "gluTessEndPolygon() must follow a gluTessBeginPolygon()",
	(unsigned char*) "gluTessEndContour() must follow a gluTessBeginContour()",
	(unsigned char*) "a coordinate is too large",
	(unsigned char*) "need combine callback",
};

const unsigned char* __gluTessErrorString(int errnum)
{
	return __gluTessErrors[errnum];
}

struct token_string
{
	GLUuint Token;
	const char* String;
};

static const struct token_string Errors [] =
{
	/* GL */
	{ GL_NO_ERROR, "no error"},
	{ GL_INVALID_ENUM, "invalid enumerant" },
	{ GL_INVALID_VALUE, "invalid value" },
	{ GL_INVALID_OPERATION, "invalid operation" },
	{ GL_STACK_OVERFLOW, "stack overflow" },
	{ GL_STACK_UNDERFLOW, "stack underflow" },
	{ GL_OUT_OF_MEMORY, "out of memory" },

	/* GLU */
	{ GLU_INVALID_ENUM, "invalid enumerant" },
	{ GLU_INVALID_VALUE, "invalid value" },
	{ GLU_OUT_OF_MEMORY, "out of memory" },
	{ GLU_INCOMPATIBLE_GL_VERSION, "incompatible gl version" },
	{ GLU_INVALID_OPERATION, "invalid operation" },
	{ ~0, NULL } /* end of list indicator */
};

GLAPI const GLUubyte * GLAPIENTRY gluErrorString(GLUenum error)
{
	int i;

	for (i = 0; Errors[i].String; i++)
	{
		if (Errors[i].Token == error)
		{
			return (const GLUubyte*) Errors[i].String;
		}
	}

	if ((error >= GLU_NURBS_ERROR1) && (error <= GLU_NURBS_ERROR37))
	{
		return (const GLUubyte*) __gluNURBSErrorString(error - (GLU_NURBS_ERROR1 - 1));
	}
	if ((error >= GLU_TESS_ERROR1) && (error <= GLU_TESS_ERROR6))
	{
		return (const GLUubyte*) __gluTessErrorString(error - (GLU_TESS_ERROR1 - 1));

	}	return (const GLUubyte*) 0;
}