//
//  graphicsContext.h
//  Indigo
//
//  Created by David Richter on 5/31/19.
//  Copyright © 2019 David Richter. All rights reserved.
//

#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "triangle.h"

class GraphicsContext
{
public:
    GraphicsContext()  {}
    ~GraphicsContext() {}
    
    void initialize()
    {
        startGlfw();
        createNewWindow();
        initializeGlew();
    }
    
    void startGlfw()
    {
        glfwInit();
        
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    }
    
    void initializeGlew()
    {
        glewExperimental = GL_TRUE;
        glewInit();
    }
    
    void createNewWindow()
    {
        mWindow = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);
        
        if (mWindow == nullptr)
        {
            std::cout << "glfwCreateWindow Error: " << glGetError() << std::endl;
            glfwTerminate();
        }
        
        glfwMakeContextCurrent(mWindow);
        glfwSetFramebufferSizeCallback(mWindow, framebuffer_size_callback);
    }
    
    void run()
    {
        while (!glfwWindowShouldClose(mWindow))
        {
            processInput();
            
            glClearColor(0.15f, 0.15f, 0.5f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(mWindow);
            glfwPollEvents();
        }
        
        glfwTerminate();
    }
    
    void processInput()
    {
        if(glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(mWindow, true);
    }
    
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }
    
    void cleanup()
    {
        std::cout << "Cleaning up... " << std::endl;
        glfwDestroyWindow(mWindow);
    }

    
private:
    GLFWwindow* mWindow;
    
    const int WIDTH = 1280;
    const int HEIGHT = 720;
    const char* TITLE = "Indigo";
};
