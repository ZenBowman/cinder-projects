//
//  matrixops.h
//  SimpleGame
//
//  Created by Prasan Samtani on 4/26/14.
//
//

#ifndef SimpleGame_matrixops_h
#define SimpleGame_matrixops_h

#include "filter.h"
#include "CinderOpenCV.h"

using namespace ci;
using namespace ci::app;
using namespace std;

typedef cv::Mat ImageMatrix;

namespace MatrixOperations {
  
  ImageMatrix applyPixelFilter(ImageMatrix &source, PixelFilter &pixelFilter);
  
}

#endif
