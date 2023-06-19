/**
 * @file 
 * vector3_type.tpp
 * 
 * @author 
 * Maksim Jaroslavcevas radioboos@gmail.com
 * 
 * @copyright
 * see LICENSE.md file
*/

#ifndef _OMNI_TYPES_VECTOR_3_TYPE_TPP_
#define _OMNI_TYPES_VECTOR_3_TYPE_TPP_

#include "vector2_type.tpp"

#include <ostream>
#include <cmath>

namespace omni::types {
    /**
     * @brief Type that used as 3d geometrical vector
     * 
     * @tparam _T type of the vector
    */
    template<typename _T>
    struct Vec3 {
        /** @brief Raw vector values */
        _T x;
        _T y;
        _T z;

        /** @brief Some overoaded operators */
        Vec3 operator+(const Vec3& vec) const;
        Vec3 operator-(const Vec3& vec) const;
        Vec3 operator*(const Vec3& vec) const;
        Vec3 operator/(const Vec3& vec) const;

        Vec3 operator*(const _T& value) const;
        Vec3 operator/(const _T& value) const;

        /* Vector x= Vector */
        Vec3<_T>& operator+=(const Vec3<_T>& other);
        Vec3<_T>& operator-=(const Vec3<_T>& other);
        Vec3<_T>& operator*=(const Vec3<_T>& other);
        Vec3<_T>& operator/=(const Vec3<_T>& other);
        
        /* Vector x= arbirary values */
        Vec3<_T>& operator+=(const _T& other);
        Vec3<_T>& operator-=(const _T& other);
        Vec3<_T>& operator*=(const _T& other);
        Vec3<_T>& operator/=(const _T& other);

        operator Vec2<_T>() const;

        bool operator==(const Vec3<_T> other);
        bool operator!=(const Vec3<_T> other);

        std::string to_string() const;

        Vec3<_T>& abs();
        _T length() const;
    };
}

namespace omni::types {
    template<typename _T>
    Vec3<_T> Vec3<_T>::operator+(const Vec3& vec) const { return Vec3{this->x + vec.x, this->y + vec.y, z + vec.z}; }
    
    template<typename _T>
    Vec3<_T> Vec3<_T>::operator-(const Vec3& vec) const { return Vec3{this->x - vec.x, this->y - vec.y, z - vec.z}; }
    
    template<typename _T>
    Vec3<_T> Vec3<_T>::operator*(const Vec3& vec) const { return Vec3{this->x * vec.x, this->y * vec.y, z * vec.z}; }
    
    template<typename _T>
    Vec3<_T> Vec3<_T>::operator/(const Vec3& vec) const { return Vec3{this->x / vec.x, this->y / vec.y, z / vec.z}; }

    template<typename _T>
    Vec3<_T> Vec3<_T>::operator*(const _T& value) const { return Vec3{this->x * value, this->y * value, this->z * value }; }
    
    template<typename _T>
    Vec3<_T> Vec3<_T>::operator/(const _T& value) const { 
        if(value == 0) throw std::overflow_error("Divide by zero exception");

        return Vec3{this->x / value, this->y / value, this->z / value }; 
    }

    /* Vector x= Vector */
    template<typename _T>
    Vec3<_T>& Vec3<_T>::operator+=(const Vec3<_T>& other) { this->x += other.x; this->y += other.y; this->z += other.z; return *this; }
    
    template<typename _T>
    Vec3<_T>& Vec3<_T>::operator-=(const Vec3<_T>& other) { this->x -= other.x; this->y -= other.y; this->z -= other.z; return *this; }
    
    template<typename _T>
    Vec3<_T>& Vec3<_T>::operator*=(const Vec3<_T>& other) { this->x *= other.x; this->y *= other.y; this->z *= other.z; return *this; }
    
    template<typename _T>
    Vec3<_T>& Vec3<_T>::operator/=(const Vec3<_T>& other) { this->x /= other.x; this->y /= other.y; this->z /= other.z; return *this; }
    
    /* Vector x= arbirary values */
    template<typename _T>
    Vec3<_T>& Vec3<_T>::operator+=(const _T& other) { this->x += other; this->y += other; this->z += other; return *this; }
    
    template<typename _T>
    Vec3<_T>& Vec3<_T>::operator-=(const _T& other) { this->x -= other; this->y -= other; this->z -= other; return *this; }
    
    template<typename _T>
    Vec3<_T>& Vec3<_T>::operator*=(const _T& other) { this->x *= other; this->y *= other; this->z *= other; return *this; }
    
    template<typename _T>
    Vec3<_T>& Vec3<_T>::operator/=(const _T& other) { this->x /= other; this->y /= other; this->z /= other; return *this; }

    template<typename _T>
    Vec3<_T>::operator Vec2<_T>() const { return Vec2<_T>{this->x, this->y}; }

    template<typename _T>
    bool Vec3<_T>::operator==(const Vec3<_T> other) { return this->x == other.x && this->y == other.y && this->z == other.z; }
    
    template<typename _T>
    bool Vec3<_T>::operator!=(const Vec3<_T> other) { return !this == other; }

    /**
     * @brief Puts string representation of the object to the out stream
     * 
     * @param os - reference to the out stream
     * @param vec - reference to the object instance
     * 
     * @return std::ostream& reference to the stream instance 
    */
    template<typename _T>
    std::ostream& operator<<(std::ostream& os, const Vec3<_T>& vec) {
        os << vec.x << " " << vec.y << " " << vec.z;
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
    template<typename _T>
    std::istream& operator>>(std::istream& os, const Vec3<_T>& vec) {
        os >> vec.x >> vec.y >> vec.z;

        return os;
    } 

    /**
     * @brief Method used to get string representation of object instance
     * 
     * @return std::string string representation 
    */
    template<typename _T>
    std::string Vec3<_T>::to_string() const {
        std::stringstream ss;
        ss << this->x << ' ' << this->y << ' ' << z;
        return ss.str();
    }

    /**
     * @brief Converts all values of the vector to their absolute values
     * 
     * @return Vec2<_T>& reference to vector instance
    */
    template<typename _T>
    Vec3<_T>& Vec3<_T>::abs() {
        if(this->x < 0) this->x = -this->x;
        if(this->y < 0) this->y = -this->y;
        if(this->z < 0) this->z = -this->z;
        return *this;
    }

    /**
     * @brief Calculates length of the vector
     * 
     * @return f32 length of the vector
    */
    template<typename _T>
    _T Vec3<_T>::length() const {
        return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
    }
}

#endif
