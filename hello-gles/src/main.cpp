#include <cstdlib>
#include <iostream>
#include <string>
#include <GLFW/glfw3.h>
#include <EGL/egl.h>
#include <GLES3/gl3.h>

#include "window.h"

GLuint create_shader(GLenum type, const char *shader_source) {
    GLuint shader = glCreateShader(type);
    if (shader == 0) {
        return 0;
    }

    glShaderSource(shader, 1, &shader_source, nullptr);
    glCompileShader(shader);

    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (!status) {
        GLint length = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

        if (length > 1) {
            std::string message;
            message.resize(length);
            glGetShaderInfoLog(shader, length, nullptr, &message[0]);
            std::cerr << message << std::endl;
        }

        glDeleteShader(shader);
        return 0;
    }

    return shader;
}

int main(int argc, char *argv[]) {
    if (!glfwInit()) {
        return EXIT_FAILURE;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow *window = glfwCreateWindow(640, 480, "Hello GLES", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return EXIT_FAILURE;
    }

    EGLNativeWindowType native_window = init_native_window(window);
    if (!native_window) {
        glfwDestroyWindow(window);
        glfwTerminate();
        return EXIT_FAILURE;
    }

    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (display == EGL_NO_DISPLAY) {
        glfwDestroyWindow(window);
        glfwTerminate();
        return EXIT_FAILURE;
    }

    EGLint major, minor;
    if (!eglInitialize(display, &major, &minor)) {
        glfwDestroyWindow(window);
        glfwTerminate();
        return EXIT_FAILURE;
    }

    const EGLint config_attribs[] = {
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
            EGL_RED_SIZE, 8,
            EGL_GREEN_SIZE, 8,
            EGL_BLUE_SIZE, 8,
            EGL_DEPTH_SIZE, 24,
            EGL_NONE
    };
    EGLConfig config;
    EGLint num_configs;
    if (!eglChooseConfig(display, config_attribs, &config, 1,
                         &num_configs)) {
        glfwDestroyWindow(window);
        glfwTerminate();
        return EXIT_FAILURE;
    }

    EGLSurface surface = eglCreateWindowSurface(display, config, native_window, NULL);
    if (surface == EGL_NO_SURFACE) {
        glfwDestroyWindow(window);
        glfwTerminate();
        return EXIT_FAILURE;
    }

    const EGLint context_attribs[] = {
            EGL_CONTEXT_CLIENT_VERSION, 3,
            EGL_NONE
    };
    EGLContext context = eglCreateContext(display, config, EGL_NO_CONTEXT, context_attribs);
    if (context == EGL_NO_CONTEXT) {
        eglDestroySurface(display, surface);
        glfwTerminate();
        return EXIT_FAILURE;
    }

    if (!eglMakeCurrent(display, surface, surface, context)) {
        eglDestroyContext(display, context);
        eglDestroySurface(display, surface);
        glfwDestroyWindow(window);
        glfwTerminate();
        return EXIT_FAILURE;
    }

    const std::string_view vertex_shader_source =
            "#version 300 es                           \n"
            "layout(location = 0) in vec4 position;    \n"
            "void main()                               \n"
            "{                                         \n"
            "   gl_Position = position;                \n"
            "}                                         \n";
    const std::string_view fragment_shader_source =
            "#version 300 es                           \n"
            "precision mediump float;                  \n"
            "out vec4 frag_color;                      \n"
            "void main()                               \n"
            "{                                         \n"
            "   frag_color = vec4(1.0, 0.0, 0.0, 1.0); \n"
            "}                                         \n";

    GLuint vertex_shader = create_shader(GL_VERTEX_SHADER, vertex_shader_source.data());
    GLuint fragment_shader = create_shader(GL_FRAGMENT_SHADER, fragment_shader_source.data());
    GLuint program = glCreateProgram();

    if (program == 0) {
        eglDestroyContext(display, context);
        eglDestroySurface(display, surface);
        glfwDestroyWindow(window);
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    GLint status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if (!status) {
        GLint length = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);

        if (length > 1) {
            std::string message;
            message.resize(length);
            glGetProgramInfoLog(program, length, nullptr, &message[0]);
            std::cerr << message << std::endl;
        }

        glDeleteProgram(program);
        eglDestroyContext(display, context);
        eglDestroySurface(display, surface);
        glfwDestroyWindow(window);
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

    const GLfloat vertices[] = {
            0.0f, 0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f
    };

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glViewport(0, 0, 640, 480);
        glUseProgram(program);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices);
        glEnableVertexAttribArray(0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        eglSwapBuffers(display, surface);
        glfwPollEvents();
    }

    glDeleteProgram(program);
    eglDestroyContext(display, context);
    eglDestroySurface(display, surface);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
