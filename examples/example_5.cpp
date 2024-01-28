#include <iostream>

#include "omni_types.tpp"

int main() {
    using namespace omni::types;

    Color<R8G8B8A8> color{255, 255, 255, 255};

    color.a = 0;

    std::ignore = color;

    return 0;
}