#ifndef FRAMEBUFFERS_H
#define FRAMEBUFFERS_H

#include <PR/ultratypes.h>

#include "config.h"

extern u16 gFrameBuffers[3][SCREEN_WIDTH * SCREEN_HEIGHT];
#define gFrameBuffer0 gFrameBuffers[0]
#define gFrameBuffer1 gFrameBuffers[1]
#define gFrameBuffer2 gFrameBuffers[2]

#endif // FRAMEBUFFERS_H
