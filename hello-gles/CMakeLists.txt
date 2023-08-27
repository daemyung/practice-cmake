# 필요한 CMake 최소 버전 명시
cmake_minimum_required(VERSION 3.0.0)

# 프로젝트 이름 지정
project(hello-gles LANGUAGES CXX OBJCXX)

# 사용할 C++ 버전을 17으로 설정
set(CMAKE_CXX_STANDARD 17)

# 타겟 프로그램 정의
add_executable(hello-gles
    src/window.h
    src/window.mm
    src/main.cpp
)

# EGL 인클루드 폴더 검색
find_path(EGL_REGISTRY_INCLUDE_DIRS "EGL/egl.h")

# GLES 인클루드 폴더 검색
find_path(GLES_REGISTRY_INCLUDE_DIRS "GLES3/gl3.h")

# 타겟을 컴파일할 때 사용할 인클루드 디렉토리를 지정
target_include_directories(hello-gles
PRIVATE
    ${EGL_REGISTRY_INCLUDE_DIRS}
    ${GLES_REGISTRY_INCLUDE_DIRS}
)

# 타겟을 컴파일할 때 사용할 컴파일 디파인을 지정
target_compile_definitions(hello-gles
PRIVATE
    GLFW_INCLUDE_ES3
    GLFW_EXPOSE_NATIVE_COCOA
)

# GLFW3 패키지 검사
find_package(glfw3 CONFIG REQUIRED)

# Angle 패키지 검사
find_package(unofficial-angle REQUIRED CONFIG)

# 타겟을 링킹할 때 필요한 타겟이나 라이브러리를 지정
target_link_libraries(hello-gles
PRIVATE
    glfw
    unofficial::angle::libEGL
    unofficial::angle::libGLESv2
)

