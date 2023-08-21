#include "test_shared.h"

int main() {
    using namespace omni::types;

    TEST_CASE {
        Mat4f a = {{5, 2, 6, 1, 0, 6, 2, 0, 3, 8, 1, 4, 1, 8, 5, 6}};
        Mat4f b = {{7, 5, 8, 0, 1, 8, 2, 6, 9, 4, 3, 8, 5, 3, 7, 9}};

        Mat4f c = {{96, 68, 69, 69, 24, 56, 18, 52, 58, 95, 71, 92, 90, 107, 81, 142}};

        ensure((a * b) == c);
    }

    return 0;
}

