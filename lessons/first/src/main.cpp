// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
using namespace glm;

#include <common/shader.hpp>

int main( void ) {
    // Initialise GLFW
    if( !glfwInit() ) {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return -1;
    }

    glfwWindowHint( GLFW_SAMPLES, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    // To make MacOS happy; should not be needed
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

    GLFWwindow *window = glfwCreateWindow( 1024, 768, "First", NULL, NULL );

    if ( NULL == window ) {
        fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU,"
                         " they are not 3.3 compatible.\n" );
        glfwTerminate( );
        return -1;
    }   

    glfwMakeContextCurrent( window );

    // Initialize GLEW
    glewExperimental = true;

    if( glewInit() != GLEW_OK ) {
        fprintf( stderr, "Failed to initialize GLEW.\n" );
        glfwTerminate();
        return -1;
    }

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode( window, GLFW_STICKY_KEYS, GL_TRUE);

    // Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

    //  ALL CODE BEFORE HERE IS JUST SETTING UP THE USER INTERFACE
    //  Now comes the real aplication

    //  Create and compile our GLSL program from the shaders
    GLuint programID = LoadShaders( "SimpleVertexShader.vertexshader",
                                    "SimpleFragmentShader.fragmentshader" );

    static const GLfloat g_vertex_buffer_data[] = {
        -0.1f, -0.1f, 0.0f,
        0.1f, -0.1f, 0.0f,
        0.0f,  0.1f, 0.0f,
    };

    //  This will identify our vertex buffer
    GLuint vertexbuffer;
    //  Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers( 1, &vertexbuffer );
    //  The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer( GL_ARRAY_BUFFER, vertexbuffer );
    //  Give our vertex to OpenGl
    glBufferData( GL_ARRAY_BUFFER, sizeof( g_vertex_buffer_data ),
                  g_vertex_buffer_data, GL_STATIC_DRAW );
    
    do {
        //  This  will  change the backgroung color to darke blue because of the
        //  previous glClearColor(0.0f, 0.0f, 0.4f, 0.0f) call
        glClear( GL_COLOR_BUFFER_BIT );
        //  Use shader
        glUseProgram( programID );
      
        //  Draw triangle...
        //  1rst attribute_buffer: vertices
        glEnableVertexAttribArray( 0 );
        glBindBuffer( GL_ARRAY_BUFFER, vertexbuffer );
        glVertexAttribPointer(
            0,  //  attribute  0. No particular reason for 0, but must match the
                //  layout in the shader.
            3,  //  size
            GL_FLOAT,   //  type
            GL_FALSE,   //  normalized?
            0,  // stride
            ( void* )0  //  array buffer offser
        );

        //  Drar the triangle
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glDisableVertexAttribArray( 0 );

        //  Swap buffers
        glfwSwapBuffers( window );
        glfwPollEvents();
    }  // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey( window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
    glfwWindowShouldClose( window) == 0 );

    // Cleanup VBO
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteProgram(programID);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
}
