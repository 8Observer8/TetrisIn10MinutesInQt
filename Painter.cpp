#include "Painter.h"

void Painter::rect(int x1, int y1, int x2, int y2)
{
    glBegin( GL_QUADS );
    {
        glVertex2f( x1, y1 );
        glVertex2f( x2, y1 );
        glVertex2f( x2, y2 );
        glVertex2f( x1, y2 );
    }
    glEnd();
}

void Painter::setColor( Painter::Color color )
{
    static const struct
    {
        float r, g, b;
    } colors[] = {
    { 1, 0, 0 },        // Red
    { 1, 1, 1 },        // White
    { 1, 0, 1 },        // Magenta
    { 0, 0, 0.5 },      // Dark blue
    { 0, 1, 0 },        // Green
    { 0.5, 0.5, 0 },    // Brown
    { 0, 1, 1 },        // Cyan
    { 0, 0, 0 },        // Black
};
    glColor3f( colors[color].r,
               colors[color].g,
               colors[color].b );
}
