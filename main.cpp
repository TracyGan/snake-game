
#include <vector>
#include <iostream>
#include <GLFW/glfw3.h>
using namespace std;

enum Direction { NORTH, SOUTH, WEST, EAST };
const int WIDTH = 640;
const int HEIGHT = 480;
bool isGameOver;

void InitGame() {
    isGameOver = false;
};

void RenderSnake(int x, int y, int cellSize) {
    // Head of the snake
    glColor3f(0.0f, 0.39f, 0.0f);

    glBegin(GL_QUADS);
        glVertex2i(x, y);
        glVertex2i(x + cellSize, y);
        glVertex2i(x + cellSize, y + cellSize);
        glVertex2i(x, y + cellSize);
    glEnd();

    // Eyes of the snake

    int eyeDimension = cellSize / 5;
    int eyeY = y + cellSize - eyeDimension - 5;

    int leftEye = x + cellSize / 4 - eyeDimension / 2;
    int rightEye = x + 3 * cellSize / 4 - eyeDimension / 2;
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
        // Left eye
        glVertex2i(leftEye, eyeY);
        glVertex2i(leftEye + eyeDimension, eyeY);
        glVertex2i(leftEye + eyeDimension, eyeY + eyeDimension);
        glVertex2i(leftEye, eyeY + eyeDimension);

        // Right eye
        glVertex2i(rightEye, eyeY);
        glVertex2i(rightEye + eyeDimension, eyeY);
        glVertex2i(rightEye + eyeDimension, eyeY + eyeDimension);
        glVertex2i(rightEye, eyeY + eyeDimension);
    glEnd();

    glFlush(); 
};

void RenderGame() {
    GLFWwindow* window;

    if (!glfwInit()) return;

    window = glfwCreateWindow(WIDTH, HEIGHT, "Snake Game", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return;
    } 

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        // RenderSnake();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return;
};


int main(int argc, const char * argv[]) {
    RenderGame();
}