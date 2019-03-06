#include "ofApp.h"

ofVec2f randomVec(0,0);
int currentTime = 0;
int deltaTime = 0;
int interval = 800;

//--------------------------------------------------------------
void ofApp::setup(){
    ofColor predCol(255,0,0);
    ofColor preyCol(0,0,255);
    predator.setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), predCol, 1.0);
    prey.setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), preyCol, 2.0);

    randomVec.set(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));

    currentTime = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void ofApp::update(){
    predator.update();
    prey.update();
    deltaTime = ofGetElapsedTimeMillis() - currentTime;
    if(deltaTime > interval){
        //std::cout << "New Location" << endl;
        randomVec.set(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
        //std::cout << "randomVec: " << randomVec << endl;
        currentTime = ofGetElapsedTimeMillis();
    }
    prey.seek(randomVec);
    predator.arrive(prey.location);
}
//--------------------------------------------------------------
void ofApp::draw(){
    predator.draw();
    prey.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    //mouseloc.set(x,y);
    //boid.arrive(mouseloc);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    randomVec.set(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
