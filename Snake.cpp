#include <vector>
#include <iostream>
#include <GLFW/glfw3.h>
#include "snake.h"
#include "constants.h"
#include "food.h"

Snake::Snake(int startX, int startY) {
    body.push_back({startX, startY});
    dir = NORTH;
}

Direction Snake::getDirection() {
    return dir;
}

void Snake::setDirection(Direction d) {
    dir = d;
}   

bool Snake::checkCollision() {
    auto headX = body.front().first;
    auto headY = body.front().second;

    return (headX < 0 || headX >= WIDTH || headY < 0 || headY >= HEIGHT);
}

void Snake::eat() {

}

void Snake::move() {
    if (dir == NORTH) body.front().second += 1;
    else if (dir == SOUTH) body.front().second -= 1;
    else if (dir == EAST) body.front().first += 1;
    else if (dir == WEST) body.front().first -= 1;
}

void Snake::render() {
    auto x = body.front().first;
    auto y = body.front().second;

    auto halfCellSize = CELL_SIZE / 2;
    // Head of the snake
    glColor3f(0.0f, 0.39f, 0.0f);


    glBegin(GL_QUADS);
        glVertex2i(x - halfCellSize, y - halfCellSize);
        glVertex2i(x + halfCellSize, y - halfCellSize);
        glVertex2i(x + halfCellSize, y + halfCellSize);
        glVertex2i(x - halfCellSize, y + halfCellSize);
    glEnd();

    // Eyes of the snake
    int eyeDimension = CELL_SIZE / 5;
    int leftEyeX, leftEyeY, rightEyeX, rightEyeY;

    switch (dir) {
         case NORTH: 
            leftEyeX = x - CELL_SIZE / 4 - eyeDimension / 2;
            rightEyeX = x + CELL_SIZE / 4 - eyeDimension / 2;
            leftEyeY = rightEyeY = y + halfCellSize - eyeDimension - 2; 
            break;

        case SOUTH: 
            leftEyeX = x - CELL_SIZE / 4 - eyeDimension / 2;
            rightEyeX = x + CELL_SIZE / 4 - eyeDimension / 2;
            leftEyeY = rightEyeY = y - halfCellSize + 2; 
            break;
            
        case WEST: 
            leftEyeX = rightEyeX = x - halfCellSize + 2; 
            leftEyeY = y + CELL_SIZE / 4 - eyeDimension / 2;
            rightEyeY = y - CELL_SIZE / 4 - eyeDimension / 2;
            break;
            
        case EAST: 
            leftEyeX = rightEyeX = x + halfCellSize - eyeDimension - 2;
            leftEyeY = y + CELL_SIZE / 4 - eyeDimension / 2;
            rightEyeY = y - CELL_SIZE / 4 - eyeDimension / 2;
            break;
    }

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        // Left eye
        glVertex2i(leftEyeX, leftEyeY);
        glVertex2i(leftEyeX + eyeDimension, leftEyeY);
        glVertex2i(leftEyeX + eyeDimension, leftEyeY + eyeDimension);
        glVertex2i(leftEyeX, leftEyeY + eyeDimension);

        // Right eye
        glVertex2i(rightEyeX, rightEyeY);
        glVertex2i(rightEyeX + eyeDimension, rightEyeY);
        glVertex2i(rightEyeX + eyeDimension, rightEyeY + eyeDimension);
        glVertex2i(rightEyeX, rightEyeY + eyeDimension);
    glEnd();

    glFlush(); 
};