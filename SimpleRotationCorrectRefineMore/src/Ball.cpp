//
//  Ball.cpp
//  Dynamics_1
//
//  Created by Conor Russomanno on 10/8/15.
//
//

#include "Ball.h"

//--------------------------------------------------------------
void Ball::setup(float _angle, float _rotationSpeed, int _radius, float _diameter,
                 //float _centerX,
                 //float _centerY,
                 float _pointX, float _pointY, float _pointZ, int _color1,int _color2,int _color3, bool _mode0, bool _mode1, bool _mode2, bool _mode3, bool _mode4, bool _mode5){
  ofSetFrameRate(120);
//    angle= asin(mouseY)/radius;
    angle = _angle;
    rotationSpeed= _rotationSpeed;
    radius = _radius;
    diameter = _diameter;
   // center.x = _centerX;
   // center.y = _centerY;
    point.x = _pointX;
    point.y = _pointY;
    point.z = _pointZ;
    color1 = _color1;
    color2 = _color2;
    color3 = _color3;
    mode0 = _mode0;
    mode1 = _mode1;
    mode2 = _mode2;
    mode3 = _mode3;
    mode4 = _mode4;
    mode5 = _mode5;
    

    
//    mode1=false;
//    mode2=false;

    

  

    


    ofSetCircleResolution(40);
    
}



//--------------------------------------------------------------
void Ball::update(){
    

//    angle = asin(mouseY)/radius;
 
    angle += rotationSpeed;//at each update the angle get's incremented

    //	}
    if (angle>=TWO_PI) { //if the angle is more than or equal to two PI (a full rotation measured in Radians) then make it zero.
        angle=0;
    }
    
    //here we get the sine and cosine values for the angle

    point.x = (cos(angle)* radius)+ ofGetWidth()/2;
    point.y = (sin(angle)* radius)+ ofGetHeight()/2;
    if(mode2==true || mode3==true){
//    point.z -= 2.5;
    }
//    diameter -= 0.01;
    if (diameter <= 0){
        diameter = 0;
    }
//    color1++;
//    color2++;
//    color3++;
    

    
//    point.set(cos(angle) * radius, sin(angle) * radius, 0);//here we set the cyan circle position

    
}


//--------------------------------------------------------------
void Ball::draw(){
  
    ofSetColor(color1, color2, color3);
    ofCircle(point, diameter);
        
            ofSetFrameRate(120);
    if (mode1==true){
    
    ofSetColor(color1-70, color2-70, color3-70);
    ofCircle(point, diameter+7);
    
    ofSetColor(color1-50, color2-50, color3-50);
    ofCircle(point, diameter+5);
    
    ofSetColor(color1-30, color2-30, color3-30);
    ofCircle(point, diameter+3);
    
    ofSetColor(color1-20, color2-20, color3-20);
    ofCircle(point, diameter+2);
    
    ofSetColor(color1-10, color2-10, color3-10);
    ofCircle(point, diameter+1);
    
    ofSetColor(color1, color2, color3);
    ofCircle(point, diameter);
        
    ofSetColor(color1+10, color2+10, color3+10);
    ofCircle(point, diameter-1);
        
    ofSetColor(color1+20, color2+20, color3+20);
    ofCircle(point, diameter-3);
    }
    
    if (mode2==true){
        
    ofSetColor(color1, color2, color3,7);
    ofCircle(point, diameter+15);
        
    ofSetColor(color1, color2, color3,13);
    ofCircle(point, diameter+12);
        
    ofSetColor(color1, color2, color3,20);
    ofCircle(point, diameter+10);
        
    ofSetColor(color1, color2, color3,40);
    ofCircle(point, diameter+7);
        
    ofSetColor(color1, color2, color3,70);
    ofCircle(point, diameter+5);
        
    ofSetColor(color1, color2, color3,120);
    ofCircle(point, diameter+3.5);

    ofSetColor(color1, color2, color3,180);
    ofCircle(point, diameter+2);
    
        
    ofSetColor(ofRandom(color1), color2, color3);
    ofCircle(point, diameter);
        
    }
    
    if (mode3==true){
        
        ofSetColor(color1, color2, color3);
        ofCircle(point, diameter);
        
        ofSetColor(color1, color2, color3);
        ofCircle(point+40, diameter);
        
        ofSetColor(color1, color2, color3);
        ofCircle(point+20, diameter);
    }

    if (mode4==true){
        
        
    }
}

//--------------------------------------------------------------
void Ball::keyPressed(int key){
    
//    if (key == 'u'){
//        mode1 = true;
//    }
//    if (key == 'i'){
//        cout<<mode2<<endl;
//        mode2 = true;
//    }
//     if (key == 'p'){
//        mode1 = false;
//        mode2 = false;
//
//    }



}

//--------------------------------------------------------------
void Ball::keyReleased(int key){
    
}

//--------------------------------------------------------------
void Ball::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void Ball::mouseDragged(int x, int y, int button){
    

}

//--------------------------------------------------------------
void Ball::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Ball::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Ball::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void Ball::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void Ball::dragEvent(ofDragInfo dragInfo){
    
}
