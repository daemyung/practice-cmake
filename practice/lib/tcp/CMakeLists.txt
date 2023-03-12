# 라이브러리 타겟을 정의
add_library(tcp STATIC
    include/tcp.h
    src/tcp.cpp
    src/config/server.h
)

# 타겟을 컴파일할 때 사용할 인클루드 디렉토리를 지정
target_include_directories(tcp
PUBLIC
    # 아래 인클루드 디렉토리는 PUBLIC이기 때문에 링크한 타겟도 사용 가능
    include
PRIVATE
    # 아래 인클루드 디렉토리는 PRIVATE이기 때문에 타겟만 사용 가능
    src/config
)
