//
//  rednessfilter.cpp
//  SimpleGame
//
//  Created by Prasan Samtani on 4/26/14.
//
//

#include "colorfilters.h"

namespace MatrixOperations {
  
  const double colorDominationFactor = 1.2;
  
  bool RednessFilter::passesFilter(const Pixel &pixel) {
    return ((pixel.red > (pixel.blue * colorDominationFactor)) &&
            (pixel.red > (pixel.green * colorDominationFactor)));
  }
  
  bool BluenessFilter::passesFilter(const Pixel &pixel) {
    return ((pixel.blue > (pixel.red * colorDominationFactor)) &&
            (pixel.blue > (pixel.green * colorDominationFactor)));
  } 

  
  
}