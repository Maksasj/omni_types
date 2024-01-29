/**
 * @file
 * color_format.h
 *
 * @author
 * Maksim Jaroslavcevas radioboos@gmail.com
 *
 * @copyright
 * see LICENSE.md file
*/

#ifndef _OMNI_TYPES_COLOR_FORMAT_H_
#define _OMNI_TYPES_COLOR_FORMAT_H_

namespace omni::types {
    enum ColorFormat {
        R8G8B8_UINT,
        R8G8B8A8_UINT,

        R32G32B32A32_FLOAT,

        RGB24 = R8G8B8_UINT,
        RGBA32 = R8G8B8A8_UINT,
        RGBA32f = R32G32B32A32_FLOAT
    };
}

#endif
