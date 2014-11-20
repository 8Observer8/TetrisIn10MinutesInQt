#include "Well.h"
#include "Tetromino.h"
#include "Painter.h"

Well::Well()
{
    for ( int y = 0; y < 20; ++y ) {
        for ( int x = 0; x < 20; ++x ) {
            m_map[y][x] = false;
        }
    }
}

void Well::draw( Painter & p ) const
{
    p.setColor( Painter::WHITE );
    for( int y = 0; y < 20; ++y ) {
        for( int x = 0; x < 10; ++x ) {
            if ( m_map[y][x] ) {
                p.rect( x * 8 + 1, y * 8 + 1,
                        ( x + 1 ) * 8 - 1, ( y + 1 ) * 8 - 1 );
            } else {
                p.rect( x * 8 + 3, y * 8 + 3,
                        ( x + 1 ) * 8 - 3, ( y + 1 ) * 8 - 4 );
            }
        }
    }
}

bool Well::isCollision(const Tetromino &t) const
{
    for(  int y = 0; y < 4; ++y ) {
        for(  int x = 0; x < 4; ++x ) {
            if ( t.map( x, y ) ) {
                int wx = x + t.x();
                int wy = y + t.y();
                if ( wx < 0 || wx >= 10 || wy < 0 || wy >= 20 ) {
                    return true;
                }
                if ( m_map[wy][wx] ) {
                    return true;
                }
            }
        }
    }
    return false;
}

int Well::removeSolidLines()
{
    int res = 0;
    for( int y = 0; y < 20; ++y ) {
        bool solid = true;
        for ( int x = 0; x < 10; ++x ) {
            if ( !m_map[y][x] ) {
                solid = false;
                break;
            }
        }
        if ( solid ) {
            ++res;
            for ( int yy = y - 1; yy >= 0; --yy ) {
                for( int x = 0; x < 10; ++x ) {
                    m_map[yy + 1][x] = m_map[yy][x];
                }
            }
        }
        for ( int x = 0; x < 10; ++x ) {
            m_map[0][x] = false;
        }
    }

    return res;
}

void Well::unite( const Tetromino &t )
{
    for(  int y = 0; y < 4; ++y ) {
        for(  int x = 0; x < 4; ++x ) {
            int wx = x + t.x();
            int wy = y + t.y();
            if ( wx >= 0 && wx < 10 && wy > 0 && wy < 20 ) {
                m_map[wy][wx] = m_map[wy][wx] || t.map( x, y );
            }
        }
    }
}
