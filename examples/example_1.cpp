#include <iostream>

#define OMNI_TYPES_ENABLE_REFLECTIONS
#include "omni_types.tpp"

int main() {
    using namespace omni::types;

    Vec2f vec = Vec2f::splat(0.0f);

    std::cout << vec << "\n";

    return 0;
}