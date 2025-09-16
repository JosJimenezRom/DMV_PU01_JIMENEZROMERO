#include <GL/glut.h>
#include "menu.hpp"

Figura figura_actual = Figura::RectaDirecta;
int color_actual = 1;
int grosor_actual = 1;

void seleccionarFigura(int opcion) {
    switch (opcion) {
        case 1: figura_actual = Figura::RectaDirecta; break;
        case 2: figura_actual = Figura::RectaDDA; break;
        case 3: figura_actual = Figura::CirculoPMedio; break;
        case 4: figura_actual = Figura::ElipsePMedio; break;
    }
}

void seleccionarColor(int opcion) { color_actual = opcion; }
void seleccionarGrosor(int opcion) {
    if (opcion == 1) grosor_actual = 1;
    else if (opcion == 2) grosor_actual = 2;
    else if (opcion == 3) grosor_actual = 3;
    else if (opcion == 4) grosor_actual = 5;
}

void menu::crearMenu() {
    int m_figuras = glutCreateMenu(seleccionarFigura);
    glutAddMenuEntry("Recta (Directo)", 1);
    glutAddMenuEntry("Recta (ADD/DDA)", 2);
    glutAddMenuEntry("Círculo (Punto Medio)", 3);
    glutAddMenuEntry("Elipse (Punto Medio)", 4);

    int m_colores = glutCreateMenu(seleccionarColor);
    glutAddMenuEntry("Negro", 1);
    glutAddMenuEntry("Rojo", 2);
    glutAddMenuEntry("Verde", 3);
    glutAddMenuEntry("Azul", 4);

    int m_grosor = glutCreateMenu(seleccionarGrosor);
    glutAddMenuEntry("1 px", 1);
    glutAddMenuEntry("2 px", 2);
    glutAddMenuEntry("3 px", 3);
    glutAddMenuEntry("5 px", 4);

    int m_principal = glutCreateMenu([](int){});
    glutAddSubMenu("Dibujo", m_figuras);
    glutAddSubMenu("Color", m_colores);
    glutAddSubMenu("Grosor", m_grosor);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

