#include <GL/glut.h>
#include <iostream>
#include "eventos.hpp"

int x_inicio = -1, y_inicio = -1;
int x_fin    = -1, y_fin    = -1;


//manejo del mouse
void manejarMouse(int boton, int estado, int x, int y) {
    if (boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN) {
        if (x_inicio == -1) {
            x_inicio = x;
            y_inicio = y;
            std::cout << "Punto inicial: (" << x << ", " << y << ")" << std::endl;
        } else {
            x_fin = x;
            y_fin = y;
            std::cout << "Punto final: (" << x << ", " << y << ")" << std::endl;

            //Aquí luego se llamará a la función de dibujo
            x_inicio = -1;
            y_inicio = -1;
        }

        glutPostRedisplay();
    }
}

//Captura teclas
void manejarTeclado(unsigned char tecla, int x, int y) {
    switch (tecla) {
        case 'c': case 'C':
            std::cout << "Limpiar pantalla (pendiente)" << std::endl;
            break;
        case 'z': case 'Z':
            std::cout << "Deshacer último (pendiente)" << std::endl;
            break;
        default:
            std::cout << "Tecla presionada: " << tecla << std::endl;
    }
}

void eventos::registrarCallbacks() {
    glutMouseFunc(manejarMouse);
    glutKeyboardFunc(manejarTeclado);
}
