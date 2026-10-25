#ifndef TRANSFORM2D_HPP_6A31CA41_7EDF_4BBD_BE8D_02F8ECD4A79D
#define TRANSFORM2D_HPP_6A31CA41_7EDF_4BBD_BE8D_02F8ECD4A79D

#include "stdtypes.hpp"

// For simplicity, these are defined only for Mat22f, i.e., the 2x2 float
// matrix type.
inline 
Mat22f make_scaling_2d( float aX, float aY ) noexcept
{
	Mat22f ret{};
	ret[0,0] = aX;
	ret[1,1] = aY;

	return ret; //TODO: implement me
}
inline 
Mat22f make_scaling_2d( float aUniform ) noexcept
{
	Mat22f ret{};
	ret[0,0] = aUniform;
	ret[1,1] = aUniform;

	return ret; //TODO: implement me
}

inline
Mat22f make_rotation_2d( float aAngleInRadians ) noexcept
{
	Mat22f ret{};
	float c = std::cos(aAngleInRadians);
	float s = std::sin(aAngleInRadians);
	ret[0,0] = c;
	ret[0,1] = -s;
	ret[1,0] = s;
	ret[1,1] = c;

	return ret; //TODO: implement me
}

#endif // TRANSFORM2D_HPP_6A31CA41_7EDF_4BBD_BE8D_02F8ECD4A79D
