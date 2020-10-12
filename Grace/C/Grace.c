#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define CONTENT "#include <stdio.h>%1$c#include <sys/types.h>%1$c#include <sys/stat.h>%1$c#include <fcntl.h>%1$c#include <unistd.h>%1$c#define CONTENT %2$c%3$s%2$c%1$c#define CODE()({int fd;if ((fd = open(%2$cGrace_kid.c%2$c, O_CREAT | O_RDWR | O_TRUNC, 0666)) >= 0){dprintf(fd, CONTENT, 10, 34, CONTENT);}else dprintf(2, %2$cGrace: Error: Can not open file Grace_kid.c%%1$c%2$c, 10);})%1$c#define START int main() {CODE();}%1$c%1$c/*%1$c    This is a comment%1$c*/%1$cSTART%1$c"
#define CODE()({int fd;if ((fd = open("Grace_kid.c", O_CREAT | O_RDWR | O_TRUNC, 0666)) >= 0){dprintf(fd, CONTENT, 10, 34, CONTENT);}else dprintf(2, "Grace: Error: Can not open file Grace_kid.c%1$c", 10);})
#define START int main() {CODE();}

/*
    This is a comment
*/
START
