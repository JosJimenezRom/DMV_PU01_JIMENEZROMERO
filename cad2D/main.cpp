// main.cpp
#include <GL/glut.h>
#include "utilidades/menu.hpp"
#include "utilidades/eventos.hpp"

// Parámetros iniciales de la ventana
int ancho_ventana = 800;
int alto_ventana  = 600;

void inicializarVentana() {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(ancho_ventana, alto_ventana);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("CAD 2D - Proyecto Josue");

    glClearColor(1.0, 1.0, 1.0, 1.0); // fondo blanco
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, ancho_ventana, 0, alto_ventana); // origen abajo-izquierda
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    inicializarVentana();

    eventos::registrarCallbacks();  // mouse, teclado, redibujar
    menu::crearMenu();              // menú popup con botón derecho

    glutMainLoop();
    return 0;
}

