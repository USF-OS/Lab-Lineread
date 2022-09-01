#include <unistd.h>
#include <errno.h>

/**
 * Uses the read(2) system call to read files line by line.
 *
 * @param fd The file descriptor to read from
 * @param buf Buffer to store the string
 * @param sz Buffer size (maximum amount of data read)
 *
 * @return Number of bytes read, or -1 on failure.
 */
ssize_t lineread(int fd, char *buf, size_t sz)
{
    // TODO: use read() to implement a function that reads files line by line
    // (separated by a \n newline character)

    return 0;
}

/**
 * Uses the read(2) system call to read files line by line, with a
 * dynamically-allocated buffer.
 *
 * NOTE: This function allocates memory! The caller is responsible for clearning
 * up using free().
 *
 * @param fd The file descriptor to read from
 *
 * @return Pointer to the dynamically-allocated buffer, or NULL on failure.
 */

char *dynamic_lineread(int fd)
{
    // TODO: use your lineread() function to build a dynamic version that
    // automatically allocates and resizes a buffer for the line.
    //
    // Helpful functions: realloc()
    return NULL;
}
