// Lab2-Start.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(int argc, char* argv[])
{
	// initialise a window and let GLFW know that it should target opengl version 4.3
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	GLFWwindow* window = glfwCreateWindow(800, 600, "OpeningAWindow", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// make this new window our current context, THEN try to initialise GLAD function ptrs
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialise GLAD" << std::endl;
		return -1;
	}

	// until we receive a message to close the program
	while (!glfwWindowShouldClose(window))
	{
		// clear the screen to a green colour
		glClearColor(0.1f, 0.1f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// swap buffers i.e. draw to screen
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// cleanup
	glfwTerminate();
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
