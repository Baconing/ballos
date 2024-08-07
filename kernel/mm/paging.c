#include <mm/paging.h>
#include <sys/hcf.h>
#include <terminal.h>
#include <limine.h>
#include <stddef.h>

__attribute__((used, section(".requests")))
static volatile struct limine_paging_mode_request paging_mode_request = {
    .id = LIMINE_PAGING_MODE_REQUEST,
    .mode = LIMINE_PAGING_MODE_X86_64_4LVL,
    .revision = 0
};

void paging_init() {
    terminal_write("[MM/PAGING] Initializing paging...");

    if (paging_mode_request.response == NULL) {
        terminal_write("ERROR (paging mode request failed)\n");
        hcf();
    }

    if (paging_mode_request.response->mode != LIMINE_PAGING_MODE_X86_64_4LVL) {
        terminal_write("ERROR (paging mode (x86-64 level 4) not supported)\n");
        hcf();
    }

    terminal_write("OK\n");
}