#ifndef WELL_H
#define WELL_H

class Tetromino;
class Painter;

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
    void unite( const Tetromino & );

    // Удаление полностью заполненных строк
    int removeSolidLines();

private:
    bool m_map[20][10];
};

#endif // WELL_H
