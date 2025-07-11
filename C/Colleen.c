#include <stdio.h>

/*
    comment outside the program
*/

void another_function() {}

int main() {
/*
    comment inside the main
*/
    char *quine = "#include <stdio.h>%1$c%1$c/*%1$c    comment outside the program%1$c*/%1$c%1$cvoid another_function() {}%1$c%1$cint main() {%1$c/*%1$c    comment inside the main%1$c*/%1$c    char *quine = %2$c%3$s%2$c;%1$c    printf(quine, 10, 34, quine);%1$c    another_function();%1$c    return 0;%1$c}";
    printf(quine, 10, 34, quine);
    another_function();
    return 0;
}