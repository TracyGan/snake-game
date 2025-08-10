#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <utility>

using namespace std;

enum Direction { UP, DOWN, LEFT, RIGHT };

struct Snake {
    int x, y;
    vector<pair<int, int>> body;
    Direction dir;

    // Constructor
    Snake();

    // Change Snake's head direction to NSWE
    void changeDirection(Direction d);

    // Check if snake collides with border or itself
    bool checkCollision();

    void eat();
};


#endif 