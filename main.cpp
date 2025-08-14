
#include <vector>
#include <iostream>
#include <GLFW/glfw3.h>
#include <GLUT/glut.h>
#include <unistd.h> 

#include "snake.h"
#include "constants.h"
#include "food.h"

using namespace std;

bool isGameOver;
Snake snake(WIDTH / 2, HEIGHT / 2);

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
            case GLFW_KEY_UP:
                snake.setDirection(NORTH);
                break;
            case GLFW_KEY_DOWN:
                snake.setDirection(SOUTH);
                break;
            case GLFW_KEY_LEFT:
                snake.setDirection(WEST);
                break;
            case GLFW_KEY_RIGHT:
                snake.setDirection(EAST);
                break;
        }
    }
}

void RenderText(float x, float y, const char* text) {
    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

void RenderStartScreen(GLFWwindow* window) {
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();

        glColor3f(1.0f, 1.0f, 1.0f); 
        RenderText(WIDTH/4, HEIGHT/2 + 10, "Start Snake Game");
        RenderText(WIDTH/4, HEIGHT/2 - 10, "Press SPACE to start");

        glfwSwapBuffers(window);
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
            break; 
        } 
    }
};

void RenderGame() {
    GLFWwindow* window;
    Food food(WIDTH, HEIGHT);
    bool paused = true;

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

    glfwSetKeyCallback(window, keyCallback);

    RenderStartScreen(window);

    while (paused && !glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        
        bool growing = false;
        if (snake.checkCollision()) {
            isGameOver = true;
            glfwSetWindowShouldClose(window, GL_TRUE);
            // RenderEndScreen(window);
        }

        if (snake.eat(food.getPosition())) {
            growing = true;
            food.respawn(WIDTH, HEIGHT);
        }
        snake.move(growing);
        snake.renderSnake();
        food.render();

        glfwSwapBuffers(window);
        glfwPollEvents();

        usleep(150000);
    }

    glfwTerminate();
    return;
};


int main(int argc, const char * argv[]) {
    // InitGame();
    RenderGame();
}
