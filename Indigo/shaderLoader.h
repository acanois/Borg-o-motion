//
//  shaderLoader.h
//  Indigo
//
//  Created by David Richter on 6/1/19.
//  Copyright © 2019 David Richter. All rights reserved.
//

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class ShaderLoader
{
public:
    ShaderLoader()  {}
    ~ShaderLoader() {}
    
    std::string getShaderSource(const char* glslPath)
    {
        std::ifstream glslFile;
        
        glslFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        
        try
        {
            glslFile.open(glslPath);
            
            std::stringstream glslStream;
            
            glslStream << glslFile.rdbuf();
            glslFile.close();
            
            glslSource = glslStream.str();
        }
        catch (std::ifstream::failure e)
        {
            std::cout << "Shader file failed to read properly: " << std::endl;
        }
        
        return glslSource;
    }
    
private:
    std::string glslSource;
};
