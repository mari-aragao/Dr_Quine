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

    if (i < 0) return 0;

    snprintf(filename, sizeof(filename), "Sully_%d.c", i);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("Error in open");
        return -1;
    }
    
    char *code = "#include <stdio.h>%c#include <fcntl.h>%c#include <unistd.h>%c#include <stdlib.h>%c%cint main() {%c    int i = %d;%c    int fd;%c    char filename[64];%c    char compile_cmd[128];%c    char execute_cmd[64];%c%c    if (i < 0) return 0;%c%c    snprintf(filename, sizeof(filename), %cSully_%%d.c%c, i);%c    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);%c    if (fd < 0)%c    {%c        perror(%cError in open%c);%c        return -1;%c    }%c    %c    char *code = %c%s%c;%c    dprintf(fd, code, 10, 10, 10, 10, 10, 10, i - 1, 10, 10, 10, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 34, code, 34, 10, 10, 10, 10, 10, 10, 34, 34, 10, 10, 34, 34, 10, 10, 10, 10, 34, 34, 10, 10, 34, 34, 10, 10, 10, 10, 10);%c%c    close(fd);%c    if (fd < 0) return -1;%c%c    snprintf(compile_cmd, sizeof(compile_cmd), %cgcc -Wall -Wextra %%s -o Sully_%%d%c, filename, i);%c    if (system(compile_cmd) != 0) {%c        fprintf(stderr, %cCompilation failed%c);%c        return -1;%c    }%c%c    snprintf(execute_cmd, sizeof(execute_cmd), %c./Sully_%%d%c, i);%c    if (system(execute_cmd) != 0) {%c        fprintf(stderr, %cExecution failed%c);%c        return -1;%c    }%c%c    return 0;%c}";
    dprintf(fd, code, 10, 10, 10, 10, 10, 10, i - 1, 10, 10, 10, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 34, code, 34, 10, 10, 10, 10, 10, 10, 34, 34, 10, 10, 34, 34, 10, 10, 10, 10, 34, 34, 10, 10, 34, 34, 10, 10, 10, 10, 10);

    close(fd);
    if (fd < 0) return -1;

    snprintf(compile_cmd, sizeof(compile_cmd), "gcc -Wall -Wextra %s -o Sully_%d", filename, i);
    if (system(compile_cmd) != 0) {
        fprintf(stderr, "Compilation failed");
        return -1;
    }

    snprintf(execute_cmd, sizeof(execute_cmd), "./Sully_%d", i);
    if (system(execute_cmd) != 0) {
        fprintf(stderr, "Execution failed");
        return -1;
    }

    return 0;
}