#include <vector>
#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>

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

    auto halfCellSize = CELL_SIZE / 2;

    return (headX + halfCellSize < 0 || headX + halfCellSize >= WIDTH || 
    headY + halfCellSize < 0 || headY + halfCellSize >= HEIGHT);
}

bool Snake::eat(std::pair<int, int> foodPosition) {
    auto headX = body.front().first;
    auto headY = body.front().second;

    int x = headX - foodPosition.first;
    int y = headY - foodPosition.second;

    return sqrt((x * x) + (y * y)) < (FOOD_RADIUS + (CELL_SIZE / 2));
}

void Snake::grow() {
    auto tailX = body.back().first;
    auto tailY = body.back().second;

    if (dir == NORTH) body.push_back({tailX, tailY + CELL_SIZE});
    else if (dir == SOUTH) body.push_back({tailX, tailY - CELL_SIZE});
    else if (dir == EAST) body.push_back({tailX - CELL_SIZE, tailY});
    else if (dir == WEST) body.push_back({tailX + CELL_SIZE, tailY});
}

void Snake::move(bool growing) {
    int headX = body.front().first;
    int headY = body.front().second;

    if (dir == NORTH) headY += CELL_SIZE;
    else if (dir == SOUTH) headY -= CELL_SIZE;
    else if (dir == EAST) headX += CELL_SIZE;
    else if (dir == WEST) headX -= CELL_SIZE;

    body.insert(body.begin(), {headX, headY});

    if (!growing) {
        body.pop_back();
    }
}

void Snake::renderSnake() {
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

    for (size_t i = 1; i < body.size(); ++i) {
        renderBody(body[i].first, body[i].second);
    }

    glFlush(); 
};

void Snake::renderBody(int x, int y) {

    auto halfCellSize = CELL_SIZE / 2;
    
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2i(x - halfCellSize, y - halfCellSize);
        glVertex2i(x + halfCellSize, y - halfCellSize);
        glVertex2i(x + halfCellSize, y + halfCellSize);
        glVertex2i(x - halfCellSize, y + halfCellSize);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(2); 
    glBegin(GL_LINE_LOOP);
        glVertex2i(x - halfCellSize, y - halfCellSize);
        glVertex2i(x + halfCellSize, y - halfCellSize);
        glVertex2i(x + halfCellSize, y + halfCellSize);
        glVertex2i(x - halfCellSize, y + halfCellSize);
    glEnd();
    
}