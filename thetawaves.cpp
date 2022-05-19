#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857

void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glColor3f(1.0f, 0.0f, 0.0f);

	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(-620.0, 620.0, -340.0, 340.0);
}


void myDisplay(void)
{
    float j,i = 0;
	float limit = 0.0f;
    while(1)
	{
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        float x, y;
        j = 500.0f;
        for ( ; i <  limit; i += 0.01)
        {
            x = j;
            y = 200 * sin(i);
            glVertex2i(x, y);
			j-= 1.0f;
        }
		limit += 0.1f;
 		i = limit * 0.1;
        glEnd();
		glutSwapBuffers();

	}
}


int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(1920, 600);
	
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Game");

	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
