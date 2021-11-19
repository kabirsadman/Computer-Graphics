#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (0, 0, 0);
glPointSize(5.0);
    glBegin(GL_POLYGON);

    glVertex2i(400, 200);
    glVertex2i(600, 350);
    glVertex2i(370, 350);
    glVertex2i(300, 600);
    glVertex2i(230, 350);
    glVertex2i(000, 350);
    glVertex2i(200, 200);
    glVertex2i(300, 140);
    glVertex2i(500, 000);




    glEnd();
    glFlush ();
}
void myInit (void)
{
glClearColor(15.1, 15.1, 15.1, 15.1);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-50, 700, -50, 700);
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (660, 480);
glutInitWindowPosition (500, 400);
glutCreateWindow ("star");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
