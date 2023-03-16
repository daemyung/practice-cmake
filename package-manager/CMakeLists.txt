# 필요한 CMake 최소 버전 명시
cmake_minimum_required(VERSION 3.0.0)

# 프로젝트 이름 지정
project(package-manager)

# 타겟 프로그램 정의
add_executable(package-manager src/main.cpp)

# 필요한 패키지 찾기
find_package(fmt CONFIG REQUIRED)

# 타겟을 링킹할 때 필요한 타겟이나 라이브러리를 지정
target_link_libraries(package-manager
PRIVATE
    fmt::fmt
)
