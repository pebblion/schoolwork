//  Adding lighting effects on two objects: torus and sphere 
// c++ -w lightPA2.cpp -framework OpenGL -framework GLUT

#include <GL/glut.h>
#include <stdlib.h>

static GLfloat rot1 = 0.0, rot2 = 00.0;
static GLfloat light_position[] = {0.0, 0.0, 10.0, 0.0};
static GLfloat light1_position[] = { 5.0, 5.0, 5.0, 1.0 };
static GLfloat zero[] = {0.0, 0.0, 0.0, 1.0};
static GLfloat light_diffuse[] = {0.0, 1.0, 1.0, 1.0};
static GLfloat torus_emission[] = {1.0, 0.1, 0.1, 1.0};
static GLfloat torus_diffuse[] = {0.5, 0.5, 0.5, 1.0};
static GLfloat sphere_diffuse[] = {0.8, 0.8, 0.8, 1.0};
static GLfloat sphere_specular[] = {1.0, 1.0, 1.0, 1.0};
static GLfloat light1_specular[] = {1.0, 1.0, 1.0, 1.0};
static GLfloat shininess[] = {90.0};

void init(void)
{
    glClearColor(0.2, 0.2, 0.2, 0.0);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, zero);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, zero);
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
    glLightfv(GL_LIGHT1, GL_AMBIENT_AND_DIFFUSE, zero);
    glEnable(GL_DEPTH_TEST);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, torus_emission);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, torus_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, zero);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, zero);
    glutSolidTorus(0.5, 1.0, 50, 50);
    glRotatef(rot1, 0.0, 1.0, 0.0);
    glTranslatef(4.0, 0.0, 0.0);
    glRotatef(rot2, 0.5, 1.0, 0.0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, sphere_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, sphere_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, zero);
    glutSolidSphere(1.0, 100, 100);
    glPopMatrix();
    glutSwapBuffers();
}

void yearDisplay(void)
{
    rot1 = rot1 + 1.0;
    if (rot1 > 360.0)
        rot1 = rot1 - 360.0;
    rot2 = rot2 + 2.0;
    if (rot2 > 360.0)
        rot2 = rot2 - 360.0;
    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'y':
        glutIdleFunc(yearDisplay);
        break;
    case 'n':
        glutIdleFunc(NULL);
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lighting");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}