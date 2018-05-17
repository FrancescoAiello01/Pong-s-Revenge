#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>

#endif /* Ball_hpp */

#pragma once
#include "Opponent.hpp"
#include "ofApp.h"

class Player;
class GameComponents;

class Ball {
public:
    Ball(float x, float y, float r, float speedX, float speedY);
    void wallBounce(GameComponents * gc);
    void playerBounce(Player * p);
    void opponentBounce(Opponent * o);
    void reset(GameComponents * gc);
    void draw();
    float getY();
    float getX();
private:
    float x;
    float y;
    float r;
    float speedX;
    float speedY;

};
