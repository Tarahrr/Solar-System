

#include<gl\glut.h>
#include<iostream>
using namespace std;



float a = 0;

float x = 100;
float y = 15.0;
float t = 0.0;
float xl = 0.0;
float Inc = 0.0;
float orbit = 0.0;
//angleSun
float  angleSun[9] = { 0.2376, 0.6075, 1, 1.8694, 12, 29, 84, 165, 248 };
//angleY - around the sun
float  angleY[9] = { 59.0, 243, 1, 1.02, 0.38, 0.41, 0.43, 0.63, 6.16 };
//distance
float  dist[9] = { 1.0, 1.89, 2.63, 4.0, 13.66, 25.0, 50.52, 78.94, 103.50 };
//diameter
float  red[9] = { 0.202, 0.516, 0.538, 0.286, 5.991, 4.978, 2.109, 2.278, 0.1 };
//color

float colorR[9] = { 0.54, 0.9, 0, 0.45, 0.69, 0.63, 0.9, 1, 0.63 };
float colorG[9] = { 0.76, 0.51, 0, 1, 0.22, 1, 0.29, 0.31, 1 };
float colorB[9] = { 1, 0.04, 0.32, 1, 1, 0.64, 0.14, 0.28, 0.83 };

float q = 0.0, w = 0.0, e =0.0 , r =0;




void lighting()
{


	//glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse_color);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

}

/*
void drawSphereMoon(float distance, float reduis, float angleY, float angleSun, float rot){
	//earth
	//around the sun
	glRotatef(xl, 0.0, 0.0, 1.0);
	glRotatef(angleSun + rot, 0.0, 0.0, 1.0);

	glTranslatef(distance, 0.0, 0.0);
	//around the sun
	glRotatef(angleY, 0.0, 0.0, 1.0);
	//color
	glColor3f(0.0,0.0,1.0);
	//glutSolidSphere(reduis, 30, 30);
	glutWireSphere(reduis, 30, 30);

	//Draw moon
	orbit += 1;
	glRotatef(orbit / 0.0729, 0.0, 0.0, 1.0);
	glTranslatef(2.63 + 0.0067, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(0.145, 10, 10);
}*/
void drawSphere(float distance, float reduis, float angleY, float angleSun, float rot, int i){
	//earth
	//dore khorshid
	GLfloat light_ambient_color[] = { 0.5, 0.5, 0.5, 0.5 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, light_ambient_color);
	glRotatef(xl, 0.0, 0.0, 1.0);
	glRotatef(angleSun , 0.0, 0.0, 1.0);

	glTranslatef(distance, 0.0, 0.0);
	//arounf the sun
	glRotatef(angleY, 0.0, 0.0, 1.0);
	//color
	glColor3f(colorR[i], colorG[i], colorB[i]);
	//glutSolidSphere(reduis, 30, 30);
	glutWireSphere(reduis, 30, 30);
}
void drawsun(){
	glTranslatef(0.0, 0.0, -x);
	glRotatef(t, 0.0, 1.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glRotatef(xl, 1.0, 0.0, 0.0);
	GLfloat light_ambient_color[] = { 4.0, 4.0, 0.0, 2.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, light_ambient_color);
	glColor3f(1.0, 1.0, 0.0);
	glutWireSphere(58.6, 15, 15);
	//glutSolidSphere(58.6, 30, 30);

}
void Display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//********************************************************************
	// Reset transformations
	GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	//glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient_color);
	glEnable(GL_LIGHT0);
	glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glLoadIdentity();
	drawsun();

	if (t > 360 || t < -360)
		t = t / 360;

	//lighting();
	// ***************************************************************
	float sum = 58.6;
	Inc= Inc +1;
	for (int i = 0; i < 9; i++){
		sum += dist[i] * 2;
		glPushMatrix();
			drawSphere(sum, red[i], Inc / angleY[i], Inc / (angleSun[i] * 10), t,i);
		glPopMatrix();
	}
	//***************************************************************
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}
void pressSpecialKey(int key, int xx, int yy)
{
	switch (key) {
	case GLUT_KEY_UP: x -= 1; break;
	case GLUT_KEY_DOWN: x += 1; break;
	case GLUT_KEY_RIGHT: t += 0.5; break;
	case GLUT_KEY_LEFT: t -= 0.5; break;
	case GLUT_KEY_F1: xl -= 0.5; break;
	case GLUT_KEY_F2: xl += 0.5; break;
	}
}

void releaseSpecialKey(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_UP: x = x; break;
	case GLUT_KEY_DOWN: x = x; break;
	}
}
void init(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

}
static void ResizeWindow(int w, int h)
{
	float aspectRatio;

	if (h == 0) h = 1;
	else h = h;

	if (w == 0) w = 1;
	else w = w;
	glViewport(0, 0, w, h);
	aspectRatio = (float)w / (float)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, aspectRatio, 1, 10000000000);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(60, 25);
	glutInitWindowSize(1200, 650);
	glutCreateWindow("My Solar System");

	init();
	
	glutDisplayFunc(Display);
	glutReshapeFunc(ResizeWindow);
	glutSpecialFunc(pressSpecialKey);
	glutSpecialUpFunc(releaseSpecialKey);
	glutMainLoop();

	return 0;

}
