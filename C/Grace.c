#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/*
    comment
*/

#define FILE_NAME "Grace_kid.c"
#define QUINE "#include <stdio.h>%1$c#include <fcntl.h>%1$c#include <unistd.h>%1$c%1$c/*%1$c    comment%1$c*/%1$c%1$c#define FILE_NAME %2$cGrace_kid.c%2$c%1$c#define QUINE %2$c%3$s%2$c%1$c#define GRACE() int main() {int fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, 0644); if (fd < 0) return -1; dprintf(fd, QUINE, 10, 34, QUINE); close(fd); return 0;}%1$c%1$cGRACE()%1$c"
#define GRACE() int main() {int fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, 0644); if (fd < 0) return -1; dprintf(fd, QUINE, 10, 34, QUINE); close(fd); return 0;}

GRACE()
