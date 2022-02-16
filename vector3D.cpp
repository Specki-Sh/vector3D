#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<vector>

using namespace std;

struct Point3D
{
  float abscissa = 0;
  float ordinate = 0;
  float applicate = 0;
};

class Vector3D
{
private:
  static Point3D point;
public:
    Vector3D (float x, float y, float z)
  {
    this->point.abscissa = x;
    this->point.ordinate = y;
    this->point.applicate = z;
  }

  Vector3D (Point3D p)
  {
    this->point = p;
  }

  float length () const
  {
    return sqrt (pow (point.abscissa, 2) +
		 pow (point.ordinate, 2) + 
		 pow (point.applicate, 2));
  }

  float scalarProduct (const Vector3D & v) const
  {
    return this->point.abscissa * v.point.abscissa +
      this->point.ordinate * v.point.ordinate +
      this->point.applicate * v.point.applicate;
  }

  Vector3D crossProduct (const Vector3D & v) const
  {
    Point3D p;
      p.abscissa = this->point.ordinate * v.point.applicate -
                   this->point.applicate * v.point.applicate;
      p.ordinate = this->point.applicate * v.point.abscissa -
                   this->point.abscissa * v.point.applicate;
      p.applicate = this->point.abscissa * v.point.ordinate -
                    this->point.ordinate * v.point.abscissa;
      return Vector3D (p);
  }

  float angel (const Vector3D & v) const
  {
    return this->scalarProduct (v) / (this->length () + v.length ());
  }

  Vector3D sum (const Vector3D & v) const
  {
    Point3D p;
    p.abscissa = this->point.abscissa + v.point.abscissa;
    p.ordinate = this->point.ordinate + v.point.ordinate;
    p.applicate = this->point.applicate + v.point.applicate;
    return Vector3D (p);
  }

  Vector3D difference (const Vector3D & v) const
  {
    Point3D p;
    p.abscissa = this->point.abscissa - v.point.abscissa;
    p.ordinate = this->point.ordinate - v.point.ordinate;
    p.applicate = this->point.applicate - v.point.applicate;
    return Vector3D (p);
  }

  static vector < Vector3D > generate (int n)
  {
    vector < Vector3D > v;
    for (int i = 0; i < n; i++)
      {
	v.emplace_back (Vector3D (rand (), rand (), rand ()));
      }
    return v;
  }
};

