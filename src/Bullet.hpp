#ifndef Bullet_hpp
#define Bullet_hpp

#include <stdio.h>

#endif /* Bullet_hpp */
#pragma once
#include "ofApp.h"

class Player;
class Opponent;
class GameComponents;

class Bullet {
public:
    Bullet(float x, float y, float r, bool fired);
    void move();
    void initialDraw(Player * p);
    void draw();
    void collision(Opponent * o);
    void fireBullet();
private:
    float x;
    float y;
    float r;
    bool fired;
};
