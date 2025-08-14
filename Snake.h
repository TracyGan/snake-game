#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <utility>

enum Direction { NORTH, SOUTH, WEST, EAST };

class Snake {
    private:
        std::vector<std::pair<int, int>> body;
        Direction dir;

    public:
        Snake(int startX, int startY);

        Direction getDirection();

        // Set Snake's head direction to NSWE
        void setDirection(Direction d);

        // Check if snake collides with border or itself
        bool checkCollision();

        bool eat(std::pair<int, int> foodPosition);

        void grow();

        void renderSnake();

        void renderBody(int x, int y);

        void move(bool growing);
};

#endif 