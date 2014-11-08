#include "Tetromino.h"
#include "Painter.h"

Tetromino::Tetromino( Tetromino::Name name ) :
    m_name( name ),
    m_angle( 0 ),
    m_x( 0 ),
    m_y( 0 )
{

}

void Tetromino::draw( Painter &p ) const
{
    p.setColor( static_cast<Painter::Color>( m_name ) );
    for ( int y = 0; y < 4; ++y ) {
        for ( int x = 0; x < 4; ++x ) {
            if ( map( x, y ) ) {
                p.rect( ( x + m_x ) * 8 + 1,
                        ( y + m_y ) * 8 + 1,
                        ( x + m_x + 1 ) * 8 - 1,
                        ( y + m_y + 1 ) * 8 - 1 );
            }
        }
    }
}

void Tetromino::move(int dx, int dy)
{
    m_x += dx;
    m_y += dy;
}

void Tetromino::rotate( Tetromino::Direction d )
{
    m_angle = ( m_angle + d + 4 ) % 4;
}

bool Tetromino::map( int x, int y ) const
{
    static const char *SHAPES[] =
    {
        "  8 "  // I
        "  8 "
        "  8 "
        "  8 ",

        "  8 "  // J
        "  8 "
        "  8 "
        " 88 ",

        " 8  "  // L
        " 8  "
        " 8  "
        " 88 ",

        " 88 "  // O
        " 88 "
        "    "
        "    ",

        "  8 "  // S
        " 88 "
        " 8  "
        "    ",

        " 8  "  // Z
        " 88 "
        "  8 "
        "    ",

        "    "  // T
        " 888"
        "  8 "
        "    ",
    };

    static const struct
    {
        int x, y;
    } ROTATE[][16] = {
    {
        { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 },
        { 1, 0 }, { 1, 1 }, { 1, 2 }, { 1, 3 },
        { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 },
        { 3, 0 }, { 3, 1 }, { 3, 2 }, { 3, 3 },
    },
    {
        { 3, 0 }, { 2, 0 }, { 1, 0 }, { 0, 0 },
        { 3, 1 }, { 2, 1 }, { 1, 1 }, { 0, 1 },
        { 3, 2 }, { 2, 2 }, { 1, 2 }, { 0, 2 },
        { 3, 3 }, { 2, 3 }, { 1, 3 }, { 0, 3 },
    },
    {
        { 3, 3 }, { 3, 2 }, { 3, 1 }, { 3, 0 },
        { 2, 3 }, { 2, 2 }, { 2, 1 }, { 2, 0 },
        { 1, 3 }, { 1, 2 }, { 1, 1 }, { 1, 0 },
        { 0, 3 }, { 0, 2 }, { 0, 1 }, { 0, 0 },
    },
    {
        { 0, 3 }, { 1, 3 }, { 2, 3 }, { 3, 3 },
        { 0, 2 }, { 1, 2 }, { 2, 2 }, { 3, 2 },
        { 0, 1 }, { 1, 1 }, { 2, 1 }, { 3, 1 },
        { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 },
    }
    };

    return SHAPES[m_name][ROTATE[m_angle][y * 4 + x].y * 4 +
            ROTATE[m_angle][y * 4 + x].x] != ' ';
}
