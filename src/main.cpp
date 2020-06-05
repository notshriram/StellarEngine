#include <iostream>


// Other includes
#include "Window.h"
#include "Shader.h"
#include "Renderer.h"


// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

int main()
{
	Window window("Stellar",800,600);
	window.init();

	Shader shader("Shaders/core.vs","Shaders/core.frag");

	GLfloat vertices[] =
	{
		// Positions         // Colors
		0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  // Bottom Left
		0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f   // Top
	};
	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0); // Unbind VAO

	while (!window.isClosed()) 
	{
		window.clear();

		shader.Use();
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		window.update();
	}
}




