#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class SimpleGameApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void SimpleGameApp::setup()
{
}

void SimpleGameApp::mouseDown( MouseEvent event )
{
}

void SimpleGameApp::update()
{
}

void SimpleGameApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( SimpleGameApp, RendererGl )
