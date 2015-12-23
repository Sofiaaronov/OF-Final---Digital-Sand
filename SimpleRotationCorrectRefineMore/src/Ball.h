//
//  Ball.h
//  Dynamics_1
//
//  Created by Conor Russomanno on 10/8/15.
//
//

#include "ofMain.h"

class Ball : public ofBaseApp{
    
public:
    void setup(
               float _angle,
               float _rotationSpeed,
               int _radius,
               float _diameter,
              // float _centerX,
              // float _centerY,
               float _pointX,
               float _pointY,
               float _pointZ,
               int _color1,
               int _color2,
               int _color3,
               bool _mode0,
               bool _mode1,
               bool _mode2,
               bool _mode3,
               bool _mode4,
               bool _mode5
               
               );
  
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
    

    float angle;
    float sine;
    float cosine;
    float rotationSpeed;
    int radius;
    int color1;
    int color2;
    int color3;
    bool mode0;
    bool mode1;
    bool mode2;
    bool mode3;
    bool mode4;
    bool mode5;
    
    vector<ofMeshFace> triangles;
        ofSpherePrimitive sphere;

    
    

               float diameter;
    
    
    
    

    

    
    ofPoint center;
               
    ofPoint point;
    
    
    
};