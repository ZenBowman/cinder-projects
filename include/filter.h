//
//  filter.h
//  SimpleGame
//
//  Created by Prasan Samtani on 4/26/14.
//
//

#ifndef SimpleGame_filter_h
#define SimpleGame_filter_h

namespace MatrixOperations {
  
  struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
  };
  
  // Defines a per-pixel predicate filter which can be used to create a mask
  class PixelFilter {
  public:
    virtual bool passesFilter(const Pixel &pixel) = 0;
  };
  
}
#endif
