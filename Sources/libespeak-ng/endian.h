/* Compatibility shim for <endian.h>
 *
 * "License": Public Domain
 * "Original": https://gist.github.com/panzi/6856583
 *
 * I, Mathias Panzenböck, place this file hereby into the public domain. Use it
 * at your own risk for whatever you like. In case there are jurisdictions that
 * don't support putting things in the public domain you can also consider it
 * to be "dual licensed" under the BSD, MIT and Apache licenses, if you want
 * to. This code is trivial anyway. Consider it an example on how to get the
 * endian conversion functions on different platforms.
 *
 * Modifications also in the Public Domain and dual licensed under BSD, MIT and
 * Apache licenses (using the terms outlined above):
 *
 * Copyright (C) 2016 Reece H. Dunn
 */

#pragma once

#include <libkern/OSByteOrder.h>

#define htobe16(x) OSSwapHostToBigInt16(x)
#define htole16(x) OSSwapHostToLittleInt16(x)
#define be16toh(x) OSSwapBigToHostInt16(x)
#define le16toh(x) OSSwapLittleToHostInt16(x)

#define htobe32(x) OSSwapHostToBigInt32(x)
#define htole32(x) OSSwapHostToLittleInt32(x)
#define be32toh(x) OSSwapBigToHostInt32(x)
#define le32toh(x) OSSwapLittleToHostInt32(x)

#define htobe64(x) OSSwapHostToBigInt64(x)
#define htole64(x) OSSwapHostToLittleInt64(x)
#define be64toh(x) OSSwapBigToHostInt64(x)
#define le64toh(x) OSSwapLittleToHostInt64(x)

#define __BYTE_ORDER    BYTE_ORDER
#define __BIG_ENDIAN    BIG_ENDIAN
#define __LITTLE_ENDIAN LITTLE_ENDIAN
#define __PDP_ENDIAN    PDP_ENDIAN
