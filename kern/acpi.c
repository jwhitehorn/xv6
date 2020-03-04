#include "types.h"
#include "x86.h"


void acpi_halt() {
    outw(0x604, 0x2000); //shutdown (only in QEMU)
}
