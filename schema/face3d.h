#pragma once

#include "../includes.h"

namespace libredwg2 {

class Vertex3d
{
  private:
    double position_[3];

  public:
    Vertex3d()
    {
      position_[0] = 0.;
      position_[1] = 0.;
      position_[2] = 0.;
    }

    Vertex3d(double x, double y, double z)
    {
      position_[0] = x;
      position_[1] = y;
      position_[2] = z;
    }
};

class Face3d
{
  ////////////////////////////////////////////////////////////////
  // Definitions
  ////////////////////////////////////////////////////////////////
  public:

  ////////////////////////////////////////////////////////////////
  // Members
  ////////////////////////////////////////////////////////////////
  private:
    Vertex3d apex_[4];

  ////////////////////////////////////////////////////////////////
  // Constructors & Destructor
  ////////////////////////////////////////////////////////////////
  public:
    Face3d(const Vertex3d& c1, const Vertex3d& c2, const Vertex3d& c3, const Vertex3d& c4)
    {
      apex_[0] = c1;
      apex_[1] = c2;
      apex_[2] = c3;
      apex_[3] = c4;
    }

  ////////////////////////////////////////////////////////////////
  // Operators
  ////////////////////////////////////////////////////////////////
  private:

  ////////////////////////////////////////////////////////////////
  // Functions
  ////////////////////////////////////////////////////////////////
  public:

};

////////////////////////////////////////////////////////////////

}
