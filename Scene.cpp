#include "Scene.h"
#include "Painter.h"

Scene::Scene( QWidget *parent ) :
    QGLWidget( parent )
{
    this->setFocusPolicy( Qt::StrongFocus );
    connect( &m_timer, SIGNAL( timeout() ),
             this, SLOT( slotUpdate() ) );
    m_timer.start( 1000 );
}

void Scene::slotUpdate()
{
    m_game.tick();
    updateGL();
}

void Scene::initializeGL()
{
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
}

void Scene::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT );

    Painter p;
    m_game.draw( p );
}

void Scene::resizeGL( int w, int h )
{
    // Set Viewport to window dimensions
    glViewport( 0, 0, w, h );

    // Reset coordinate system
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    // Establish clipping volume (left, right, bottom, top, near, far)
    glOrtho( 0, 10 * 8, 20 * 8, 0, -1.0, 1.0);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

void Scene::keyPressEvent( QKeyEvent *event )
{
    switch( event->key() ) {
        case Qt::Key_Left:
            m_game.keyEvent( Game::LEFT );
            break;
        case Qt::Key_Right:
            m_game.keyEvent( Game::RIGHT );
            break;
        case Qt::Key_Up:
            m_game.keyEvent( Game::UP );
            break;
        case Qt::Key_Down:
            m_game.keyEvent( Game::DOWN );
            break;
    }

    updateGL();
}
