#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "ofxGui.h"



class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    Ball myBall;
    
    int numBalls;
    vector <Ball> balls;
    int counter;

    float size;

    int c1;
    int c2;
    int c3;
    bool mode0 = true;
    bool mode1 = false;
    bool mode2 = false;
    bool mode3 = false;
    bool mode4 = false;
    bool mode5 = false;

    
    ofxPanel gui;
    ofxToggle modePlain;
    ofxToggle modeSphere;
    ofxToggle modeAlpha;
    ofxToggle modeMultiple;
    ofxToggle modeLine;
    ofxToggle modeLine3D;

    ofxToggle colore;
//    ofxIntSlider velocity;
    ofParameter <float> velocity;
    ofParameter <float> diameter;
    ofParameter <float> distance;
 ofxColorSlider color;
    


    

    
    ofEasyCam cam;
    
};
