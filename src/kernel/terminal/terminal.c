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
#include <terminal.h>
#include <serial.h>
#include <string.h>
#include <vga.h>

size_t terminalRow;
size_t terminalColumn;
uint16_t terminalColor;
uint16_t* terminalBuffer;

void terminalInitialize() {
    terminalRow = 0;
    terminalColumn = 0;
    terminalColor = vgaEntryColor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    terminalBuffer = (uint16_t*) 0xB8000;
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminalBuffer[index] = vgaEntry(' ', terminalColor);
        }
    }

    serialEnable(COM0);
}

void terminalSetColor(uint8_t color) {
    terminalColor = color;
}

void terminalPutEntryAt(char c, uint8_t color, size_t x, size_t y) {
    const size_t index = y * VGA_WIDTH + x;
    terminalBuffer[index] = vgaEntry(c, color);
}

void terminalPutChar(char c) {
    if (c == 0x0a && terminalRow++ != VGA_HEIGHT) {
        terminalColumn = 0;
        return;
    } else if (c == 0x0a && terminalRow++ >= VGA_HEIGHT) {
        terminalRow = 0;
        terminalColumn = 0;
        return;
    }

    terminalPutEntryAt(c, terminalColor, terminalColumn, terminalRow);
    serialSend(COM0, c);

    if (terminalColumn++ == VGA_WIDTH) {
        terminalColumn = 0;
        if (terminalRow++ >= VGA_HEIGHT) {
            terminalRow = 0;
        }
    }
}

void terminalWrite(const char* data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        terminalPutChar(data[i]);
    }
}

void terminalWriteString(const char* data) {
    terminalWrite(data, strlen(data));
}