# 필요한 CMake 최소 버전 명시
cmake_minimum_required(VERSION 3.11.0)

# 프로젝트 이름 지정
project(fetch-content)

# 사용할 C++ 버전을 20으로 설정
set(CMAKE_CXX_STANDARD 20)

# 모듈 로드
include(CheckIncludeFileCXX)

# C++ 파일이 있는지 검사
check_include_file_cxx("filesystem" CXX_FILESYSTEM_HAVE_HEADER)

# 파일이 없는 경우 메세지 출력
if(NOT CXX_FILESYSTEM_HAVE_HEADER)
    message(STATUS "Oh no! can't use filesystem!")
endif()

# 모듈 로드
include(FetchContent)

# 컨텐츠를 GIT 사용해서 가져온다고 선언
FetchContent_Declare(spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG 706ad7059125f32158dad4441938c08fa910f143
)

# 컨텐츠를 URL 다운로드를 통해 가져올지 선언
FetchContent_Declare(poco
    URL https://github.com/pocoproject/poco/archive/refs/tags/poco-1.12.4-release.tar.gz
    URL_HASH MD5=0ca5d1e2f2a5e8ba2f0a83c2e6df374a
    DOWNLOAD_EXTRACT_TIMESTAMP 20230316091300  # YYYYMMDDHHMMSS
)

# 선언된 컨텐츠들을 프로젝트에서 사용할 수 있도록 준비
FetchContent_MakeAvailable(spdlog poco)

# 타겟 프로그램 정의
add_executable(fetch-content src/fetch-content.cpp)

# 타겟을 링킹할 때 필요한 타겟이나 라이브러리를 지정
target_link_libraries(fetch-content
PRIVATE
    spdlog::spdlog
    Poco::Net
)
