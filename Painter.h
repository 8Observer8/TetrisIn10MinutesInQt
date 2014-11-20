#ifndef PAINTER_H
#define PAINTER_H

#include <GL/gl.h>

class Painter
{
public:
    enum Color { RED, WHITE, MAGANTA, DARK_BLUE,
                 GREEN, BROWN, CYAN, BLACK };
    void rect( int x1, int y1, int x2, int y2 );
    void setColor( Color );
};

#endif // PAINTER_H
