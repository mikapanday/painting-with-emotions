# Painting with Emotions Canvas

A creative coding canvas built with openFrameworks for emotional painting.

## Project Structure

```
paintingWithEmotions/
├── src/
│   ├── main.cpp          # Entry point
│   ├── ofApp.h           # Header file
│   └── ofApp.cpp         # Main application code
├── bin/
│   └── data/             # Place your assets here (images, sounds, etc.)
├── Makefile
├── config.make
└── addons.make
```

## Features

- **Canvas Size**: 1280x720 pixels
- **Background**: White canvas ready for painting
- **Frame Rate**: 60 FPS
- **Mouse Interaction**: Interactive circle follows mouse cursor

## Building and Running

### Option 1: Using Make (Command Line)
```bash
cd /Users/mikapanday/Documents/Destroyer/Sketchbook/Painting-with-emotion/painting-with-emotions/of_v0.12.0_osx_release/apps/myApps/paintingWithEmotions
make
make run
```

### Option 2: Using Xcode
1. Open the projectGenerator app located in:
   `/Users/mikapanday/Documents/Destroyer/Sketchbook/Painting-with-emotion/painting-with-emotions/of_v0.12.0_osx_release/projectGenerator`
2. Point it to this project directory
3. Click "Update" to generate Xcode project files
4. Open the generated `.xcodeproj` file
5. Build and run from Xcode

## Customization

### Changing Canvas Size
Edit `src/main.cpp` and modify the `ofSetupOpenGL()` parameters:
```cpp
ofSetupOpenGL(1280, 720, OF_WINDOW);  // width, height, mode
```

### Changing Background Color
Edit `src/ofApp.cpp` in the `setup()` function:
```cpp
ofBackground(255, 255, 255);  // R, G, B (0-255)
```

## Adding Features

The canvas is ready for you to add:
- Drawing tools
- Emotion-based color palettes
- Brush effects
- Saving/loading functionality
- Audio reactivity
- And more!

## Key Methods

- `setup()`: Initialize your application (called once)
- `update()`: Update logic (called every frame)
- `draw()`: Render graphics (called every frame)
- `mouseDragged()`: Handle mouse drawing
- `keyPressed()`: Handle keyboard shortcuts

## Resources

- [openFrameworks Documentation](https://openframeworks.cc/documentation/)
- [openFrameworks Learning](https://openframeworks.cc/learning/)
- [openFrameworks Forum](https://forum.openframeworks.cc/)

Happy Creating! 🎨

