#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    webCam.setup(640,480);
    parameters.add(min.set("min",30.0,0.0,300.0));
    parameters.add(max.set("max",300.0,0.0,600.0));
    parameters.add(threshold.set("threshold",100.0,0.0,200.0));
    parameters.add(hole.set("hole",false));
    gui.setup(parameters);

}

//--------------------------------------------------------------
void ofApp::update(){
    webCam.update();

    if(webCam.isFrameNew())
    {

        contour.setMinAreaRadius(min);
        contour.setMaxAreaRadius(max);
        contour.setThreshold(threshold);
        contour.setFindHoles(hole);
        contour.setTargetColor(color);
        contour.findContours(webCam);

    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    webCam.draw(0,0);
    contour.draw();
    gui.draw();
    ofFill();
    ofSetColor(color);
    ofDrawRectangle(webCam.getWidth(),0,128,128);

}
//---------------------------------------------------
void ofApp::exit()
{
    webCam.close();

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
color = webCam.getPixels().getColor(x,y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    color = webCam.getPixels().getColor(x,y);
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
