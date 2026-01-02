#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    // Multi-page canvas system
    int currentPage;
    int totalPages;
    void drawNavigationArrows();
    void drawPageNumber();
    void nextPage();
    void previousPage();
    bool isMouseOverRightArrow();
    bool isMouseOverLeftArrow();
    
    // Page content drawing functions
    void drawPage1();  // Skeptical figure page
    void drawPage2();  // Curiosity and wonder scene
    void drawPage3();  // Grief symbols
    void drawPage4();  // 3D Universe of Play
    void drawPage5();  // The Sublime of Reality - Renaissance Masterwork
    void drawPage6();  // The Absurd - Surreal chaos
    
    // Page 2: Curiosity and Wonder
    void drawCuriousFigure();
    vector<ofVec3f> sparkles;        // Position and size of sparkles
    vector<ofColor> sparkleColors;   // Colors of each sparkle
    vector<ofVec2f> floatingStars;   // Mysterious floating stars
    vector<float> starRotations;     // Star rotation angles
    float reachAnimation;            // Reaching gesture animation
    float eyeSparkle;                // Eye brightness for wonder
    
    // Page 3: Grief (symbolic)
    struct Petal {
        ofVec2f pos;
        float rotation;
        float rotationSpeed;
        float fallSpeed;
        float alpha;
        ofColor color;
    };
    vector<Petal> fallingPetals;     // Wilting flower petals
    struct Teardrop {
        ofVec2f pos;
        float speed;
        float alpha;
    };
    vector<Teardrop> tears;          // Falling tears/rain
    float heavyWeight;               // Sinking stone animation
    float voidExpansion;             // Empty void pulsing
    vector<ofVec2f> brokenPieces;    // Scattered broken pieces
    vector<float> pieceAngles;       // Angles of broken pieces
    float fadingLight;               // Light fading away
    
    // Page 4: 3D Universe of Play
    struct PlayShape {
        ofVec3f position;
        ofVec3f rotation;
        ofVec3f rotationSpeed;
        ofVec3f orbitCenter;
        float orbitRadius;
        float orbitSpeed;
        float orbitAngle;
        ofColor color;
        int shapeType; // 0=sphere, 1=box, 2=cone, 3=cylinder
        float size;
        float bouncePhase;
    };
    vector<PlayShape> playShapes;
    ofEasyCam cam3D;                // 3D camera
    ofLight light1, light2;         // 3D lights
    float cameraOrbitAngle;         // Camera rotation
    bool enable3DCamera;
    
    // Page 5: The Sublime of Reality - Renaissance-level masterwork
    struct SublimeGeometry {
        ofVec3f position;
        ofVec3f rotation;
        ofVec3f rotationSpeed;
        float scale;
        int geometryType; // 0=icosahedron, 1=octahedron, 2=torus, 3=nested spheres
        ofColor innerColor;
        ofColor outerColor;
        float pulsation;
        float pulsationPhase;
    };
    vector<SublimeGeometry> sacredShapes;
    
    struct LightRay3D {
        ofVec3f origin;
        ofVec3f direction;
        float length;
        float width;
        ofColor color;
        float intensity;
        float pulsation;
    };
    vector<LightRay3D> divineRays;
    
    struct VortexRing {
        float radius;
        float height;
        float rotation;
        float rotationSpeed;
        ofColor color;
        int segments;
    };
    vector<VortexRing> cosmicVortex;
    
    ofEasyCam sublimeCam;
    ofLight sublimeLight1, sublimeLight2, sublimeLight3;
    
    void drawSublimeReality();
    void drawAtmosphericDepth3D();
    void drawSacredGeometry3D();
    void drawDivineLight3D();
    void drawInfiniteRegress();
    void drawFractalCrystal(ofVec3f pos, float size, int depth, float hue);
    void drawGoldenSpiral3D();
    
    float goldenRatio;
    float sublimeTime;
    float fibonacci[20];
    
    // Page 6: The Absurd - Surreal nightmare/dream
    struct AbsurdObject {
        ofVec3f position;
        ofVec3f rotation;
        ofVec3f scale;
        ofVec3f velocity;
        int shapeType;
        ofColor color;
        float glitchAmount;
        float wobblePhase;
        bool inverted;
        float textureOffset;
    };
    vector<AbsurdObject> absurdObjects;
    
    ofEasyCam absurdCam;
    ofLight absurdLight1, absurdLight2;
    
    // Procedural textures (no external images needed)
    ofImage checkerTexture;
    ofImage noiseTexture;
    ofImage spiralTexture;
    ofImage glitchTexture;
    
    void drawAbsurdReality();
    void generateProceduralTextures();
    void drawGlitchedGeometry(ofVec3f pos, float size, float glitch);
    void drawImpossibleStaircase();
    void drawMelting3DObject(ofVec3f pos, float size, float meltAmount);
    void drawInvertedCube(ofVec3f pos, float size);
    void drawParadoxSphere(ofVec3f pos, float size);
    
    float absurdTime;
    float chaosLevel;
    
    // Skeptical figure properties (Page 1)
    void drawSkepticalFigure();
    
    float figureX, figureY;          // Position
    float floatOffset;               // Vertical floating animation
    float headTiltAngle;             // Head tilt for skepticism
    float eyeWanderX, eyeWanderY;    // Uncertain eye movements
    float thoughtBubbleAlpha;        // Pulsing thought bubble
    float shoulderSlump;             // Slumped shoulders
    vector<ofVec2f> questionMarks;   // Floating question marks
    vector<float> questionMarkAlphas; // Alpha for each question mark
    float time;                      // Animation timer
};

