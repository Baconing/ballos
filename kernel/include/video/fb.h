#ifndef FB_H
#define FB_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <limine.h>

void blank_fb(uint32_t color);
void fb_init();
void place_pixel_fb(size_t x, size_t y, uint32_t color);
void fb_write(const char *string);
void fb_write_char(char c);
bool fb_available();
struct limine_framebuffer *fb_info();

#endif
