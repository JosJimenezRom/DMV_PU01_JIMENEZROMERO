#include <GL/glut.h>
#include "figuras.hpp"

void figuras::dibujarRectaDirecta(int x1, int y1, int x2, int y2) {
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
}
