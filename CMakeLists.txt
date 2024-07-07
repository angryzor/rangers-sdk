cmake_minimum_required(VERSION 3.28)
project(rangers-sdk VERSION 0.1.8
                   DESCRIPTION "An SDK for Sonic Frontiers"
                   LANGUAGES CXX ASM_MASM)

# Temporary workaround for bug, see
# - https://discourse.cmake.org/t/building-lib-file-from-asm-cmake-bug/1959
# - https://gitlab.kitware.com/cmake/cmake/-/issues/18889
set(CMAKE_ASM_MASM_CREATE_STATIC_LIBRARY "<CMAKE_AR> /OUT:<TARGET> <LINK_FLAGS> <OBJECTS>")

add_library(rangers-sdk STATIC)
target_compile_features(rangers-sdk PUBLIC cxx_std_17)

if(DEFINED RANGERS_SDK_CUSTOM_EIGEN_TARGET)
    target_link_libraries(rangers-sdk PUBLIC ${RANGERS_SDK_CUSTOM_EIGEN_TARGET})
else()
    target_link_libraries(rangers-sdk PUBLIC eigen)
endif()

target_include_directories(rangers-sdk PUBLIC rangers-api)
target_sources(rangers-sdk
    PRIVATE
        src/thunks.asm
    PUBLIC FILE_SET HEADERS BASE_DIRS include FILES
        include/rangers-sdk.h
)

add_subdirectory(vendor EXCLUDE_FROM_ALL)
