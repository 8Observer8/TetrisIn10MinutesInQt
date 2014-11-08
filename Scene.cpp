#include "Scene.h"
#include "Painter.h"
#include "Tetromino.h"

Scene::Scene( QWidget *parent ) :
    QGLWidget( parent )
{
}

void Scene::initializeGL()
{
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
}

void Scene::paintGL()
{
    // Clear the window with current clearing color
    glClear( GL_COLOR_BUFFER_BIT );

    // Set current drawing color
    //		   R	 G	   B
    glColor3f( 0.0f, 0.0f, 0.0f );

    Painter p;
    Tetromino t( Tetromino::L );
    t.draw( p );
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
