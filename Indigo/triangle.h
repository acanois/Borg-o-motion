//
//  triangle.h
//  Indigo
//
//  Created by David Richter on 5/31/19.
//  Copyright © 2019 David Richter. All rights reserved.
//

#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shaderLoader.h"

class Triangle
{
public:
    Triangle()  {}
    ~Triangle() {}
    
    void generateVbo()
    {
        glGenBuffers(1, &mVbo);
        glBindBuffer(GL_ARRAY_BUFFER, mVbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(mVertices), mVertices, GL_STATIC_DRAW);
    }
    
private:
    float mVertices[9] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };
    
    GLuint mVbo;
};
