/* A simple solar system with a sun and a planet   */

#include <glut.h>
#include <stdlib.h>

static GLfloat year = 0.0, day = 0.0;

void display(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);    /* Renders based on the distance from the viewpoint */
    glPushMatrix();		/* saves the current state by pushing in the stack */
    glRotatef(year, 0.0, 1.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidSphere(1.0, 20, 16);        /* draws a sun in red */
    glTranslatef(5.0, 0.0, 0.0);
    // glRotatef(day, 0.0, 1.0, 0.0);
    // glColor3f(0.0, 0.0, 1.0);
    //glutWireSphere(0.5, 10, 8);	     /* draws a smaller planet in blue */
    glTranslatef(-3.0, 0.0, 0.0);
    glRotatef(day, 0.0, 0.75, 0.0);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidSphere(0.3, 10, 8); // Mercury

    glColor3f(0.7, 0.7, 0.0);
    glTranslatef(1.5, 0.0, 0.0);
    glutSolidSphere(0.6, 10, 8); // Venus

    glColor3f(0.6, 0.0, 0.0);
    glTranslatef(2.5, 0.0, 0.0);
    glutSolidSphere(0.5, 10, 16); // Mars
   
    glRotatef(30, 0.0, 0.0, 0.75);
    glRotatef(day * 5, 0.0, 0.75, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.75, 0.0, 0.0);
    glutSolidSphere(0.15, 10, 8);
    
    glTranslatef(0.75, 0.0, 0.0);
    glutSolidSphere(0.25, 10, 8);

    glPopMatrix();         /* restores the state before the rotations and translation */
    glutSwapBuffers();     /* swaps the front and back color buffers for animation */
}

void yearDisplay(void)
{
    year = year + 1.0;         // changing the angle for global (sun) rotation 
    if (year > 360.0) year = year - 360.0;
    day = day + 10.0;           // changing the angle for local (planet) rotation 
    if (day > 360.0) day = day - 360.0;
    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'y':
        glutIdleFunc(yearDisplay);   // The rotation angles get updated
        break;
    case 'n':
        glutIdleFunc(NULL);
        break;
    case 27:
        exit(0);
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("A simple solar system");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}