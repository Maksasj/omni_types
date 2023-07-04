/**
 * @file 
 * uuid.tpp
 * 
 * @author 
 * Maksim Jaroslavcevas radioboos@gmail.com
 * 
 * @copyright
 * see LICENSE.md file
*/

#ifndef _OMNI_TYPES_UUID_TYPE_TPP_
#define _OMNI_TYPES_UUID_TYPE_TPP_

#include "primitive_types.h"

#include <iomanip>
#include <ostream>
#include <random>
#include <cmath>

namespace omni::types {
    class UUID {
        private:
            u64 _data[2];
        
            UUID(const u64& data1, const u64& data2);

        public:
            friend class UUIDGenerator;

            UUID();

            std::string to_string() const;
    };

    struct UUIDGenerator {
        static UUID generate_uuid();
    };
}

namespace omni::types {
    UUID::UUID(const u64& data1, const u64& data2) {
        _data[0] = data1;
        _data[1] = data2;
    }

    UUID::UUID() {
        *this = UUID(0, 0);
    }

    std::string UUID::to_string() const {
        std::stringstream ss;
        ss << std::hex << std::setfill('0') << std::setw(16) << _data[0];
        ss << std::hex << std::setfill('0') << std::setw(16) << _data[1];

        std::string tmp = ss.str();
        tmp.insert(8, "-");
        tmp.insert(13, "-");
        tmp.insert(18, "-");
        tmp.insert(23, "-");

        return tmp;
    }

    UUID UUIDGenerator::generate_uuid() {
        static std::random_device rd;
        static std::mt19937_64 gen(rd());

        static std::uniform_int_distribution<u64> dist(0ULL, std::numeric_limits<u64>::max());

        return UUID(dist(gen), dist(gen));
    }
}

#endif
