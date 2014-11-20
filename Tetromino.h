#ifndef TETROMINO_H
#define TETROMINO_H

class Painter;

class Tetromino
{
public:
    enum Direction { LEFT = -1, RIGHT = 1 };
    enum Name { I, J, L, O, S, Z, T };

    // Создание тетромины по имени
    Tetromino( Name );

    // Рисование тетромины на рисовальщике Painter
    void draw( Painter & ) const;

    // Перемещение тетромины на dx, dy
    void move( int dx, int dy );

    // Поворот тетромины по часовой стрелке или
    // против часовой стрелке
    void rotate( Direction );

    bool map( int x, int y ) const;

    int x() const { return m_x; }
    int y() const { return m_y; }

private:
    Name m_name;
    int m_angle;
    int m_x;
    int m_y;
};

#endif // TETROMINO_H
