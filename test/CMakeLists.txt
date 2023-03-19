# 필요한 CMake 최소 버전 명시
cmake_minimum_required(VERSION 3.0.0)

# 프로젝트 정의
project(test)

# BUILD_TESTING 옵션 정의
option(BUILD_TESTING "Enable build testing." OFF)

# 사용할 C++ 버전을 20으로 설정
set(CMAKE_CXX_STANDARD 20)

# 타겟 프로그램 정의
add_executable(pass src/pass.cpp)

# 타겟 프로그램 정의
add_executable(fail src/fail.cpp)

# CTest 모듈 로드
include(CTest)

# BUILD_TESTING 옵션 출력
message(STATUS "Build testing is ${BUILD_TESTING}")

# 테스트 정의
add_test(NAME foo-test COMMAND pass)

# 테스트 정의
add_test(NAME bar-test COMMAND fail)

# 테스트 정의
add_test(NAME baz-test COMMAND fail "Fail is not fail.")

# 테스트 속성 정의
set_tests_properties(baz-test
PROPERTIES
    PASS_REGULAR_EXPRESSION "Fail is not fail."
)
