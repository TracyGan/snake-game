#include <vector>
#include <iostream>
#include <GLFW/glfw3.h>
#include "snake.h"

Snake::Snake(int startX, int startY) {
    body.push_back({startX, startY});
    dir = NORTH;
}

void Snake::changeDirection(Direction d) {
    if ((dir == NORTH && d != SOUTH) ||
        (dir == SOUTH && d != NORTH) ||
        (dir == EAST  && d != WEST)  ||
        (dir == WEST  && d != EAST)) {
        dir = d;
    };
}   

bool Snake::checkCollision() {
    return true;
}

void Snake::eat() {

}

void Snake::move() {
    if (dir == NORTH) body.front().second += 1;
    else if (dir == SOUTH) body.front().second -= 1;
    else if (dir == EAST) body.front().first += 1;
    else if (dir == WEST) body.front().first -= 1;
}

void Snake::render(int cellSize) {
    auto x = body.front().first;
    auto y = body.front().second;
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