//
//  player.h
//  SimpleGame
//
//  Created by Prasan Samtani on 4/25/14.
//
//

#ifndef __SimpleGame__player__
#define __SimpleGame__player__

#include <iostream>
#include "cinder/gl/Texture.h"

enum PlayerState {
  IDLE = 0,
  WALKING,
  JUMPING
};

class Player {
public:
  cinder::gl::Texture *currentTexture;
private:
  PlayerState state;
};

#endif /* defined(__SimpleGame__player__) */
