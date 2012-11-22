#ifndef _REVECTOR_H_
#define _REVECTOR_H_

class Vector2f;
class Vector3f;
class Vector4f;

// v' = a * v 
Vector2f operator*(float left,const Vector2f& v);
Vector3f operator*(float left, const Vector3f& v);
Vector4f operator*(float left,const Vector4f& v);

// vector with 2 floats
class Vector2f
{
public:
	union
	{
		float mV[2];
		struct{float mX,mY;};
	};

	//ctors
	Vector2f(float x=0,float y=0):mX(x),mY(y){}

	inline Vector2f& set(float x, float y)
	{
		mX = x;
		mY = y;
		return (*this);
	}

	float& operator [](long k)
	{
		return mV[k];
	}

	const float& operator [](long k) const
	{
		return mV[k];
	}

	Vector2f operator+(const Vector2f& r) const
	{
		return Vector2f(mX+r.mX,mY+r.mY);
	}

	Vector2f operator-(const Vector2f& r) const
	{
		return Vector2f(mX-r.mX,mY-r.mY);
	}
	Vector2f operator-() const
	{
		return Vector2f(-mX,-mY);
	}
	Vector2f operator+() const
	{
		return *this;
	}
	Vector2f operator*(const float r) const
	{
		return Vector2f(mX*r,mY*r);
	}
	Vector2f operator/(const float r) const
	{
		return Vector2f(mX/r,mY/r);
	}

	//return the norm(length) of the vector
	float norm() const
	{
		return sqrt(mX*mX+mY*mY);
	}

	//return the norm(length) of the vector
	float norm2() const
	{
		return mX*mX+mY*mY;
	}

	float dot(const Vector2f& r) const
	{
		return mX*r.mX+mY*r.mY;
	}

	//calculate a project of v on q direction
	Vector2f proj(const Vector2f& q) const
	{
		float len = dot(q)/q.norm2();
		return len*q;
	}

	//return the normalized version of vector
	Vector2f nomalized() const
	{
		float n2 = mX*mX+mY*mY;
		assert( n2 != 0 );
		float n = 1.0f/sqrt(n2);
		return Vector2f(mX*n,mY*n);
	}

	// return the cos(a), a is the angle between this and q
	float cosAngle(const Vector2f& q) const
	{
		return dot(q)/(norm()*q.norm());
	}

	// return the sin(a), a is the angle between this and q
	float sinAngle(const Vector2f& q) const
	{
		return (mX*q.mY-mY*q.mX)/(norm()*q.norm());
	}
};

// vector with 3 floats
class Vector3f
{
public:
	union
	{
		float mV[3];
		struct{float mX,mY,mZ;};
	};

	Vector3f():mX(0),mY(0),mZ(0){}
	Vector3f(float x,float y,float z):mX(x),mY(y),mZ(z){}

	Vector3f operator+(const Vector3f& r) const
	{
		return Vector3f(mX+r.mX,mY+r.mY,mZ+r.mZ);
	}
	Vector3f operator-(const Vector3f& r) const
	{
		return Vector3f(mX-r.mX,mY-r.mY,mZ-r.mZ);
	}
	Vector3f operator-() const
	{
		return Vector3f(-mX,-mY,-mZ);
	}
	Vector3f operator+() const
	{
		return *this;
	}
	Vector3f operator*(const float r) const
	{
		return Vector3f(mX*r,mY*r,mZ*r);
	}
	Vector3f operator/(const float r) const
	{
		return Vector3f(mX/r,mY/r,mZ/r);
	}

	float dot(const Vector3f& r) const
	{
		return mX*r.mX+mY*r.mY+mZ*r.mZ;
	}

	Vector3f cross(const Vector3f& r) const
	{
		return Vector3f(mY*r.mZ - mZ*r.mY,
			mZ*r.mX - mX*r.mZ,
			mX*r.mY - mY*r.mX);
	}
	//return the norm(length) of the vector
	float norm() const
	{
		return sqrt(mX*mX+mY*mY+mZ*mZ);
	}

	//return the norm(length) of the vector
	float norm2() const
	{
		return mX*mX+mY*mY+mZ*mZ;
	}

	//calculate a project of v on q direction
	Vector3f proj(const Vector3f& q) const
	{
		float len = dot(q)/q.norm2();
		return len*q;
	}

	//return the normlized version of vector
	Vector3f nomalized() const
	{
		float n2 = mX*mX+mY*mY+mZ*mZ;
		assert( n2 != 0 );
		float n = 1.0f/sqrt(n2);
		return Vector3f(mX*n,mY*n,mZ*n);
	}

	// return the cos(a), a is the angle between this and q
	float cosAngle(const Vector3f& q) const
	{
		return dot(q)/(norm()*q.norm());
	}

	// return the sin(a), a is the angle between this and q
	float sinAngle(const Vector3f& q) const
	{
		return cross(q).norm()/(norm()*q.norm());
	}
};

// vector with 4 floats
class Vector4f
{
public:
	union
	{
		float mV[4];
		struct{float mX,mY,mZ,mW;};
	};

	Vector4f():mX(0),mY(0),mZ(0),mW(1){}
	Vector4f(float x,float y,float z,float w):mX(x),mY(y),mZ(z),mW(w){}

	Vector4f operator+(const Vector4f& r) const
	{
		return Vector4f(mX+r.mX,mY+r.mY,mZ+r.mZ,mW+r.mW);
	}
	Vector4f operator-(const Vector4f& r) const
	{
		return Vector4f(mX-r.mX,mY-r.mY,mZ-r.mZ,mW-r.mW);
	}
	Vector4f operator-() const
	{
		return Vector4f(-mX,-mY,-mZ,-mW);
	}
	Vector4f operator+() const
	{
		return *this;
	}
	Vector4f operator*(const float r) const
	{
		return Vector4f(mX*r,mY*r,mZ*r,mW*r);
	}
	Vector4f operator/(const float r) const
	{
		return Vector4f(mX/r,mY/r,mZ/r,mW/r);
	}
};

inline Vector2f operator*(float left,const Vector2f& v)
{
	return Vector2f(left*v.mX,left*v.mY);
}

inline Vector3f operator*(float left, const Vector3f& v)
{
	return Vector3f(left*v.mX,left*v.mY,left*v.mZ);
}

inline Vector4f operator*(float left,const Vector4f& v)
{
	return Vector4f(left*v.mX,left*v.mY,left*v.mZ,left*v.mW);
}

#endif //_REVECTOR_H_