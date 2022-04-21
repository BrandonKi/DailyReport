#ifndef DR_COMMON_H
#define DR_COMMON_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cassert>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <memory>

using i8  = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using u8  = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;


struct Args {
	std::vector<std::string> files;
	// TODO other options
};

[[nodiscard]]
inline std::string read_file(std::string filepath) {
    std::ifstream file;
    file.open(filepath);
    if(!file)
        return {};
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    return std::string(buffer.str());
}

inline bool is_alpha(char c) {
	return (c >= 'a' && c <= 'z') ||
		   (c >= 'A' && c <= 'Z');  
}

inline bool is_numeric(char c) {
	return (c >= '0' && c <= '9');
}

inline bool is_alpha_numeric(char c) {
	return is_alpha(c) || is_numeric(c);  
}

#endif // DR_COMMON_H
