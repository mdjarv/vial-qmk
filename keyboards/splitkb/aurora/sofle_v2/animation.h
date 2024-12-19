#ifndef ANIMATION_H
#define ANIMATION_H

#include "quantum.h"

typedef struct {
    const char* frames;          // Pointer to frame data stored in PROGMEM
    uint16_t frame_size;         // Size of each frame in bytes
    const uint16_t* delays;      // Pointer to array of delays for each frame
    uint8_t frame_count;         // Number of frames
    uint8_t idx;                 // Current frame index
    uint32_t timer;              // Current frame timer
} Animation;

void render_animation(Animation* anim) {
    if (timer_elapsed(anim->timer) >= anim->delays[anim->idx]) {
        anim->idx = (anim->idx + 1) % anim->frame_count;
        anim->timer = timer_read();
    }
    oled_write_raw_P(anim->frames + (anim->idx * anim->frame_size), anim->frame_size);
}

#endif // ANIMATION_H

