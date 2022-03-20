# HyperEngine
Game Engine as per The Cherno YouTube series within the scope of the Engine Architecture and Design FHTW course
The engine compiles to a DLL.

## Components
* Entry Point: A simple entry point to the engine that can be accessed from an application using the engine
* Logging: Use of library spdlog to facilitate basic logging requirements and log levels
* Event System: To dispatch and react to events such as resizing the window
* Window Abstraction: Use of library GLFW to implement a basic abstract window class that may be implemented for various OS' + implementation of such class for the Windows OS
* Window Events: Definition and handling of various window events, such the interaction with a mouse/keyboard or resize/closing of the window
