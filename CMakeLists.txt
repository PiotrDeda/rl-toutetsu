cmake_minimum_required(VERSION 3.22)
project(RLToutetsu)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS -static)

set(CMAKE_MODULE_PATH "D:/Libraries/FindSDL2")
set(SDL2_PATH "D:/Libraries/SDL2-2.0.22/x86_64-w64-mingw32")
set(SDL2_IMAGE_PATH "D:/Libraries/SDL2_image-2.6.0/x86_64-w64-mingw32")
set(SDL2_TTF_PATH "D:/Libraries/SDL2_ttf-2.20.0/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(RLToutetsu ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})

file(GLOB_RECURSE ASSETS "${CMAKE_BINARY_DIR}/assets/*")
file(REMOVE ${ASSETS})
file(COPY src/assets DESTINATION ${CMAKE_BINARY_DIR})
