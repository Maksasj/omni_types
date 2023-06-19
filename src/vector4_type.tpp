/**
 * @file 
 * vector4_type.tpp
 * 
 * @author 
 * Maksim Jaroslavcevas radioboos@gmail.com
 * 
 * @copyright
 * see LICENSE.md file
*/

#ifndef _OMNI_TYPES_VECTOR_4_TYPE_TPP_
#define _OMNI_TYPES_VECTOR_4_TYPE_TPP_

#include "vector3_type.tpp"

#include <ostream>
#include <cmath>

namespace omni::types {
   /**
     * @brief Type that used as 4d geometrical vector
     * 
     * @tparam _T type of the vector
    */
    template<typename _T>
    struct Vec4 {
        /**
         * @brief Raw vector values
        */
        _T x;
        _T y;
        _T z;
        _T w;

        /**
         * @brief Some overoaded operators
        */
        Vec4 operator+(const Vec4& vec) { return Vec4{this->x + vec.x, this->y + vec.y, this->z + vec.z, w + vec.w}; }
        Vec4 operator-(const Vec4& vec) { return Vec4{this->x - vec.x, this->y - vec.y, this->z - vec.z, w - vec.w}; }
        Vec4 operator*(const Vec4& vec) { return Vec4{this->x * vec.x, this->y * vec.y, this->z * vec.z, w * vec.w}; }
        Vec4 operator/(const Vec4& vec) { return Vec4{this->x / vec.x, this->y / vec.y, this->z / vec.z, w / vec.w}; }

        Vec4 operator*(const _T& value) { return Vec4{this->x * value, this->y * value, this->z * value, this->w * value }; }
        Vec4 operator/(const _T& value) { 
            if(value == 0) throw std::overflow_error("Divide by zero exception");

            return Vec4{ this->x / value, this->y / value, this->z / value, this->w / value }; 
        }

        /* Vector x= Vector */
        Vec4<_T>& operator+=(const Vec4<_T>& other) { this->x += other.x; this->y += other.y; this->z += other.z; this->w += other.w; return *this; }
        Vec4<_T>& operator-=(const Vec4<_T>& other) { this->x -= other.x; this->y -= other.y; this->z -= other.z; this->w -= other.w; return *this; }
        Vec4<_T>& operator*=(const Vec4<_T>& other) { this->x *= other.x; this->y *= other.y; this->z *= other.z; this->w *= other.w; return *this; }
        Vec4<_T>& operator/=(const Vec4<_T>& other) { this->x /= other.x; this->y /= other.y; this->z /= other.z; this->w /= other.w; return *this; }

        /* Vector x= arbirary values */
        Vec4<_T>& operator+=(const _T& other) { this->x += other; this->y += other; this->z += other; this->w += other; return *this; }
        Vec4<_T>& operator-=(const _T& other) { this->x -= other; this->y -= other; this->z -= other; this->w -= other; return *this; }
        Vec4<_T>& operator*=(const _T& other) { this->x *= other; this->y *= other; this->z *= other; this->w *= other; return *this; }
        Vec4<_T>& operator/=(const _T& other) { this->x /= other; this->y /= other; this->z /= other; this->w /= other; return *this; }

        bool operator==(const Vec4<_T> other) { return this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w; }
        bool operator!=(const Vec4<_T> other) { return !this == other; }

        /**
         * @brief Puts string representation of the object to the out stream
         * 
         * @param os - reference to the out stream
         * @param vec - reference to the object instance
         * 
         * @return std::ostream& reference to the stream instance 
        */
        friend std::ostream& operator<<(std::ostream& os, const Vec4<_T>& vec) {
            os << vec.x << " " << vec.y << " " << vec.z << " " << vec.w; 
            return os;
        } 

        /**
         * @brief Constructs object from it string representation
         * 
         * @param os - reference to the in stream
         * @param vec - reference to the object instance
         * 
         * @return std::istream& reference to the stream instance 
        */
        friend std::istream& operator>>(std::istream& os, const Vec4<_T>& vec) {
            os >> vec.x >> vec.y >> vec.z >> vec.w;

            return os;
        } 

        /**
         * @brief Method used to get string representation of object instance
         * 
         * @return std::string string representation 
        */
        std::string to_string() const {
            std::stringstream ss;
            ss << this->x << ' ' << this->y << ' ' << this->z << ' ' << w; 
            return ss.str();
        }

        /**
         * @brief Converts all values of the vector to their absolute values
         * 
         * @return Vec2<_T>& reference to vector instance
        */
        Vec4<_T>& abs() {
            if(this->x < 0) this->x = -this->x;
            if(this->y < 0) this->y = -this->y;
            if(this->z < 0) this->z = -this->z;
            if(this->w < 0) this->z = -this->w;
            return *this;
        }

        /**
         * @brief Calculates length of the vector
         * 
         * @return f32 length of the vector
        */
        f32 length() const {
            return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z,  + this->w * this->w);
        }
    };
}

namespace omni::types {
    
}

#endif
