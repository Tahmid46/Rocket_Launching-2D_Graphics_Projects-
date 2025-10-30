# Rocket Launching - 2D Graphics Project

A 2D graphics simulation of a rocket launching using OpenGL and GLUT (OpenGL Utility Toolkit). This project demonstrates computer graphics concepts including animation, transformations, polygon rendering, and user interaction.

## Overview

This project creates an animated scene showing a rocket launching from a ground-based launching pad into space. The simulation features:

- **Rocket Animation**: A multi-stage rocket that launches vertically from a launching pad
- **Dynamic Background**: Transitions from an Earth scene (ground and sky) to a space scene with stars and planets
- **Fire Effects**: Animated fire/exhaust effects during rocket launch
- **Interactive Controls**: Keyboard controls to manipulate the rocket's movement
- **Celestial Objects**: Stars, planets, and other space objects rendered in the space scene

## Features

### Visual Elements

1. **Rocket**: 
   - Three-stage design with payload (red nose cone)
   - Body composed of gray fuel tanks
   - Animated vertical ascent

2. **Launching Pad**: 
   - Ground-based platform that disappears after launch
   - Provides initial support structure

3. **Fire/Exhaust**: 
   - Animated flame effect at the rocket's base
   - Orange and white gradient for realistic appearance

4. **Background Scenes**:
   - **Ground Scene**: Green ground with blue sky (pre-launch)
   - **Space Scene**: Black background with stars and celestial bodies (post-launch)

5. **Stars and Planets**:
   - White stars of varying sizes
   - Colored planets (orange/red) with procedurally generated surfaces
   - Creates an immersive space environment

### Controls

- **UP Arrow**: Launch the rocket (increase altitude, activate fire effect)
- **LEFT Arrow**: Move rocket left
- **RIGHT Arrow**: Move rocket right
- **DOWN Arrow**: Move rocket down

## Technical Details

### Dependencies

- **OpenGL**: Core graphics library
- **GLUT/FreeGLUT**: OpenGL Utility Toolkit for window management and input handling
- **C++ Standard Library**: For basic operations

### Graphics Techniques Used

- **Polygon Rendering**: GL_POLYGON, GL_QUADS, GL_TRIANGLES for shapes
- **Point Rendering**: GL_POINTS for stars
- **Color Gradients**: Smooth color transitions
- **Animation**: Timer-based frame updates (controlled FPS)
- **Coordinate Transformations**: Position updates for movement
- **Procedural Generation**: Random variations in planet surfaces

### Code Structure

- `main.cpp`: Single source file containing all graphics code
- **Key Functions**:
  - `drawRocket()`: Renders the rocket with all its components
  - `drawFire()`: Animates the exhaust flames
  - `drawStars()`: Renders stars and celestial objects
  - `drawBackground()`: Renders ground and sky
  - `launchingPad()`: Renders the launching platform
  - `FlyRocket()`: Handles keyboard input for rocket control
  - `timer_callback()`: Updates animation frames

## Building and Running

### Prerequisites

Install the required OpenGL and GLUT libraries:

**On Linux (Ubuntu/Debian):**
```bash
sudo apt-get install freeglut3-dev
sudo apt-get install mesa-common-dev
```

**On macOS:**
```bash
# GLUT is included with Xcode Command Line Tools
xcode-select --install
```

**On Windows:**
- Install MinGW or Visual Studio
- Download and install FreeGLUT binaries
- Link against `glut32.lib`, `opengl32.lib`, `glu32.lib`

### Compilation

**Using g++ (Linux/macOS):**
```bash
g++ main.cpp -o rocket -lGL -lGLU -lglut
```

**Using Code::Blocks:**
1. Open `Polygon.cbp` in Code::Blocks
2. Build and run the project (F9)

### Running the Program

```bash
./rocket
```

A 600x600 pixel window titled "Rocket Launching" will appear with the initial scene showing the rocket on its launching pad.

## Project Configuration

- **Window Size**: 600x600 pixels
- **Coordinate System**: Orthographic projection (-5 to 5 on all axes)
- **Default FPS**: 10 (changes to 1.5 after transition to space)
- **Color Format**: RGB

## Animation Sequence

1. **Phase 1**: Rocket sits on launching pad with Earth background
2. **Phase 2**: Press UP arrow to initiate launch sequence
3. **Phase 3**: Rocket ascends with fire effects visible
4. **Phase 4**: Upon reaching altitude (yr=7.5), background transitions to space
5. **Phase 5**: Rocket continues in space environment with stars and planets visible

## Educational Value

This project demonstrates fundamental computer graphics concepts:
- 2D geometric primitives and polygon rendering
- Animation and timing
- User input handling
- State management (scene transitions)
- Color theory and gradients
- Coordinate systems and transformations

## License

This is an educational project. Feel free to use and modify for learning purposes.

## Author

Created as a 2D Graphics Project demonstrating OpenGL/GLUT capabilities.

## Future Enhancements

Potential improvements could include:
- Sound effects for rocket launch
- More complex star field with parallax scrolling
- Multiple rockets or satellites
- Particle systems for more realistic exhaust
- Camera follow mode
- Fuel gauge and mission timer
- Multiple launch scenarios or missions
