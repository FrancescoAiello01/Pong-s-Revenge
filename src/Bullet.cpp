#include "Bullet.hpp"

Bullet::Bullet(float x, float y, float r, bool fired) {
    this->x = x;
    this->y = y;
    this->r = r;
    this->fired = fired;
}

void Bullet::move() {
    if (fired == true) {
        x += 8;
    }
}

void Bullet::initialDraw(Player * p) {
    if (fired == true) {
        x = p->getPlayerX();
        y = p->getPlayerY() + 40;
        ofDrawCircle(x, y, r);
    }
    
}

void Bullet::draw() {
    if (fired == true) {
        ofDrawCircle(x, y, r);
    }
}

void Bullet::collision(Opponent * o) {
    if (o->getOpponentX() < this->x && this->x < (o->getOpponentX() + this->r + 10) && o->getOpponentY() + 80 + this->r > this->y && this->y > o->getOpponentY() - this->r) {
        o->freeze();
        fired = false;
        x += 1; // So count frame only runs one time
        o->countFrame();
    }
    if (x > ofGetWidth()) {
        fired = false;
    }
}

void Bullet::fireBullet() {
    fired = true;
}
