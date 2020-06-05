#pragma once 

#define GLEW_STATIC
#include<GL/glew.h>

#include <GLFW/glfw3.h>

class Window 
{
public:
	Window(const char* name,int width,int height);
	~Window();
	void init();
	void update() const;
	void clear() const;
	bool isClosed() const;
	int getWidth() const;
	int getHeight() const;
private:
	const char* m_name;
	int m_width, m_height;
	GLFWwindow* m_window;
};