#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/*
    This program will print its own source when run.
*/

#define FILE_NAME "Grace_kid.c"
#define QUINE "#include <stdio.h>%c#include <fcntl.h>%c#include <unistd.h>%c%c/*%c    This program will print its own source when run.%c*/%c%c#define FILE_NAME %cGrace_kid.c%c%c#define QUINE %c%s%c%c#define GRACE() int main() {int fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, 0644); if (fd < 0) return -1; dprintf(fd, QUINE, 10, 10, 10, 10, 10, 10, 10, 10, 34, 34, 10, 34, QUINE, 34, 10, 10, 10, 10); close(fd); return 0;}%c%cGRACE()%c"
#define GRACE() int main() {int fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, 0644); if (fd < 0) return -1; dprintf(fd, QUINE, 10, 10, 10, 10, 10, 10, 10, 10, 34, 34, 10, 34, QUINE, 34, 10, 10, 10, 10); close(fd); return 0;}

GRACE()
