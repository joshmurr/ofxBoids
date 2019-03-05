#include "boid.h"
Boid::Boid(){
}

void Boid::setup(float x, float y, ofColor c, float ms){
    thisColor.set(c);

    acceleration.set(0,0);
    velocity.set(0,0);
    location.set(x, y);
    size = 3.0;

    maxspeed = ms;
    maxforce = 0.1;

    angle = 0;
}

void Boid::update(){
    velocity += acceleration;
    velocity.limit(maxspeed);
    location += velocity;
    acceleration.set(0,0);
}

void Boid::applyforce(ofVec2f force){
    acceleration += force;
}

void Boid::seek(ofVec2f target){
    ofVec2f desired = _mouseloc = target - location;
    desired.normalize();
    desired *= maxspeed;
    ofVec2f steer = desired - velocity;
    steer.limit(maxforce);
    applyforce(steer);
}

void Boid::arrive(ofVec2f target){
    ofVec2f desired = _mouseloc = target - location;
    float d = location.distance(target);
    desired.normalize();
    if(d<100){
        float m = ofMap(d, 0, 100, 0, maxspeed);
        desired *= m;
    } else {
        desired *= maxspeed;
    }

    ofVec2f steer = desired - velocity;
    steer.limit(maxforce);
    applyforce(steer);
}

//void Boid::flee

void Boid::draw(){
    ofSetColor(thisColor);
    ofPushMatrix();
        ofTranslate(location.x, location.y);
        //Create Heading vector:
        float headx = cos(velocity.x);
        float heady = sin(velocity.y);
        ofVec2f heading(headx, heady);

        angle = atan2(heading.y-_mouseloc.y,heading.x-_mouseloc.x)+mathspi; 

        ofRotateRad(angle);
        ofFill();
        ofSetColor(thisColor);
        ofDrawTriangle(0,5,20,0,0,-5);
    ofPopMatrix();
}
