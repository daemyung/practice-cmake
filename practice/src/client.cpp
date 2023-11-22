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

#include <cstdlib>
#include <iostream>
#include <rest.h>
#include <engine.h>
#include <thread.h>

// rest가 tcp를 PUBLIC으로 링크했기 때문에 사용 가능합니다.
#include <tcp.h>

// engine이 audio, gpu를 PRIVATE으로 링크했기 때문에 사용할 수 없습니다.
// #include <audio.h>
// #include <gpu.h>

int main(int argc, char* argv[]) {
    {
        tcp ctx;
        ctx.send({'t', 'e', 's', 't', ' ', 'm', 'e', 's', 's', 'a', 'g', 'e', '.'});
    }

    while (true) {
        std::cout << "press any key and q is quit: ";
        uint8_t key;
        std::cin >> key;

        if (key == 'q') {
            break;
        }

        engine::update();
        engine::render();
        rest::request({'d', 'o', 'n', 'e', '.'});
    }

    return EXIT_SUCCESS;
}