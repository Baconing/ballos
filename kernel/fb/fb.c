#include <video/fb.h>
#include <terminal.h>
#include <klibc/string.h>
#include <sys/hcf.h>
#include "terminal/flanterm.h"
#include "terminal/backends/fb.h"

static struct limine_framebuffer *framebuffer;
static struct flanterm_context *terminal_ctx;

static uint32_t default_bg = 0x0000FF;
static uint32_t default_fg = 0xFFFFFF;

__attribute__((used, section(".requests")))
static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

void blank_fb(uint32_t color) {
    volatile uint32_t *fb_ptr = framebuffer->address;
    for (size_t y = 0; y < framebuffer->height; y++) {
        for (size_t x = 0; x < framebuffer->width; x++) {
            fb_ptr[y * (framebuffer->pitch / 4) + x] = color;
        }
    }
}

void fb_init() {
    terminal_write("[VIDEO/FB] Initializing framebuffer...\n");
    if (framebuffer_request.response == NULL
     || framebuffer_request.response->framebuffer_count < 1) {
        terminal_write("ERROR (no usable framebuffer)\n");
    }

    framebuffer = framebuffer_request.response->framebuffers[0];
    blank_fb(default_bg);

    terminal_ctx = flanterm_fb_init(
        NULL,
        NULL,
        framebuffer->address, framebuffer->width, framebuffer->height, framebuffer->pitch,
        framebuffer->red_mask_size, framebuffer->red_mask_shift,
        framebuffer->green_mask_size, framebuffer->green_mask_shift,
        framebuffer->blue_mask_size, framebuffer->blue_mask_shift,
        NULL,
        NULL, NULL,
        &default_bg, &default_fg,
        &default_bg, &default_fg,
        NULL, 0, 0, 1,
        0, 0,
        0
    );
    terminal_write("OK\n");
}


void place_pixel_fb(size_t x, size_t y, uint32_t color) {
    volatile uint32_t *fb_ptr = framebuffer->address;
    fb_ptr[y * (framebuffer->pitch / 4) + x] = color;
}

void fb_write(const char *string) {
    flanterm_write(terminal_ctx, string, strlen(string));
}

void fb_write_char(char c) {
    flanterm_write(terminal_ctx, &c, 1);
}

bool fb_available() {
    return framebuffer != NULL;
}

struct limine_framebuffer *fb_info() {
    return framebuffer;
}