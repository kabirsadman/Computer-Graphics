#include <iostream>
#include<math.h>
#include<GL/gl.h>
#include <GL/glut.h>

using namespace std;


float X1,X2, X3, Y1, Y2, Y3;
int tx, ty, choose,op;
float d,sx,sy;

void Translation(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3ub (128, 128, 128);

    glBegin(GL_TRIANGLES);
    glVertex2i(X1, Y1);
    glVertex2i(X2, Y2);
    glVertex2i(X3, Y3);
    glEnd();
    glColor3ub (255, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(X1+tx, Y1+ty);
    glVertex2i(X2+tx, Y2+ty);
    glVertex2i(X3+tx, Y3+ty);
    glEnd();
    glFlush();
}

void Scaliing(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3ub (128, 128, 128);

    glBegin(GL_TRIANGLES);
    glVertex2i(X1, Y1);
    glVertex2i(X2, Y2);
    glVertex2i(X3, Y3);
    glEnd();
    glColor3ub (255, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(X1*sx, Y1*sy);
    glVertex2i(X2*sx, Y2*sy);
    glVertex2i(X3*sx, Y3*sy);
    glEnd();
    glFlush ();
}
void clock(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3ub (128, 128, 128);

    glBegin(GL_TRIANGLES);
    glVertex2i(X1, Y1);
    glVertex2i(X2, Y2);
    glVertex2i(X3, Y3);
    float nX2=X2*cos(d*3.14/180)+Y2*sin(d*3.14/180);
    float nY2=Y2*cos(d*3.14/180)-X2*sin(d*3.14/180);
    float nX3=X3*cos(d*3.14/180)+Y3*sin(d*3.14/180);
    float nY3=Y3*cos(d*3.14/180)-X3*sin(d*3.14/180);
    glColor3ub (255, 0, 0);
    glBegin(GL_TRIANGLES);



    glVertex2f(X1,Y1);

    glVertex2f(nX2,nY2);
    glVertex2f(nX3,nY3);
    glEnd();
    glFlush ();


}
void antiClock(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3ub (128, 128, 128);

    glBegin(GL_TRIANGLES);
    glVertex2i(X1, Y1);
    glVertex2i(X2, Y2);
    glVertex2i(X3, Y3);
    float nX2=X2*cos(d*3.14/180)-Y2*sin(d*3.14/180);
    float nY2=X2*sin(d*3.14/180)+Y2*cos(d*3.14/180);
    float nX3=X3*cos(d*3.14/180)-Y3*sin(d*3.14/180);
    float nY3=X3*sin(d*3.14/180)+Y3*cos(d*3.14/180);
    cout<<nX2<<" "<<nY2<<endl<<nX3<<" "<<nY3<<endl;
    glColor3ub (255, 0, 0);
    glBegin(GL_TRIANGLES);



    glVertex2f(X1,Y1);

    glVertex2f(nX2,nY2);
    glVertex2f(nX3,nY3);
    glEnd();
    glFlush ();

}
void myDisplay(void)
{
    if(choose == 1)Translation();
    else if(choose==2) Scaliing();
    else {
        if(op==1)antiClock();
        else clock();
    }
}

void myInit (void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, 640, 0, 480);
}


int main(int argc, char** argv)
{
cout<<"Enter 3 points: ";
    cin>>X1>>Y1;
    cin>>X2>>Y2;
    cin>>X3>>Y3;
cout<<"Enter the choice: ";
cin>>choose;
if(choose == 1){
    cout<<"Enter the translation factor: ";
    cin>>tx>>ty;

}
else if(choose==2){
    cout<<"Enter the Scaling factor: ";
    cin>>sx>>sy;

}
else{
    cout<<"1. Anti-Clock Wise  2. Clock Wise"<<endl;
    cin>>op;
    cout<<"Enter the value of degree : ";
    cin>>d;


}


glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
