
#include <vector>
#include <iostream>
#include <GLFW/glfw3.h>
#include "snake.h"

using namespace std;

const int WIDTH = 700;
const int HEIGHT = 500;
bool isGameOver;

void InitGame() {
    isGameOver = false;
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

    // Setup 2D projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH, 0, HEIGHT, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    int snakeX = WIDTH / 2;
    int snakeY = HEIGHT / 2;
    int cellSize = 20;

    Snake snake(snakeX, snakeY);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();

        snake.move();
        snake.render(cellSize);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return;
};


int main(int argc, const char * argv[]) {
    InitGame();
    RenderGame();
}