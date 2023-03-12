# 라이브러리 타겟을 정의
add_library(engine STATIC
    include/engine.h
    src/engine.cpp
)

# 타겟을 컴파일할 때 사용할 인클루드 디렉토리를 지정
target_include_directories(engine
PUBLIC
    # 아래 인클루드 디렉토리는 PUBLIC이기 때문에 링크한 타겟도 사용 가능
    include
)

# 타겟을 링킹할 때 필요한 타겟이나 라이브러리를 지정
target_link_libraries(engine
PRIVATE
    # 아래의 타겟이나 라이브러리는 PRIVATE이기 때문에 타겟만 사용 가능
    audio
    gpu
    thread
)