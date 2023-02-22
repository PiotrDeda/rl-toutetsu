cmake_minimum_required(VERSION 3.22)
project(RLToutetsu)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)

set(ICON icon.rc)

set(CMAKE_MODULE_PATH "F:/Libraries/FindSDL2")
set(SDL2_PATH "F:/Libraries/SDL2-2.26.3/x86_64-w64-mingw32")
set(SDL2_IMAGE_PATH "F:/Libraries/SDL2_image-2.6.3/x86_64-w64-mingw32")
set(SDL2_TTF_PATH "F:/Libraries/SDL2_ttf-2.20.2/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG master)
FetchContent_MakeAvailable(fmt)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(RLToutetsu ${SOURCES} ${ICON})

target_link_libraries(${CMAKE_PROJECT_NAME}
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        fmt::fmt)

file(GLOB_RECURSE ASSETS "${CMAKE_BINARY_DIR}/assets/*" "${CMAKE_BINARY_DIR}/*.dll")
if(ASSETS)
    file(REMOVE ${ASSETS})
endif()
file(COPY src/assets DESTINATION ${CMAKE_BINARY_DIR})
file(GLOB DLLS "src/bin/*.dll")
file(COPY ${DLLS} DESTINATION ${CMAKE_BINARY_DIR})
