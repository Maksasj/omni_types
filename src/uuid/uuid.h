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

#ifndef _OMNI_TYPES_UUID_TYPE_H_
#define _OMNI_TYPES_UUID_TYPE_H_

#include "../primitive_types.h"

#include <sstream>
#include <string>
#include <iomanip>
#include <random>
#include <cmath>

namespace omni::types {
    class UUID {
        private:
            u64 _data[2];
        
            UUID(const u64& data1, const u64& data2) {
                _data[0] = data1;
                _data[1] = data2;
            }

        public:
            UUID() {
                *this = UUID(0, 0);
            }
            
            bool operator==(const UUID& other) const {
                return this->_data[0] == other._data[0] && this->_data[1] == other._data[1];
            }

            bool operator!=(const UUID& other) const {
                return !(*this == other);
            }

            std::string to_string() const {
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

            static UUID gen() {
                static std::random_device rd;
                static std::mt19937_64 gen(rd());

                static std::uniform_int_distribution<u64> dist(0ULL, std::numeric_limits<u64>::max());

                return UUID(dist(gen), dist(gen));
            }
    };
}

#endif
