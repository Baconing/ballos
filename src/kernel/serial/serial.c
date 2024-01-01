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

#include <serial.h>
#include <system.h>

void serialSend(int device, char data) {
    outb(device, data);
}

bool serialTransmitEmpty(int device) {
    return (inb(device + 5) & 0x20) != 0;
}

char serialReceive(int device) {
    return inb(device);
}

bool serialReceived(int device) {
    return (inb(device + 5) & 1) != 0;
}

void serialEnable(int device) {
    outb(device + 1, 0x00);
    outb(device + 3, 0x80);
    outb(device + 0, 0x03);
    outb(device + 1, 0x00);
    outb(device + 3, 0x03);
    outb(device + 2, 0xC7);
    outb(device + 4, 0x0B);
    outb(device + 4, 0x1E);
    outb(device + 0, 0xAE);

    if (inb(device) != 0xAE) {
        panic("Serial port failed to initialize!");
    }

    outb(device + 4, 0x0F);
}

void serialDisable(int device) {
    outb(device + 4, 0x00);
}
