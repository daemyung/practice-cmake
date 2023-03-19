# 한줄 주석

#[=[
여러줄 라인 주석
#]=]

#[==[
여러줄 라인 주석
#]==]

#[===[
여러줄 라인 주석
#]===]

# 필요한 CMake 최소 버전 명시
cmake_minimum_required(VERSION 3.0.0)

# 프로젝트 정의
project(command VERSION 0.0.1 LANGUAGES C CXX)

# 메시지 출력
message("Hello CMake!")

# STATUS 모드로 메시지 출력
message(STATUS "Hello CMake in STATUS!")

# 변수 생성
set(variable CMake)

# 변수 참조
message("This is a " ${variable} "! ${variable}!")

# 변수 파괴
unset(variable)

# 옵션 정의
option(BUILD_EXAMPLE "Enable build examples." ON)

# 옵션 출력
message(STATUS "Building examples is ${BUILD_EXAMPLE}")

# 리스트 생성
list(APPEND FILES foo.cpp bar.cpp baz.cpp qux.cpp)

# 리스트 길이 조회
list(LENGTH FILES NUM_FILES)

# 리스트와 정보 출력
message("File List[${NUM_FILES}]: ${FILES}")

# 리스트 검색
list(FIND FILES baz.cpp baz_cpp_index)

# 리스트 검색 결과 출력
message("baz.cpp is located in the ${baz_cpp_index} index.")

# 리스트 정렬
list(SORT FILES)

# 정렬된 리스트 출력
message("Sorted File List: " ${FILES})

# 조건문 처리
if(APPLE)
    message(STATUS "My system is macOS.")
elseif(WIN32)
    message(STATUS "My system is Windows.")
elseif(UNIX)
    message(STATUS "My system is Linux.")
else()
    message(STATUS "My system is unknown.")
endif()

# 반복문
foreach(FILE IN LISTS FILES)
    message(${FILE} " is in the list")
endforeach()

# 빌드에 포함할 소스 디렉토리를 추가
add_subdirectory(cmake)

# 컴파일 옵션 추가
add_compile_options(-Wall -Wextra)

# 실행 타겟을 정의
add_executable(foo src/foo.cpp)

# 라이브러리 타겟을 정의
add_library(bar STATIC
    lib/bar/include/bar.h
    lib/bar/src/bar.cpp
)

# 타겟의 속성을 설정
set_target_properties(foo PROPERTIES 
    WINDOWS_EXPORT_ALL_SYMBOLS YES
    MACOSX_BUNDLE YES
)

# 타겟을 링킹할 때 필요한 타겟이나 라이브러리를 지정
target_link_libraries(foo PRIVATE bar)

# 타겟에 명시된 소스 파일을 추가
target_sources(foo PRIVATE src/baz.h src/baz.cpp)

# 타겟을 컴파일할 때 사용할 컴파일 디파인을 지정
target_compile_definitions(foo PRIVATE NOMINMAX)

# 타겟을 컴파일할 때 사용할 인클루드 디렉토리를 지정
target_include_directories(bar PUBLIC lib/bar/include)

# 타겟을 컴파일할 때 사용할 컴파일 옵션을 지정
target_compile_options(bar PRIVATE -pedantic)
