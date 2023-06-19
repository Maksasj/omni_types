/**
 * @file 
 * interpolation.tpp
 * 
 * @author 
 * Maksim Jaroslavcevas radioboos@gmail.com
 * 
 * @copyright
 * see LICENSE.md file
*/

#ifndef _OMNI_TYPES_MATRIX_TPP_
#define _OMNI_TYPES_MATRIX_TPP_

#include <ostream>
#include <sstream>
#include <cmath>

#include "primitive_types.h"

namespace omni::types {
    /**
     * @brief Type that used as mathematical matrix
     * 
     * @tparam _T type of the matrix
     * @tparam _width width of the matrix
     * @tparam _heigth height of the matrix
    */
    template<typename _T, u32 _width, u32 _heigth>
    struct Matrix {
        /**
         * @brief Raw matrix values
        */
        _T e[_width * _heigth];

        /**
         * @brief Static method that returns rotation matrix by angle
         * 
         * @param rotationAngle rotation angle
         * @return Matrix<f32, 2, 2> new matrix instance 
        */
        static Matrix<f32, 2, 2> get_rotation_matrix(const f32 &rotationAngle) {
            return {{(f32)cos(rotationAngle), -(f32)sin(rotationAngle), (f32)sin(rotationAngle), (f32)cos(rotationAngle)}};
        }

        /**
         * @brief Static method that returns zero rotation matrix by angle
         * 
         * @return Matrix<f32, 2, 2> new matrix instance 
        */
        static Matrix<f32, 2, 2> get_zero_rotation_matrix() {
            return {{ 1, 0, 0, 1 }};
        }

        /**
         * @brief Puts string representation of the object to the out stream
         * 
         * @param os - reference to the out stream
         * @param mat - reference to the object instance
         * 
         * @return std::ostream& reference to the stream instance 
        */
        friend std::ostream& operator<<(std::ostream& os, const Matrix<_T, _width, _heigth>& mat) {
            for(i32 i = 0; i < _width * _heigth; ++i)
                os << mat.e[i] << " ";

            return os;
        } 

        /**
         * @brief Constructs object from it string representation
         * 
         * @param os - reference to the in stream
         * @param mat - reference to the object instance
         * 
         * @return std::istream& reference to the stream instance 
        */
        friend std::istream& operator>>(std::istream& os, const Matrix<_T, _width, _heigth>& mat) {
            for(i32 i = 0; i < _width * _heigth; ++i)
                os >> mat.e[i];

            return os;
        } 

        /**
         * @brief Method used to get string representation of object instance
         * 
         * @return std::string string representation 
        */
        std::string to_string() const {
            std::stringstream ss;

            for(i32 i = 0; i < _width * _heigth; ++i)
                ss << e[i] << " ";
            
            return ss.str();
        }
    };
}

#endif
