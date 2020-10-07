#define CONTENT "#define CONTENT %2$c%5$s%2$c%1$c#define _GNU_SOURCE%1$c#include <stdarg.h>%1$c#include <sys/types.h>%1$c#include <sys/stat.h>%1$c#include <fcntl.h>%1$c#include <unistd.h>%1$c#include <stdlib.h>%1$c#include <stdio.h>%1$c#include <string.h>%1$c%1$cvoid multiple_free(char *first, ...)%1$c{%1$c    char *str;%1$c    va_list ap;%1$c%1$c    str = first;%1$c%1$c    va_start(ap, first);%1$c%1$c    while (str != NULL)%1$c    {%1$c        free(str);%1$c        str = va_arg(ap, char*);%1$c    }%1$c    va_end(ap);%1$c}%1$c%1$cint main(void)%1$c{%1$c    int i = %4$d;%1$c    int fd;%1$c    char *file_name;%1$c    char *command;%1$c    extern const char *__progname;%1$c%1$c    if (i > 0)%1$c    {%1$c        i = strcmp(__progname, %2$cSully%2$c) == 0 ? i : i - 1;%1$c        if (asprintf(&file_name, %2$cSully_%3$cd.c%2$c, i) == -1)%1$c            return (1);%1$c        if ((fd = open(file_name, O_CREAT | O_RDWR, 0666)) < 0)%1$c        {%1$c            free(file_name);%1$c            return(1);%1$c        }%1$c        dprintf(fd, CONTENT, 10, 34, 37, i, CONTENT);%1$c        if (close(fd) != 0)%1$c            return (1);%1$c        if (asprintf(&command, %2$cgcc -Wall -Wextra -Werror -o %3$c.*s %3$cs%2$c, %1$c        ((int)strlen(file_name) - 2), file_name,file_name) == -1)%1$c        {%1$c            free(file_name);%1$c            return (1);%1$c        }%1$c        if (system(command) != 0)%1$c        {%1$c            multiple_free(command, file_name, NULL);%1$c            return (1);%1$c        }%1$c        free(command);%1$c        if (asprintf(&command, %2$c./%3$c.*s%2$c, ((int)strlen(file_name) - 2), %1$c        file_name) == -1)%1$c        {%1$c            free(file_name);%1$c            return (1);%1$c        }%1$c        if (system(command) != 0)%1$c        {%1$c            multiple_free(command, file_name, NULL);%1$c            return (1);%1$c        }%1$c        multiple_free(command, file_name, NULL);%1$c    }%1$c    return (0);%1$c}%1$c"
#define _GNU_SOURCE
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void multiple_free(char *first, ...)
{
    char *str;
    va_list ap;

    str = first;

    va_start(ap, first);

    while (str != NULL)
    {
        free(str);
        str = va_arg(ap, char*);
    }
    va_end(ap);
}

int main(void)
{
    int i = 5;
    int fd;
    char *file_name;
    char *command;
    extern const char *__progname;

    if (i > 0)
    {
        i = strcmp(__progname, "Sully") == 0 ? i : i - 1;
        if (asprintf(&file_name, "Sully_%d.c", i) == -1)
            return (1);
        if ((fd = open(file_name, O_CREAT | O_RDWR, 0666)) < 0)
        {
            free(file_name);
            return(1);
        }
        dprintf(fd, CONTENT, 10, 34, 37, i, CONTENT);
        if (close(fd) != 0)
            return (1);
        if (asprintf(&command, "gcc -Wall -Wextra -Werror -o %.*s %s", 
        ((int)strlen(file_name) - 2), file_name,file_name) == -1)
        {
            free(file_name);
            return (1);
        }
        if (system(command) != 0)
        {
            multiple_free(command, file_name, NULL);
            return (1);
        }
        free(command);
        if (asprintf(&command, "./%.*s", ((int)strlen(file_name) - 2), 
        file_name) == -1)
        {
            free(file_name);
            return (1);
        }
        if (system(command) != 0)
        {
            multiple_free(command, file_name, NULL);
            return (1);
        }
        multiple_free(command, file_name, NULL);
    }
    return (0);
}
