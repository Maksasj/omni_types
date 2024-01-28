/**
 * @file
 * color_r8g8b8.tpp
 *
 * @author
 * Maksim Jaroslavcevas radioboos@gmail.com
 *
 * @copyright
 * see LICENSE.md file
*/

#ifndef _OMNI_TYPES_COLOR_R8G8B8_TPP_
#define _OMNI_TYPES_COLOR_R8G8B8_TPP_

#include "color.tpp"
#include "color_format.h"

namespace omni::types {
    template<>
    struct Color<R8G8B8> {
        u8 r, g, b;
    };
}

#endif
