/* yubikey.h --- Prototypes for low-level Yubikey OTP functions.
 *
 * Written by Simon Josefsson <simon@josefsson.org>.
 * Copyright (c) 2006, 2007, 2008, 2009 Yubico AB
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *    * Redistributions in binary form must reproduce the above
 *      copyright notice, this list of conditions and the following
 *      disclaimer in the documentation and/or other materials provided
 *      with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef YUBIKEY_H
#define YUBIKEY_H

#include <stdint.h>
#include <string.h>

#define YUBIKEY_BLOCK_SIZE 16
#define YUBIKEY_KEY_SIZE 16
#define YUBIKEY_UID_SIZE 6

#define	YUBIKEY_CRC_OK_RESIDUE 0xf0b8

#define yubikey_crc_ok_p(tok) (yubikey_crc16 ((tok), YUBIKEY_BLOCK_SIZE) == YUBIKEY_CRC_OK_RESIDUE)

/*
 * Low-level functions; ModHex.
 */

#define YUBIKEY_MODHEX_MAP "cbdefghijklnrtuv"

/* ModHex encode input string SRC of length SRCSIZE and put the zero
   terminated output string in DST.  The size of the output string DST
   must be at least 2*SRCSIZE+1.  The output string is always
   2*SRCSIZE large plus the terminating zero.  */
extern void yubikey_modhex_encode(char *dst, const char *src, size_t srcsize);

/* ModHex decode input string SRC of length DSTSIZE/2 into output
   string DST.  The output string DST is always DSTSIZE/2 large plus
   the terminating zero.  */
extern void yubikey_modhex_decode(char *dst, const char *src, size_t dstsize);

/* Low-level functions; AES. */

/* AES-decrypt one 16-byte block STATE using the 128-bit KEY, leaving
   the decrypted output in the STATE buffer. */
void yubikey_aes_decrypt(uint8_t *state, const uint8_t *key);

/*
 * Low-level functions; CRC.
 */
uint16_t yubikey_crc16 (const uint8_t *buf, size_t buf_size);

#endif