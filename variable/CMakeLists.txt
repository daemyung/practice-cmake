# 필요한 CMake 최소 버전 명시
cmake_minimum_required(VERSION 3.0.0)

# 프로젝트 이름 지정
project(variable)

# 변수 생성 및 출력
set(I_AM_VARIABLE TRUE)
message(STATUS ${I_AM_VARIABLE})

# CMake 변수 출력
message(STATUS "System Name: ${CMAKE_SYSTEM_NAME}")
message(STATUS "System Version: ${CMAKE_SYSTEM_VERSION}")
message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "Install Directory: ${CMAKE_INSTALL_PREFIX}")

# CMAKE_SYSTEM_NAME을 사용하여 운영체제마다 다른 명령어 실행
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    message("OS is Windows.")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    message("OS is Linux.")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    message("OS is macOS.")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Android")
    message("OS is Android.")
else()
    message("OS is unknown.")
endif()

# 운영체제 변수를 이용하여 운영체제마다 다른 명령어 실행
if(WIN32)      
    message("OS is Windows.")
elseif(LINUX)
    message("OS is Linux.")
elseif(APPLE)
    message("OS is macOS.")
elseif(ANDROID)
    message("OS is Android.")
else()
    message("OS is unknown.")
endif()

# 라이브러리 타겟이 동적 또는 정적 빌드 설정
set(BUILD_SHARED_LIBS FALSE)

# BUILD_SHARED_LIBS에 의해 라이브러리 타겟이 동적 또는 정적으로 빌드
add_library(foo
    src/foo.cpp
)

# 타겟이 설치될 경로 지정
install(TARGETS foo DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
