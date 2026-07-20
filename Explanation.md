3D Solar System

The idea of this project is to build a 3D Solar System using OpenGL. It consists of the Sun at the center, the Earth revolving around the Sun, and the Moon revolving around the Earth.

The main goal of this project is to demonstrate hierarchical modeling, transformations, rotations, basic lighting, and animations. In this system, the Earth revolves around the Sun, while the Moon revolves around the Earth. This naturally creates a hierarchical structure.

The hierarchy is organized into three levels:

First layer: Sun
Second layer: Earth
Third layer: Moon

If we try to calculate the Moon's absolute (x, y, z) position directly, it becomes complicated because the Moon's position depends on two factors:

The current position of the Earth relative to the Sun.
The Moon's position relative to the Earth.

Calculating these positions manually requires estimating the distances and continuously updating the coordinates, which becomes complex. Hierarchical modeling overcomes this problem by chaining the transformations. We first apply the transformation for the Sun, then apply the Earth's transformation relative to the Sun, and finally apply the Moon's transformation relative to the Earth.

In this hierarchy, every object inherits the transformation of its parent. The Earth's transformation is applied on top of the Sun's transformation, and the Moon's transformation is applied on top of the Earth's transformation. This makes the animation and positioning of objects much simpler and more realistic.

3D Solar System using OpenGL – Working Explanation

The Moon's transformation is relative to the Earth, and the Earth's transformation is relative to the Sun. This is where hierarchical modeling comes into the picture. Instead of calculating the position of every object independently, each object inherits the transformation of its parent. This makes the animation simpler and more efficient.

To design and implement this project, I used the OpenGL library.

Step 1: Initialize the OpenGL Window

The first step is to initialize the OpenGL window and enable the required features using OpenGL functions such as:

glEnable(GL_DEPTH_TEST)
glEnable(GL_LIGHTING)
glEnable(GL_LIGHT0)
glEnable(GL_COLOR_MATERIAL)

Here:

Depth testing ensures that objects closer to the camera hide objects that are farther away.
Lighting gives the Sun, Earth, and Moon a realistic 3D appearance.
Step 2: Draw the Sun

The Sun is placed at the center of the scene and remains stationary. It acts as the reference point for the entire solar system.

Step 3: Draw the Earth

The Earth revolves around the Sun. To achieve this:

Apply a rotation around the Sun.
Apply a translation away from the Sun to set the orbital radius.
Draw the Earth.

Step 4: Draw the Moon

The Moon revolves around the Earth. The steps are:

Rotate around the Earth.
Translate away from the Earth.
Draw the Moon.

The Moon automatically moves whenever the Earth moves because the Earth's transformation is already applied. This is achieved using the matrix stack functions glPushMatrix() and glPopMatrix(), which preserve and restore transformation states.

Step 5: Hierarchical Modeling

Instead of calculating the Moon's position separately, we first calculate the Earth's position. Then, using the Earth's transformed coordinate system, we calculate the Moon's position.

The hierarchy is:

First layer: Sun
Second layer: Earth
Third layer: Moon

Since each object depends on its parent, the Moon automatically follows the Earth, and the Earth automatically follows the Sun.

Step 6: Animation

Inside the display function, the Earth angle and Moon angle are updated for every frame.

The Earth revolves around the Sun at a slower speed.
The Moon revolves around the Earth at a faster speed.

Updating these angles continuously creates a smooth animation.

Step 7: Lighting

The Sun acts as the source of light. To simulate sunlight, OpenGL lighting functions such as:

glLightfv()
GL_LIGHT0
GL_POSITION

are used to define the position and properties of the light source. As a result, the Earth and Moon receive realistic lighting effects.

Concepts Used
Transformation: Used to move planets from one position to another.
Rotation: Used to simulate revolution around another object.
Hierarchical Modeling: Used to establish parent-child relationships, where the Moon depends on the Earth and the Earth depends on the Sun.
Matrix Stack (glPushMatrix() and glPopMatrix()): Used to save and restore transformations so that each object's transformations do not affect others.
Lighting: Used to simulate sunlight and provide a realistic 3D appearance.

Overall Flow
Initialize the OpenGL window.
Draw the Sun.
Apply rotation and translation to draw the Earth.
Apply rotation and translation to draw the Moon.
Update the Earth and Moon rotation angles.
Refresh the display and repeat the process continuously to create the animation.

The Simple Implementation is given in the SolarSyste.cpp