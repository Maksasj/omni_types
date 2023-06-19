/**
 * @file 
 * vector2_type.tpp
 * 
 * @author 
 * Maksim Jaroslavcevas radioboos@gmail.com
 * 
 * @copyright
 * see LICENSE.md file
*/

#ifndef _OMNI_TYPES_VECTOR_2_TYPE_TPP_
#define _OMNI_TYPES_VECTOR_2_TYPE_TPP_

#include "primitive_types.h"

#include <ostream>
#include <cmath>

namespace omni::types {
    /**
     * @brief Type that used as 2d geometrical vector
     * 
     * @tparam _T type of the vector
    */
    template<typename _T>
    struct Vec2 {
        /** @brief Raw vector values */
        _T x;
        _T y;

        Vec2() {}
        Vec2(const _T& _x, const _T& _y) : x(_x), y(_y) {}

        static Vec2<_T> splat(const _T& value) {
            return Vec2(value, value);
        }

        /** @brief Some overoaded operators */
        Vec2 operator+(const Vec2& vec);
        Vec2 operator-(const Vec2& vec);

        Vec2 operator*(const _T& value) const;
        Vec2 operator/(const _T& value) const;

        /* Vector x= Vector */
        Vec2<_T>& operator+=(const Vec2<_T>& other);
        Vec2<_T>& operator-=(const Vec2<_T>& other);
        Vec2<_T>& operator*=(const Vec2<_T>& other);
        Vec2<_T>& operator/=(const Vec2<_T>& other);

        /* Vector x= arbirary values */
        Vec2<_T>& operator+=(const _T& other);
        Vec2<_T>& operator-=(const _T& other);
        Vec2<_T>& operator*=(const _T& other);
        Vec2<_T>& operator/=(const _T& other);

        bool operator==(const Vec2<_T> other);
        bool operator!=(const Vec2<_T> other);

        std::string to_string() const;

        Vec2<_T>& abs();
        _T length() const;
    };
}

namespace omni::types {
    template<typename _T>
    Vec2<_T> Vec2<_T>::operator+(const Vec2& vec) { return Vec2{x + vec.x, y + vec.y }; }

    template<typename _T>
    Vec2<_T> Vec2<_T>::operator-(const Vec2& vec) { return Vec2{x - vec.x, y - vec.y }; }

    template<typename _T>
    Vec2<_T> Vec2<_T>::operator*(const _T& value) const { return Vec2{x * value, y * value }; }
    
    template<typename _T>
    Vec2<_T> Vec2<_T>::operator/(const _T& value) const {
        if(value == 0) throw std::overflow_error("Divide by zero exception");

        return Vec2{x / value, y / value }; 
    }

    /* Vector x= Vector */
    template<typename _T>
    Vec2<_T>& Vec2<_T>::operator+=(const Vec2<_T>& other) { this->x += other.x; this->y += other.y; return *this; }

    template<typename _T>
    Vec2<_T>& Vec2<_T>::operator-=(const Vec2<_T>& other) { this->x -= other.x; this->y -= other.y; return *this; }
    
    template<typename _T>
    Vec2<_T>& Vec2<_T>::operator*=(const Vec2<_T>& other) { this->x *= other.x; this->y *= other.y; return *this; }
    
    template<typename _T>
    Vec2<_T>& Vec2<_T>::operator/=(const Vec2<_T>& other) { this->x /= other.x; this->y /= other.y; return *this; }

    /* Vector x= arbirary values */
    template<typename _T>
    Vec2<_T>& Vec2<_T>::operator+=(const _T& other) { this->x += other; this->y += other; return *this; }
    
    template<typename _T>
    Vec2<_T>& Vec2<_T>::operator-=(const _T& other) { this->x -= other; this->y -= other; return *this; }
    
    template<typename _T>
    Vec2<_T>& Vec2<_T>::operator*=(const _T& other) { this->x *= other; this->y *= other; return *this; }
    
    template<typename _T>
    Vec2<_T>& Vec2<_T>::operator/=(const _T& other) { this->x /= other; this->y /= other; return *this; }

    template<typename _T>
    bool Vec2<_T>::operator==(const Vec2<_T> other) { return this->x == other.x && this->y == other.y; }
    
    template<typename _T>
    bool Vec2<_T>::operator!=(const Vec2<_T> other) { return !this == other; }

    template<typename _T>
    std::ostream& operator<<(std::ostream& os, const Vec2<_T>& vec) {
        os << vec.x << " " << vec.y;
        return os;
    }

    template<typename _T>
    std::istream& operator>>(std::istream& os, const Vec2<_T>& vec) {
        os >> vec.x >> vec.y;
        return os;
    } 

    /**
     * @brief Method used to get string representation of object instance
     * 
     * @return std::string string representation 
    */
    template<typename _T>
    std::string Vec2<_T>::to_string() const {
        std::stringstream ss;
        ss << x << ' ' << y;
        return ss.str();
    }

    /**
     * @brief Converts all values of the vector to their absolute values
     * 
     * @return Vec2<_T>& reference to vector instance
    */
    template<typename _T>
    Vec2<_T>& Vec2<_T>::Vec2::abs() {
        if(this->x < 0) this->x = -this->x;
        if(this->y < 0) this->y = -this->y;
        return *this;
    }

    /**
     * @brief Calculates length of the vector
     * 
     * @return _T length of the vector
    */
    template<typename _T>
    _T Vec2<_T>::length() const {
        return sqrtf(this->x * this->x + this->y * this->y);
    }
}

#endif
