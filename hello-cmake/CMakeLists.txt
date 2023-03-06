# 최소 CMake 버전 요구사항 명시
cmake_minimum_required(VERSION 3.0.0)

# 프로젝트 이름 지정
project(hello-cmake)

# 타겟 프로그램 정의
add_executable(hello_cmake src/main.cpp)

# 조건문
if(BUILD_TESTING)
	# 메세지 출력
	message("Hello Test")
endif()
