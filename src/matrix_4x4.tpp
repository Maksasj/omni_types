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

#include "matrix.tpp"

namespace omni::types {
    template<>
    struct Matrix<f32, 4, 4> {
        f32 e[4 * 4];

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
