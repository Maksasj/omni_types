/**
 * @file 
 * vector_types.h
 * 
 * @author 
 * Maksim Jaroslavcevas radioboos@gmail.com
 * 
 * @copyright
 * see LICENSE.md file
*/

#ifndef _OMNI_TYPES_VECTOR_TYPES_H_
#define _OMNI_TYPES_VECTOR_TYPES_H_

#include "primitive_types.h"

#include "vector2_type.tpp"
#include "vector3_type.tpp"
#include "vector4_type.tpp"

#ifdef OMNI_TYPES_ENABLE_REFLECTIONS 
    #include "../3dparty/omni_reflector/src/omni_reflector.h"
#endif

namespace omni::types {
    using Vec2f = Vec2<f32>;
    using Vec3f = Vec3<f32>;
    using Vec4f = Vec4<f32>;

    using Vec2i = Vec2<i32>;
    using Vec3i = Vec3<i32>;
    using Vec4i = Vec4<i32>;

}

#ifdef OMNI_TYPES_ENABLE_REFLECTIONS
    OMNI_ADAPT_STRUCTURE_NAME(omni::types, Vec2f, x, y);
    OMNI_ADAPT_STRUCTURE_NAME(omni::types, Vec3f, x, y, z);
    OMNI_ADAPT_STRUCTURE_NAME(omni::types, Vec4f, x, y, z, w);

    OMNI_ADAPT_STRUCTURE_NAME(omni::types, Vec2i, x, y);
    OMNI_ADAPT_STRUCTURE_NAME(omni::types, Vec3i, x, y, z);
    OMNI_ADAPT_STRUCTURE_NAME(omni::types, Vec4i, x, y, z, w);
#endif

#endif
