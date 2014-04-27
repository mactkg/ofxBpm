#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofAddListener(bpm.beatEvent, this, &ofApp::bang);
    bpm.start();
    ofBackground(128);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofDrawBitmapString("Tap space key to auto detect BPM\n"
                       "Use arrow keys to adjust BPM\n"
                       "Press R key to reset counting\n"
                       "BPM:" + ofToString(bpm.getBpm()), 200, 300);
    
    ofFill();
    for (int i=0; i<4; i++) {
        if (int(bpm.getBeatByPercent()*4)==i) {
            ofSetColor(255, 0, 0);
        } else {
            ofSetColor(255);
        }
        ofEllipse(ofGetWidth()/2-150+100*i, ofGetHeight()/2, 50, 50);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' ')
        bpm.tap();
    else if(key == 'r')
        bpm.reset();
    else if(key == OF_KEY_DOWN)
        bpm.setBpm(bpm.getBpm()-1);
    else if(key == OF_KEY_UP)
        bpm.setBpm(bpm.getBpm()+1);
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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

//--------------------------------------------------------------
void ofApp::bang(void){
    ofLogNotice("bang") << ofToString(bpm.getBeatByPercent()) << "/" << ofToString(bpm.getBpm());
}