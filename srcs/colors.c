#include "../includes/fractol.h"
void calculatei_color(int rootIndex, double proximity, uint32_t* color) {
    double saturation = 1.0 - proximity; 

    switch (rootIndex) {
        case 0:
            *color = (uint32_t)(255 * saturation) << 16;  // Red
            break;
        case 1:
            *color = (uint32_t)(255 * saturation) << 8;   // Green 
            break;
        case 2:
            *color = (uint32_t)(255 * saturation);        // Blue
            break;
        default:
            *color = 0x000000;  //Black by default 
            break;
    }
}
