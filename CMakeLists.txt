cmake_minimum_required(VERSION 3.16)
project(trapped LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include_directories(include)

# Fetch SFML
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_executable(trapped ${SOURCE_FILES})
target_link_libraries(trapped PRIVATE sfml-graphics)
target_compile_features(trapped PRIVATE cxx_std_17)

# Copy OpenAL DLL on Windows
if(WIN32)
    add_custom_command(
        TARGET trapped
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy
            ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll
            $<TARGET_FILE_DIR:trapped>
        VERBATIM)
endif()

# set VORBIS paths on Unix
if(UNIX)
    set(VORBIS_LIBRARY "/usr/lib/x86_64-linux-gnu/libvorbis.so")
    set(VORBIS_INCLUDE_DIR "/usr/include/vorbis")
endif()

install(TARGETS trapped)

file(GLOB_RECURSE SRC_SUBDIRECTORIES "src/*")
file(GLOB_RECURSE INCLUDE_SUBDIRECTORIES "include/*")

foreach(SUBDIRECTORY ${SRC_SUBDIRECTORIES} ${INCLUDE_SUBDIRECTORIES})
    if(IS_DIRECTORY ${SUBDIRECTORY})
        include_directories(${SUBDIRECTORY})
    endif()
endforeach()
