#include "GameComponents.hpp"
#include <string>

using namespace std;

GameComponents::GameComponents(int currentScore, int highScore, int numberOfBalls, int bulletCounter, int gameState) {
    this->currentScore = currentScore;
    this->highScore = highScore;
    this->numberOfBalls = numberOfBalls;
    this->bulletCounter = bulletCounter;
    this->gameState = gameState;
}

void GameComponents::changeState() { //Increments game state, but if at 3, resets to 1
    if (gameState < 3) {
        gameState++;
    } else if (gameState == 3){
        gameState = 1;
    }
}

void GameComponents::increaseScore() {
    currentScore++;
}

int GameComponents::returnGameState() {
    return gameState;
}

int GameComponents::returnBalls() {
    return numberOfBalls;
}

void GameComponents::reduceBalls() {
    numberOfBalls--;
}

void GameComponents::drawBalls() {
    ofDrawBitmapString("Balls Left: " + ofToString(numberOfBalls), ofGetWidth() / 16, ofGetHeight() - 730);
}

void GameComponents::drawScore() {
    ofDrawBitmapString("Score: " + ofToString(currentScore), ofGetWidth() - 120, ofGetHeight() - 730);
}

void GameComponents::updateHighScore() {
    
    int tempScore;
    
    ifstream file("score.txt");
    if(file.is_open())
    {
        file >> tempScore;
    }
    
    if (tempScore > highScore) {
        highScore = tempScore;
    }
    
    if (currentScore > highScore) {
        highScore = currentScore;
        
        std::ofstream ofs("score.txt", std::ofstream::trunc);
        
        ofs << highScore;
        
        ofs.close();
    }
}

void GameComponents::drawHighScore() {
    if (gameState == 1) {
        ofDrawBitmapString(ofToString(highScore), 950, 20); // Draw high score
    } else if (gameState == 3) {
        ofDrawBitmapString(ofToString(highScore), ofGetWidth() / 2 + 90, ofGetHeight() - 330); // Draw high score
        ofDrawBitmapString(ofToString(currentScore), ofGetWidth() / 2 + 150, ofGetHeight() - 480); //Draw current score
        
        if (currentScore > highScore) {
            ofDrawBitmapString("New High Score!", ofGetWidth() / 2 + 300, ofGetHeight() - 500);
        }
    }
}

void GameComponents::reduceBullet() {
    bulletCounter--;
}

void GameComponents::increaseBullet() {
    if (currentScore % 10 == 0) {
        bulletCounter++;
        currentScore++;
    }
}

int GameComponents::returnBulletCount() {
    return bulletCounter;
}

void GameComponents::drawBulletCount() {
    ofDrawBitmapString("Bullet Count: " + std::to_string(bulletCounter), ofGetWidth() / 16, ofGetHeight() - 710);
}
