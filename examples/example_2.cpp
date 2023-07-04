#include <iostream>

#define OMNI_TYPES_ENABLE_REFLECTIONS
#include "omni_types.tpp"

int main() {
    using namespace omni::types;

    UUID uuid = UUIDGenerator::generate_uuid();

    std::cout << uuid.to_string() << "\n";

    return 0;
}