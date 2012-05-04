#!/bin/bash

#make sure you are in the RGBDToolkit project when you run this script
cd ../../addons
>>>>>>> 05fd9d33b12a15e1a861f91b92177427dd303ceb
git clone https://github.com/obviousjim/ofxCameraTrack
git clone https://github.com/Flightphase/ofxGameCamera
git clone https://github.com/Flightphase/ofxRange
git clone https://github.com/Flightphase/ofxTimeline
git clone https://github.com/Flightphase/ofxTween
git clone https://github.com/Flightphase/ofxMSAInteractiveObject
git clone https://github.com/Flightphase/ofxTextInputField
git clone https://github.com/Flightphase/ofxSimpleGuiToo
git clone https://github.com/obviousjim/ofxRGBDepth
git clone https://github.com/obviousjim/ofxCv
git clone https://github.com/obviousjim/ofxKinect
git clone https://github.com/obviousjim/ofxOpenNI
git clone https://github.com/obviousjim/ofxMSATimer

cd ofxCv/
git checkout opencv-2.3
cd ..

# you also need to replace ofxOpenCv/libs/opencv with this link:
# https://github.com/kylemcdonald/ofxCv/downloads
# opencv-2.3.-osx.zip — OpenCV 2.3 library 
