#if defined(linux) || defined(_WIN32)
#include <GL/glut.h>    /*Äëÿ Linux è Windows*/
#else
#include <GLUT/GLUT.h>  /*Äëÿ Mac OS*/
#endif
 
void reshape(int w, int h)
{
        glViewport(0, 0, w, h);
       
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, w, 0, h);
       
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
}
 
void display()
{
        glClear(GL_COLOR_BUFFER_BIT);
       
	glBegin(GL_QUADS);
	glColor3f(93.0, 148.0, 243.0);
	glVertex2i(0, 0);
	glColor3f(93.0, 148.0, 243.0);
	glVertex2i(0, 600);
	glColor3f(93.0, 148.0, 243.0);
	glVertex2i(800, 600);
	glColor3f(93.0, 148.0, 243.0);
	glVertex2i(800, 0);
	glEnd();;
       
        glutSwapBuffers();
}
 
int main (int argc, char * argv[])
{
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
       
        glutInitWindowSize(800, 600);
        glutCreateWindow("OpenGL lesson 1");
       
        glutReshapeFunc(reshape);
        glutDisplayFunc(display);
       
        glutMainLoop();
       
        return 0;
}