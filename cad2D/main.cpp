#include <GL/glut.h>

int ancho_ventana = 800;
int alto_ventana  = 600;


void configurarVentana() {
    glClearColor(1.0, 1.0, 1.0, 1.0); //Fondo de color blanco
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, ancho_ventana, 0, alto_ventana);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void dibujar() {
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void redimensionar(int w, int h) {
    ancho_ventana = w;
    alto_ventana  = h;
    glViewport(0, 0, w, h);
    configurarVentana();
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(ancho_ventana, alto_ventana);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("CAD 2D - Proyecto Josue");

    configurarVentana();

    glutDisplayFunc(dibujar);
    glutReshapeFunc(redimensionar);

    glutMainLoop();
    return 0;
}


