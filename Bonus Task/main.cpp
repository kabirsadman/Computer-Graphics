#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (0,0,0);
glPointSize(5.0);
glBegin(GL_QUADS);
glVertex2i(30, 100);
glVertex2i(60, 10);
glVertex2i(60, 30);
glVertex2i(30, 100);
glEnd();
glBegin(GL_QUADS);
glVertex2i(60, 10);
glVertex2i(60, 30);
glVertex2i(90, 80);
glVertex2i(90, 60);
glEnd();
glBegin(GL_QUADS);
glVertex2i(90, 80);
glVertex2i(90, 60);
glVertex2i(120, 10);
glVertex2i(120, 30);
glEnd();
glBegin(GL_QUADS);
glVertex2i(120, 10);
glVertex2i(120, 30);
glVertex2i(150, 100);
glVertex2i(150, 100);
glEnd();

glFlush();
}
void myInit (void)
{
glClearColor(15.0, 15.0, 15.0, 15.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (650, 300);
glutCreateWindow ("Bonus");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
