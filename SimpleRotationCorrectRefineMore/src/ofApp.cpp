
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    
    //System Setup Stuff
    
    ofBackground(255); //white background
    ofSetFrameRate(120); //default is 60, but you can adjust this
    ofEnableAlphaBlending(); //allow for transparency, bc why not?
    
    //ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    ofSetFrameRate(200);
    ofBackground(50);
    
    //initial values
    ofSetCircleResolution(40);
    
    gui.setup();
    gui.add(modePlain.setup("Plain", false));
    gui.add(modeSphere.setup("Texture Sphere", false));
    gui.add(modeAlpha.setup("Texture Alpha", false));
    gui.add(modeMultiple.setup("Texture Multiple", false));
    gui.add(modeLine.setup("Texture Line", false));
    gui.add(modeLine3D.setup("Line3D", false));

//    gui.add(colore.setup("color", true));
    
    gui.add(velocity.set("velocity", 0.02f, -0.04f, 0.04f));
    gui.add(diameter.set("diameter", 10, 1,30));
    gui.add(distance.set("Line3D distance", 0.5, 0.01,2));


//
    gui.add(color.setup("color for Line3D",ofColor(200,100,150),ofColor(0,0),ofColor(255,255)));
    




//    gui.add(modeSphere.setup("Texture Sphere"));
//    gui.add(modeAlpha.setup("Texture Alpha"));

    

   // ofSetBackgroundAuto(true); //maybe we don't want to autodraw the background... if we don't set this to false
    //    ofEnableSmoothing(); //this makes shapes much smoother... similar to anti-aliasing in Photoshop, Maya, etc.
    

   

    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //update many balls
    for(int i = 0; i < balls.size(); i++){
        balls[i].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
       gui.draw();
    
    if(modePlain){
        mode0 = true;
        mode1 = false;
        mode2 = false;
        mode3 = false;
        mode4 = false;
        mode5 = false;
        
    }
    if(modeSphere){
        mode0 = false;
        mode1 = true;
        mode2 = false;
        mode3 = false;
        mode4 = false;
        mode5 = false;

    }
    if(modeAlpha){
        mode0 = false;
        mode1 = false;
        mode2 = true;
        mode3 = false;
        mode4 = false;
        mode5 = false;

    }
    if(modeMultiple){
        mode0 = false;
        mode1 = false;
        mode2 = false;
        mode3 = true;
        mode4 = false;
        mode5 = false;

    }
    if(modeLine){
        mode0 = false;
        mode1 = false;
        mode2 = false;
        mode3 = false;
        mode4 = true;
        mode5 = false;

    }
    if(modeLine3D){
        mode0 = false;
        mode1 = false;
        mode2 = false;
        mode3 = false;
        mode4 = false;
        mode5 = true;
        
    }
    if(mode4 == true) {
        ofSetColor(c1,c2,c3);
        ofPushStyle();
        
        ofSetLineWidth(diameter);
        ofNoFill();
        ofBeginShape();
        
        for(int i = 0; i < balls.size(); i++){
            ofCurveVertex(balls[i].point.x, balls[i].point.y);
     

            //        ofCurveVertex(balls[i].point.x * -0.1 + ofGetWidth()/2, balls[i].point.y * -0.1 + ofGetHeight()/2);
            //        ofCurveVertex(balls[i].point.x * -0.1 + ofGetWidth()/2, balls[i].point.y * -0.1 + ofGetHeight()/2);
        }
        ofEndShape();
        ofPopStyle();
        
    }
    if(mode5 == true) {
        
        ofSetColor(color);//        ofSetColor(c1,c2,c3);
        ofPushStyle();

        
        ofSetLineWidth(diameter);

        ofNoFill();
        ofBeginShape();
        for(int i = 0; i < balls.size(); i++){
            
            ofCurveVertex(balls[i].point.x, balls[i].point.y);
            //        ofCurveVertex(balls[i].point.x * 0.1 + ofGetWidth()/2, balls[i].point.y * 0.1 + ofGetHeight()/2);
            
            ofCurveVertex(balls[i].point.x * distance , balls[i].point.y * distance);
            ofCurveVertex(balls[i].point.x * -distance + ofGetWidth()/2+ ofGetWidth()/4, balls[i].point.y * -distance + ofGetHeight()/2 + ofGetHeight()/4);
        }
        ofEndShape();
        ofPopStyle();

        
    }


//    if(modeMultiple+modeAlpha+modeSphere){
//        mode1 = true;
//        mode2 = true;
//        mode3 = true;
//    }




    //note Easy Cam auto translates to center of screen
   // cam.begin();
    
//    ofPushStyle();
//    ofSetColor(255, 255, 255, 25);
//    ofRect(0,0, ofGetWidth(), ofGetHeight());
//    ofPopStyle();
    
    //draw many balls
    ofPushMatrix();

//        ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
//        ofScale(.5, .5);
        for(int i = 0; i < balls.size(); i++){
            balls[i].draw();
        }
    ofPopMatrix();
    //cam.end();
    

    stringstream ss;
    
    ss << "(m): CLEAR"<<endl;
    ofDrawBitmapString(ss.str().c_str(), 20, 300);
    
    ss << "(spacebar): ScreenShot"<<endl;
    ofDrawBitmapString(ss.str().c_str(), 20, 320);
    
    
    
    
    
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
      if (key == ' '){
          ofImage screenShot;
          screenShot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
          screenShot.saveImage("Sand.png");
      }
      if (key == 'm'){
            balls.clear();
      }
    if(modeSphere==true){
//      if (key == 'u'){
       cout<<modeSphere<<endl;
          mode1 = true;
          mode2 = false;
          mode3 = false;
      }
    
   if(modeAlpha==true){
        mode1 = false;
        mode2 = true;
        mode3 = false;
   }
    
    if(modeMultiple==true){
           mode1 = false;
           mode2 = false;
           mode3 = true;
      }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    Ball temp;
      ofSetFrameRate(120);
//    for(int i = 0; i < balls.size(); i++){
//        balls[i].mouseDragged(x, y, button);
//    }
    float xP = (x - ofGetWidth()/2);
    float yP = (y - ofGetHeight()/2);
//    size = ofRandom(1,20);
    
    
    temp.setup(atan2(ofGetMouseY() - ofGetHeight()/2, ofGetMouseX() - ofGetWidth()/2), //angle
               velocity, //rotationSpeed
               sqrt(xP*xP + yP*yP), //radius
//               size, // diameter
               diameter,
               //ofGetWidth()/2, //centerX
               //ofGetHeight()/2, //centerY
               ofGetMouseX() - ofGetWidth()/2,//pointX
               ofGetMouseY() - ofGetHeight()/2,//pointY
               0,//pointZ
               c1+ofRandom(50,150),//color1
               c2+ofRandom(50,150),//color2
               c3+ofRandom(50,150),
               mode0,
               mode1,
               mode2,
               mode3,
               mode4,
               mode5
               );
    balls.push_back(temp);
cout << "numBalls = ";
 cout << balls.size() << endl;
    if(mode4 == true) {
        ofSetColor(c1,c2,c3);
    }

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    float xP = (x - ofGetWidth()/2);
    float yP = (y - ofGetHeight()/2);
    c1 = ofRandom(0,255);
    c2 = ofRandom(0,255);
    c3 = ofRandom(0,255);

//    colore = (ofRandom(50,255), ofRandom(50,255), ofRandom(50,255));
//    colore = (255, 0, 0);
    
    // ofEllipse(10,10,10,10);
    
    //    balls[counter].update();
    //    balls[counter].draw();
    //    counter++;
    
    //    createNewBall();
    
    size = 10;
    
    Ball temp;
    temp.setup(atan2(ofGetMouseY() - ofGetHeight()/2, ofGetMouseX() - ofGetWidth()/2), //angle
               velocity, //rotationSpeed
               sqrt(xP * xP + yP *yP ), //radius
//               size,//diameter
               diameter,
               //ofGetWidth()/2, //centerX
               //ofGetHeight()/2, //centerY
               ofGetMouseX() - ofGetWidth()/2,//pointX
               ofGetMouseY() - ofGetHeight()/2,//pointY
               0,//pointZ
               c1,//color1
               c2,//color2
               c3,//color3
               mode0,
               mode1,
               mode2,
               mode3,
               mode4,
               mode5
               );
    balls.push_back(temp);
    cout << "numBalls = ";
    cout << balls.size() << endl;
 
//    if (c1==255){
//        c1 -= 1;
//    }
//    if (c1==1){
//        c1 += 1;
//    }


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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