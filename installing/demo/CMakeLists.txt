# 필요한 CMake 최소 버전 명시
cmake_minimum_required(VERSION 3.0.0)

# 프로젝트 정의
project(demo)

# 사용할 C++ 버전을 20으로 설정
set(CMAKE_CXX_STANDARD 20)

# 실행 타겟을 정의
add_executable(bar src/bar.cpp)

# 필요한 패키지 찾기
find_package(installing REQUIRED
PATHS
    ../build/install
)

# 타겟을 링킹할 때 필요한 타겟이나 라이브러리를 지정
target_link_libraries(bar
PRIVATE
    installing::foo
)