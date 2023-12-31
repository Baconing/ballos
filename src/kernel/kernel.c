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
#include <terminal.h>

#if defined(__linux__)
#error "You are not using a crosscompiler"
#endif
 
#if !defined(__i386__)
#error "This must be crosscompiled to i386"
#endif

void kernel_main(void)
{
	terminalInitialize();
 
	terminalWriteString("eyyy wsg wellcum to ballos\n");

    serialEnable(COM0);

    char* serialMessage = "serial test\n";
    for (size_t i = 0; i < strlen(serialMessage); i++) {
        serialSend(COM0, serialMessage[i]);
    }

    while (true) {
        if (!serialReceived(COM0)) continue;
        char recv = serialReceive(COM0);
        terminalPutChar(recv);
        serialSend(COM0, recv);
    }
}
