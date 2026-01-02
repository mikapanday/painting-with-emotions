# OpenFrameworks Canvas Setup - COMPLETE ✓

## What Was Done

1. **Downloaded openFrameworks v0.12.0** (410 MB)
   - Location: `of_v0.12.0_osx_release/`
   - Version: 0.12.0 for macOS

2. **Created Project: "Painting with Emotions"**
   - Location: `of_v0.12.0_osx_release/apps/myApps/paintingWithEmotions/`
   - Canvas size: 1280 x 720 pixels
   - Background: White
   - Successfully compiled and ready to run!

## Project Structure

```
painting-with-emotions/
├── of_v0.12.0_osx_release/          # OpenFrameworks library
│   ├── apps/
│   │   └── myApps/
│   │       └── paintingWithEmotions/  # Your project!
│   │           ├── src/
│   │           │   ├── main.cpp       # Entry point
│   │           │   ├── ofApp.h        # Header
│   │           │   └── ofApp.cpp      # Your canvas code
│   │           ├── bin/
│   │           │   ├── data/          # Place assets here
│   │           │   └── paintingWithEmotions.app  # Compiled app
│   │           ├── Makefile
│   │           ├── config.make
│   │           └── README.md          # Project documentation
│   ├── addons/                        # Available addons
│   ├── examples/                      # Example projects
│   └── projectGenerator/              # GUI tool for projects
└── SETUP_COMPLETE.md                  # This file
```

## How to Run Your Canvas

### Option 1: From Terminal (Recommended)
```bash
cd /Users/mikapanday/Documents/Destroyer/Sketchbook/Painting-with-emotion/painting-with-emotions/of_v0.12.0_osx_release/apps/myApps/paintingWithEmotions
make run
```

### Option 2: Double-Click
Navigate to:
```
of_v0.12.0_osx_release/apps/myApps/paintingWithEmotions/bin/paintingWithEmotions.app
```
Double-click the app to run it!

### Option 3: Recompile and Run
```bash
cd /Users/mikapanday/Documents/Destroyer/Sketchbook/Painting-with-emotion/painting-with-emotions/of_v0.12.0_osx_release/apps/myApps/paintingWithEmotions
make clean
make
make run
```

## Current Canvas Features

Your canvas currently has:
- ✓ White background (255, 255, 255)
- ✓ 1280x720 window size
- ✓ 60 FPS rendering
- ✓ Smooth graphics enabled
- ✓ Interactive blue circle that follows your mouse
- ✓ Welcome text overlay

## Next Steps - Building Your Emotion Painting App

### 1. Add Drawing Functionality
Edit `src/ofApp.cpp` and modify the `mouseDragged()` function:

```cpp
void ofApp::mouseDragged(int x, int y, int button) {
    // Draw a brush stroke
    ofSetColor(255, 0, 0);  // Red color
    ofDrawCircle(x, y, 10);  // Draw at mouse position
}
```

### 2. Add Emotion-Based Colors
Create color palettes based on emotions:

```cpp
// In ofApp.h, add:
ofColor currentColor;
string currentEmotion;

// In ofApp.cpp, add a method:
void setEmotionColor(string emotion) {
    if (emotion == "happy") {
        currentColor = ofColor(255, 255, 0);  // Yellow
    } else if (emotion == "sad") {
        currentColor = ofColor(0, 0, 255);    // Blue
    } else if (emotion == "angry") {
        currentColor = ofColor(255, 0, 0);    // Red
    }
}
```

### 3. Save Your Artwork
Add image saving functionality:

```cpp
void ofApp::keyPressed(int key) {
    if (key == 's') {
        // Save the current canvas
        ofImage img;
        img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        img.save("painting_" + ofGetTimestampString() + ".png");
    }
}
```

### 4. Add More Brush Effects
Try different brush styles:
- Variable brush sizes
- Opacity/transparency
- Particle effects
- Gradient brushes

## Useful OpenFrameworks Functions

### Drawing
- `ofDrawCircle(x, y, radius)` - Draw a circle
- `ofDrawRectangle(x, y, w, h)` - Draw a rectangle
- `ofDrawLine(x1, y1, x2, y2)` - Draw a line
- `ofDrawEllipse(x, y, w, h)` - Draw an ellipse

### Colors
- `ofSetColor(r, g, b)` - Set drawing color
- `ofSetColor(r, g, b, alpha)` - Set color with transparency
- `ofBackground(r, g, b)` - Set background color

### Input
- `ofGetMouseX()` / `ofGetMouseY()` - Get mouse position
- `ofGetMousePressed()` - Check if mouse is pressed
- Mouse events: `mousePressed()`, `mouseReleased()`, `mouseDragged()`
- Keyboard events: `keyPressed()`, `keyReleased()`

## Resources

- **Project README**: `of_v0.12.0_osx_release/apps/myApps/paintingWithEmotions/README.md`
- **OpenFrameworks Docs**: https://openframeworks.cc/documentation/
- **Learning**: https://openframeworks.cc/learning/
- **Forum**: https://forum.openframeworks.cc/
- **Examples**: Check `of_v0.12.0_osx_release/examples/` for inspiration

## Troubleshooting

### If the app doesn't run:
```bash
cd /Users/mikapanday/Documents/Destroyer/Sketchbook/Painting-with-emotion/painting-with-emotions/of_v0.12.0_osx_release/apps/myApps/paintingWithEmotions
make clean
make
make run
```

### If you get permission errors:
```bash
chmod +x bin/paintingWithEmotions.app/Contents/MacOS/paintingWithEmotions
```

### To use Xcode:
1. Run the Project Generator app: `of_v0.12.0_osx_release/projectGenerator/`
2. Point it to your project folder
3. Click "Update" to generate Xcode files
4. Open the `.xcodeproj` file

## System Info

- **OS**: macOS 24.6.0
- **OpenFrameworks**: v0.12.0
- **Compiler**: C++17 with Objective-C++
- **Build System**: Make / Xcode

---

🎨 **Your canvas is ready! Start creating emotional art!**

Happy coding! Run `make run` to see your canvas in action.

