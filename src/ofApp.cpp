#include "ofApp.h"


void ofApp::setup(){
    ofSetFrameRate(60);
    
    //Gameplay setup
    player = new Player(ofGetWidth() / 16, ofGetHeight() / 2, 0, 10, 80, false);
    opponent = new Opponent(ofGetWidth() - 100, ofGetHeight() / 2, 0, 10, 80, false, 0);
    ball = new Ball(ofGetWidth() / 2, ofGetHeight() / 2, 7, ofRandom(1, 5), ofRandom(1, 5));
    
    //Game Component Setup
    gc = new GameComponents(0, 0, 3, 0, 1); // Second value is high score, make it read that from a file
    
    //Bullet setup
    b = new Bullet(0, 0, 4, false);

    //Play music
    ofSoundPlayer music;
    music.load("music.mp3");
    music.play();
    
//    //Load sound
//    hit.load("hit.mp3");
//    miss.load("miss.mp3");
    
}

void ofApp::update(){
    // Show FPS
    std::stringstream strm;
    strm << "Pong's Revenge | FPS: " << std::floor(ofGetFrameRate() * 1.) / 1.; // No decimals
    ofSetWindowTitle(strm.str());
    
    
    if (gc->returnGameState() == 1) { // Start menu
    } else if (gc->returnGameState() == 2) { // Game screen
        
        //Player & Opponent movements
        player->move();
        opponent->move(ball);
        
        //Bullet movement
        b->move();
        b->collision(opponent);
        
        //Update bullet count
        gc->increaseBullet();
        
        //Opponent bounce off wall
        opponent->bounce();
        
        //Ball bouncing
        ball->wallBounce(gc);
        ball->playerBounce(player);
        ball->opponentBounce(opponent);
        
        //Player bounce off wall
        player->bounce();
        
        //Update high score
        gc->updateHighScore();
        
        //Check if we should unfreeze yet
        opponent->unfreeze();
        
    } else if (gc->returnGameState() == 3) { // End screen
        gc->updateHighScore();
    }
}

void ofApp::draw(){
    if (gc->returnGameState() == 1) { // Start screen
        
        //Start screen setup
        ofSetColor(255);
        ofImage start_screen;
        start_screen.load("main_menu.png");
        start_screen.draw(0,0);
        
        //High score
        ofDrawBitmapString("High Score:", 850, 20);
        gc->drawHighScore();
        
        //Play button
        ofDrawBitmapString("Click To Play", ofGetWidth() / 2 - 50, 500);
        
    } else if (gc->returnGameState() == 2) { // Game screen
        
        player->playerDraw();
        opponent->draw();
        ball->draw();
        b->draw();
        
        //Draw lives remaining and score
        gc->drawBalls();
        gc->drawScore();
        gc->drawBulletCount();
        
    } else if (gc->returnGameState() == 3) { // End screen
        //End screen setup
        ofImage end_screen;
        ofSetColor(255);
        end_screen.load("end_screen.png");
        end_screen.draw(0,0);
        
        gc->drawHighScore();
    }
}

void ofApp::keyPressed(int key){
    if (gc->returnGameState() == 2) {
        if (ofGetKeyPressed('w')) {
            player->playerMoveUp();
        }
        if (ofGetKeyPressed('s')) {
            player->playerMoveDown();
        }
        
        // Fire bullet
        if (gc->returnBulletCount() > 0) {
            if (ofGetKeyPressed(' ')) {
                b->fireBullet();
                b->initialDraw(player);
                gc->reduceBullet();
            }
        }
    }
}

void ofApp::keyReleased(int key){
    if (gc->returnGameState() == 1) { // Start menu
        gc->changeState();
    } else if (gc->returnGameState() == 2) { // Game menu
        //gc->changeState(); //For testing
    } else if (gc->returnGameState() == 3) { // End screen
        gc->changeState();
    }
}

void ofApp::mouseMoved(int x, int y ){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::mouseReleased(int x, int y, int button){
    if (gc->returnGameState() == 1) {
        if(x > ofGetWidth() / 2 - 50 && x < ofGetWidth() / 2 && y > 500 && y < 510)
        {
            gc->changeState();
        }
    }
}

void ofApp::mouseEntered(int x, int y){

}

void ofApp::mouseExited(int x, int y){

}

void ofApp::windowResized(int w, int h){

}

void ofApp::gotMessage(ofMessage msg){

}

void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
