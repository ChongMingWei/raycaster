#pragma once

#include "game.h"
#include "raycaster.h"

class Renderer
{
    RayCaster *_rc;

    inline static uint32_t GetARGB(uint8_t brightness, short type)
    {
        switch (type) {
        case 0:  // sky
            return (brightness << 16) + (brightness << 8) + 255;
        case 1:  // wall
            return (brightness << 16) + brightness;
        case 2:  // floor
            return (brightness << 16) + (255 << 8) + brightness;
        default:
            return (brightness << 16) + (brightness << 8) + brightness;
        }
    }

public:
    void TraceFrame(Game *g, uint32_t *frameBuffer);
    Renderer(RayCaster *rc) { _rc = rc; };
    ~Renderer(){};
};
