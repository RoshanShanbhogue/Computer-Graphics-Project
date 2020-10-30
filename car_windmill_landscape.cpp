#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

/*GLboolean moving = GL_FALSE;

#define MOTION_ON	    3
#define MOTION_OFF	    4
#define QUIT		    5
*/
const double PI = 3.141592654;
float ta=0,tb=0,tc=0;
int frameNumber = 0;
//to draw disks for the sun, the head and tail lights of the car and the wheels of the car
void drawDisk(double radius) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 32; d++) {
		double angle = 2*PI/32 * d;
		glVertex2d( radius*cos(angle), radius*sin(angle));
	}
	glEnd();
}
// to draw the wheels of the car
void drawWheel() {
    int i;
	glColor3f(0,0,0);
	drawDisk(1);
	glColor3f(0.75f, 0.75f, 0.75f);
	drawDisk(0.8);
	glColor3f(0,0,0);
	drawDisk(0.2);
	glRotatef(frameNumber*5,0,0,1);
	glBegin(GL_LINES);
	for (i = 0; i < 5; i++) {
		glVertex2f(0,0);
		glVertex2d(cos(i*2*PI/5), sin(i*2*PI/5));
		glVertex2f(0.1,0.1);
		glVertex2d(cos(i*2*PI/5), sin(i*2*PI/5));
		glVertex2f(0.05,0.05);
		glVertex2d(cos(i*2*PI/5), sin(i*2*PI/5));
		glVertex2f(0.075,0.075);
		glVertex2d(cos(i*2*PI/5), sin(i*2*PI/5));
		glVertex2f(0.025,0.025);
		glVertex2d(cos(i*2*PI/5), sin(i*2*PI/5));
	}
//	glLineWidth(5.0f);
	glEnd();
}

void drawCar() {
//tires
	glPushMatrix();
	glTranslatef(-1.5f, -0.1f, 0);
	glScalef(0.8f,0.8f,1);
	drawWheel();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(1.5f, -0.1f, 0);
	glScalef(0.8f,0.8f,1);
	drawWheel();
	glPopMatrix();
//car bod
	glColor3f(0.5,0,0.5);
	glBegin(GL_POLYGON);
		glVertex2f(-3.0f,0);
		glVertex2f(3.75f,0);
		glVertex2f(3.75f,1);
		glVertex2f(3.0f,1);
		glVertex2f(2.0f,3);
		//glVertex2f(-2.0f,2);
		//glVertex2f(-2.0f,1);
		glVertex2f(-3.0f,3);
	glEnd();
	glColor3f(0,0.5,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(0.0,2.7);
		glVertex2f(1.9,2.7);
		glVertex2f(1.9,1.2);
		glVertex2f(0.0,1.2);
	glEnd();
	glColor3f(0,0.5,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(2.0,2.7);
		glVertex2f(2.0,1.2);
		glVertex2f(2.7,1.2);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINES);
		glVertex2f(0.0,0.2);
		glVertex2f(0.0,2.7);
		
		glVertex2f(0.0,2.7);
		glVertex2f(1.9,2.7);
		
		glVertex2f(1.9,2.7);
		glVertex2f(1.9,1.2);
		
		glVertex2f(1.9,1.2);
		glVertex2f(0.0,1.2);
		
		glVertex2f(1.9,1.2);
		glVertex2f(1.9,0.6);
		
		glVertex2f(1.9,0.6);
		glVertex2f(1.5,0.2);
		
		glVertex2f(1.5,0.2);
		glVertex2f(0.0,0.2);
		
		glVertex2f(0.1,0.8);
		glVertex2f(0.4,0.8);
	/*	
		glVertex2f(-0.1,0.1);
		glVertex2f(-0.1,1.9);
		
		glVertex2f(-0.1,1.9);
		glVertex2f(-1.9,1.9);
		
		glVertex2f(-1.9,1.9);
		glVertex2f(-2.4,0.9);
		
		glVertex2f(-2.4,0.9);
		glVertex2f(-0.1,0.9);
		
		glVertex2f(-1.9,0.9);
		glVertex2f(-1.9,0.1);
		
		glVertex2f(-1.9,0.1);
		glVertex2f(-0.1,0.1);
		
		glVertex2f(-1.9,1.9);
		glVertex2f(-1.9,0.9);
	
		glVertex2f(-1.6,0.7);
		glVertex2f(-1.4,0.7);*/
	glEnd();
	
	/*glColor3f(1,0,0);
	glBegin(GL_LINES);
		glVertex2f(-3.5,2);
		glVertex2f(-3.0,1);
	glEnd();*/
//head and tail lights
	glTranslated(3.7,0.8,0);
	glColor3f(1,1,0);
	drawDisk(0.2);
	
	glTranslated(-6.7,0,0);
	glColor3f(1,0.15,1);
	drawDisk(0.2);
	
	glTranslated(0,0.3,0);
	glColor3f(1,0,0);
	drawDisk(0.2);
}

void drawSun() {
	int i;
	glColor3f(1,1,0);
	for (i = 0; i < 13; i++) { 
		glRotatef( 360 / 13, 0, 0, 1 );
		glBegin(GL_LINES);
			glVertex2f(0, 0);
			glVertex2f(0.75f, 0);
		glEnd();
	}
	drawDisk(0.5);
	glColor3f(0,0,0);
}

void drawWindmill() {
	int i;
	glColor3f(0.8f, 0.8f, 0.9f);
	glBegin(GL_POLYGON);
		glVertex2f(-0.05f, 0);
		glVertex2f(0.05f, 0);
		glVertex2f(0.05f, 3);
		glVertex2f(-0.05f, 3);
	glEnd();
	glTranslatef(0, 3, 0);
	glRotated(frameNumber * (180.0/46), 0, 0, 1);
	glColor3f(0.4f, 0.4f, 0.8f);
	for (i = 0; i < 3; i++) {
		glRotated(120, 0, 0, 1);
		glBegin(GL_POLYGON);
			glVertex2f(0,0);
			glVertex2f(0.5f, 0.1f);
			glVertex2f(1.5f,0);
			glVertex2f(0.5f, -0.1f);
		glEnd();
    glColor3f(1,0,1);
    drawDisk(0.1);
	}
}

void display() {
//the blue sky
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
//three mountains
	glColor3f(0.2f, 0.3f, 0);
	glBegin(GL_POLYGON);
		glVertex2f(-3,-1);
		glVertex2f(3,2.1f);
		glVertex2f(7,-1);
	glEnd();
	glColor3f(0, 0.6f, 0.2f);
	glBegin(GL_POLYGON);
		glVertex2f(-3,-1);
		glVertex2f(1.5f,1.65f);
		glVertex2f(5,-1);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(0,-1);
		glVertex2f(6,1.2f);
		glVertex2f(20,-1);
	glEnd();
//some icing on the second mountain
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
		glVertex2f(2.4f,1.8f);
		glVertex2f(3,2.1f);
		glVertex2f(3.4f,1.8f);
	glEnd();
//road
	glColor3f(0.4f, 0.4f, 0.5f);
	glBegin(GL_POLYGON);
		glVertex2f(0,-0.4f);
		glVertex2f(7,-0.4f);
		glVertex2f(7,0.4f);
		glVertex2f(0,0.4f);
	glEnd();
//lane strip
	glLineWidth(6);
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(0,0);
		glVertex2f(7,0);
	glEnd();
	glLineWidth(1);
//sun
	glPushMatrix();
	glTranslated(5.8,3,0);
	glRotated(-frameNumber*0.7,0,0,1);
	drawSun();
	glPopMatrix();
// 3 windmills
	glPushMatrix();
	glTranslated(0.75,1,0);
	glScaled(0.6,0.6,1);
	drawWindmill();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.2,1.6,0);
	glScaled(0.4,0.4,1);
	drawWindmill();
	glPopMatrix();

	glPushMatrix();
	glTranslated(3.7,0.8,0);
	glScaled(0.7,0.7,1);
	drawWindmill();
	glPopMatrix();
//the amazing 2d car
	glPushMatrix();
	//glTranslated(10*(frameNumber % 300) / 300.0, 0, 0);
    glTranslatef(ta,tb,tc);
	glScaled(0.3,0.3,1);
	drawCar();
	glPopMatrix();	
	
	glutSwapBuffers();
}
void arrow(int key, int x, int y)
    {
        switch(key)
        {
          /*  case GLUT_KEY_UP:
            tb+=0.1;
            break;
            case GLUT_KEY_DOWN:
            tb-=0.1;
            break;*/
            case GLUT_KEY_LEFT:
            ta-=0.1;
            if(ta==-0.5) ta=0;
            break;
            case GLUT_KEY_RIGHT:
            ta+=0.1;
            if(ta==0.5) ta=0.5;
            break;
        }

    glutPostRedisplay();
    }   

void doFrame(int v) {
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(30,doFrame,0);
}

void init() {
	glClearColor(0.5f, 0.5f, 1, 1);
		//setting the coordinates system.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 7, -1, 4, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

//void menu(int item)
//{
//  switch (item) {
//  case MOTION_ON:moving = GL_TRUE;
//                 glutIdleFunc(display);
//                 break;
//  
//  case MOTION_OFF:moving = GL_FALSE;
//                  glutIdleFunc(NULL);
//                  break;
//
//  case QUIT:exit(0);
//            break;
//  }
//}

int main(int argc, char** argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(100,100);  
    glutCreateWindow("CG PROJECT BY ROSHAN D SHANBHOGUE : CAR, MOUNTAINS, SUN AND WINDMILLS"); 
    init();
    glutDisplayFunc(display);   
    glutTimerFunc(200,doFrame,0); 
 //glutAddMenuEntry("Motion on", MOTION_ON);
 //glutAddMenuEntry("Motion off",MOTION_OFF);
 //glutAddMenuEntry("Quit", QUIT);
 //glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutSpecialFunc( arrow );
    glutMainLoop(); 
    return 0;
}    
