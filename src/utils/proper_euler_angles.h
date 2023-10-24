/**
 * @file 
 * proper_euler_angles.h
 * 
 * @author 
 * Maksim Jaroslavcevas radioboos@gmail.com
 * 
 * @copyright
 * see LICENSE.md file
*/

#ifndef _OMNI_TYPES_PROPER_EULER_ANGLES_
#define _OMNI_TYPES_PROPER_EULER_ANGLES_

#include "../matrix/matrix_4x4.tpp"

namespace omni::types {
    static inline Matrix<f32, 4, 4> proper_euler_angle_xzx(const Vec3f& rotation);

    static inline Matrix<f32, 4, 4> proper_euler_angle_xyx(const Vec3f& rotation);

    static inline Matrix<f32, 4, 4> proper_euler_angle_yxy(const Vec3f& rotation);

    static inline Matrix<f32, 4, 4> proper_euler_angle_yzy(const Vec3f& rotation);

    static inline Matrix<f32, 4, 4> proper_euler_angle_zyz(const Vec3f& rotation);

    static inline Matrix<f32, 4, 4> proper_euler_angle_zxz(const Vec3f& rotation);
}

#endif
