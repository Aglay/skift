#pragma once

#include <libsystem/Common.h>

typedef enum
{
    COM1 = 0x3f8,
    COM2 = 0x2F8,
    COM3 = 0x3E8,
    COM4 = 0x2E8,
} COMPort;

void com_wait_write(COMPort port);

void com_wait_read(COMPort port);

void com_putc(COMPort port, char c);

char com_getc(COMPort port);

size_t com_write(COMPort port, const void *buffer, size_t size);

void com_initialize(COMPort port);