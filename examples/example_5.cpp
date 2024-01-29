#include <iostream>

#include "omni_types.tpp"

int main() {
    using namespace omni::types;

    {
        ColorRGBA32 color{255, 255, 255, 255};
        std::ignore = color;
    }

    {
        ColorRGBA32f color = ColorRGBA32f::CYAN;
        std::ignore = color;
    }

    return 0;
}