int i = 100;
#define CONTENT "#define _GNU_SOURCE\n#include <sys/types.h>\n#include <sys/stat.h>\n#include <fcntl.h>\n#include <unistd.h>\n#include <stdlib.h>\n#include <stdio.h>\n#include <string.h>\n\nvoid print_content_to_file(int fd)\n{\n    int j;\n\n    j = 0;\n    dprintf(fd, \"int i = %d;\\n#define CONTENT \\\"\", i - 1);\n    while (CONTENT[j])\n    {\n        if (CONTENT[j] == 10)\n            write(fd, \"\\\\n\", 2);\n        else if (CONTENT[j] == 92)\n            write(fd, \"\\\\\\\\\", 2);\n        else if (CONTENT[j] == 34)\n            write(fd, \"\\\\\\\"\", 2);\n        else\n            write(fd, &CONTENT[j], 1);\n        j++;\n    }\n    write(fd, \"\\\"\\n\", 2);\n    j = 0;\n    while (CONTENT[j])\n    {\n        write(fd, &CONTENT[j], 1);\n        j++;\n    }\n}\n\nint main(void)\n{\n    int fd;\n    char *file_name;\n    char *command;\n\n    if (i > 0)\n    {\n        if (asprintf(&file_name, \"Sully_%d.c\", i - 1) == -1)\n            return (1);\n        if ((fd = open(file_name, O_CREAT | O_RDWR, 0666)) < 0)\n        {\n            free(file_name);\n            return(1);\n        }\n        print_content_to_file(fd);\n        if (close(fd) != 0)\n            return (1);\n        if (asprintf(&command, \"gcc -Wall -Wextra -Werror -o %.*s %s\", ((int)strlen(file_name) - 2), file_name,file_name) == -1)\n        {\n            free(file_name);\n            return (1);\n        }\n        if (system(command) != 0)\n        {\n            free(command);\n            free(file_name);\n            return (1);\n        }\n        free(command);\n        if (asprintf(&command, \"./%.*s\", ((int)strlen(file_name) - 2), file_name) == -1)\n        {\n            free(file_name);\n            return (1);\n        }\n        if (system(command) != 0)\n        {\n            free(command);\n            free(file_name);\n            return (1);\n        }\n        free(command);\n        free(file_name);\n    }\n    return (0);\n}\n"
#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_content_to_file(int fd)
{
    int j;

    j = 0;
    dprintf(fd, "int i = %d;\n#define CONTENT \"", i - 1);
    while (CONTENT[j])
    {
        if (CONTENT[j] == 10)
            write(fd, "\\n", 2);
        else if (CONTENT[j] == 92)
            write(fd, "\\\\", 2);
        else if (CONTENT[j] == 34)
            write(fd, "\\\"", 2);
        else
            write(fd, &CONTENT[j], 1);
        j++;
    }
    write(fd, "\"\n", 2);
    j = 0;
    while (CONTENT[j])
    {
        write(fd, &CONTENT[j], 1);
        j++;
    }
}

int main(void)
{
    int fd;
    char *file_name;
    char *command;

    if (i > 0)
    {
        if (asprintf(&file_name, "Sully_%d.c", i - 1) == -1)
            return (1);
        if ((fd = open(file_name, O_CREAT | O_RDWR, 0666)) < 0)
        {
            free(file_name);
            return(1);
        }
        print_content_to_file(fd);
        if (close(fd) != 0)
            return (1);
        if (asprintf(&command, "gcc -Wall -Wextra -Werror -o %.*s %s", ((int)strlen(file_name) - 2), file_name,file_name) == -1)
        {
            free(file_name);
            return (1);
        }
        if (system(command) != 0)
        {
            free(command);
            free(file_name);
            return (1);
        }
        free(command);
        if (asprintf(&command, "./%.*s", ((int)strlen(file_name) - 2), file_name) == -1)
        {
            free(file_name);
            return (1);
        }
        if (system(command) != 0)
        {
            free(command);
            free(file_name);
            return (1);
        }
        free(command);
        free(file_name);
    }
    return (0);
}
