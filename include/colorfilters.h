//
//  rednessfilter.h
//  SimpleGame
//
//  Created by Prasan Samtani on 4/26/14.
//
//

#ifndef SimpleGame_rednessfilter_h
#define SimpleGame_rednessfilter_h

#include "filter.h"

namespace MatrixOperations {
  class RednessFilter : public PixelFilter {
  public:
    bool passesFilter(const Pixel &pixel) override;
  };
  
  class BluenessFilter : public PixelFilter {
  public:
    bool passesFilter(const Pixel &pixel) override;
  };
}

#endif
