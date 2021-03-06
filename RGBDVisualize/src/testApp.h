#pragma once

#include "ofMain.h"
#include "ofxRGBDRenderer.h"
#include "ofxRGBDVideoDepthSequence.h"
#include "ofxDepthImageRecorder.h"
#include "ofxGameCamera.h"
#include "ofxTimeline.h"
#include "ofxTLVideoPlayer.h"
#include "ofxTLVideoDepthAlignmentScrubber.h"
#include "ofxTLDepthImageSequence.h"
#include "ofxMSAInteractiveObjectDelegate.h"
#include "ofxSimpleGuiToo.h"
#include "ofxTLCameraTrack.h"
#include "ofxDepthHoleFiller.h"
#include "ofxRGBDRenderSettings.h"

typedef struct {
	ofxMSAInteractiveObjectWithDelegate* load;
	ofxMSAInteractiveObjectWithDelegate* toggle;
	string fullCompPath;
	bool batchExport;
	bool wasRenderedInBatch;
	string name;
} Comp;

class testApp : public ofBaseApp, public ofxMSAInteractiveObjectDelegate {

  public:
	void setup();
	void update();
	void draw();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
 	
	void updateRenderer(ofVideoPlayer& fromPlayer);
	void processDepthFrame();
	void processGeometry();
	void drawGeometry();
	
	bool loadNewProject();
	bool loadDepthSequence(string path);
	bool loadVideoFile(string hiResPath, string lowResPath); //hires can be ""
	bool loadAlignmentMatrices(string path);
	
    void loadShaders();
    
	ofxXmlSettings projectsettings;

	void loadCompositions();
	void newComposition();
	void saveComposition();
	bool loadCompositionAtIndex(int i);
	bool loadAssetsFromCompositionDirectory(string mediaPath);
	void refreshCompButtons();
	
	//MSA Object delegate
	ofxMSAInteractiveObjectWithDelegate* newCompButton;
	ofxMSAInteractiveObjectWithDelegate* saveCompButton;	
	vector<Comp*> comps;
	
	bool playerElementAdded;
	
 	void objectDidRollOver(ofxMSAInteractiveObject* object, int x, int y);
    void objectDidRollOut(ofxMSAInteractiveObject* object, int x, int y);
	void objectDidPress(ofxMSAInteractiveObject* object, int x, int y, int button);	
	void objectDidRelease(ofxMSAInteractiveObject* object, int x, int y, int button);	
	void objectDidMouseMove(ofxMSAInteractiveObject* object, int x, int y);
	
	void finishRender();
	void toggleCameraPlayback();
	
	void populateTimelineElements();
	void loadTimelineFromCurrentComp();
	
	void startCameraRecord();
	void stopCameraRecord();
	void toggleCameraRecord();
	
	int currentCompIndex;
	string currentCompositionDirectory;
	string mediaBinDirectory;
	string pairingsFile;
	ofVideoPlayer* hiResPlayer;
	ofVideoPlayer* lowResPlayer;
		
    bool pauseRender;
	bool temporalAlignmentMode;
	bool captureFramePair;
	long currentDepthFrame;
	bool viewComps;
	bool shouldExportSettings;
    
	unsigned short* depthPixelDecodeBuffer;
//	ofShortPixels holeFilledPixels;
	
	bool allLoaded;
    float accumulatedPerlinOffset;
    
	ofxGameCamera cam;
	ofxTLCameraTrack cameraTrack;
	bool sampleCamera;
	ofxRGBDRenderer renderer;
	
	ofxTimeline timeline;
	ofxTLVideoPlayer videoTimelineElement;
	ofxTLDepthImageSequence depthSequence;
	ofxTLVideoDepthAlignmentScrubber alignmentScrubber;
	ofxDepthHoleFiller holeFiller;
	ofxRGBDRenderSettings settingsExporter;
	
	ofRectangle fboRectangle;
    
    ofFbo swapFbo; //used for temp drawing
	ofFbo fbo1;
    ofFbo fbo2;
    ofFbo dofBuffer;
    ofFbo dofBlurBuffer;
    int curbuf;
    
    ofRectangle depthAlignAssistRect;
    ofRectangle colorAlignAssistRect;
    
	ofImage savingImage;
	string saveFolder;
	string lastSavedDate;

	float currentXMultiplyShift;
	float currentYMultiplyShift;
//	float currentXAdditiveShift;
//	float currentYAdditiveShift;
//	float currentXScale;
//	float currentYScale;
//	float currentRotationCompensation;
//	float currentZFuzz;
	

    bool selfOcclude;
	bool currentLockCamera;
	
	bool shouldResetDuration;
    bool setDurationToClipLength;
	int currentDuration;
	
	bool currentMirror;
	bool presentMode;
	
	bool shouldSaveCameraPoint;
	bool shouldClearCameraMoves;
	bool shouldResetCamera;
	
	bool enableVideoInOut;
	float videoInPercent;
	float videoOutPercent;
	
	bool drawPointcloud;
	bool drawWireframe;
	bool drawMesh;
	bool drawDepthDistortion;
	bool drawGeometryDistortion;
    
	int currentSimplify;
	
	bool fillHoles;
	int currentHoleKernelSize;
	int currentHoleFillIterations;
	
	bool hasHiresVideo;
	
	bool startRenderMode;
	bool currentlyRendering;
	int currentRenderFrame;
	int lastRenderFrame;
	int numFramesToRender;
	int numFramesRendered;
	bool rendererDirty;
    ofNode renderedCameraPos;
    
	ofImage testImageOne;
	ofImage testImageTwo;
	
	ofVec3f lightpos;
	ofLight light;

	string pathDelim;
    
    bool drawDOF;
    ofShader DOFCloud;
    ofShader alphaFadeShader;
    ofShader gaussianBlur;
    ofShader dofRange;
    ofShader dofBlur;
    

};
