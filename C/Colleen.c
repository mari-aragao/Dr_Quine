#include <stdio.h>

/*
    This program will print its own source when run.
*/

void another_function() {}

int main() {
/*
    This program will print its own source when run.
*/
    char *quine = "#include <stdio.h>%c%c/*%c    This program will print its own source when run.%c*/%c%cvoid another_function() {}%c%cint main() {%c/*%c    This program will print its own source when run.%c*/%c    char *quine = %c%s%c;%c    printf(quine, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, quine, 34, 10, 10, 10, 10, 10);%c    another_function();%c    return 0;%c}%c";
    printf(quine, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, quine, 34, 10, 10, 10, 10, 10);
    another_function();
    return 0;
}
