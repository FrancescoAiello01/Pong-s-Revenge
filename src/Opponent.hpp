#ifndef Opponent_hpp
#define Opponent_hpp

#include <stdio.h>

#endif /* Opponent_hpp */
#pragma once

class Ball;

class Opponent {
public:
    Opponent(float x, float y, float v, int w, int h, bool frozen, float frameCount);
    void draw();
    void move(Ball * b);
    bool outOfZone();
    void bounce();
    float getOpponentX();
    float getOpponentY();
    void freeze();
    void countFrame();
    void unfreeze();
private:
    float x;
    float y;
    float v;
    int w;
    int h;
    bool frozen;
    float frameCount;
    
};
