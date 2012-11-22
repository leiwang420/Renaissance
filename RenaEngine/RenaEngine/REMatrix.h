#ifndef _REMATRIX_H_
#define _REMATRIX_H_

#include "REVector.h"

class Matrix33f;
class Matrix44f;

class Matrix33f
{
public:
	union
	{
		float mM[3][3];
		Vector3f mV[3];//use as row-major matrix
	};
};

class Matrix44f
{
	union
	{
		float mM[4][4];
		Vector4f mV[4];//use as row-major matrix
	};

	static Matrix44f lookAtMatrix(Vector3f eye,Vector3f at,Vector3f up);
};


#endif //_REMATRIX_H_