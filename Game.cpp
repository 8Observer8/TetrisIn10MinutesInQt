#include <cstdlib>
#include "Game.h"
#include "Painter.h"

Game::Game() :
    m_tetromino( static_cast<Tetromino::Name>( std::rand() % 7 ) )
{

}

void Game::draw( Painter &p )
{
    m_well.draw( p );
    m_tetromino.draw( p );
}

void Game::tick()
{
    Tetromino t = m_tetromino;
    t.move( 0, 1 );
    if ( !m_well.isCollision( t ) ) {
        m_tetromino = t;
    } else {
        m_well.unite( m_tetromino );
        m_well.removeSolidLines();
        m_tetromino = Tetromino( static_cast<Tetromino::Name>( std::rand() % 7 ) );
        if ( m_well.isCollision( m_tetromino ) ) {
            restart();
        }
    }
}

void Game::restart()
{
    m_well = Well();
}

void Game::keyEvent( Game::Direction d )
{
    Tetromino t = m_tetromino;
    switch ( d ) {
        case UP:
            t.rotate( Tetromino::LEFT );
            break;
        case DOWN:
            t.move( 0, 1 );
            break;
        case LEFT:
            t.move( -1, 0 );
            break;
        case RIGHT:
            t.move( 1, 0 );
            break;
    }
    if ( !m_well.isCollision( t ) ) {
        m_tetromino = t;
    }
}
