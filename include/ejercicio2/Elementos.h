#ifndef TAREA5_PROGRA3_ELEMENTOS_H
#define TAREA5_PROGRA3_ELEMENTOS_H
#include <iostream>
using namespace std;
class Window {
public:
    virtual ~Window() = default;
    virtual void draw() = 0;
};
class Button{
public:
    virtual ~Button() = default;
    virtual void draw() = 0;
};
class Shader{
public:
    virtual ~Shader() = default;
    virtual void compile() = 0;
};

class OpenGLWindow : public Window {
public:
    void draw() override {
        cout << "Se ha creado una ventana para OpenGL" << endl;
    }
};
class OpenGLButton : public Button {
public:
    void draw() override {
        cout << "Se ha creado un boton para OpenGL" << endl;
    }
};
class OpenGLShader : public Shader {
public:
    void compile() override {
        cout << "Se ha copilado un shader para OpenGL" << endl;
    }
};

class VulkanWindow : public Window {
public:
    void draw() override {
        cout << "Se ha creado una ventana para Vulkan" << endl;
    }
};
class VulkanButton : public Button {
public:
    void draw() override {
        cout << "Se ha creado un boton para Vulkan" << endl;
    }
};
class VulkanShader : public Shader {
public:
    void compile() override {
        cout << "Se ha copilado un shader para Vulkan" << endl;
    }
};




#endif //TAREA5_PROGRA3_ELEMENTOS_H