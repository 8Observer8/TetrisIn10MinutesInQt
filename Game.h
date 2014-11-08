#ifndef GAME_H
#define GAME_H

#include "Painter.h"

class Game
{
public:
    enum Direction { UP, DOWN, LEFT, RIGHT };
    void draw( Painter & );
    void tick();
    void restart();
    void keyEvent( Direction );
};

#endif // GAME_H
