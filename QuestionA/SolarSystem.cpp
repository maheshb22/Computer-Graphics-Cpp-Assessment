#include <GL/glut.h>

// Rotation angles
float earthAngle = 0.0f;
float moonAngle = 0.0f;

// Function to draw the solar system
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	// Camera position
	gluLookAt(0.0, 5.0, 12.0,
			  0.0, 0.0, 0.0,
			  0.0, 1.0, 0.0);

	// Light source placed at the Sun
	GLfloat lightPos[] = {0.0f, 0.0f, 0.0f, 1.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	//------------------ SUN ------------------
	glPushMatrix();                  // Save current transformation
	glColor3f(1.0f, 1.0f, 0.0f);     // Yellow color
	glutSolidSphere(1.0, 40, 40);    // Draw Sun
	glPopMatrix();                   // Restore transformation

	//------------------ EARTH ------------------
	glPushMatrix();

	// Earth revolves around the Sun
	glRotatef(earthAngle, 0.0f, 1.0f, 0.0f);

	// Move Earth away from the Sun
	glTranslatef(5.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);     // Blue Earth
	glutSolidSphere(0.5, 30, 30);

	//------------------ MOON ------------------
	glPushMatrix();

	// Moon revolves around the Earth
	glRotatef(moonAngle, 0.0f, 1.0f, 0.0f);

	// Distance from Earth
	glTranslatef(1.2f, 0.0f, 0.0f);

	glColor3f(0.8f, 0.8f, 0.8f);     // Gray Moon
	glutSolidSphere(0.2, 20, 20);

	glPopMatrix();   // End Moon

	glPopMatrix();   // End Earth

	glutSwapBuffers();
}

// Animation function
void update()
{
	earthAngle += 0.2f;   // Earth revolves slowly
	moonAngle += 1.5f;    // Moon revolves faster

	if (earthAngle > 360)
		earthAngle -= 360;

	if (moonAngle > 360)
		moonAngle -= 360;

	glutPostRedisplay();
}

// OpenGL initialization
void init()
{
	glEnable(GL_DEPTH_TEST);      // Enable depth testing
	glEnable(GL_LIGHTING);        // Enable lighting
	glEnable(GL_LIGHT0);          // Enable first light source
	glEnable(GL_COLOR_MATERIAL);  // Use object colors

	glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
}

// Main function
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(800, 600);
	glutCreateWindow("Simple Solar System");

	init();

	glutDisplayFunc(display);
	glutIdleFunc(update);

	glutMainLoop();

	return 0;
}
