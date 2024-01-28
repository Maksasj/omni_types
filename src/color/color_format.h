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
        R8G8B8,
        R8G8B8A8,

        RGB24 = R8G8B8,
        RGBA32 = R8G8B8A8
    };
}

#endif
