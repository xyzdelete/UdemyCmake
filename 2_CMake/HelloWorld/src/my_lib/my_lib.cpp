#include <iostream>
#include <my_lib.h>

#include <nlohmann/json.hpp>

/**
 * @brief Prints out hello world and tests the JSON
 *
 */
void print_hello_world()
{
    std::cout << "Hello World!" << std::endl;

    std::cout << "JSON Lib Version: "
        << NLOHMANN_JSON_VERSION_MAJOR << "."
        << NLOHMANN_JSON_VERSION_MINOR << "."
        << NLOHMANN_JSON_VERSION_PATCH << std::endl;
}
