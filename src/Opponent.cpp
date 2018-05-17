#include "Opponent.hpp"
#include "Ball.hpp"
#include "ofApp.h"

static const float ACCELERATION = 0.1;

Opponent::Opponent(float x, float y, float v, int w, int h, bool frozen, float frameCount) {
    this->x = x;
    this->y = y;
    this->v = v;
    this->w = w;
    this->h = h;
    this->frozen = frozen;
    this->frameCount = frameCount;
}

void Opponent::draw() {
    ofSetColor(50, 50, 50);
    ofDrawRectangle(this->x, this->y, this->w, this->h);
}

void Opponent::move(Ball * b) {
    if (frozen != true) {
        this->y += this->v;
        
        float tempY = this->y;
        if (tempY + 40 > b->getY()) {
            this->v -= ACCELERATION / 2;
        } else if (tempY + 40 < b->getY()){
            this->v += ACCELERATION / 2;
        } else if (y == b->getY()) {}
    }
}

bool Opponent::outOfZone() {
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

void Opponent::bounce() {
    if (outOfZone()) {
        this->v * -1;
    }
}

float Opponent::getOpponentX() {
    return x;
}

float Opponent::getOpponentY() {
    return y;
}

void Opponent::freeze() {
    frozen = true;
}

void Opponent::unfreeze() {
    if (frameCount + 60 == ofGetFrameNum()) {
        frozen = false;
        cout << frameCount;
    }
}

void Opponent::countFrame() {
    frameCount = ofGetFrameNum();
    cout << frameCount;
}
