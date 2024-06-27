# 라이브러리 타겟을 정의
add_library(audio STATIC
    include/audio.h
)

# 타겟을 컴파일할 때 사용할 인클루드 디렉토리를 지정
target_include_directories(audio
PUBLIC
    # 아래 인클루드 디렉토리는 PUBLIC이기 때문에 링크한 타겟도 사용 가능
    include
)

# 운영체제에 따른 파일을 타겟에 추가
if (APPLE)
    target_sources(audio
    PRIVATE
        src/apple/core-audio.cpp
    )
elseif(LINUX)
    target_sources(audio
    PRIVATE
        src/linux/alsa.cpp
    )
elseif(WIN32)
    target_sources(audio
    PRIVATE
        src/win32/wasapi.cpp
    )
else()
    message(FATAL_ERROR "Your platform isn't supported.")
endif()
