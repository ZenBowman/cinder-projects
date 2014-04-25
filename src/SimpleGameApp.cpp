#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"

#include "cinder/qtime/QuickTime.h"

using namespace ci;
using namespace ci::app;
using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;

class SimpleGameApp : public AppNative {
public:
  void prepareSettings(Settings *settings);
	void setup();
  void keyDown(KeyEvent keyEvent);
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
  
private:
  qtime::MovieGl playerMovie;
  gl::Texture backgroundImage;
  gl::Texture playerImage;
  Vec2i playerPosition;
};

void SimpleGameApp::prepareSettings(Settings *settings)
{
  settings->setWindowSize(WIDTH, HEIGHT);
}

void SimpleGameApp::setup()
{
  Url url("http://www.durationator.com/img/background-green.jpg");
  backgroundImage = gl::Texture(loadImage(loadUrl(url)));
  playerImage = gl::Texture(loadImage(loadResource("leprechaun.gif")));
  playerMovie = qtime::MovieGl(loadResource("leprechaun.gif"));
  playerMovie.setLoop();
  playerMovie.play();
}

void SimpleGameApp::keyDown(cinder::app::KeyEvent keyEvent)
{
  const int keyCode = keyEvent.getCode();
  if (keyCode == KeyEvent::KEY_RIGHT) {
    playerPosition.x += 1;
  } else if (keyCode == KeyEvent::KEY_LEFT) {
    playerPosition.x -= 1;
  }
}

void SimpleGameApp::mouseDown( MouseEvent event )
{
}

void SimpleGameApp::update()
{
  const auto elapsedFrame = getElapsedFrames();
}

void SimpleGameApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
  
  backgroundImage.enableAndBind();
  gl::draw(backgroundImage, getWindowBounds());
  
  const int x1 = playerPosition.x * 100;
  const int x2 = x1 + 100;
  const int y1 = HEIGHT - (playerPosition.y * 100) - 100;
  const int y2 = y1 + 100;
  gl::draw(playerMovie.getTexture(), Area(x1, y1, x2, y2));
  
}

CINDER_APP_NATIVE( SimpleGameApp, RendererGl )
