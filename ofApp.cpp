#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetColor(239);
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.75);

	vector<glm::vec3> locations;
	for (int i = 0; i < 650; i++) {

		glm::vec3 random_point(ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.001), 0, 1, -1, 1),
			ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.001), 0, 1, -1, 1), 
			ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.001), 0, 1, -1, 1));

		int len = 50;
		if (i > 80) { len = 140; }
		if (i > 300) { len = 300; }
		
		random_point = glm::normalize(random_point) * len;
		locations.push_back(random_point);
	}

	for (int i = 0; i < locations.size(); i++) {

		ofDrawSphere(locations[i], 3);
		for (int j = i + 1; j < locations.size(); j++) {

			float length = glm::distance(locations[i], locations[j]);
			if (length < 30) {

				ofDrawLine(locations[i], locations[j]);
			}
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}