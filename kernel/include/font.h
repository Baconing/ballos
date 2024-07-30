//
// Created by bacon on 7/28/24.
//
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <liballoc.h>

#ifndef FONT_H
#define FONT_H

#define PSF1_FONT_MAGIC 0x0436

typedef struct {
    uint16_t magic; // Magic bytes for identification.
    uint8_t fontMode; // PSF font mode.
    uint8_t characterSize; // PSF character size.
} PSF1_Header;

#define PSF_FONT_MAGIC 0x864ab572

typedef struct {
    uint32_t magic;         /* magic bytes to identify PSF */
    uint32_t version;       /* zero */
    uint32_t headersize;    /* offset of bitmaps in file, 32 */
    uint32_t flags;         /* 0 if there's no unicode table */
    uint32_t numglyph;      /* number of glyphs */
    uint32_t bytesperglyph; /* size of each glyph */
    uint32_t height;        /* height in pixels */
    uint32_t width;         /* width in pixels */
} PSF_font;

#define PIXEL uint32_t   /* pixel pointer */

void psf_init();
void putchar(
    uint32_t *fb,
    int scanline,
    /* note that this is int, not char as it's a unicode character */
    unsigned short int c,
    /* cursor position on screen, in characters not in pixels */
    int cx, int cy,
    /* foreground and background colors, say 0xFFFFFF and 0x000000 */
    uint32_t fg, uint32_t bg);

#endif //FONT_H
