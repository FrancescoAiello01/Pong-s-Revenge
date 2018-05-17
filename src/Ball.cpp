#include "Ball.hpp"
#include "Player.hpp"




Ball::Ball(float x, float y, float r, float speedX, float speedY) {
    this->x = x;
    this->y = y;
    this->r = r;
    this->speedX = speedX;
    this->speedY = speedY;
}

void Ball::wallBounce(GameComponents * gc) {
    this->x = this->x + speedX;
    this->y = this->y + speedY;
    
    if (this->y > ofGetHeight() - this->r) {
        this->y = ofGetHeight() - this->r;
        speedY *= -1;
    }
    if (this->x > ofGetWidth() - this->r) {
        gc->increaseScore();
        reset(gc);
    }
    
    if (this->y < this->r) {
        this->y = this->r;
        speedY = speedY * -1;
    }
    
    if (this->x < this->r) {
        gc->reduceBalls();
        reset(gc);
    }
}

void Ball::playerBounce(Player * p) {
    float playerX = p->getPlayerX();
    float playerY = p->getPlayerY();
    
    if (playerX < this->x && this->x < (playerX + this->r + 10) && playerY + 80 + this->r > this->y && this->y > playerY - this->r) {
        speedX *= -1.05;
    }
//    hit.play();
}

void Ball::opponentBounce(Opponent * o) {
    float opponentX = o->getOpponentX();
    float opponentY = o->getOpponentY();
    
    if (opponentX < this->x && this->x < (opponentX + this->r + 10) && opponentY + 80 + this->r > this->y && this->y > opponentY - this->r) {
        speedX *= -1.05;
    }
//    hit.play();
}

void Ball::reset(GameComponents * gc) {
    if (gc->returnBalls() > 0) {
        x = ofGetWidth() / 2;
        y = ofGetHeight() /2;
    
        if (ofRandom(0, 2) == 1) {
        speedX = ofRandom(-2, -4);
        speedY = ofRandom(-1, 1);
        } else {
            speedX = ofRandom(2, 4);
            speedY = ofRandom(-1, 1);
        }
    } else {
        gc->changeState();
    }
//    miss.play();
}

void Ball::draw() {
    ofSetColor(50, 50, 50);
    ofDrawCircle(this->x, this->y, this->r);
}

float Ball::getY() {
    return this->y;
}

float Ball::getX() {
    return this->x;
}
