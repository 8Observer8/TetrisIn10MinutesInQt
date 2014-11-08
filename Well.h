#ifndef WELL_H
#define WELL_H

#include "Tetromino.h"

class Well
{
public:
    Well();
    // Рисуем колодец на рисовальщике Painter
    void draw( Painter & ) const;

    // Проверка на столкновения тетрамины и
    // блоками в колодце
    bool isCollision( const Tetromino & ) const;

    // Перенос тетромины в колодец
    int unite( const Tetromino & );
};

#endif // WELL_H
