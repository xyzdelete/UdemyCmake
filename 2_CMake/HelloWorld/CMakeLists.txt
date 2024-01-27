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
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(AddGitSubmodule)

add_git_submodule(dependencies/json)

add_subdirectory(configured)
add_subdirectory(dependencies)
add_subdirectory(src)
add_subdirectory(app)