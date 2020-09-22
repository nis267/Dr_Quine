int i = 100;
#define CONTENT "#include <sys/types.h>\n#include <sys/stat.h>\n#include <fcntl.h>\n#include <unistd.h>\n#include <stdlib.h>\n#include <stdio.h>\n#include <string.h>\n\nint count_nb_digits(int nbr)\n{\n    int count;\n    count = 0;\n    while (nbr != 0)\n    {\n        nbr /= 10;\n        count++;\n    }\n    return count;\n}\n\nvoid print_content_to_file(int fd)\n{\n    int j;\n\n    j = 0;\n    dprintf(fd, \"int i = %d%s\", i - 1, \";\\n\");\n    dprintf(fd, \"%s\", \"#define CONTENT \\\"\");\n    while (CONTENT[j])\n    {\n        if (CONTENT[j] == 10)\n            write(fd, \"\\\\n\", 2);\n        else if (CONTENT[j] == 92)\n            write(fd, \"\\\\\\\\\", 2);\n        else if (CONTENT[j] == 34)\n            write(fd, \"\\\\\\\"\", 2);\n        else\n            write(fd, &CONTENT[j], 1);\n        j++;\n    }\n    write(fd, \"\\\"\\n\", 2);\n    j = 0;\n    while (CONTENT[j])\n    {\n        write(fd, &CONTENT[j], 1);\n        j++;\n    }\n}\n\nint main(void)\n{\n    int nb_digits;\n    int fd;\n    char *file_name;\n    char *command;\n\n    if (i > 0)\n    {\n        nb_digits = count_nb_digits(i);\n        if ((file_name = (char*)malloc(9 + nb_digits)) == NULL)\n            return(1);\n        strcpy(file_name, \"Sully_\");\n        sprintf(file_name + 6, \"%d\", i - 1);\n        strcat(file_name, \".c\");\n        fd = open(file_name, O_CREAT | O_RDWR, 0666);\n        if (fd < 0)\n        {\n            free(file_name);\n            return(1);\n        }\n        print_content_to_file(fd);\n        close(fd);\n        if ((command = (char*)malloc(29 + (strlen(file_name) - 2) + 1 + strlen(file_name) + 1)) == NULL)\n        {\n            free(file_name);\n            return(1);\n        }\n        strcpy(command, \"gcc -Wall -Wextra -Werror -o \");\n        strncat(command, file_name, (strlen(file_name) - 2));\n        strcat(command, \" \");\n        strcat(command, file_name);\n        if (system(command) != 0)\n        {\n            free(command);\n            free(file_name);\n            return (1);\n        }\n        free(command);\n        if ((command = (char*)malloc(strlen(\"./\") + (strlen(file_name)) - strlen(\".c\") + 1)) == NULL)\n        {\n            free(file_name);\n            return (1);\n        }\n        strcpy(command, \"./\");\n        strncat(command, file_name, (strlen(file_name) - strlen(\".c\")));\n        if (system(command) != 0)\n        {\n            free(command);\n            free(file_name);\n            return (1);\n        }\n        free(command);\n        free(file_name);\n    }\n    return (0);\n}\n"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int count_nb_digits(int nbr)
{
    int count;
    count = 0;
    while (nbr != 0)
    {
        nbr /= 10;
        count++;
    }
    return count;
}

void print_content_to_file(int fd)
{
    int j;

    j = 0;
    dprintf(fd, "int i = %d%s", i - 1, ";\n");
    dprintf(fd, "%s", "#define CONTENT \"");
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
    int nb_digits;
    int fd;
    char *file_name;
    char *command;

    if (i > 0)
    {
        nb_digits = count_nb_digits(i);
        if ((file_name = (char*)malloc(9 + nb_digits)) == NULL)
            return(1);
        strcpy(file_name, "Sully_");
        sprintf(file_name + 6, "%d", i - 1);
        strcat(file_name, ".c");
        fd = open(file_name, O_CREAT | O_RDWR, 0666);
        if (fd < 0)
        {
            free(file_name);
            return(1);
        }
        print_content_to_file(fd);
        close(fd);
        if ((command = (char*)malloc(29 + (strlen(file_name) - 2) + 1 + strlen(file_name) + 1)) == NULL)
        {
            free(file_name);
            return(1);
        }
        strcpy(command, "gcc -Wall -Wextra -Werror -o ");
        strncat(command, file_name, (strlen(file_name) - 2));
        strcat(command, " ");
        strcat(command, file_name);
        if (system(command) != 0)
        {
            free(command);
            free(file_name);
            return (1);
        }
        free(command);
        if ((command = (char*)malloc(strlen("./") + (strlen(file_name)) - strlen(".c") + 1)) == NULL)
        {
            free(file_name);
            return (1);
        }
        strcpy(command, "./");
        strncat(command, file_name, (strlen(file_name) - strlen(".c")));
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
