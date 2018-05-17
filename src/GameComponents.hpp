#ifndef GameComponents_hpp
#define GameComponents_hpp

#include <stdio.h>

#endif /* GameComponents_hpp */

#pragma once
#include "ofMain.h"

class GameComponents {
public:
    GameComponents(int currentScore, int highScore, int numberOfBalls, int bulletCounter, int gameState);
    void changeState();
    void increaseScore();
    int returnGameState();
    int returnBalls();
    void reduceBalls();
    void drawBalls();
    void drawScore();
    void updateHighScore();
    void drawHighScore();
    void reduceBullet();
    void increaseBullet();
    int returnBulletCount();
    void drawBulletCount();
private:
    int currentScore;
    int highScore;
    int numberOfBalls;
    int bulletCounter;
    int gameState;
};
