# 필요한 CMake 최소 버전 명시
cmake_minimum_required(VERSION 3.0.0)

# 프로젝트 이름 지정
project(glob)

# cpp 파일 리스트 생성
file(GLOB FILES *.cpp)

# cpp 파일 리스트 출력
foreach(FILE IN ITEMS ${FILES})
    message(STATUS ${FILE})
endforeach()

# 라이브러리 타겟을 정의
add_library(glob STATIC ${FILES})
