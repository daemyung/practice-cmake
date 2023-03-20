# 필요한 CMake 최소 버전 명시
cmake_minimum_required(VERSION 3.0.0)

# 프로젝트 정의
project(packaging)

# 사용할 C++ 버전을 20으로 설정
set(CMAKE_CXX_STANDARD 20)

# GNUInstallDirs 모듈 로드
include(GNUInstallDirs)

# 라이브러리 타겟을 정의
add_library(foo 
    include/foo.h
    src/foo.cpp
)

# 타겟을 빌드하고 설치 할 때 사용할 인클루드 디렉토리를 지정
target_include_directories(foo
PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# 타겟의 속성을 설정
set_target_properties(foo PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS TRUE
)

# 타겟들의 어떻게 그리고 어디에 설치할지 설정
install(TARGETS foo
    EXPORT packaging-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# 파일들을 어디에 설치할지 설정
install(FILES include/foo.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# 설치할 타겟을 위한 CMake 파일들을 생성하고 설치
install(EXPORT packaging-config
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/packaging
    NAMESPACE packaging::
)

# InstallRequiredSystemLibraries 모듈 로드
include(InstallRequiredSystemLibraries)

# 패키징 관련된 변수 설정
set(CPACK_PACKAGE_VENDOR "Triangle")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_GENERATOR "STGZ;ZIP")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")

# CPack 모듈 로드
include(CPack)
