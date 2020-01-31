// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include <iostream>

using namespace std;

float angulo = 0.0f;

void actualizar()
{
	angulo += 0.01f;
	if (angulo >= 360)
	{
		angulo = 0;
	}
}

void dibujarTriangulo() {
	glPushMatrix();

	glTranslatef(0.0f, 0.0f, 0.0f);
	glRotatef(0.0f+angulo, 0.0f, 1.0f, 0.0f);
	glScalef(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLES);

	glColor3f(0.9f, 0.4f, 0.8f);
	glVertex3f(0.1f, 0.0f, 0.0f);
	glVertex3f(-0.1f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.2f, 0.0f);

	glEnd();
	glPopMatrix();

	//

	glPushMatrix();

	glRotatef(0.0f + angulo, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glScalef(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLES);

	glColor3f(0.9f, 0.4f, 0.8f);
	glVertex3f(0.1f, 0.0f, 0.0f);
	glVertex3f(0.3f, 0.0f, 0.0f);
	glVertex3f(0.2f, 0.2f, 0.0f);

	glEnd();
	glPopMatrix();

	//

	glPushMatrix();

	glRotatef(0.0f + angulo, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glScalef(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLES);

	glColor3f(0.9f, 0.4f, 0.8f);
	glVertex3f(0.0f, 0.2f, 0.0f);
	glVertex3f(0.2f, 0.2f, 0.0f);
	glVertex3f(0.1f, 0.4f, 0.0f);

	glEnd();
	glPopMatrix();
}

void dibujar() {
	dibujarTriangulo();
}

int main()
{
	//declarar una ventana
	GLFWwindow* window;

	//Si no se pudo iniciar glfw
	//terminamos ejecucion
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//Si se pudo inicial glfw
	//inicializamos la ventana
	window = glfwCreateWindow(800, 600, "Ventana", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecemos la ventana como contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto se activan las funciones "modernas" (GPU)
	glewExperimental = true;

	GLenum errores = glewInit();
	if (errores != GLEW_OK)
	{
		glewGetErrorString(errores);
	}

	const GLubyte* versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	//ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region de dibujo
		glViewport(0, 0, 600, 600);
		//Establecemos el color de borrado
		//Valores RGBA
		glClearColor(0.9, 0.2, 0.5, 1);
		//Borrar!
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		//Actualizar valores y dibujar
		actualizar();
		dibujar();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	//Despues del ciclo de dibujo
	//Eliminamos ventana y procesos de glfw
	glfwDestroyWindow(window);
	glfwTerminate();
}

