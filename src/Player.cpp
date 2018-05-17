#include "Player.hpp"
#include "ofApp.h"

static const float ACCELERATION = 1.5;

Player::Player(float x, float y, float v, int w, int h, bool frozen) {
    this->x = x;
    this->y = y;
    this->v = v;
    this->w = w;
    this->h = h;
    this->frozen = frozen;
}

void Player::playerMoveUp() {
    this->v -= ACCELERATION;
}

void Player::playerMoveDown() {
    this->v += ACCELERATION;
}

void Player::move() {
    this->y += this->v;
    this->v *= 0.95;
}

bool Player::outOfZone() {
    if (this->y <= 0) {
        this->y = 0;
        return true;
    } else if ((this->y + this->h) >= ofGetHeight()) {
        this->y = ofGetHeight() - this->h;
        return true;
    } else {
        return false;
    }
}

void Player::bounce() {
    if (outOfZone()) {
        this->v *= -0.3;
    }
}

void Player::playerDraw() {
    ofSetColor(50, 50, 50);
    ofDrawRectangle(this->x, this->y, this->w, this->h);
}

float Player::getPlayerX() {
    return this->x;
}

float Player::getPlayerY() {
    return this->y;
}

void Player::freeze() {
    frozen = true;
}
