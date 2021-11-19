#include<cstdio>

#include <GL/gl.h>
#include <GL/glut.h>


GLfloat position = 0.0f, position1 = 0.0f, posRocket=0.0,position6=0.0f,pos9=0.0f, positionbullet=0.0f,ammopos=0.0f;

GLfloat speed = 0.1f, speed1=0.2f, speedRocket=0.3f, speed6=0.3f,speed9=0.3f, speedbullet = 0.1f,speedAmmo=0.2f;

void update(int value) {

    if(position < -1.8)
        position = 1.2f;

    position -= speed;

    if(position1 < -1.8)
        position1 = 1.2f;

    position1 -= speed1;


    if(position6 < -1.8)
        position6 = 1.2f;

    position6 -= speed6;
	glutPostRedisplay();



	glutTimerFunc(100, update, 0);
}
void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed += 0.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}

	glutPostRedisplay();
}


void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 'l':
      if(posRocket && pos9 < -.90){
        posRocket && pos9 == posRocket && pos9;
	glutPostRedisplay();
    }
    else{
        posRocket-=0.05;
        pos9-=0.05;
    }
    break;
case 'r':
  if(posRocket && pos9 > .90){
        posRocket && pos9 == posRocket && pos9;
	glutPostRedisplay();
    }
    else{
        posRocket+=0.05;
        pos9+=0.05;
    }
    break;

    if(ammopos>0.0)
    {
        ammopos+=speedAmmo;
    }
    if(ammopos>2.00)
    {
       ammopos=0.00f;

    }
case 'f':
    ammopos+=speedAmmo;
    break;




glutPostRedisplay();



	}
}


void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();



glPushMatrix();
glTranslatef(0,position, 0.0f);
   //glBegin(GL_QUADS);
    //  glColor3f(1.0f, 0.0f, 0.0f);
    //  glVertex2f(-0.2f, -0.2f);
    //  glVertex2f( 0.2f, -0.2f);
     // glVertex2f( 0.2f,  0.2f);
     // glVertex2f(-0.2f,  0.2f);
  //  glEnd();
   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex2f(-0.8f,0.7f);
   glVertex2f(-0.6f, 0.9f);
   glVertex2f(-1.0f, 0.9f);
   glEnd();

glPopMatrix();



glPushMatrix();
glTranslatef(0,position1, 0.0f);
   //glBegin(GL_QUADS);
    //  glColor3f(1.0f, 0.0f, 0.0f);
    //  glVertex2f(-0.2f, -0.2f);
    //  glVertex2f( 0.2f, -0.2f);
     // glVertex2f( 0.2f,  0.2f);
     // glVertex2f(-0.2f,  0.2f);
  //  glEnd();
   glBegin(GL_TRIANGLES);
   glColor3f(1.0f, 0.0f, 1.0f);
   glVertex2f(0.8f,0.7f);
   glVertex2f(1.0f, 0.9f);
   glVertex2f(0.6f, 0.9f);
   glEnd();

glPopMatrix();

 glPushMatrix();
    glTranslatef(pos9,0.0, 0.0f);
     glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex2f(-0.1f,-1.0f);
   glVertex2f(0.1f, -1.0f);
   glVertex2f(0.0f, 0.0f);
   glEnd();
   glPopMatrix();

glPushMatrix();
glTranslatef(posRocket,0.0, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.2f, -1.0f);
      glVertex2f( 0.2f, -1.0f);
      glVertex2f( 0.2f,  -0.8f);
      glVertex2f(-0.2f,  -0.8f);
    glEnd();



 //  glBegin(GL_TRIANGLES);
  // glColor3f(1.0f, 0.0f, 1.0f);
  // glVertex2f(0.8f,0.7f);
  // glVertex2f(1.0f, 0.9f);
  // glVertex2f(0.6f, 0.9f);
  // glEnd();
//lllloll
glTranslatef(0,position6, 0.0f);

glPushMatrix();
 glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex2f(-0.2f,0.2f);
   glVertex2f(0.2f, 0.2f);
   glVertex2f(0.0f, 0.0f);
   glEnd();
   glPopMatrix();


   glFlush();
}



int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(320, 320);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Basic Animation");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutTimerFunc(1000, update, 0);
   glutMainLoop();
   return 0;
}
