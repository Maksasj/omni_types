/**
 * @file 
 * trait_bryan_angles.h
 * 
 * @author 
 * Maksim Jaroslavcevas radioboos@gmail.com
 * 
 * @copyright
 * see LICENSE.md file
*/

#ifndef _OMNI_TYPES_TRAIT_BRYAN_ANGLES_
#define _OMNI_TYPES_TRAIT_BRYAN_ANGLES_

#include "../matrix/matrix_4x4.tpp"

namespace omni::types {
    static Matrix<f32, 4, 4> trait_bryan_angle_xzy(const Vec3f& rotation);
    static Matrix<f32, 4, 4> trait_bryan_angle_xyz(const Vec3f& rotation);
    static Matrix<f32, 4, 4> trait_bryan_angle_yxz(const Vec3f& rotation);
    static Matrix<f32, 4, 4> trait_bryan_angle_yzx(const Vec3f& rotation);
    static Matrix<f32, 4, 4> trait_bryan_angle_zyx(const Vec3f& rotation);
    static Matrix<f32, 4, 4> trait_bryan_angle_zxy(const Vec3f& rotation);
}

#endif
