cmake_minimum_required(VERSION 3.22)

project(CppProjectTemplate
    VERSION 1.0.0
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(LIBRARY_NAME Library)
set(EXECUTABLE_NAME Executable)

option(ENABLE_TESTING "Enable a Unit Testing Build" ON)
option(ENABLE_WARNINGS "Enable warnings" ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable as errors" OFF)

option(ENABLE_ADDRESS_SANITIZER "Enable address sanitizer" ON)
option(ENABLE_UNDEFINED_SANITIZER "Enable undefined sanitizer" ON)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(AddGitSubmodule)
include(FetchContent)
include(Docs)

if(${ENABLE_WARNINGS})
    include(Warnings)
endif()

if(
    ${ENABLE_ADDRESS_SANITIZER}
    OR
    ${ENABLE_UNDEFINED_SANITIZER}
)
    include(Sanitizers)
    add_sanitizer_flags()
endif()


FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.3
    GIT_SHALLOW TRUE
)
FetchContent_Declare(
    FMT
    GIT_REPOSITORY https://github.com/fmtlib/fmt
    GIT_TAG 10.2.1
    GIT_SHALLOW TRUE
)
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_TAG v1.13.0
    GIT_SHALLOW TRUE
)
FetchContent_Declare(
    cxxopts
    GIT_REPOSITORY https://github.com/jarro2783/cxxopts
    GIT_TAG v3.1.1
    GIT_SHALLOW TRUE
)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2
    GIT_TAG v3.5.2
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(nlohmann_json)
FetchContent_MakeAvailable(FMT)
FetchContent_MakeAvailable(spdlog)
FetchContent_MakeAvailable(cxxopts)
FetchContent_MakeAvailable(Catch2)

add_subdirectory(configured)
add_subdirectory(dependencies)
add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)