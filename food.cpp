#include <random>
#include <GLFW/glfw3.h>

#include "food.h"
#include <GLFW/glfw3.h>

Food::Food(int maxX, int maxY) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribX(15, maxX - 15);
    std::uniform_int_distribution<> distribY(15, maxY - 15);

    position.first = distribX(gen);
    position.second = distribY(gen);
}

void Food::render() {
    float radius = 10.0f;  
    int numSegments = 50;   
    float centerX = position.first;     
    float centerY = position.second;      

    glColor3f(1.0f, 165.0f/255.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(centerX, centerY); // center of circle
        for(int i = 0; i <= numSegments; i++) {
            float angle = 2.0f * 3.14159f * i / numSegments;
            float dx = radius * cos(angle);
            float dy = radius * sin(angle);
            glVertex2f(centerX + dx, centerY + dy);
        }
    glEnd();

    glFlush();
}