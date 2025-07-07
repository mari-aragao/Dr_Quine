#include <stdio.h>

//comment outside the program

void another_function() {}

int main() {
    //comment in the main
    char *quine = "#include <stdio.h>%c%c//comment outside the program%c%cvoid another_function() {}%c%cint main() {%c    //comment in the main%c    char *quine = %c%s%c;%c    printf(quine, 10, 10, 10, 10, 10, 10, 10, 10, 34, quine, 34, 10, 10, 10, 10, 10);%c    another_function();%c    return 0;%c}%c";
    printf(quine, 10, 10, 10, 10, 10, 10, 10, 10, 34, quine, 34, 10, 10, 10, 10, 10);
    another_function();
    return 0;
}
