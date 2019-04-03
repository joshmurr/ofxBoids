#include "boid.h"
#include "flowfield.h"

Boid::Boid(){
}

void Boid::setup(float x, float y, ofColor c, float ms){
    thisColor.set(c);

    acceleration.set(0,0);
    velocity.set(0,0);
    location.set(x, y);
    target.set(0,0);
    desired.set(0,0);
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

void Boid::wrap(){
    if(location.x > ofGetWidth()){
        location.x = 0;
    } else if(location.x < 0){
        location.x = ofGetWidth();
    }
    if(location.y > ofGetHeight()){
        location.y = 0;
    } else if(location.y < 0){
        location.y = ofGetHeight();
    }
            
}

void Boid::bounce(){
    if(location.x > ofGetWidth()){
        velocity.x *= -1;
    } else if(location.x < 0){
        velocity.x *= -1;
    }
    if(location.y > ofGetHeight()){
        velocity.y *= -1;
    } else if(location.y < 0){
        velocity.y *= -1;
    }
            
}
void Boid::seek(ofVec2f newTarget){
    target.set(newTarget);
    desired = _mouseloc = target - location;
    desired.normalize();
    desired *= maxspeed;
    ofVec2f steer = desired - velocity;
    steer.limit(maxforce);
    applyforce(steer);
}

void Boid::arrive(ofVec2f newTarget){
    target.set(newTarget);
    desired = _mouseloc = target - location;
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


void Boid::arriveCircleJitter(ofVec2f newTarget, int radius){
    target.set(newTarget);
    // Current ARRIVE code
    desired = target - location;
    float d = location.distance(target);
    desired.normalize();

    rad = radius;
    jitter.set(rad*sin(angle), rad*cos(angle));
    newJitter = jitter;
    jitter.normalize();

    if(d<100){
        float m = ofMap(d, 0, 100, 0, maxspeed);
        desired *= m;
    } else {
        angle = ofRandom(PI*2);
        desired *= maxspeed;
    }

    desired += jitter;

    ofVec2f steer = desired - velocity;
    steer.limit(maxforce);
    applyforce(steer);
}

void Boid::flee(ofVec2f newTarget){
    //This isn't righ.
    target.set(newTarget);
    desired = target - location;
    desired.normalize();
    ofVec2f steer = desired - velocity;
    steer.limit(maxforce);
    steer *= -1;
    applyforce(steer);
}

void Boid::follow(Flowfield &flow){
    ofVec2f desired = flow.lookup(location);
    desired *= maxspeed;
    ofVec2f steer = desired - velocity;
    steer.limit(maxforce);
    applyforce(steer);
}

void Boid::draw(bool debug){
    ofSetColor(thisColor);
    ofPushMatrix();
        ofTranslate(location.x, location.y);
        ofRotateRad(atan2(velocity.y, velocity.x));
        ofFill();
        ofSetColor(thisColor);
        ofDrawTriangle(0,5,20,0,0,-5);
    ofPopMatrix();

    if(debug){
        ofSetLineWidth(1);
        ofNoFill();
        ofSetColor(thisColor);
        ofDrawCircle(target, rad);
        ofSetColor(251,255,35);
        ofDrawLine(location.x, location.y, target.x, target.y);
        ofSetColor(thisColor);
        ofDrawLine(location.x, location.y, target.x+newJitter.x, target.y+newJitter.y);
        ofSetColor(145,25,255);
        ofDrawLine(target.x, target.y, target.x+newJitter.x, target.y+newJitter.y);
    }
}
