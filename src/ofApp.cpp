#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    flowfield.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<boids.size(); i++){
        boids[i].update();
        boids[i].wrap();
        boids[i].follow(flowfield);
    }
    //if(deltaTime > interval){
    //}
    //idler.arriveCircleJitter(mouseloc, 80);
}
//--------------------------------------------------------------
void ofApp::draw(){
    flowfield.draw();
    for(int i=0; i<boids.size(); i++){
        boids[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        Boid newBoid;
        newBoid.setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofColor(ofRandom(255),ofRandom(255),55), ofRandom(0.1,3));
        boids.push_back(newBoid);
    }
    if(key == '1'){
        for(int i=0; i<10; i++){
            Boid newBoid;
            newBoid.setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofColor(ofRandom(255),ofRandom(255),55), ofRandom(0.1,3));
            boids.push_back(newBoid);
        }
    }
    if(key == '2'){
        for(int i=0; i<50; i++){
            Boid newBoid;
            newBoid.setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofColor(ofRandom(255),ofRandom(255),55), ofRandom(0.1,3));
            boids.push_back(newBoid);
        }
    }
    if(key == '3'){
        for(int i=0; i<100; i++){
            Boid newBoid;
            newBoid.setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofColor(ofRandom(255),ofRandom(255),55), ofRandom(0.1,3));
            boids.push_back(newBoid);
        }
    }
    if(key == 'c'){
        boids.clear();
    }
    if(key == 'n'){
        printf("Number of Boids: %lu\n", boids.size());
    }


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mouseloc.set(x,y);
    //boid.arrive(mouseloc);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //for(int i=0; i<boids.size(); i++){
        //boids[i].setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofColor(ofRandom(255),214,55), 1.5);
    //}
    flowfield.setup();
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
