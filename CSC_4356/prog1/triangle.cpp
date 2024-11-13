// A simple OpenGL program which draws a red triangle in a white window.
// c++ -w triangle.cpp -framework OpenGL -framework GLUT 

#include <glut.h> // Change the location as needed to <GL/glut.h> or <glut.h>
#include <stdlib.h>     // Header file for C++


void init(void)
{
    glClearColor(0.8, 0.8, 0.8, 0.0);     // Specifiy window clearing (gray) color
    glMatrixMode(GL_PROJECTION);         // Set the pojection parameters
    glOrtho(-1.0, 1.0, -1.0, 1.0, 0.0, 0.0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);         // Apply the clearing color
    glColor3f(1.0, 0.0, 0.0);             // Set drawing red color
    glBegin(GL_TRIANGLE_STRIP);               // Drawing mode
    glVertex2f(0.0, 0.8);
    glColor3f(1.0, 1.0, 0.0); // yellow
    glVertex2f(0.7, 0.4);
    glColor3f(0.0, 1.0, 0.0); // green
    glVertex2f(0.7, -0.4);
    glColor3f(0.0, 1.0, 1.0); // cyan
    glVertex2f(0.0, -0.8);
    glColor3f(0.0, 0.0, 1.0); // blue
    glVertex2f(-0.7, -0.4);
    glColor3f(1.0, 0.0, 1.0);
    glVertex2f(-0.7,0.4);
    glEnd();
    glPointSize(10.0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS); // Points
    glVertex2f(0.0, 0.8);
    glVertex2f(0.7, 0.4);
    glVertex2f(0.7, -0.4);
    glVertex2f(0.0, -0.8);
    glVertex2f(-0.7, -0.4);
    glVertex2f(-0.7, 0.4);
    glEnd();
    glBegin(GL_LINES); // X and Y axes
    glVertex2f(0.0, 1.0);
    glVertex2f(0.0, -1.0);
    glVertex2f(-1.0, 0);
    glVertex2f(1, 0);
    glEnd();
    glFlush();         // Process all OpenGL routines asap (start drawing)
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {			// Exit or close the display when press "esc" key
    case 27:
        exit(0);
        break;
    }
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);                        // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set display mode
    glutInitWindowPosition(100, 100);    // Set top-left display window position
    glutInitWindowSize(500, 500);        // Set display window width and height
    glutCreateWindow("Polygon");       // Create display window
    init();                               // Execute initialization procedure
    glutDisplayFunc(display);		  // Send graphics to display window	
    glutKeyboardFunc(keyboard);	  // Process keyboard input
    glutMainLoop();                       // Display every thing and wait
}