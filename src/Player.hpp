#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>

#endif /* Player_hpp */

#pragma once

class Player {
public:
    Player(float x, float y, float v, int w, int h, bool frozen);
    void playerMoveUp();
    void playerMoveDown();
    void playerDraw();
    void move();
    bool outOfZone();
    void bounce();
    float getPlayerX();
    float getPlayerY();
    void freeze();
private:
    float x;
    float y;
    float v;
    int w;
    int h;
    bool frozen;
};
