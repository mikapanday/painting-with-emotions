#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    // Set the background color to a contemplative gray-blue
    ofBackground(180, 190, 200);
    
    // Set the framerate
    ofSetFrameRate(60);
    
    // Enable smooth graphics
    ofEnableSmoothing();
    
    // Set the window title
    ofSetWindowTitle("Painting with Emotions - Sketchbook");
    
    // Initialize multi-page system
    currentPage = 1;
    totalPages = 6;
    
    // Initialize model interpretations
    modelRow = 0;      // 0 = Sonnet 4.5, 1 = GPT-5.1 Codex Max
    totalRows = 2;
    
    // Initialize figure position (center of screen)
    figureX = ofGetWidth() / 2;
    figureY = ofGetHeight() / 2;
    
    // Initialize animation variables
    floatOffset = 0;
    headTiltAngle = 0;
    eyeWanderX = 0;
    eyeWanderY = 0;
    thoughtBubbleAlpha = 0;
    shoulderSlump = 0;
    time = 0;
    
    // Initialize question marks around the figure
    for(int i = 0; i < 5; i++) {
        float angle = ofRandom(TWO_PI);
        float distance = ofRandom(150, 250);
        questionMarks.push_back(ofVec2f(cos(angle) * distance, sin(angle) * distance));
        questionMarkAlphas.push_back(ofRandom(100, 255));
    }
    
    // Initialize Page 2: Curiosity and Wonder elements
    for(int i = 0; i < 30; i++) {
        // Random sparkles floating around
        sparkles.push_back(ofVec3f(
            ofRandom(ofGetWidth()),
            ofRandom(ofGetHeight()),
            ofRandom(1, 4)  // size
        ));
        
        // Bright, magical colors
        sparkleColors.push_back(ofColor(
            ofRandom(150, 255),
            ofRandom(150, 255),
            ofRandom(200, 255)
        ));
    }
    
    // Initialize floating stars to discover
    for(int i = 0; i < 8; i++) {
        float angle = ofRandom(TWO_PI);
        float distance = ofRandom(100, 300);
        floatingStars.push_back(ofVec2f(
            ofGetWidth()/2 + cos(angle) * distance,
            ofGetHeight()/2 + sin(angle) * distance - 100
        ));
        starRotations.push_back(ofRandom(TWO_PI));
    }
    
    reachAnimation = 0;
    eyeSparkle = 0;
    
    // Initialize Page 3: Grief symbols
    // Create falling petals (loss, wilting)
    for(int i = 0; i < 40; i++) {
        Petal petal;
        petal.pos = ofVec2f(ofRandom(ofGetWidth()), ofRandom(-200, ofGetHeight()));
        petal.rotation = ofRandom(TWO_PI);
        petal.rotationSpeed = ofRandom(-0.05, 0.05);
        petal.fallSpeed = ofRandom(0.5, 2.0);
        petal.alpha = ofRandom(150, 255);
        // Muted, dying flower colors
        petal.color = ofColor(
            ofRandom(100, 150),  // Faded reds/browns
            ofRandom(80, 120),
            ofRandom(100, 130)
        );
        fallingPetals.push_back(petal);
    }
    
    // Create tears/rain drops
    for(int i = 0; i < 25; i++) {
        Teardrop tear;
        tear.pos = ofVec2f(ofRandom(ofGetWidth()), ofRandom(-300, ofGetHeight()));
        tear.speed = ofRandom(2.0, 5.0);
        tear.alpha = ofRandom(100, 200);
        tears.push_back(tear);
    }
    
    // Initialize broken pieces (shattered hope)
    for(int i = 0; i < 12; i++) {
        brokenPieces.push_back(ofVec2f(
            ofGetWidth()/2 + ofRandom(-150, 150),
            ofGetHeight()/2 + ofRandom(-100, 100)
        ));
        pieceAngles.push_back(ofRandom(TWO_PI));
    }
    
    heavyWeight = 0;
    voidExpansion = 0;
    fadingLight = 255;
    
    // Initialize Page 4: 3D Universe of Play
    enable3DCamera = false;
    cameraOrbitAngle = 0;
    
    // Setup 3D camera
    cam3D.setDistance(800);
    
    // Setup lights for 3D scene
    light1.setPointLight();
    light1.setPosition(200, 200, 200);
    light1.setDiffuseColor(ofColor(255, 200, 150));
    
    light2.setPointLight();
    light2.setPosition(-200, -100, 200);
    light2.setDiffuseColor(ofColor(150, 200, 255));
    
    // Create playful 3D shapes
    for(int i = 0; i < 25; i++) {
        PlayShape shape;
        
        // Random position in 3D space
        shape.orbitCenter = ofVec3f(
            ofRandom(-200, 200),
            ofRandom(-200, 200),
            ofRandom(-200, 200)
        );
        
        shape.orbitRadius = ofRandom(50, 150);
        shape.orbitSpeed = ofRandom(0.3, 1.5);
        shape.orbitAngle = ofRandom(TWO_PI);
        
        // Random rotation speeds
        shape.rotationSpeed = ofVec3f(
            ofRandom(-2, 2),
            ofRandom(-2, 2),
            ofRandom(-2, 2)
        );
        shape.rotation = ofVec3f(0, 0, 0);
        
        // Bright, playful colors
        shape.color = ofColor(
            ofRandom(100, 255),
            ofRandom(100, 255),
            ofRandom(100, 255)
        );
        
        // Random shape type
        shape.shapeType = (int)ofRandom(0, 4);
        shape.size = ofRandom(20, 60);
        shape.bouncePhase = ofRandom(TWO_PI);
        
        playShapes.push_back(shape);
    }
    
    // Initialize Page 5: The Sublime of Reality - Renaissance Masterwork
    goldenRatio = 1.618033988749895;
    sublimeTime = 0;
    
    // Calculate Fibonacci sequence for sacred proportions
    fibonacci[0] = 1;
    fibonacci[1] = 1;
    for(int i = 2; i < 20; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }
    
    // Setup sublime 3D camera
    sublimeCam.setDistance(1200);
    sublimeCam.setFov(70);
    
    // Setup three-point lighting (Renaissance technique in 3D)
    sublimeLight1.setPointLight();
    sublimeLight1.setPosition(0, -400, 400);
    sublimeLight1.setDiffuseColor(ofColor(255, 250, 240));
    sublimeLight1.setSpecularColor(ofColor(255, 255, 255));
    
    sublimeLight2.setPointLight();
    sublimeLight2.setPosition(-300, 200, 200);
    sublimeLight2.setDiffuseColor(ofColor(180, 200, 255));
    
    sublimeLight3.setPointLight();
    sublimeLight3.setPosition(300, 200, 200);
    sublimeLight3.setDiffuseColor(ofColor(255, 200, 180));
    
    // Create sacred geometric forms (Platonic solids and beyond)
    for(int i = 0; i < 12; i++) {
        SublimeGeometry geo;
        
        float angle = (i / 12.0) * TWO_PI;
        float radius = 300 + (i % 3) * 150;
        float height = sin(angle * 3) * 200;
        
        geo.position = ofVec3f(
            cos(angle) * radius,
            height,
            sin(angle) * radius
        );
        
        geo.rotation = ofVec3f(ofRandom(360), ofRandom(360), ofRandom(360));
        geo.rotationSpeed = ofVec3f(
            ofRandom(-0.3, 0.3),
            ofRandom(-0.5, 0.5),
            ofRandom(-0.3, 0.3)
        );
        
        geo.scale = 30 + ((int)fibonacci[i % 10] % 50);
        geo.geometryType = i % 4;
        geo.pulsationPhase = ofRandom(TWO_PI);
        
        // Divine color palette - golds, ethereal whites, celestial blues
        geo.innerColor = ofColor(255, 245, 230);
        float hue = (i / 12.0) * 60 + 180; // Blues to golds
        geo.outerColor = ofColor::fromHsb(hue, 100, 255);
        
        sacredShapes.push_back(geo);
    }
    
    // Create divine light rays (Chiaroscuro in 3D)
    for(int i = 0; i < 16; i++) {
        LightRay3D ray;
        
        float angle = (i / 16.0) * TWO_PI;
        ray.origin = ofVec3f(0, -300, 0);
        ray.direction = ofVec3f(
            cos(angle) * 0.7,
            1.0,
            sin(angle) * 0.7
        );
        ray.length = 800 + ofRandom(-200, 200);
        ray.width = ofRandom(20, 50);
        ray.color = ofColor(255, 250, 240);
        ray.intensity = ofRandom(80, 150);
        ray.pulsation = ofRandom(TWO_PI);
        
        divineRays.push_back(ray);
    }
    
    // Create cosmic vortex rings (infinite regress)
    for(int i = 0; i < 15; i++) {
        VortexRing ring;
        ring.radius = 50 + i * 40;
        ring.height = i * 80 - 560;
        ring.rotation = ofRandom(TWO_PI);
        ring.rotationSpeed = 0.5 + i * 0.1;
        ring.segments = 36 + i * 4;
        
        // Color shifts from earthly to celestial
        float hue = 180 + (i / 15.0) * 80;
        ring.color = ofColor::fromHsb(hue, 150 - i * 8, 255);
        
        cosmicVortex.push_back(ring);
    }
    
    // Initialize Page 6: The Absurd
    absurdTime = 0;
    chaosLevel = 0;
    
    // Setup absurd camera
    absurdCam.setDistance(600);
    
    // Chaotic lighting
    absurdLight1.setPointLight();
    absurdLight1.setPosition(200, 0, 200);
    absurdLight1.setDiffuseColor(ofColor(255, 0, 255)); // Magenta madness
    
    absurdLight2.setPointLight();
    absurdLight2.setPosition(-200, 0, 200);
    absurdLight2.setDiffuseColor(ofColor(0, 255, 255)); // Cyan chaos
    
    // Generate procedural textures (no external files needed)
    generateProceduralTextures();
    
    // Create absurd objects - things that shouldn't exist
    for(int i = 0; i < 20; i++) {
        AbsurdObject obj;
        
        // Random impossible positions
        obj.position = ofVec3f(
            ofRandom(-400, 400),
            ofRandom(-300, 300),
            ofRandom(-400, 400)
        );
        
        obj.rotation = ofVec3f(
            ofRandom(360),
            ofRandom(360),
            ofRandom(360)
        );
        
        // Absurd scales - too big, too small, wrong proportions
        obj.scale = ofVec3f(
            ofRandom(0.3, 3.0),
            ofRandom(0.3, 3.0),
            ofRandom(0.3, 3.0)
        );
        
        // Chaotic velocities
        obj.velocity = ofVec3f(
            ofRandom(-2, 2),
            ofRandom(-2, 2),
            ofRandom(-2, 2)
        );
        
        obj.shapeType = (int)ofRandom(0, 6);
        
        // Garish, clashing colors
        obj.color = ofColor(
            ofRandom(100, 255),
            ofRandom(100, 255),
            ofRandom(100, 255)
        );
        
        obj.glitchAmount = ofRandom(0.0, 1.0);
        obj.wobblePhase = ofRandom(TWO_PI);
        obj.inverted = ofRandom(1.0) > 0.5;
        obj.textureOffset = ofRandom(1000);
        
        absurdObjects.push_back(obj);
    }
}

//--------------------------------------------------------------
void ofApp::generateProceduralTextures() {
    // Generate textures programmatically (no external images needed)
    
    int texSize = 256;
    
    // Checkerboard texture
    checkerTexture.allocate(texSize, texSize, OF_IMAGE_COLOR);
    for(int y = 0; y < texSize; y++) {
        for(int x = 0; x < texSize; x++) {
            bool check = ((x / 32) + (y / 32)) % 2 == 0;
            ofColor c = check ? ofColor(255) : ofColor(0);
            checkerTexture.setColor(x, y, c);
        }
    }
    checkerTexture.update();
    
    // Noise texture
    noiseTexture.allocate(texSize, texSize, OF_IMAGE_COLOR);
    for(int y = 0; y < texSize; y++) {
        for(int x = 0; x < texSize; x++) {
            float n = ofNoise(x * 0.05, y * 0.05) * 255;
            noiseTexture.setColor(x, y, ofColor(n));
        }
    }
    noiseTexture.update();
    
    // Spiral texture
    spiralTexture.allocate(texSize, texSize, OF_IMAGE_COLOR);
    for(int y = 0; y < texSize; y++) {
        for(int x = 0; x < texSize; x++) {
            float dx = x - texSize/2;
            float dy = y - texSize/2;
            float angle = atan2(dy, dx);
            float dist = sqrt(dx*dx + dy*dy);
            float spiral = sin(angle * 5 + dist * 0.1) * 127 + 128;
            spiralTexture.setColor(x, y, ofColor(spiral));
        }
    }
    spiralTexture.update();
    
    // Glitch texture
    glitchTexture.allocate(texSize, texSize, OF_IMAGE_COLOR);
    for(int y = 0; y < texSize; y++) {
        for(int x = 0; x < texSize; x++) {
            int val = (int)ofRandom(0, 256);
            glitchTexture.setColor(x, y, ofColor(val, ofRandom(255), ofRandom(255)));
        }
    }
    glitchTexture.update();
}

//--------------------------------------------------------------
void ofApp::update() {
    // Increment time for animations
    time += 0.016; // Approximately 60fps
    
    // Floating animation - slow, uncertain bobbing
    floatOffset = sin(time * 0.8) * 15 + sin(time * 1.3) * 8;
    
    // Head tilt - skeptical angle that sways
    headTiltAngle = sin(time * 0.5) * 12;
    
    // Eye wander - uncertain, searching movements
    eyeWanderX = sin(time * 1.2) * 3 + cos(time * 0.7) * 2;
    eyeWanderY = cos(time * 0.9) * 3 + sin(time * 1.5) * 2;
    
    // Thought bubble pulsing
    thoughtBubbleAlpha = 100 + sin(time * 2.0) * 80;
    
    // Shoulder slump - varies with doubt
    shoulderSlump = 5 + sin(time * 0.6) * 3;
    
    // Update floating question marks
    for(int i = 0; i < questionMarks.size(); i++) {
        // Rotate question marks slowly around figure
        float angle = atan2(questionMarks[i].y, questionMarks[i].x);
        angle += 0.003 * (i % 2 == 0 ? 1 : -1);
        float distance = questionMarks[i].length();
        questionMarks[i].x = cos(angle) * distance;
        questionMarks[i].y = sin(angle) * distance + sin(time * 2.0 + i) * 5;
        
        // Pulse alpha
        questionMarkAlphas[i] = 150 + sin(time * 1.5 + i * 0.5) * 100;
    }
    
    // Update Page 2: Curiosity and Wonder animations
    reachAnimation = sin(time * 1.5) * 20;
    eyeSparkle = 200 + sin(time * 3.0) * 55;
    
    // Update sparkles - floating upward with shimmer
    for(int i = 0; i < sparkles.size(); i++) {
        sparkles[i].y -= 0.5;
        sparkles[i].x += sin(time * 2.0 + i) * 0.3;
        
        // Reset if goes off top
        if(sparkles[i].y < -10) {
            sparkles[i].y = ofGetHeight() + 10;
            sparkles[i].x = ofRandom(ofGetWidth());
        }
    }
    
    // Update star rotations and positions
    for(int i = 0; i < floatingStars.size(); i++) {
        starRotations[i] += 0.02 * (i % 2 == 0 ? 1 : -1);
        
        // Gentle orbit around center
        float centerX = ofGetWidth()/2;
        float centerY = ofGetHeight()/2 - 100;
        float dx = floatingStars[i].x - centerX;
        float dy = floatingStars[i].y - centerY;
        float angle = atan2(dy, dx);
        angle += 0.005;
        float dist = sqrt(dx*dx + dy*dy);
        
        floatingStars[i].x = centerX + cos(angle) * dist;
        floatingStars[i].y = centerY + sin(angle) * dist + sin(time * 1.5 + i) * 10;
    }
    
    // Update Page 3: Grief symbols
    // Petals falling and wilting
    for(int i = 0; i < fallingPetals.size(); i++) {
        fallingPetals[i].pos.y += fallingPetals[i].fallSpeed;
        fallingPetals[i].pos.x += sin(time * 2.0 + i) * 0.5;
        fallingPetals[i].rotation += fallingPetals[i].rotationSpeed;
        
        // Fade as they fall
        fallingPetals[i].alpha -= 0.2;
        
        // Reset at top if reaches bottom
        if(fallingPetals[i].pos.y > ofGetHeight() + 20 || fallingPetals[i].alpha < 20) {
            fallingPetals[i].pos.y = -20;
            fallingPetals[i].pos.x = ofRandom(ofGetWidth());
            fallingPetals[i].alpha = ofRandom(150, 255);
        }
    }
    
    // Tears falling
    for(int i = 0; i < tears.size(); i++) {
        tears[i].pos.y += tears[i].speed;
        
        // Reset at top
        if(tears[i].pos.y > ofGetHeight() + 10) {
            tears[i].pos.y = -10;
            tears[i].pos.x = ofRandom(ofGetWidth());
        }
    }
    
    // Heavy weight sinking
    heavyWeight = sin(time * 0.3) * 30 + 30;
    
    // Void expansion (emptiness)
    voidExpansion = 100 + sin(time * 0.5) * 40;
    
    // Fading light
    fadingLight = 200 + sin(time * 0.4) * 55;
    
    // Broken pieces slowly drifting apart
    for(int i = 0; i < brokenPieces.size(); i++) {
        float centerX = ofGetWidth()/2;
        float centerY = ofGetHeight()/2;
        float dx = brokenPieces[i].x - centerX;
        float dy = brokenPieces[i].y - centerY;
        
        // Drift away from center
        brokenPieces[i].x += dx * 0.0001;
        brokenPieces[i].y += dy * 0.0001;
        
        pieceAngles[i] += 0.01;
    }
    
    // Update Page 4: 3D Universe of Play
    cameraOrbitAngle += 0.005;
    
    for(int i = 0; i < playShapes.size(); i++) {
        // Update orbit position
        playShapes[i].orbitAngle += playShapes[i].orbitSpeed * 0.01;
        
        // Calculate position in orbit with bouncing
        float bounce = sin(time * 3.0 + playShapes[i].bouncePhase) * 30;
        
        playShapes[i].position.x = playShapes[i].orbitCenter.x + 
            cos(playShapes[i].orbitAngle) * playShapes[i].orbitRadius;
        playShapes[i].position.y = playShapes[i].orbitCenter.y + 
            sin(playShapes[i].orbitAngle) * playShapes[i].orbitRadius + bounce;
        playShapes[i].position.z = playShapes[i].orbitCenter.z + 
            sin(playShapes[i].orbitAngle * 0.5) * playShapes[i].orbitRadius;
        
        // Update rotation
        playShapes[i].rotation.x += playShapes[i].rotationSpeed.x;
        playShapes[i].rotation.y += playShapes[i].rotationSpeed.y;
        playShapes[i].rotation.z += playShapes[i].rotationSpeed.z;
    }
    
    // Update Page 5: The Sublime of Reality
    sublimeTime = time;
    
    // Update sacred geometries - eternal rotation
    for(int i = 0; i < sacredShapes.size(); i++) {
        sacredShapes[i].rotation.x += sacredShapes[i].rotationSpeed.x;
        sacredShapes[i].rotation.y += sacredShapes[i].rotationSpeed.y;
        sacredShapes[i].rotation.z += sacredShapes[i].rotationSpeed.z;
        
        // Pulsation (breathing of reality)
        sacredShapes[i].pulsation = sin(time * 1.5 + sacredShapes[i].pulsationPhase) * 0.3 + 1.0;
        
        // Gentle vertical oscillation
        sacredShapes[i].position.y += sin(time * 0.5 + i) * 0.5;
    }
    
    // Update divine rays - pulsing intensity
    for(int i = 0; i < divineRays.size(); i++) {
        divineRays[i].intensity = 100 + sin(time * 2.0 + divineRays[i].pulsation) * 50;
    }
    
    // Update vortex rings - spiral motion
    for(int i = 0; i < cosmicVortex.size(); i++) {
        cosmicVortex[i].rotation += cosmicVortex[i].rotationSpeed * 0.01;
    }
    
    // Update Page 6: The Absurd
    absurdTime = time;
    chaosLevel = sin(time * 0.5) * 0.5 + 0.5; // Oscillating chaos
    
    // Update absurd objects - chaotic, nonsensical motion
    for(int i = 0; i < absurdObjects.size(); i++) {
        // Chaotic rotation
        absurdObjects[i].rotation.x += absurdObjects[i].velocity.x;
        absurdObjects[i].rotation.y += absurdObjects[i].velocity.y;
        absurdObjects[i].rotation.z += absurdObjects[i].velocity.z;
        
        // Wobbling position (reality glitching)
        float wobble = sin(time * 3.0 + absurdObjects[i].wobblePhase) * 20;
        absurdObjects[i].position.x += sin(time + i) * 0.5;
        absurdObjects[i].position.y += wobble * 0.05;
        
        // Random direction changes (absurd physics)
        if(ofRandom(1.0) < 0.01) {
            absurdObjects[i].velocity *= -1;
        }
        
        // Glitch amount fluctuates
        absurdObjects[i].glitchAmount = 0.5 + sin(time * 4.0 + i) * 0.5;
        
        // Scale breathing (wrong)
        float breathe = sin(time * 2.0 + i) * 0.2 + 1.0;
        absurdObjects[i].scale.x = absurdObjects[i].scale.x * 0.95 + breathe * 0.05;
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    // Handle 3D camera mode for pages 4, 5, and 6
    enable3DCamera = (currentPage == 4 || currentPage == 5 || currentPage == 6);
    
    // Draw the current page content
    switch(currentPage) {
        case 1:
            drawPage1();
            break;
        case 2:
            drawPage2();
            break;
        case 3:
            drawPage3();
            break;
        case 4:
            drawPage4();
            break;
        case 5:
            drawPage5();
            break;
        case 6:
            drawPage6();
            break;
    }
    
    // Draw navigation arrows, page number, and model navigation (on top of everything)
    // Disable depth test for 2D UI elements
    ofDisableDepthTest();
    drawNavigationArrows();
    drawPageNumber();
    drawModelNavigation();
}

//--------------------------------------------------------------
void ofApp::drawPage1() {
    // Page 1: Skeptical Figure
    if(modelRow == 0) {
        ofBackground(180, 190, 200); // Sonnet 4.5: contemplative gray-blue
    } else {
        ofBackground(140, 160, 200); // GPT-5.1 Codex Max: cooler analytical tint
    }
    
    ofSetColor(40, 50, 60);
    ofDrawBitmapString("Page 1: A Figure Skeptical About the Future", 20, 20);
    ofSetColor(80, 90, 100);
    ofDrawBitmapString("Prompt: \"Create a floating figure that experiences", 20, 40);
    ofDrawBitmapString("        a lot of skepticism about the future\"", 20, 55);
    ofSetColor(40, 50, 60);
    if(modelRow == 0) {
        ofDrawBitmapString("Sonnet 4.5 interpretation • Press SPACE to reset animation", 20, 75);
    } else {
        ofDrawBitmapString("GPT-5.1 Codex Max interpretation • Press SPACE to reset animation", 20, 75);
    }
    
    drawSkepticalFigure();
}

//--------------------------------------------------------------
void ofApp::drawPage2() {
    // Page 2: Curiosity and Wonder
    // Deep purple-blue night sky gradient
    if(modelRow == 0) {
        ofBackgroundGradient(ofColor(20, 10, 50), ofColor(60, 40, 100), OF_GRADIENT_LINEAR); // Sonnet 4.5
    } else {
        ofBackgroundGradient(ofColor(10, 20, 70), ofColor(90, 70, 140), OF_GRADIENT_LINEAR); // GPT-5.1 Codex Max
    }
    
    ofSetColor(220, 220, 255);
    ofDrawBitmapString("Page 2: Curiosity and Wonder", 20, 20);
    ofSetColor(180, 180, 220);
    ofDrawBitmapString("Prompt: \"Create a scene about curiosity and wonder\"", 20, 40);
    ofSetColor(220, 220, 255);
    if(modelRow == 0) {
        ofDrawBitmapString("Discovering the magic around us (Sonnet 4.5 view)", 20, 60);
    } else {
        ofDrawBitmapString("Analytical awe through GPT-5.1 Codex Max", 20, 60);
    }
    
    // Draw magical sparkles floating everywhere
    for(int i = 0; i < sparkles.size(); i++) {
        ofSetColor(sparkleColors[i], 150 + sin(time * 3.0 + i) * 100);
        ofDrawCircle(sparkles[i].x, sparkles[i].y, sparkles[i].z);
        
        // Add a glow effect
        ofSetColor(sparkleColors[i], 50);
        ofDrawCircle(sparkles[i].x, sparkles[i].y, sparkles[i].z * 2);
    }
    
    // Draw mysterious floating stars
    for(int i = 0; i < floatingStars.size(); i++) {
        ofPushMatrix();
        ofTranslate(floatingStars[i].x, floatingStars[i].y);
        ofRotateDeg(ofRadToDeg(starRotations[i]));
        
        // Draw a glowing star
        ofSetColor(255, 220, 100, 200);
        ofBeginShape();
        for(int j = 0; j < 10; j++) {
            float angle = (j * TWO_PI / 10);
            float radius = (j % 2 == 0) ? 15 : 7;
            ofVertex(cos(angle) * radius, sin(angle) * radius);
        }
        ofEndShape(true);
        
        // Glow
        ofSetColor(255, 240, 150, 80);
        ofDrawCircle(0, 0, 20);
        
        ofPopMatrix();
    }
    
    // Draw the curious figure
    drawCuriousFigure();
}

//--------------------------------------------------------------
void ofApp::drawCuriousFigure() {
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2 + 50);
    
    // Gentle floating motion
    float float_y = sin(time * 1.2) * 10;
    ofTranslate(0, float_y);
    
    // BODY - upright, open posture
    ofSetColor(80, 120, 180);
    ofDrawRectangle(-30, 0, 60, 90);
    
    // ARMS - one reaching up with wonder, one at side
    ofSetColor(80, 120, 180);
    
    // Right arm reaching up toward the stars
    ofPushMatrix();
    ofTranslate(30, 10);
    ofRotateDeg(-45 + reachAnimation);
    ofDrawRectangle(0, 0, 15, 70);
    
    // Hand reaching
    ofSetColor(100, 140, 200);
    ofDrawCircle(7, 70, 10);
    ofPopMatrix();
    
    // Left arm at side
    ofSetColor(80, 120, 180);
    ofDrawRectangle(-45, 10, 15, 60);
    
    // LEGS - standing with wonder
    ofDrawRectangle(-25, 90, 18, 55);
    ofDrawRectangle(7, 90, 18, 55);
    
    // HEAD - tilted up, looking at the wonders above
    ofSetColor(120, 160, 220);
    ofPushMatrix();
    ofTranslate(0, -25);
    ofRotateDeg(-15);  // Looking upward
    ofDrawCircle(0, 0, 35);
    
    // EYES - wide with wonder and curiosity
    ofSetColor(eyeSparkle, eyeSparkle, 255);
    ofDrawCircle(-12, -5, 8);   // Left eye - wide open
    ofDrawCircle(12, -5, 8);    // Right eye - wide open
    
    // Pupils looking up at the stars
    ofSetColor(20, 20, 80);
    ofDrawCircle(-12, -8, 4);
    ofDrawCircle(12, -8, 4);
    
    // Sparkle in eyes (wonder)
    ofSetColor(255, 255, 255);
    ofDrawCircle(-10, -10, 2);
    ofDrawCircle(14, -10, 2);
    
    // MOUTH - open in awe and excitement
    ofSetColor(180, 120, 140);
    ofDrawCircle(0, 8, 8);
    ofSetColor(80, 40, 60);
    ofDrawCircle(0, 8, 6);
    
    // EYEBROWS - raised with curiosity
    ofSetLineWidth(3);
    ofSetColor(60, 80, 120);
    ofNoFill();
    ofBeginShape();
    ofVertex(-20, -15);
    ofVertex(-12, -18);
    ofVertex(-4, -15);
    ofEndShape();
    
    ofBeginShape();
    ofVertex(4, -15);
    ofVertex(12, -18);
    ofVertex(20, -15);
    ofEndShape();
    ofFill();
    
    ofPopMatrix();
    
    // Magical aura around figure
    ofSetColor(150, 200, 255, 30 + sin(time * 2.0) * 20);
    ofDrawCircle(0, 20, 80 + sin(time * 2.5) * 10);
    ofSetColor(200, 150, 255, 20 + sin(time * 2.5) * 15);
    ofDrawCircle(0, 20, 100 + sin(time * 2.0) * 15);
    
    // Sparkles emanating from reaching hand
    for(int i = 0; i < 5; i++) {
        float handX = 30 + cos(ofDegToRad(-45 + reachAnimation)) * 40;
        float handY = 10 + sin(ofDegToRad(-45 + reachAnimation)) * 40;
        
        float sparkX = handX + sin(time * 3.0 + i * 0.8) * 30;
        float sparkY = handY + cos(time * 2.5 + i * 0.8) * 30 - 20;
        
        ofSetColor(255, 230, 150, 180 + sin(time * 4.0 + i) * 70);
        ofDrawCircle(sparkX, sparkY, 3);
    }
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::drawPage3() {
    // Page 3: Grief - Symbolic Representation
    // Heavy, oppressive dark gray background
    if(modelRow == 0) {
        ofBackground(40, 45, 50);  // Sonnet 4.5: muted heaviness
    } else {
        ofBackground(25, 30, 35);  // GPT-5.1 Codex Max: deeper void
    }
    
    ofSetColor(150, 150, 160);
    ofDrawBitmapString("Page 3: Grief", 20, 20);
    ofSetColor(120, 120, 130);
    ofDrawBitmapString("Prompt: \"Don't use people figurines.", 20, 40);
    ofDrawBitmapString("        Display the feeling of grief with symbols\"", 20, 55);
    ofSetColor(150, 150, 160);
    if(modelRow == 0) {
        ofDrawBitmapString("A symbolic journey through loss (Sonnet 4.5)", 20, 75);
    } else {
        ofDrawBitmapString("Cold analytic grief interpretation (GPT-5.1 Codex Max)", 20, 75);
    }
    
    // THE VOID - Empty space, absence, what is missing
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2 - 150);
    ofSetColor(0, 0, 0, 180);
    ofDrawCircle(0, 0, voidExpansion);
    ofSetColor(20, 20, 25, 150);
    ofDrawCircle(0, 0, voidExpansion * 1.3);
    ofPopMatrix();
    
    // FADING LIGHT - A single dimming light, hope fading
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, 100);
    ofSetColor(fadingLight, fadingLight - 50, fadingLight - 100, fadingLight);
    ofDrawCircle(0, 0, 25);
    ofSetColor(fadingLight - 100, fadingLight - 120, fadingLight - 150, fadingLight * 0.3);
    ofDrawCircle(0, 0, 50);
    ofSetColor(fadingLight - 150, fadingLight - 170, fadingLight - 180, fadingLight * 0.1);
    ofDrawCircle(0, 0, 80);
    ofPopMatrix();
    
    // FALLING PETALS - Wilting flowers, dying beauty, loss
    for(const auto& petal : fallingPetals) {
        ofPushMatrix();
        ofTranslate(petal.pos.x, petal.pos.y);
        ofRotateDeg(ofRadToDeg(petal.rotation));
        
        ofSetColor(petal.color, petal.alpha);
        // Draw petal shape
        ofBeginShape();
        ofVertex(0, -8);
        ofVertex(4, -4);
        ofVertex(6, 0);
        ofVertex(4, 4);
        ofVertex(0, 6);
        ofVertex(-4, 4);
        ofVertex(-6, 0);
        ofVertex(-4, -4);
        ofEndShape(true);
        
        ofPopMatrix();
    }
    
    // HEAVY STONE - The weight of grief pressing down
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2 + 100 + heavyWeight);
    
    // Draw a heavy, oppressive stone
    ofSetColor(60, 60, 70);
    ofDrawRectangle(-70, -40, 140, 80);
    
    // Cracks in the stone (something broken)
    ofSetColor(40, 40, 45);
    ofSetLineWidth(2);
    ofDrawLine(-50, -20, -20, 10);
    ofDrawLine(20, -25, 45, 15);
    ofDrawLine(-30, 0, 35, -5);
    
    // Shadow beneath (heaviness, burden)
    ofSetColor(0, 0, 0, 80);
    ofDrawEllipse(0, 60, 160, 20);
    
    ofPopMatrix();
    
    // TEARS/RAIN - Falling like constant sorrow
    for(const auto& tear : tears) {
        ofSetColor(100, 120, 140, tear.alpha);
        
        // Draw teardrop shape
        ofPushMatrix();
        ofTranslate(tear.pos.x, tear.pos.y);
        
        ofBeginShape();
        ofVertex(0, 0);
        ofVertex(-3, 8);
        ofVertex(0, 15);
        ofVertex(3, 8);
        ofEndShape(true);
        
        ofPopMatrix();
        
        // Trail
        ofSetColor(100, 120, 140, tear.alpha * 0.3);
        ofDrawLine(tear.pos.x, tear.pos.y - 5, tear.pos.x, tear.pos.y);
    }
    
    // BROKEN PIECES - Shattered heart, broken dreams
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2 + 200, ofGetHeight()/2);
    
    for(int i = 0; i < brokenPieces.size(); i++) {
        ofPushMatrix();
        ofTranslate(brokenPieces[i].x - ofGetWidth()/2 - 200, 
                    brokenPieces[i].y - ofGetHeight()/2);
        ofRotateDeg(ofRadToDeg(pieceAngles[i]));
        
        // Jagged broken piece
        ofSetColor(80, 70, 90, 150);
        ofBeginShape();
        ofVertex(0, -15);
        ofVertex(10, -8);
        ofVertex(8, 0);
        ofVertex(12, 5);
        ofVertex(5, 12);
        ofVertex(0, 8);
        ofVertex(-8, 10);
        ofVertex(-10, 3);
        ofVertex(-6, -5);
        ofEndShape(true);
        
        ofPopMatrix();
    }
    
    ofPopMatrix();
    
    // WILTED FLOWER STEM - What remains, standing but lifeless
    ofPushMatrix();
    ofTranslate(150, ofGetHeight() - 100);
    
    // Bent, wilted stem
    ofSetColor(60, 80, 70);
    ofSetLineWidth(4);
    ofNoFill();
    ofBeginShape();
    ofVertex(0, 0);
    ofVertex(5, -30);
    ofVertex(3, -60);
    ofVertex(-10, -80);
    ofVertex(-20, -95);
    ofEndShape();
    
    // Dead flower head, drooping
    ofFill();
    ofSetColor(70, 60, 65);
    ofDrawCircle(-20, -95, 12);
    
    ofPopMatrix();
    
    // EMPTY FRAME - What once held something precious
    ofPushMatrix();
    ofTranslate(ofGetWidth() - 200, ofGetHeight()/2 + 50);
    
    ofSetColor(50, 45, 55);
    ofSetLineWidth(8);
    ofNoFill();
    ofDrawRectangle(-60, -80, 120, 160);
    
    // Nothing inside - just emptiness
    ofSetColor(30, 30, 35);
    ofFill();
    ofDrawRectangle(-55, -75, 110, 150);
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::drawPage4() {
    // Page 4: 3D Universe of Play
    // Bright, cheerful gradient background
    if(modelRow == 0) {
        ofBackgroundGradient(ofColor(255, 200, 100), ofColor(100, 200, 255), OF_GRADIENT_CIRCULAR); // Sonnet 4.5 playful warmth
    } else {
        ofBackgroundGradient(ofColor(120, 180, 255), ofColor(255, 140, 220), OF_GRADIENT_CIRCULAR); // GPT-5.1 playful neon
    }
    
    // Draw 2D text first (before 3D)
    ofSetColor(80, 80, 100);
    ofDrawBitmapString("Page 4: Universe of Play", 20, 20);
    ofSetColor(100, 100, 120);
    ofDrawBitmapString("Prompt: \"Use 3D models. Create a universe of play\"", 20, 40);
    ofSetColor(80, 80, 100);
    if(modelRow == 0) {
        ofDrawBitmapString("A playful 3D world of joy and fun (Sonnet 4.5)", 20, 60);
    } else {
        ofDrawBitmapString("Neon arcade joy (GPT-5.1 Codex Max)", 20, 60);
    }
    ofDrawBitmapString("Drag mouse to rotate camera!", 20, 80);
    
    // Enable 3D rendering
    ofEnableDepthTest();
    ofEnableLighting();
    
    // Enable lights
    light1.enable();
    light2.enable();
    
    // Start 3D camera
    cam3D.begin();
    
    // Draw a playful central sphere (the heart of play)
    ofPushMatrix();
    ofSetColor(255, 100, 200);
    ofRotateDeg(time * 20, 0, 1, 0);
    ofDrawSphere(0, 0, 0, 80);
    ofPopMatrix();
    
    // Draw orbiting rings (playground structure)
    ofNoFill();
    ofSetLineWidth(4);
    
    ofPushMatrix();
    ofRotateDeg(time * 15, 1, 0, 0);
    ofSetColor(255, 200, 50, 150);
    ofDrawCircle(0, 0, 0, 200);
    ofPopMatrix();
    
    ofPushMatrix();
    ofRotateDeg(time * 10, 0, 1, 0);
    ofSetColor(100, 255, 200, 150);
    ofDrawCircle(0, 0, 0, 250);
    ofPopMatrix();
    
    ofPushMatrix();
    ofRotateDeg(time * 12, 0, 0, 1);
    ofSetColor(200, 100, 255, 150);
    ofDrawCircle(0, 0, 0, 300);
    ofPopMatrix();
    
    ofFill();
    
    // Draw all playful 3D shapes
    for(const auto& shape : playShapes) {
        ofPushMatrix();
        
        // Position
        ofTranslate(shape.position.x, shape.position.y, shape.position.z);
        
        // Rotation
        ofRotateDeg(shape.rotation.x, 1, 0, 0);
        ofRotateDeg(shape.rotation.y, 0, 1, 0);
        ofRotateDeg(shape.rotation.z, 0, 0, 1);
        
        // Color with playful shimmer
        ofColor shimmerColor = shape.color;
        shimmerColor.setBrightness(200 + sin(time * 3.0 + shape.bouncePhase) * 55);
        ofSetColor(shimmerColor);
        
        // Draw shape based on type
        switch(shape.shapeType) {
            case 0: // Sphere (ball)
                ofDrawSphere(0, 0, 0, shape.size);
                break;
            case 1: // Box (building block)
                ofDrawBox(0, 0, 0, shape.size);
                break;
            case 2: // Cone (party hat)
                ofDrawCone(0, 0, 0, shape.size, shape.size * 1.5);
                break;
            case 3: // Cylinder (tube)
                ofDrawCylinder(0, 0, 0, shape.size * 0.5, shape.size * 1.2);
                break;
        }
        
        ofPopMatrix();
    }
    
    // Draw floating confetti spirals
    ofSetLineWidth(3);
    for(int i = 0; i < 8; i++) {
        ofPushMatrix();
        ofRotateDeg(time * 30 + i * 45, 0, 1, 0);
        
        ofBeginShape();
        for(int j = 0; j < 50; j++) {
            float t = j / 50.0;
            float angle = t * TWO_PI * 3;
            float radius = 350 * t;
            float height = sin(t * TWO_PI * 2) * 100;
            
            ofColor ribbonColor = ofColor::fromHsb((int)(time * 50 + i * 30 + j * 5) % 255, 200, 255);
            ofSetColor(ribbonColor, 200);
            
            ofVertex(cos(angle) * radius, height, sin(angle) * radius);
        }
        ofEndShape();
        
        ofPopMatrix();
    }
    
    // Draw bouncing cubes in a playful pattern
    for(int x = -2; x <= 2; x++) {
        for(int z = -2; z <= 2; z++) {
            ofPushMatrix();
            float bounceY = sin(time * 2.0 + x * 0.5 + z * 0.5) * 50;
            ofTranslate(x * 150, -300 + bounceY, z * 150);
            
            ofColor floorColor = ofColor::fromHsb((int)(x * 50 + z * 50 + time * 20) % 255, 150, 255);
            ofSetColor(floorColor);
            
            ofDrawBox(0, 0, 0, 30);
            ofPopMatrix();
        }
    }
    
    // End 3D camera
    cam3D.end();
    
    // Disable 3D for UI
    light1.disable();
    light2.disable();
    ofDisableLighting();
    ofDisableDepthTest();
}

//--------------------------------------------------------------
void ofApp::drawPage5() {
    // Page 5: The Sublime of Reality - Grand Finale Renaissance Masterwork
    drawSublimeReality();
}

//--------------------------------------------------------------
void ofApp::drawSublimeReality() {
    // Atmospheric depth - sfumato effect (Renaissance technique)
    ofBackgroundGradient(
        ofColor(20, 30, 60),      // Deep infinite void
        ofColor(150, 120, 180),   // Celestial purple
        OF_GRADIENT_CIRCULAR
    );
    
    // 2D Title overlay
    ofSetColor(255, 255, 255, 220);
    ofDrawBitmapString("Page 5: The Sublime of Reality", 20, 20);
    ofSetColor(200, 200, 220);
    ofDrawBitmapString("Prompt: \"Push the boundaries in technique.", 20, 40);
    ofDrawBitmapString("        Think like Renaissance painters.", 20, 55);
    ofDrawBitmapString("        Create the sublime of reality!", 20, 70);
    ofDrawBitmapString("        Don't use people. Experiment with 3D\"", 20, 85);
    ofSetColor(255, 255, 255, 220);
    if(modelRow == 0) {
        ofDrawBitmapString("Renaissance Masterwork - Grand Finale (Sonnet 4.5)", 20, 105);
    } else {
        ofDrawBitmapString("Renaissance Masterwork - Grand Finale (GPT-5.1 Codex Max)", 20, 105);
    }
    ofDrawBitmapString("Drag mouse to explore the infinite", 20, 120);
    
    // Enable 3D rendering
    ofEnableDepthTest();
    ofEnableLighting();
    ofEnableBlendMode(OF_BLENDMODE_ADD);  // Additive blending for luminous effects
    
    // Enable sublime lights
    sublimeLight1.enable();
    sublimeLight2.enable();
    sublimeLight3.enable();
    
    // Begin 3D camera
    sublimeCam.begin();
    
    // Draw the sublime scene
    drawDivineLight3D();
    drawInfiniteRegress();
    drawSacredGeometry3D();
    drawGoldenSpiral3D();
    drawFractalCrystal(ofVec3f(0, 0, 0), 100, 4, 180);
    
    sublimeCam.end();
    
    // Disable 3D for UI
    sublimeLight1.disable();
    sublimeLight2.disable();
    sublimeLight3.disable();
    ofDisableLighting();
    ofDisableDepthTest();
    ofDisableBlendMode();
}

//--------------------------------------------------------------
void ofApp::drawDivineLight3D() {
    // Divine light source - The origin point (Chiaroscuro in 3D space)
    ofPushMatrix();
    ofTranslate(0, -300, 0);
    
    // Central radiant sphere - the sublime moment
    ofSetColor(255, 255, 255, 255);
    ofDrawSphere(0, 0, 0, 40 + sin(sublimeTime * 3.0) * 10);
    
    // Layered halos (sfumato - soft transitions)
    for(int i = 1; i < 8; i++) {
        float alpha = (8 - i) * 30;
        float size = 40 + i * 30 + sin(sublimeTime * 2.0 + i) * 8;
        ofSetColor(255, 250, 230, alpha);
        ofDrawSphere(0, 0, 0, size);
    }
    
    ofPopMatrix();
    
    // God rays in 3D space (volumetric light)
    ofNoFill();
    for(const auto& ray : divineRays) {
        ofPushMatrix();
        ofTranslate(ray.origin);
        
        // Point ray in its direction
        ofVec3f up(0, 1, 0);
        ofQuaternion q;
        q.makeRotate(up, ray.direction);
        ofMatrix4x4 m;
        q.get(m);
        ofMultMatrix(m);
        
        // Draw ray as cone of light
        ofSetColor(ray.color, ray.intensity);
        
        ofMesh rayMesh;
        rayMesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
        
        // Origin point
        rayMesh.addVertex(ofVec3f(0, 0, 0));
        rayMesh.addColor(ofColor(ray.color, ray.intensity));
        
        // Circle at end
        int segments = 16;
        for(int i = 0; i <= segments; i++) {
            float angle = (i / (float)segments) * TWO_PI;
            float x = cos(angle) * ray.width;
            float z = sin(angle) * ray.width;
            rayMesh.addVertex(ofVec3f(x, ray.length, z));
            rayMesh.addColor(ofColor(ray.color, 0));
        }
        
        rayMesh.draw();
        ofPopMatrix();
    }
    ofFill();
}

//--------------------------------------------------------------
void ofApp::drawInfiniteRegress() {
    // Infinite vortex - perspective drawing to infinity (Renaissance mastery)
    
    ofPushMatrix();
    ofRotateDeg(sublimeTime * 5, 0, 1, 0);
    
    for(const auto& ring : cosmicVortex) {
        ofPushMatrix();
        ofTranslate(0, ring.height, 0);
        ofRotateDeg(ofRadToDeg(ring.rotation), 0, 1, 0);
        
        // Draw torus ring
        ofSetColor(ring.color, 200);
        
        ofMesh ringMesh;
        ringMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        
        float tubeRadius = 8;
        for(int i = 0; i <= ring.segments; i++) {
            float theta = (i / (float)ring.segments) * TWO_PI;
            float cosTheta = cos(theta);
            float sinTheta = sin(theta);
            
            for(int j = 0; j <= 16; j++) {
                float phi = (j / 16.0) * TWO_PI;
                float cosPhi = cos(phi);
                float sinPhi = sin(phi);
                
                float x = (ring.radius + tubeRadius * cosPhi) * cosTheta;
                float y = tubeRadius * sinPhi;
                float z = (ring.radius + tubeRadius * cosPhi) * sinTheta;
                
                ringMesh.addVertex(ofVec3f(x, y, z));
                ringMesh.addColor(ring.color);
            }
        }
        
        ringMesh.draw();
        ofPopMatrix();
    }
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::drawSacredGeometry3D() {
    // Platonic solids and sacred forms floating in sublime space
    
    for(const auto& geo : sacredShapes) {
        ofPushMatrix();
        
        ofTranslate(geo.position);
        ofRotateDeg(geo.rotation.x, 1, 0, 0);
        ofRotateDeg(geo.rotation.y, 0, 1, 0);
        ofRotateDeg(geo.rotation.z, 0, 0, 1);
        
        float s = geo.scale * geo.pulsation;
        ofScale(s, s, s);
        
        // Inner glow
        ofSetColor(geo.innerColor, 200);
        
        switch(geo.geometryType) {
            case 0: // Icosahedron (20 faces - water/divine feminine)
                ofDrawIcoSphere(0, 0, 0, 1);
                break;
            case 1: // Octahedron (8 faces - air/balance)
                {
                    ofMesh octa;
                    octa.setMode(OF_PRIMITIVE_TRIANGLES);
                    // Top pyramid
                    octa.addVertex(ofVec3f(0, 1, 0));
                    octa.addVertex(ofVec3f(1, 0, 0));
                    octa.addVertex(ofVec3f(0, 0, 1));
                    // Add more faces...
                    ofDrawBox(0, 0, 0, 1);  // Simplified
                }
                break;
            case 2: // Nested spheres (infinite containment)
                for(int i = 3; i > 0; i--) {
                    float alpha = (i / 3.0) * 200;
                    ofSetColor(geo.outerColor, alpha);
                    ofDrawSphere(0, 0, 0, i * 0.4);
                }
                break;
            case 3: // Golden ratio box (divine proportion)
                ofDrawBox(0, 0, 0, 1.0, goldenRatio, 1.0);
                break;
        }
        
        // Outer ethereal shell
        ofNoFill();
        ofSetColor(geo.outerColor, 80);
        ofDrawIcoSphere(0, 0, 0, 1.5);
        ofFill();
        
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void ofApp::drawGoldenSpiral3D() {
    // Golden spiral in 3D - the mathematical perfection of nature/reality
    
    ofPushMatrix();
    ofTranslate(-200, 200, 0);
    ofRotateDeg(sublimeTime * 10, 1, 1, 0);
    
    ofNoFill();
    ofSetLineWidth(3);
    ofSetColor(255, 245, 200, 180);
    
    // Draw Fibonacci spiral in 3D
    ofBeginShape();
    for(float t = 0; t < TWO_PI * 4; t += 0.05) {
        float radius = 10 * exp(t * 0.2);
        float x = cos(t) * radius;
        float y = sin(t) * radius;
        float z = t * 15;
        ofVertex(x, y, z);
    }
    ofEndShape();
    
    // Draw golden ratio rectangles spiraling
    for(int i = 0; i < 8; i++) {
        float t = i * 0.5;
        float radius = 10 * exp(t * 0.2);
        float angle = t;
        
        ofPushMatrix();
        ofTranslate(
            cos(angle) * radius,
            sin(angle) * radius,
            t * 15
        );
        ofRotateDeg(ofRadToDeg(angle), 0, 0, 1);
        
        float size = fibonacci[i % 10] * 0.5;
        ofSetColor(255, 240, 200, 150 - i * 15);
        ofDrawRectangle(0, 0, size, size / goldenRatio);
        
        ofPopMatrix();
    }
    
    ofFill();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::drawFractalCrystal(ofVec3f pos, float size, int depth, float hue) {
    // Recursive fractal structure - infinite complexity (the sublime)
    
    if(depth <= 0 || size < 5) return;
    
    ofPushMatrix();
    ofTranslate(pos);
    ofRotateDeg(sublimeTime * 20 / (depth + 1), 1, 1, 1);
    
    // Central crystal
    ofColor crystalColor = ofColor::fromHsb(hue, 180, 255, 200);
    ofSetColor(crystalColor);
    ofDrawBox(0, 0, 0, size);
    
    // Wireframe overlay
    ofNoFill();
    ofSetColor(255, 255, 255, 100);
    ofDrawBox(0, 0, 0, size * 1.1);
    ofFill();
    
    // Recursive branches
    float newSize = size * 0.4;
    float offset = size * 0.7;
    
    // 6 directions (cubic symmetry)
    drawFractalCrystal(ofVec3f(offset, 0, 0), newSize, depth - 1, hue + 20);
    drawFractalCrystal(ofVec3f(-offset, 0, 0), newSize, depth - 1, hue + 20);
    drawFractalCrystal(ofVec3f(0, offset, 0), newSize, depth - 1, hue + 20);
    drawFractalCrystal(ofVec3f(0, -offset, 0), newSize, depth - 1, hue + 20);
    drawFractalCrystal(ofVec3f(0, 0, offset), newSize, depth - 1, hue + 20);
    drawFractalCrystal(ofVec3f(0, 0, -offset), newSize, depth - 1, hue + 20);
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::drawNavigationArrows() {
    float arrowSize = 40;
    float margin = 30;
    float yPos = ofGetHeight() / 2;
    
    // Left arrow (previous page) - only show if not on first page
    if(currentPage > 1) {
        if(isMouseOverLeftArrow()) {
            ofSetColor(100, 150, 250, 200);
        } else {
            ofSetColor(80, 80, 80, 150);
        }
        
        // Draw left arrow
        ofBeginShape();
        ofVertex(margin + arrowSize, yPos - arrowSize/2);
        ofVertex(margin, yPos);
        ofVertex(margin + arrowSize, yPos + arrowSize/2);
        ofEndShape();
        
        // Arrow stem
        ofDrawRectangle(margin + arrowSize/2, yPos - 5, arrowSize, 10);
    }
    
    // Right arrow (next page) - only show if not on last page
    if(currentPage < totalPages) {
        if(isMouseOverRightArrow()) {
            ofSetColor(100, 150, 250, 200);
        } else {
            ofSetColor(80, 80, 80, 150);
        }
        
        float rightX = ofGetWidth() - margin;
        
        // Draw right arrow
        ofBeginShape();
        ofVertex(rightX - arrowSize, yPos - arrowSize/2);
        ofVertex(rightX, yPos);
        ofVertex(rightX - arrowSize, yPos + arrowSize/2);
        ofEndShape();
        
        // Arrow stem
        ofDrawRectangle(rightX - arrowSize * 1.5, yPos - 5, arrowSize, 10);
    }
}

//--------------------------------------------------------------
void ofApp::drawPageNumber() {
    // Draw page number at the bottom center
    ofSetColor(60, 60, 60);
    string pageText = "Page " + ofToString(currentPage) + " of " + ofToString(totalPages);
    float textWidth = pageText.length() * 8;
    ofDrawBitmapString(pageText, ofGetWidth()/2 - textWidth/2, ofGetHeight() - 20);
    
    // Draw navigation hint
    ofSetColor(100, 100, 100);
    string hint = "Click arrows or use LEFT/RIGHT arrow keys to navigate";
    float hintWidth = hint.length() * 8;
    ofDrawBitmapString(hint, ofGetWidth()/2 - hintWidth/2, ofGetHeight() - 40);
}

//--------------------------------------------------------------
void ofApp::nextPage() {
    if(currentPage < totalPages) {
        currentPage++;
    }
}

//--------------------------------------------------------------
void ofApp::previousPage() {
    if(currentPage > 1) {
        currentPage--;
    }
}

//--------------------------------------------------------------
bool ofApp::isMouseOverRightArrow() {
    if(currentPage >= totalPages) return false;
    
    float margin = 30;
    float arrowSize = 40;
    float rightX = ofGetWidth() - margin;
    float yPos = ofGetHeight() / 2;
    
    return (ofGetMouseX() > rightX - arrowSize * 1.5 && 
            ofGetMouseX() < rightX &&
            ofGetMouseY() > yPos - arrowSize/2 &&
            ofGetMouseY() < yPos + arrowSize/2);
}

//--------------------------------------------------------------
bool ofApp::isMouseOverLeftArrow() {
    if(currentPage <= 1) return false;
    
    float margin = 30;
    float arrowSize = 40;
    float yPos = ofGetHeight() / 2;
    
    return (ofGetMouseX() > margin && 
            ofGetMouseX() < margin + arrowSize * 1.5 &&
            ofGetMouseY() > yPos - arrowSize/2 &&
            ofGetMouseY() < yPos + arrowSize/2);
}

//--------------------------------------------------------------
void ofApp::drawModelNavigation() {
    // Labels for model interpretation rows
    ofSetColor(60, 60, 60);
    string rowLabel = (modelRow == 0) ? "Sonnet 4.5" : "GPT-5.1 Codex Max";
    ofDrawBitmapString("Interpretation: " + rowLabel, 20, ofGetHeight() - 60);
    
    // Down arrow to switch interpretation
    float arrowSize = 28;
    float cx = ofGetWidth() - 60;
    float cy = ofGetHeight() - 50;
    if(isMouseOverDownArrow()) {
        ofSetColor(100, 150, 250, 200);
    } else {
        ofSetColor(80, 80, 80, 160);
    }
    ofBeginShape();
    ofVertex(cx - arrowSize/2, cy - arrowSize/4);
    ofVertex(cx + arrowSize/2, cy - arrowSize/4);
    ofVertex(cx, cy + arrowSize/2);
    ofEndShape();
    ofDrawBitmapString("Switch", cx - 24, cy + 20);
}

//--------------------------------------------------------------
bool ofApp::isMouseOverDownArrow() {
    float arrowSize = 28;
    float cx = ofGetWidth() - 60;
    float cy = ofGetHeight() - 50;
    return (ofGetMouseX() > cx - arrowSize/2 &&
            ofGetMouseX() < cx + arrowSize/2 &&
            ofGetMouseY() > cy - arrowSize/2 &&
            ofGetMouseY() < cy + arrowSize/2);
}

//--------------------------------------------------------------
void ofApp::nextRow() {
    modelRow = (modelRow + 1) % totalRows;
}

//--------------------------------------------------------------
void ofApp::drawSkepticalFigure() {
    ofPushMatrix();
    ofTranslate(figureX, figureY + floatOffset);
    
    // Draw floating question marks (doubts about the future)
    for(int i = 0; i < questionMarks.size(); i++) {
        ofPushMatrix();
        ofTranslate(questionMarks[i].x, questionMarks[i].y);
        ofSetColor(80, 90, 120, questionMarkAlphas[i]);
        
        // Draw question mark
        string qMark = "?";
        float size = 2.0 + sin(time * 2.0 + i) * 0.3;
        ofScale(size, size);
        ofDrawBitmapString(qMark, -4, 4);
        
        ofPopMatrix();
    }
    
    // Rotate for head tilt
    ofRotateDeg(headTiltAngle);
    
    // BODY - slumped, uncertain posture
    ofSetColor(60, 70, 90);
    ofPushMatrix();
    ofTranslate(0, shoulderSlump);
    
    // Torso
    ofDrawRectangle(-25, 0, 50, 80);
    
    // Arms hanging down (skeptical, defeated posture)
    ofDrawRectangle(-40, 10, 15, 60);  // Left arm
    ofDrawRectangle(25, 10, 15, 60);   // Right arm
    
    // Legs
    ofDrawRectangle(-20, 80, 15, 50);  // Left leg
    ofDrawRectangle(5, 80, 15, 50);    // Right leg
    
    ofPopMatrix();
    
    // HEAD - positioned above body
    ofSetColor(90, 100, 120);
    ofDrawCircle(0, -20, 30);
    
    // EYES - uncertain, wandering gaze
    ofSetColor(40, 50, 70);
    ofDrawCircle(-10 + eyeWanderX, -25 + eyeWanderY, 4);  // Left eye
    ofDrawCircle(10 + eyeWanderX, -25 + eyeWanderY, 4);   // Right eye
    
    // Furrowed brow (skeptical expression)
    ofSetLineWidth(2);
    ofDrawLine(-18, -30, -8, -32);   // Left brow
    ofDrawLine(8, -32, 18, -30);     // Right brow
    
    // Mouth - downturned, doubtful
    ofNoFill();
    ofBeginShape();
    ofVertex(-8, -8);
    ofVertex(0, -5);
    ofVertex(8, -8);
    ofEndShape();
    ofFill();
    
    // THOUGHT BUBBLE - contemplating the uncertain future
    ofSetColor(200, 210, 220, thoughtBubbleAlpha);
    
    // Main thought bubble
    ofDrawCircle(60, -60, 35);
    
    // Bubble connectors
    ofDrawCircle(40, -40, 12);
    ofDrawCircle(30, -30, 6);
    
    // Text in thought bubble
    ofSetColor(60, 70, 90, thoughtBubbleAlpha);
    ofDrawBitmapString("The", 48, -68);
    ofDrawBitmapString("Future", 42, -58);
    ofDrawBitmapString("...?", 50, -48);
    
    // Shadow beneath figure (subtle floating effect)
    ofPopMatrix();
    ofSetColor(0, 0, 0, 30);
    ofDrawEllipse(figureX, figureY + 140 + floatOffset * 0.5, 60 - floatOffset * 2, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    // Reset animation on spacebar (only for page 1)
    if(key == ' ' && currentPage == 1) {
        time = 0;
        floatOffset = 0;
        headTiltAngle = 0;
    }
    
    // Navigate with arrow keys
    if(key == OF_KEY_RIGHT) {
        nextPage();
    }
    if(key == OF_KEY_LEFT) {
        previousPage();
    }
    if(key == OF_KEY_DOWN) {
        nextRow();
    }
    
    // Close on ESC
    if(key == OF_KEY_ESC) {
        ofExit();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    // Handle key release events
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
    // Handle mouse movement
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
    // Handle mouse drag events
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    // Check if clicking on navigation arrows
    if(isMouseOverRightArrow()) {
        nextPage();
    }
    if(isMouseOverLeftArrow()) {
        previousPage();
    }
    if(isMouseOverDownArrow()) {
        nextRow();
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
    // Handle mouse release events
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
    // Handle mouse entered window
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
    // Handle mouse exited window
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
    // Handle window resize
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
    // Handle messages
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
    // Handle drag and drop
}

//--------------------------------------------------------------
void ofApp::drawPage6() {
    // Page 6: The Absurd - Surreal chaos
    drawAbsurdReality();
}

//--------------------------------------------------------------
void ofApp::drawAbsurdReality() {
    // Glitchy, unstable background
    ofColor bg1 = ofColor::fromHsb((int)(absurdTime * 20) % 255, 150, 80);
    ofColor bg2 = ofColor::fromHsb((int)(absurdTime * 30 + 128) % 255, 150, 120);
    ofBackgroundGradient(bg1, bg2, OF_GRADIENT_BAR);
    
    // 2D overlay
    ofSetColor(255, 255, 255, 200);
    ofDrawBitmapString("Page 6: THE ABSURD", 20, 20);
    ofSetColor(220, 220, 240);
    ofDrawBitmapString("Prompt: \"Use 3D, textures, and outside images.", 20, 40);
    ofDrawBitmapString("        Create the experience of the absurd!\"", 20, 55);
    ofSetColor(255, 255, 255, 200);
    if(modelRow == 0) {
        ofDrawBitmapString("Nothing makes sense. Everything exists anyway. (Sonnet 4.5)", 20, 75);
    } else {
        ofDrawBitmapString("Absurdity re-imagined (GPT-5.1 Codex Max)", 20, 75);
    }
    ofDrawBitmapString("Drag to witness the paradox", 20, 90);
    
    // Enable 3D
    ofEnableDepthTest();
    ofEnableLighting();
    
    absurdLight1.enable();
    absurdLight2.enable();
    
    // Lights glitch
    absurdLight1.setPosition(
        200 + sin(absurdTime * 7) * 100,
        cos(absurdTime * 5) * 100,
        200
    );
    
    absurdCam.begin();
    
    // Draw impossible geometry
    drawImpossibleStaircase();
    
    // Draw all absurd objects
    for(const auto& obj : absurdObjects) {
        ofPushMatrix();
        
        // Position with glitch
        ofVec3f glitchPos = obj.position;
        if(obj.glitchAmount > 0.7) {
            glitchPos.x += ofRandom(-20, 20) * chaosLevel;
            glitchPos.y += ofRandom(-20, 20) * chaosLevel;
        }
        ofTranslate(glitchPos);
        
        // Rotation
        ofRotateDeg(obj.rotation.x, 1, 0, 0);
        ofRotateDeg(obj.rotation.y, 0, 1, 0);
        ofRotateDeg(obj.rotation.z, 0, 0, 1);
        
        // Absurd scale
        ofScale(obj.scale.x, obj.scale.y, obj.scale.z);
        
        // Color shifts chaotically
        ofColor shiftedColor = obj.color;
        shiftedColor.setHue((int)(shiftedColor.getHue() + absurdTime * 30 + obj.textureOffset) % 255);
        ofSetColor(shiftedColor);
        
        // Apply texture
        if(obj.shapeType % 2 == 0) {
            checkerTexture.bind();
        } else {
            spiralTexture.bind();
        }
        
        // Draw glitched geometry
        if(obj.glitchAmount > 0.5) {
            drawGlitchedGeometry(ofVec3f(0, 0, 0), 50, obj.glitchAmount);
        } else {
            switch(obj.shapeType) {
                case 0:
                    ofDrawSphere(0, 0, 0, 50);
                    break;
                case 1:
                    ofDrawBox(0, 0, 0, 50);
                    break;
                case 2:
                    drawMelting3DObject(ofVec3f(0, 0, 0), 50, chaosLevel);
                    break;
                case 3:
                    drawInvertedCube(ofVec3f(0, 0, 0), 50);
                    break;
                case 4:
                    drawParadoxSphere(ofVec3f(0, 0, 0), 50);
                    break;
                case 5:
                    ofDrawCone(0, 0, 0, 50, 80);
                    break;
            }
        }
        
        if(obj.shapeType % 2 == 0) {
            checkerTexture.unbind();
        } else {
            spiralTexture.unbind();
        }
        
        ofPopMatrix();
    }
    
    // Floating nonsense text in 3D space
    for(int i = 0; i < 8; i++) {
        ofPushMatrix();
        float angle = (i / 8.0) * TWO_PI + absurdTime * 0.5;
        ofTranslate(
            cos(angle) * 300,
            sin(absurdTime * 2 + i) * 100,
            sin(angle) * 300
        );
        ofRotateDeg(absurdTime * 20 + i * 45, 0, 1, 0);
        
        ofSetColor(255, ofRandom(255), ofRandom(255));
        ofDrawBitmapString("WHY?", 0, 0);
        ofPopMatrix();
    }
    
    absurdCam.end();
    
    absurdLight1.disable();
    absurdLight2.disable();
    ofDisableLighting();
    ofDisableDepthTest();
}

//--------------------------------------------------------------
void ofApp::drawGlitchedGeometry(ofVec3f pos, float size, float glitch) {
    // Geometry that doesn't know what it is
    ofMesh glitchMesh;
    glitchMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    
    int vertices = 20;
    for(int i = 0; i < vertices; i++) {
        float angle = (i / (float)vertices) * TWO_PI;
        float radius = size * (1.0 + ofRandom(-glitch, glitch));
        float x = cos(angle) * radius + ofRandom(-10, 10) * glitch;
        float y = sin(angle) * radius + ofRandom(-10, 10) * glitch;
        float z = ofRandom(-size, size) * glitch;
        
        glitchMesh.addVertex(ofVec3f(x, y, z));
        glitchMesh.addColor(ofColor(ofRandom(255), ofRandom(255), ofRandom(255)));
    }
    
    // Random connections
    for(int i = 0; i < 30; i++) {
        glitchMesh.addIndex(ofRandom(vertices));
    }
    
    glitchMesh.draw();
}

//--------------------------------------------------------------
void ofApp::drawImpossibleStaircase() {
    // Penrose/Escher-style impossible geometry
    float stepSize = 60;
    int steps = 8;
    
    ofPushMatrix();
    ofTranslate(0, -100, 0);
    
    for(int i = 0; i < steps; i++) {
        float angle = (i / (float)steps) * TWO_PI;
        
        ofPushMatrix();
        ofRotateDeg(angle * 57.2958, 0, 1, 0);
        ofTranslate(200, i * 20 - sin(absurdTime + i) * 30, 0);
        
        // Impossible lighting (lit from wrong angle)
        if(i % 2 == 0) {
            ofSetColor(255, 200, 200);
        } else {
            ofSetColor(200, 200, 255);
        }
        
        noiseTexture.bind();
        ofDrawBox(0, 0, 0, stepSize, 20, stepSize);
        noiseTexture.unbind();
        
        ofPopMatrix();
    }
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::drawMelting3DObject(ofVec3f pos, float size, float meltAmount) {
    // Salvador Dali would be proud
    ofMesh meltMesh;
    meltMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    int resolution = 16;
    for(int i = 0; i <= resolution; i++) {
        float angle = (i / (float)resolution) * TWO_PI;
        
        for(int j = 0; j <= resolution; j++) {
            float v = j / (float)resolution;
            float melt = pow(v, 2) * meltAmount * 100;
            
            float x = cos(angle) * size;
            float y = -size + v * size * 2 + melt;
            float z = sin(angle) * size;
            
            meltMesh.addVertex(ofVec3f(x, y, z));
            meltMesh.addColor(ofColor(255, 200 - v * 100, 100 + v * 100));
        }
    }
    
    meltMesh.draw();
}

//--------------------------------------------------------------
void ofApp::drawInvertedCube(ofVec3f pos, float size) {
    // A cube that's inside-out
    ofPushMatrix();
    ofTranslate(pos);
    
    glitchTexture.bind();
    
    // Draw cube faces in reverse order
    ofSetColor(255, 100, 255, 150);
    ofDrawBox(0, 0, 0, size);
    
    // Draw inverted wireframe
    ofNoFill();
    ofSetColor(0, 255, 255);
    ofScale(-1, -1, -1);
    ofDrawBox(0, 0, 0, size * 0.8);
    ofFill();
    
    glitchTexture.unbind();
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::drawParadoxSphere(ofVec3f pos, float size) {
    // A sphere that contradicts itself
    ofPushMatrix();
    ofTranslate(pos);
    
    // Outer sphere
    ofSetColor(255, 255, 0, 100);
    ofDrawSphere(0, 0, 0, size);
    
    // Inner sphere (shouldn't be visible but is)
    ofSetColor(255, 0, 255, 200);
    ofDrawSphere(0, 0, 0, size * 0.7);
    
    // Impossible inner core
    ofSetColor(0, 255, 255);
    ofDrawSphere(0, 0, 0, size * 0.4);
    
    // Wireframe breaking reality
    ofNoFill();
    ofSetColor(255, 255, 255);
    for(int i = 0; i < 5; i++) {
        float s = size * (1.0 + i * 0.1);
        ofDrawSphere(0, 0, 0, s);
    }
    ofFill();
    
    ofPopMatrix();
}

