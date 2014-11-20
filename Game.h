#ifndef GAME_H
#define GAME_H

#include "Well.h"
#include "Tetromino.h"

class Painter;
class Well;

class Game
{
public:
    enum Direction { UP, DOWN, LEFT, RIGHT };
    Game();
    void draw( Painter & );
    void tick();
    void restart();
    void keyEvent( Direction );

private:
    Well m_well;
    Tetromino m_tetromino;
};

#endif // GAME_H
