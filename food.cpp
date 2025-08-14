#include <random>
#include <GLFW/glfw3.h>

#include "food.h"
#include "constants.h"

Food::Food(int maxX, int maxY) {
    std::random_device rd;
    std::mt19937 gen(rd());

    // Ensure that the coordinates are not at the border
    std::uniform_int_distribution<> distribX(15, maxX - 15);
    std::uniform_int_distribution<> distribY(15, maxY - 15);

    position.first = distribX(gen);
    position.second = distribY(gen);
}

std::pair<int, int> Food::getPosition() {
    return position;
}

void Food::render() {
    int numSegments = 50;   
    float centerX = position.first;     
    float centerY = position.second;      

    glColor3f(1.0f, 165.0f/255.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(centerX, centerY); // center of circle
        for(int i = 0; i <= numSegments; i++) {
            float angle = 2.0f * 3.14159f * i / numSegments;
            float dx = FOOD_RADIUS * cos(angle);
            float dy = FOOD_RADIUS * sin(angle);
            glVertex2f(centerX + dx, centerY + dy);
        }
    glEnd();

    glFlush();
}