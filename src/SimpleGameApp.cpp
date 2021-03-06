#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "CinderOpenCV.h"
#include "cinder/qtime/QuickTime.h"
#include "cinder/Capture.h"

#include "matrixops.h"
#include "filter.h"
#include "colorfilters.h"

using namespace ci;
using namespace ci::app;
using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;

MatrixOperations::RednessFilter rednessFilter;
MatrixOperations::BluenessFilter bluenessFilter;

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
  Capture capture;
  cv::Mat webCamFrame;
  gl::Texture webCamTexture;
  uint32_t lastMeasuredFrame;
};

void SimpleGameApp::prepareSettings(Settings *settings)
{
  settings->setWindowSize(WIDTH, HEIGHT);
}

void SimpleGameApp::setup()
{
  lastMeasuredFrame = 0;
  Url url("http://www.durationator.com/img/background-green.jpg");
  backgroundImage = gl::Texture(loadImage(loadUrl(url)));
  playerImage = gl::Texture(loadImage(loadResource("leprechaun.gif")));
  playerMovie = qtime::MovieGl(loadResource("leprechaun.gif"));
  webCamTexture = backgroundImage;
  playerMovie.setLoop();
  playerMovie.play();
  capture = Capture( 640, 480 );
  capture.start();
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



int calculateRedness(const cv::Mat &matrix) {
  const int rows = matrix.rows;
  const int cols = matrix.cols;
  unsigned int sum = 0;
  
  const unsigned char *rowPointer;
  for (int i=0; i<rows; i++) {
    rowPointer = matrix.ptr<uchar>(i);
    for (int j=0; j<cols; j++) {
      auto redval = rowPointer[j+2];
      sum += (unsigned int) redval;
    }
  }
  return sum;
}

void SimpleGameApp::update()
{
  const auto elapsedFrame = getElapsedFrames();
  
  if (capture && capture.checkNewFrame()) {
    webCamFrame = toOcv(capture.getSurface());
    cv::Mat maskMat = MatrixOperations::applyPixelFilter(webCamFrame, bluenessFilter);
    cv::Mat newMat;
    webCamFrame.copyTo(newMat, maskMat);
    webCamTexture = gl::Texture(fromOcv(newMat));
    const int redness = calculateRedness(webCamFrame);
    if ((elapsedFrame - lastMeasuredFrame) > 60) {
      lastMeasuredFrame = elapsedFrame;
      console() << "Redness = " << redness / 1000;
    }
  }
  
}

void SimpleGameApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
  
  backgroundImage.enableAndBind();
  gl::draw(webCamTexture, getWindowBounds());
  
  const int x1 = playerPosition.x * 100;
  const int x2 = x1 + 100;
  const int y1 = HEIGHT - (playerPosition.y * 100) - 100;
  const int y2 = y1 + 100;
  gl::draw(playerMovie.getTexture(), Area(x1, y1, x2, y2));
  
}

CINDER_APP_NATIVE( SimpleGameApp, RendererGl )
