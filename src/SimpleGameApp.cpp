#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;

class SimpleGameApp : public AppNative {
public:
  void prepareSettings(Settings *settings);
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
  
private:
  gl::Texture backgroundImage;
};

void SimpleGameApp::prepareSettings(Settings *settings)
{
  settings->setWindowSize(WIDTH, HEIGHT);
}

void SimpleGameApp::setup()
{
  Url url("http://www.durationator.com/img/background-green.jpg");
  backgroundImage = gl::Texture(loadImage(loadUrl(url)));
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
  
  backgroundImage.enableAndBind();
  gl::draw(backgroundImage, getWindowBounds());
  
}

CINDER_APP_NATIVE( SimpleGameApp, RendererGl )
