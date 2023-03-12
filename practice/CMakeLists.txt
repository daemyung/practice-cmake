# 필요한 CMake 최소 버전 명시
cmake_minimum_required(VERSION 3.0.0)

# 프로젝트 정의
project(practice)

# 사용할 C++ 버전을 20으로 설정
set(CMAKE_CXX_STANDARD 20)

# 컴파일러에 따른 컴파일 옵션 설정
if(MSVC)
    add_compile_options(/W3 /WX)
else()
    add_compile_options(-Wall -Werror)
endif()

# 빌드에 포함할 소스 디렉토리를 추가
add_subdirectory(lib)

# 타겟 프로그램 정의
add_executable(client src/client.cpp)

# 타겟을 링킹할 때 필요한 타겟이나 라이브러리를 지정
target_link_libraries(client
PUBLIC
    # 아래의 타겟이나 라이브러리는 PUBLIC이기 때문에 타겟을 링크한 타겟도 사용 가능
    rest
    engine
PRIVATE
    # 아래의 타겟이나 라이브러리는 PRIVATE이기 때문에 타겟만 사용 가능
    thread
)