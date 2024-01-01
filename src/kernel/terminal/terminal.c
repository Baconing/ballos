/*
 This file is a part of ballos (https://github.com/Baconing/ballos).

 Copyright (c) 2023 Brenden "Bacon" Freier <iam@baconing.tech>

 Permission to use, copy, modify, and/or distribute this software for any
 purpose with or without fee is hereby granted, provided that the above
 copyright notice and this permission notice appear in all copies.

 THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 PERFORMANCE OF THIS SOFTWARE.
 */

#include <types.h>
#include <vga.h>
#include <terminal.h>

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void terminalInitialize() {
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = VGAEntryColor(VGA_COLOR_LIGHT_GREEN, VGA_COLOR_BLACK);
    terminal_buffer = (uint16_t*) 0xB8000;
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = VGAEntry(' ', terminal_color);
        }
    }
}

void terminalSetColor(uint8_t color) {
    terminal_color = color;
}

void terminalPutEntryAt(char c, uint8_t color, size_t x, size_t y) {
    const size_t index = y * VGA_WIDTH + x;
    terminal_buffer[index] = VGAEntry(c, color);
}

void terminalPutChar(char c) {
    if (c == 0x0a && terminal_row++ != VGA_HEIGHT) {
        terminal_column = 0;
        return;
    } else if (c == 0x0a && terminal_row++ == VGA_HEIGHT) {
        terminal_row = 0;
        terminal_column = 0;
        return;
    }

    terminalPutEntryAt(c, terminal_color, terminal_column, terminal_row);

    if (terminal_column++ == VGA_WIDTH) {
        terminal_column = 0;
        if (terminal_row++ == VGA_HEIGHT) {
            terminal_row = 0;
        }
    }
}

void terminalWrite(const char* data, size_t size) {
    for (size_t i = 0; i < size; i++)
        terminalPutChar(data[i]);
}

void terminalWriteString(const char* data) {
    terminalWrite(data, strlen(data));
}