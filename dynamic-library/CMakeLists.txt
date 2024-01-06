cmake_minimum_required(VERSION 3.18)
project(dynamic-library)

set(CMAKE_CXX_STANDARD 20)

# 동적 라이브러리 정의
add_library(foo SHARED
    include/foo.h
    src/foo.cpp
)

target_include_directories(foo
PUBLIC
    include
)

add_executable(dynamic-library
    include/library.h
    src/main.cpp
)

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    target_sources(dynamic-library PRIVATE src/windows-library.cpp)
else()
    target_sources(dynamic-library PRIVATE src/unix-library.cpp)
endif()

target_include_directories(dynamic-library
PRIVATE
    include
)

target_link_libraries(dynamic-library
PRIVATE
    ${CMAKE_DL_LIBS}
)
