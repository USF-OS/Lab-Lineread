#ifndef _LINEREAD_H_
#define _LINEREAD_H_

#include <sys/types.h>

/**
 * Reads a line from a file descriptor and copies its contents into a buffer.
 *
 * @param fd File descriptor to read
 * @param buf Destination buffer to copy line contents
 * @param sz Maximum number of bytes read from the file descriptor
 *
 * @return number of bytes read, 0 if EOF is reached, -1 on error
 */
ssize_t lineread(int fd, char *buf, size_t sz);

/**
 * Reads a line from a file descriptor into an auto-sized + allocated buffer,
 * and returns a pointer to the buffer.
 *
 * @param fd File descriptor to read
 *
 * @return Pointer to the auto-sized + allocated buffer, NULL on failure.
 */
char *dynamic_lineread(int fd);

#endif
