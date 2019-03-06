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

void Boid::flee(ofVec2f target){
    //This isn't right.
    ofVec2f desired = _mouseloc = target - location;
    float d = location.distance(target);
    desired.normalize();
    ofVec2f steer = desired - velocity;
    steer.limit(maxforce);
    steer *= -1;
    applyforce(steer);
}

void Boid::draw(){
    ofSetColor(thisColor);
    ofPushMatrix();
        ofTranslate(location.x, location.y);
        ofRotateRad(atan2(velocity.y, velocity.x));
        ofFill();
        ofSetColor(thisColor);
        ofDrawTriangle(0,5,20,0,0,-5);
    ofPopMatrix();
}
