#ifndef TAREA5_PROGRA3_RENDERFACTORY_H
#define TAREA5_PROGRA3_RENDERFACTORY_H
#include "Elementos.h"

class RenderFactory {
public:
    virtual Window* createWindow() = 0;
    virtual Button* createButton() = 0;
    virtual Shader* createShader() = 0;
};


class OpenGLFactory : public RenderFactory {
public:
    Window* createWindow() override {
        return new OpenGLWindow();
    }

    Button* createButton() override {
        return new OpenGLButton();
    }

    Shader* createShader() override {
        return new OpenGLShader();
    }
};

class VulkanFactory : public RenderFactory {
public:
    Window* createWindow() override {
        return new VulkanWindow();
    }

    Button* createButton() override {
        return new VulkanButton();
    }

    Shader* createShader() override {
        return new VulkanShader();
    }
};


#endif //TAREA5_PROGRA3_RENDERFACTORY_H