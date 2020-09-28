//=============================================================================
//
//  SphereCoord.cpp
//
//=============================================================================


//=============================================================================
//  INCLUDES
//=============================================================================
#include "xsystem.h"


//=============================================================================
//  CONSTRUCTION/DESTRUCTION
//=============================================================================
BSphereCoord::BSphereCoord()
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
BSphereCoord::BSphereCoord(float r, float phi, float theta)
{
   mR     = r;
   mPhi   = phi;
   mTheta = theta;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
BSphereCoord::~BSphereCoord()
{
}


//=============================================================================
//  INTERFACE
//=============================================================================
void BSphereCoord::set(float r, float phi, float theta)
{
   mR     = r;
   mPhi   = phi;
   mTheta = theta;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void BSphereCoord::setDegrees(float r, float phi, float theta)
{
   mR     = r;
   mPhi   = DEGREES_TO_RADIANS(phi);
   mTheta = DEGREES_TO_RADIANS(theta);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void BSphereCoord::setVector(const BVector& v)
{
   mR     = (float)sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
   mPhi   = (float)atan2(-v.z, v.x);
   mTheta = (float)atan2((float)sqrt(v.x*v.x + v.z*v.z), v.y);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void BSphereCoord::getVector(BVector& v)
{
   v.x =  (float)(mR * cos(mPhi) * sin(mTheta));
   v.z = -(float)(mR * sin(mPhi) * sin(mTheta));
   v.y =  (float)(mR * cos(mTheta));
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void BSphereCoord::slerp(BSphereCoord& s1, BSphereCoord& s2, float alpha)
{
   //-- Clamp alpha.
   if (alpha < 0.0f) alpha = 0.0f;
   if (alpha > 1.0f) alpha = 1.0f;

   //-- Slerp it.
   mR     = s1.mR     + ((s2.mR     - s1.mR    ) * alpha);
   mPhi   = s1.mPhi   + ((s2.mPhi   - s1.mPhi  ) * alpha);
   mTheta = s1.mTheta + ((s2.mTheta - s1.mTheta) * alpha);
}

