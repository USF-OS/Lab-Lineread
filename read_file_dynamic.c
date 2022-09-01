#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include "lineread.h"

/**
 * This simple main() implementation demonstrates how dynamic_lineread() should
 * work.
 */
int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: read_file filename\n");
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    unsigned long counter = 0;

    while (true) {
        char *line = dynamic_lineread(fd);
        if (line == NULL) {
            break;
        }
        printf("Read %lu | %s\n", counter++, line);
    }

    return 0;
}
