/**
 * @file 
 * matrix_4x4.tpp
 * 
 * @author 
 * Maksim Jaroslavcevas radioboos@gmail.com
 * 
 * @copyright
 * see LICENSE.md file
*/

#ifndef _OMNI_TYPES_MATRIX_4X4_TPP_
#define _OMNI_TYPES_MATRIX_4X4_TPP_

#include <cmath>

#include "matrix.tpp"

namespace omni::types {
    template<>
    struct Matrix<f32, 4, 4> {
        f32 e[4 * 4];

        inline static Matrix<f32, 4, 4> splat(const f32& value) {
            return {{value, value, value, value, value, value, value, value, value, value, value, value, value, value, value, value}};
        }

        inline static Matrix<f32, 4, 4> identity() {
            auto matrix = Matrix<f32, 4, 4>::splat(0.0f);
            
            matrix.e[0] = 1.0f;
            matrix.e[5] = 1.0f;
            matrix.e[10] = 1.0f;
            matrix.e[15] = 1.0f;

            return matrix;
        }

        inline static Matrix<f32, 4, 4> translation(const Vec3<f32>& vector) {
            auto matrix = identity();

            matrix.e[3] = vector.x;
            matrix.e[7] = vector.y;
            matrix.e[11] = vector.z;

            return matrix;
        }

        inline static Matrix<f32, 4, 4> scale(const f32& rate) {
            auto matrix = identity();

            matrix.e[0] = rate;
            matrix.e[5] = rate;
            matrix.e[10] = rate;

            return matrix;
        }

        inline static Matrix<f32, 4, 4> perspective(const f32& fov, const f32& aspect, const f32& near, const f32& far) {
            auto matrix = Matrix<f32, 4, 4>::splat(0.0f);

            const f32 tanFovHalf = std::tanf(fov / 2.0f);

            matrix.e[0] = 1.0f / (aspect * tanFovHalf);
            matrix.e[5] = 1.0f / tanFovHalf;
            matrix.e[10] = - ((far + near) / (far - near));
            matrix.e[15] = - ((2.0f * far * near) / (far - near));

            matrix.e[14] = -1.0f;

            return matrix;
        }

        inline f32& operator()(const size_t& row, const size_t& col) {
            return e[4 * row + col];
        }

        inline const f32& operator()(const size_t& row, const size_t& col) const {
            return e[4 * row + col];
        }

        inline std::string to_string() const {
            std::stringstream ss;

            for(i32 i = 0; i < 16; ++i)
                ss << e[i] << " ";
            
            return ss.str();
        }

        // Todo optimse, or use something like simd
        inline Matrix<f32, 4, 4> operator*(const Matrix<f32, 4, 4>& b) const {
            return {{ 
                e[0]    * b.e[0] + e[1]     * b.e[4] + e[2]     * b.e[8]        + e[3]  * b.e[12], 
                e[0]    * b.e[1] + e[1]     * b.e[5] + e[2]     * b.e[9]        + e[3]  * b.e[13], 
                e[0]    * b.e[2] + e[1]     * b.e[6] + e[2]     * b.e[10]       + e[3]  * b.e[14], 
                e[0]    * b.e[3] + e[1]     * b.e[7] + e[2]     * b.e[11]       + e[3]  * b.e[15], 
                e[4]    * b.e[0] + e[5]     * b.e[4] + e[6]     * b.e[8]        + e[7]  * b.e[12], 
                e[4]    * b.e[1] + e[5]     * b.e[5] + e[6]     * b.e[9]        + e[7]  * b.e[13], 
                e[4]    * b.e[2] + e[5]     * b.e[6] + e[6]     * b.e[10]       + e[7]  * b.e[14], 
                e[4]    * b.e[3] + e[5]     * b.e[7] + e[6]     * b.e[11]       + e[7]  * b.e[15], 
                e[8]    * b.e[0] + e[9]     * b.e[4] + e[10]    * b.e[8]        + e[11] * b.e[12], 
                e[8]    * b.e[1] + e[9]     * b.e[5] + e[10]    * b.e[9]        + e[11] * b.e[13], 
                e[8]    * b.e[2] + e[9]     * b.e[6] + e[10]    * b.e[10]       + e[11] * b.e[14], 
                e[8]    * b.e[3] + e[9]     * b.e[7] + e[10]    * b.e[11]       + e[11] * b.e[15], 
                e[12]   * b.e[0] + e[13]    * b.e[4] + e[14]    * b.e[8]        + e[15] * b.e[12], 
                e[12]   * b.e[1] + e[13]    * b.e[5] + e[14]    * b.e[9]        + e[15] * b.e[13], 
                e[12]   * b.e[2] + e[13]    * b.e[6] + e[14]    * b.e[10]       + e[15] * b.e[14], 
                e[12]   * b.e[3] + e[13]    * b.e[7] + e[14]    * b.e[11]       + e[15] * b.e[15]
            }};
        }

        inline bool operator==(const Matrix<f32, 4, 4>& other) const {
            for(size_t i = 0; i < 16; ++i) {
                if(e[i] != other.e[i]) {
                    return false;
                }
            }

            return true;
        }
    };
}

#endif
