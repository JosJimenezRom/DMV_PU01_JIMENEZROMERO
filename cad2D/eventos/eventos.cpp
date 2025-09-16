#include <GL/glut.h>
#include <iostream>
#include "eventos.hpp"
#include "../figuras/figuras.hpp"
#include "../utilidades/menu.hpp"

//Traemos el alto de la ventana desde main.cpp para invertir Y
extern int alto_ventana;

int x_inicio = -1, y_inicio = -1;
int x_fin    = -1, y_fin    = -1;

extern Figura figura_actual;
extern int color_actual;
extern int grosor_actual;

static void aplicarEstilo() {
    switch (color_actual) {
        case 1: glColor3f(0.0f, 0.0f, 0.0f); break; //negro
        case 2: glColor3f(1.0f, 0.0f, 0.0f); break; //rojo
        case 3: glColor3f(0.0f, 1.0f, 0.0f); break; //verde
        case 4: glColor3f(0.0f, 0.0f, 1.0f); break; //azul
    }
    glLineWidth(static_cast<GLfloat>(grosor_actual));
}

//Manejo del mouse
static void manejarMouse(int boton, int estado, int x, int y) {
    if (boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN) {
        // Invertir Y para coord. de OpenGL (origen abajo-izquierda)
        const int y_invertida = alto_ventana - y;

        if (x_inicio == -1) {
            x_inicio = x;
            y_inicio = y_invertida;
            std::cout<<"Punto inicial: (" << x << ", " << y_invertida << ")\n";
        } else {
            x_fin = x;
            y_fin = y_invertida;
            std::cout<<"Punto final: (" << x << ", " << y_invertida << ")\n";

            //reseteo/limpiar dibujo
            glutPostRedisplay();

            x_inicio = -1;
            y_inicio = -1;
        }
    }
}

//Captura teclas
static void manejarTeclado(unsigned char tecla, int, int) {
    switch (tecla) {
        case 'c': case 'C':
            std::cout << "Limpiar pantalla (pendiente)\n";
            break;
        case 'z': case 'Z':
            std::cout << "Deshacer último (pendiente)\n";
            break;
        default:
            std::cout << "Tecla presionada: " << tecla << "\n";
    }
}

void eventos::registrarCallbacks() {
    glutMouseFunc(manejarMouse);
    glutKeyboardFunc(manejarTeclado);
}

void eventos::dibujarFiguraTemporal() {
    if (x_inicio == -1 || x_fin == -1) return;

    aplicarEstilo();

    switch (figura_actual) {
        case Figura::RectaDirecta:
            figuras::dibujarRectaDirecta(x_inicio, y_inicio, x_fin, y_fin);
            break;
        default:
            std::cout << "Figura aún no implementada.\n";
    }
}


