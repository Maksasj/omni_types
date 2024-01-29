/**
 * @file
 * color_r8g8b8a8.tpp
 *
 * @author
 * Maksim Jaroslavcevas radioboos@gmail.com
 *
 * @copyright
 * see LICENSE.md file
*/

#ifndef _OMNI_TYPES_COLOR_R8G8B8A8_UINT_TPP_
#define _OMNI_TYPES_COLOR_R8G8B8A8_UINT_TPP_

#include "color.tpp"
#include "color_format.h"

namespace omni::types {
    template<>
    struct Color<R8G8B8A8_UINT> {
        u8 r, g, b, a;

        static const Color<R8G8B8A8_UINT> BLACK;
        static const Color<R8G8B8A8_UINT> WHITE;
        static const Color<R8G8B8A8_UINT> RED;
        static const Color<R8G8B8A8_UINT> BLUE;
        static const Color<R8G8B8A8_UINT> GREEN;
        static const Color<R8G8B8A8_UINT> YELLOW;
        static const Color<R8G8B8A8_UINT> MAGENTA;
        static const Color<R8G8B8A8_UINT> CYAN;
    };
}

namespace omni::types {
    const Color<R8G8B8A8_UINT> Color<R8G8B8A8_UINT>::BLACK{0, 0, 0, 255};
    const Color<R8G8B8A8_UINT> Color<R8G8B8A8_UINT>::WHITE{255, 255, 255, 255};
    const Color<R8G8B8A8_UINT> Color<R8G8B8A8_UINT>::RED{255, 0, 0, 255};
    const Color<R8G8B8A8_UINT> Color<R8G8B8A8_UINT>::BLUE{0, 0, 255, 255};
    const Color<R8G8B8A8_UINT> Color<R8G8B8A8_UINT>::GREEN{0, 255, 0, 255};
    const Color<R8G8B8A8_UINT> Color<R8G8B8A8_UINT>::YELLOW{255, 255, 0, 255};
    const Color<R8G8B8A8_UINT> Color<R8G8B8A8_UINT>::MAGENTA{255, 0, 255, 255};
    const Color<R8G8B8A8_UINT> Color<R8G8B8A8_UINT>::CYAN{0, 255, 255, 255};
}

#endif
