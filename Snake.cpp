#include <vector>
#include <iostream>
#include <GLFW/glfw3.h>
using namespace std;

enum Direction { UP, DOWN, LEFT, RIGHT };

struct Snake {
    vector<pair<float, float>> body;
    Direction dir;

    Snake() {
        body.push_back({0.0f, 0.0f});
        dir = RIGHT;
    }

    void move() {
        float x = body[0].first;
        float y  = body[0].second;

        switch (dir) {
            case UP: 
                y += 0.05f;
                break;
            case DOWN:
                y -= 0.05f;
                break;
            case LEFT:
                x -= 0.05f;
                break;
            case RIGHT:
                x += 0.05f;
                break;
        }
    }
};

int main(void) {
    GLFWwindow* window;

    if (!glfwInit()) return -1;

    window = glfwCreateWindow(640, 480, "Snake Game", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    } 

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}