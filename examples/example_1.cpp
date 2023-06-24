#include <iostream>

#define OMNI_TYPES_ENABLE_REFLECTIONS
#include "omni_types.tpp"

int main() {
    using namespace omni::types;

    std::cout << omni::reflector::Reflection<Vec2f>::clearTypeName << "\n";
    std::cout << omni::reflector::Reflection<Vec3f>::clearTypeName << "\n";
    std::cout << omni::reflector::Reflection<Vec4f>::clearTypeName << "\n";

    return 0;
}