// MIT License
//
// Copyright (c) 2023 Daemyung Jang
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "engine.h"
#include <iostream>
#include <audio.h>
#include <gpu.h>

namespace engine {
    void update() {
        std::cout << "engine: do update.\n";
        audio::play("practice_cmake.mp3");
    }

    void render() {
        std::cout << "engine: do render.\n";
        std::cout << "gpu is " << gpu::name() << ".\n";

        // GPU_NAME은 gpu 타겟의 PRIVATE 디파인이기 때문에 사용할 수 없습니다.
        // std::cout << "engine::render" << " by " << GPU_NAME << std::endl;
    }
}