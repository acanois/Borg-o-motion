//
//  main.cpp
//  Indigo
//
//  Created by David Richter on 5/31/19.
//  Copyright © 2019 David Richter. All rights reserved.
//

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "graphicsContext.h"

int main()
{
    GraphicsContext gContext;
    
    gContext.initialize();
    gContext.run();
    gContext.cleanup();
    
    return 0;
}
