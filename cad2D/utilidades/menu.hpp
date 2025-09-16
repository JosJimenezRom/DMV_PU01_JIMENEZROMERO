#pragma once

//Figuras disponibles
enum class Figura {
    RectaDirecta,
    RectaDDA,
    CirculoPMedio,
    ElipsePMedio
};

extern Figura figura_actual;
extern int color_actual;
extern int grosor_actual;

namespace menu {
    void crearMenu();
}
