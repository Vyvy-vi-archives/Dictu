#ifndef dictu_c_h
#define dictu_c_h

#ifndef _GNU_SOURCE
#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200809L
#endif
#if (_POSIX_C_SOURCE >= 200112L)
#define POSIX_STRERROR
#endif
#endif


// error codes taken from https://github.com/torvalds/linux/blob/master/include/uapi/asm-generic/errno.h
#ifdef __FreeBSD__
#define EHWPOISON 133
#define ENOSTR 60
#define ENODATA 61
#define ETIME 62
#define ENOSR 63
#endif

#include <string.h>
#include <errno.h>

#ifdef __APPLE__
#define LAST_ERROR 106
#elif defined(_WIN32)
#define LAST_ERROR EWOULDBLOCK
#else
#define LAST_ERROR EHWPOISON
#endif

#include "optionals.h"
#include "../vm.h"
#include "../memory.h"

void createCModule(VM *vm);

#define MAX_ERROR_LEN 256
Value strerrorGeneric(VM *, int);
Value strerrorNative(VM *, int, Value *);

#endif //dictu_c_h
