#define CONTENT "#define CONTENT %2$c%3$s%2$c%1$c#include <stdio.h>%1$c%1$c/*%1$c    I'am another comment%1$c*/%1$c%1$cvoid print()%1$c{%1$c    printf(CONTENT, 10, 34, CONTENT);%1$c%1$c}%1$c%1$cint main(void)%1$c{%1$c    /*%1$c        I'am a comment%1$c    */%1$c    print();%1$c}%1$c"
#include <stdio.h>

/*
    I'am another comment
*/

void print()
{
    printf(CONTENT, 10, 34, CONTENT);

}

int main(void)
{
    /*
        I'am a comment
    */
    print();
}
