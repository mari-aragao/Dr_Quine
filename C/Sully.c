#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int i = 5;
    int fd;
    char filename[64];
    char compile_cmd[128];
    char execute_cmd[64];

    if (i <= -1) return 0;

    if (!access("Sully_5.c", R_OK)) i--;

    snprintf(filename, sizeof(filename), "Sully_%d.c", i);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("Error in open");
        return -1;
    }

    char *code = "#include <stdio.h>%1$c#include <fcntl.h>%1$c#include <unistd.h>%1$c#include <stdlib.h>%1$c%1$cint main() {%1$c    int i = %4$d;%1$c    int fd;%1$c    char filename[64];%1$c    char compile_cmd[128];%1$c    char execute_cmd[64];%1$c%1$c    if (i <= -1) return 0;%1$c%1$c    if (!access(%2$cSully_5.c%2$c, R_OK)) i--;%1$c%1$c    snprintf(filename, sizeof(filename), %2$cSully_%%d.c%2$c, i);%1$c    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);%1$c    if (fd < 0)%1$c    {%1$c        perror(%2$cError in open%2$c);%1$c        return -1;%1$c    }%1$c%1$c    char *code = %2$c%3$s%2$c;%1$c    dprintf(fd, code, 10, 34, code, i);%1$c%1$c    close(fd);%1$c    if (fd < 0) return -1;%1$c%1$c    snprintf(compile_cmd, sizeof(compile_cmd), %2$cgcc -Wall -Wextra %%s -o Sully_%%d%2$c, filename, i);%1$c    if (system(compile_cmd) != 0) {%1$c        fprintf(stderr, %2$cCompilation failed%2$c);%1$c        return -1;%1$c    }%1$c%1$c    if (i <= 0) return 0;%1$c%1$c    snprintf(execute_cmd, sizeof(execute_cmd), %2$c./Sully_%%d%2$c, i);%1$c    if (system(execute_cmd) != 0) {%1$c        fprintf(stderr, %2$cExecution failed%2$c);%1$c        return -1;%1$c    }%1$c%1$c    return 0;%1$c}";
    dprintf(fd, code, 10, 34, code, i);

    close(fd);
    if (fd < 0) return -1;

    snprintf(compile_cmd, sizeof(compile_cmd), "gcc -Wall -Wextra %s -o Sully_%d", filename, i);
    if (system(compile_cmd) != 0) {
        fprintf(stderr, "Compilation failed");
        return -1;
    }

    if (i <= 0) return 0;

    snprintf(execute_cmd, sizeof(execute_cmd), "./Sully_%d", i);
    if (system(execute_cmd) != 0) {
        fprintf(stderr, "Execution failed");
        return -1;
    }

    return 0;
}