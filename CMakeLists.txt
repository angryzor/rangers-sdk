cmake_minimum_required(VERSION 3.28)
project(rangers-sdk VERSION 0.1.8
                   DESCRIPTION "An SDK for Sonic Frontiers"
                   LANGUAGES CXX ASM_MASM)

add_library(rangers-sdk STATIC)
target_compile_features(rangers-sdk PUBLIC cxx_std_17)
target_include_directories(rangers-sdk PUBLIC rangers-api)
target_sources(rangers-sdk
    PRIVATE
        src/thunks.asm
    PUBLIC FILE_SET HEADERS BASE_DIRS include FILES
        include/rangers-sdk.h
)
