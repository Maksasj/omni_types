/**
 * @file
 * color_rgba32f.tpp
 *
 * @author
 * Maksim Jaroslavcevas radioboos@gmail.com
 *
 * @copyright
 * see LICENSE.md file
*/

#ifndef _OMNI_TYPES_COLOR_R32G32B32A32_FLOAT_TPP_
#define _OMNI_TYPES_COLOR_R32G32B32A32_FLOAT_TPP_

#include "color.tpp"
#include "color_format.h"

namespace omni::types {
    template<>
    struct Color<R32G32B32A32_FLOAT> {
        f32 r, g, b, a;
        
        static const Color<R32G32B32A32_FLOAT> BLACK;
        static const Color<R32G32B32A32_FLOAT> WHITE;
        static const Color<R32G32B32A32_FLOAT> RED;
        static const Color<R32G32B32A32_FLOAT> BLUE;
        static const Color<R32G32B32A32_FLOAT> GREEN;
        static const Color<R32G32B32A32_FLOAT> YELLOW;
        static const Color<R32G32B32A32_FLOAT> MAGENTA;
        static const Color<R32G32B32A32_FLOAT> CYAN;
    };
}

namespace omni::types {
    const Color<R32G32B32A32_FLOAT> Color<R32G32B32A32_FLOAT>::BLACK{0.0f, 0.0f, 0.0f, 1.0f};
    const Color<R32G32B32A32_FLOAT> Color<R32G32B32A32_FLOAT>::WHITE{1.0f, 1.0f, 1.0f, 1.0f};
    const Color<R32G32B32A32_FLOAT> Color<R32G32B32A32_FLOAT>::RED{1.0f, 0.0f, 0.0f, 1.0f};
    const Color<R32G32B32A32_FLOAT> Color<R32G32B32A32_FLOAT>::BLUE{0.0f, 0.0f, 1.0f, 1.0f};
    const Color<R32G32B32A32_FLOAT> Color<R32G32B32A32_FLOAT>::GREEN{0.0f, 1.0f, 0.0f, 1.0f};
    const Color<R32G32B32A32_FLOAT> Color<R32G32B32A32_FLOAT>::YELLOW{1.0f, 1.0f, 0.0f, 1.0f};
    const Color<R32G32B32A32_FLOAT> Color<R32G32B32A32_FLOAT>::MAGENTA{1.0f, 0.0f, 1.0f, 1.0f};
    const Color<R32G32B32A32_FLOAT> Color<R32G32B32A32_FLOAT>::CYAN{0.0f, 1.0f, 1.0f, 1.0f};
}
#endif
