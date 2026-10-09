#ifndef DISASSEMBLER_H
#define DISASSEMBLER_H

#include <stddef.h>

void hex_to_bytes(const char *hex_str, unsigned char *out_bytes, size_t *out_len);
void tuxexec_disassembler(void);

#endif
