#include <iostream>

#define OMNI_TYPES_ENABLE_REFLECTIONS
#include "omni_types.tpp"

int main() {
    using namespace omni::types;

    Vec2f a = Vec2f::splat(0.0f);
    Vec2f b = Vec2f::splat(1.0f);

    std::cout << (a != b) << "\n";

    return 0;
}