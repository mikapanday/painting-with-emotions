# 🎨 Painting with Emotions

An interactive 6-page digital sketchbook exploring the full spectrum of human emotional and philosophical experience through generative art, 3D rendering, and code.

Built with **openFrameworks** - a creative coding toolkit.

## 📖 The Emotional Journey

### Page 1: Skepticism 🤔
**Prompt:** *"Create a floating figure that experiences a lot of skepticism about the future"*

- 2D animated figure with questioning gestures
- Floating question marks representing doubt
- Wandering eyes and skeptical expression
- Gray, uncertain atmosphere

### Page 2: Curiosity & Wonder ✨
**Prompt:** *"Create a scene about curiosity and wonder"*

- Magical night sky with floating stars
- Figure reaching upward in awe
- Sparkling particles and ethereal atmosphere
- Wide-eyed wonder and discovery

### Page 3: Grief 💔
**Prompt:** *"Don't use people figurines. Display the feeling of grief with symbols"*

- Pure symbolic representation (no figures)
- Falling petals, tears, heavy stones
- Empty frames and wilted flowers
- Dark, oppressive atmosphere of loss

### Page 4: Universe of Play 🎮
**Prompt:** *"Use 3D models. Create a universe of play"*

- Full 3D interactive environment
- 25+ playful shapes bouncing and rotating
- Colorful confetti spirals
- Interactive camera (drag to explore!)

### Page 5: The Sublime ⭐
**Prompt:** *"Push the boundaries in technique. Think like Renaissance painters. Create the sublime of reality! Don't use people. Experiment with 3D"*

- Renaissance-level masterwork in 3D
- Sacred geometry (Platonic solids)
- Golden ratio and Fibonacci sequences
- Volumetric god rays and divine light
- Fractal recursion (4 levels deep)
- Chiaroscuro and sfumato techniques

### Page 6: The Absurd 🌀
**Prompt:** *"Use 3D, textures, and outside images. Create the experience of the absurd!"*

- Surreal, glitching 3D chaos
- Impossible geometry (Escher-style staircases)
- Procedurally generated textures
- Melting objects and inverted cubes
- Reality breaking down
- Existential meaninglessness made beautiful

## 🎯 Features

- **Multi-page navigation** - Arrow keys or click arrows to navigate
- **Interactive 3D camera** - Drag mouse to explore 3D pages (4, 5, 6)
- **Real-time animations** - 60fps smooth motion
- **Procedural generation** - Textures generated programmatically
- **Advanced rendering** - 3D lighting, depth testing, blend modes
- **Creative prompts displayed** - Your original prompts shown on each page

## 🚀 Setup & Installation

### Prerequisites

1. **Download openFrameworks**
   - Visit [openframeworks.cc/download](https://openframeworks.cc/download/)
   - Download version 0.12.0 for macOS
   - Extract to the project root

2. **macOS Requirements**
   - Xcode (for compilation)
   - macOS 10.15+

### Installation Steps

```bash
# Clone this repository
git clone https://github.com/mikapanday/painting-with-emotions.git
cd painting-with-emotions

# Download openFrameworks 0.12.0
# Extract of_v0.12.0_osx_release to the project root
# The structure should be:
#   painting-with-emotions/
#   ├── of_v0.12.0_osx_release/
#   │   ├── libs/
#   │   ├── addons/
#   │   └── apps/
#   │       └── myApps/
#   │           └── paintingWithEmotions/  # <-- Our project

# Navigate to the project
cd of_v0.12.0_osx_release/apps/myApps/paintingWithEmotions

# Compile
make

# Run
make run

# Or open the built app
open bin/paintingWithEmotions.app
```

### Alternative: Use Xcode

```bash
# Use the Project Generator
# 1. Open: of_v0.12.0_osx_release/projectGenerator/
# 2. Point to: apps/myApps/paintingWithEmotions
# 3. Click "Update" to generate Xcode project
# 4. Open the .xcodeproj file
# 5. Build and run in Xcode
```

## 🎮 Controls

- **← →** Arrow keys - Navigate pages
- **Mouse drag** (Pages 4-6) - Rotate 3D camera
- **Mouse scroll** (Pages 4-6) - Zoom in/out
- **SPACE** (Page 1) - Reset animation
- **ESC** - Close application

## 🏗️ Technical Achievements

### Page 1 (2D Animation)
- Character rigging and animation
- Floating motion algorithms
- Dynamic thought bubbles

### Page 2 (2D + Particles)
- Particle systems (30+ sparkles)
- Orbital motion mechanics
- Gradient rendering

### Page 3 (2D Symbolic)
- Physics simulation (falling, sinking)
- Alpha blending techniques
- Atmospheric depth

### Page 4 (3D Interactive)
- 3D primitives (spheres, cubes, cones, cylinders)
- Dynamic lighting (2 lights)
- Camera controls (ofEasyCam)
- Parametric motion (25 objects)

### Page 5 (3D Renaissance)
- Sacred geometry (12 Platonic solids)
- Volumetric light rays (16 god rays)
- Recursive fractals (4 levels, 6-way branching)
- Fibonacci sequences
- Golden ratio (φ = 1.618...)
- Torus mesh generation
- 3-point lighting setup
- Additive blend modes

### Page 6 (3D Surreal)
- Procedural texture generation (256x256)
- Dynamic mesh creation
- Impossible geometry (Penrose stairs)
- Parametric melting algorithms
- Inside-out rendering
- Chaotic state machines
- HSB color manipulation

## 📁 Project Structure

```
paintingWithEmotions/
├── src/
│   ├── main.cpp          # Entry point
│   ├── ofApp.h           # Header with class definitions
│   └── ofApp.cpp         # Main application (2000+ lines)
├── bin/
│   └── data/             # Assets directory
├── Makefile              # Build configuration
├── config.make           # Project settings
└── README.md             # Project documentation
```

## 🎨 Artistic Techniques

- **Renaissance Techniques**: Chiaroscuro, sfumato, atmospheric perspective
- **Sacred Geometry**: Golden ratio, Fibonacci, Platonic solids
- **Surrealism**: Dali-esque melting, impossible geometry
- **Minimalism**: Symbolic representation (Page 3)
- **Expressionism**: Emotional color palettes
- **Abstract**: Non-representational forms

## 🔧 Built With

- **openFrameworks 0.12.0** - Creative coding framework
- **C++17** - Programming language
- **OpenGL** - 3D rendering
- **GLSL** - Shader language (implicit)
- **ofEasyCam** - 3D camera controls
- **ofLight** - Dynamic lighting
- **ofMesh** - Custom geometry

## 📝 Development Notes

- Total lines of code: ~2000+
- Pages: 6 complete interactive scenes
- 3D objects: 60+ dynamic shapes
- Animations: All running at 60fps
- Procedural textures: 4 types (checker, noise, spiral, glitch)
- Recursive depth: Up to 4 levels (fractal crystal)

## 🎓 Learning Resources

- [openFrameworks Documentation](https://openframeworks.cc/documentation/)
- [openFrameworks Learning](https://openframeworks.cc/learning/)
- [openFrameworks Forum](https://forum.openframeworks.cc/)

## 📜 License

This project is open source. Feel free to explore, learn, and create!

## 🙏 Acknowledgments

- openFrameworks community for the amazing toolkit
- Renaissance masters for inspiring the sublime
- Existentialist philosophers for the absurd
- All emotions that make us human

---

**Created with code, emotion, and curiosity** 💙

*A collaborative exploration between human creativity and algorithmic expression*

