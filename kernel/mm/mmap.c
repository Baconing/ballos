#include <mm/mmap.h>
#include <limine.h>
#include <terminal.h>

__attribute__((used, section(".requests")))
static volatile struct limine_memmap_request memmap_request = {
    .id = LIMINE_MEMMAP_REQUEST,
    .revision = 0
};

static struct mmap_entry mmap[256];
static size_t mmap_entries = 0;

void mmap_add_entry(uint64_t base, uint64_t length, uint64_t type) {
    if (type != LIMINE_MEMMAP_USABLE) {
        return;
    }

    if (mmap_entries >= 256) {
        return;
    }

    terminal_write("    [MM/MMAP] Adding entry: base=0x");
    terminal_write_hex(base);
    terminal_write(", length=");
    terminal_write_dec(length);
    terminal_write("\n");

    struct mmap_entry *entry = &mmap[mmap_entries];
    entry->base = base;
    entry->length = length;
    mmap_entries++;
}

uint64_t mmap_total_mem() {
    uint64_t total = 0;

    for (size_t i = 0; i < mmap_entries; i++) {
        total += mmap[i].length;
    }

    return total;
}

void mmap_init() {
    terminal_write("[MM/MMAP] Initializing memory map...");

    if (memmap_request.response == NULL) {
        terminal_write("ERROR (memory map request failed)\n");
        return;
    }

    terminal_write("\n");

    for (size_t i = 0; i < memmap_request.response->entry_count; i++) {
        struct limine_memmap_entry *entry = memmap_request.response->entries[i];
        mmap_add_entry(entry->base, entry->length, entry->type);
    }

    terminal_write("OK (total memory: ");
    terminal_write_dec(mmap_total_mem());
    terminal_write(" bytes)\n");
}

struct mmap_entry *mmap_get_entries() {
    return mmap;
}

size_t mmap_get_entry_count() {
    return mmap_entries;
}
