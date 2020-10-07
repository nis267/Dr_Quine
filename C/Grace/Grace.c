#define CONTENT "#include <stdio.h>\n#include <sys/types.h>\n#include <sys/stat.h>\n#include <fcntl.h>\n#include <unistd.h>\n#define CODE()\\\n(\\\n    {\\\n        int fd;\\\n        if ((fd = open(\"Grace_kid.c\", O_CREAT | O_RDWR, 0666)) >= 0)\\\n        {\\\n            int i;\\\n            i = 0;\\\n            write(fd, \"#define CONTENT \\\"\", 17);\\\n            while (CONTENT[i])\\\n            {\\\n                if (CONTENT[i] == 10)\\\n                    write(fd, \"\\\\n\", 2);\\\n                else if (CONTENT[i] == 92)\\\n                    write(fd, \"\\\\\\\\\", 2);\\\n                else if (CONTENT[i] == 34)\\\n                    write(fd, \"\\\\\\\"\", 2);\\\n                else\\\n                    write(fd, &CONTENT[i], 1);\\\n                i++;\\\n            }\\\n            write(fd, \"\\\"\\n\", 2);\\\n            i = 0;\\\n            while (CONTENT[i])\\\n            {\\\n                write(fd, &CONTENT[i], 1);\\\n                i++;\\\n            }\\\n        }\\\n        else\\\n            write(2, \"Grace: Error: Can't open file Grace_kid.c\\n\", 42);\\\n    }\\\n)\n#define START int main() {CODE();}\n\n/*\n    I'm a comment\n*/\nSTART\n"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define CODE()\
(\
    {\
        int fd;\
        if ((fd = open("Grace_kid.c", O_CREAT | O_RDWR, 0666)) >= 0)\
        {\
            int i;\
            i = 0;\
            write(fd, "#define CONTENT \"", 17);\
            while (CONTENT[i])\
            {\
                if (CONTENT[i] == 10)\
                    write(fd, "\\n", 2);\
                else if (CONTENT[i] == 92)\
                    write(fd, "\\\\", 2);\
                else if (CONTENT[i] == 34)\
                    write(fd, "\\\"", 2);\
                else\
                    write(fd, &CONTENT[i], 1);\
                i++;\
            }\
            write(fd, "\"\n", 2);\
            i = 0;\
            while (CONTENT[i])\
            {\
                write(fd, &CONTENT[i], 1);\
                i++;\
            }\
        }\
        else\
            write(2, "Grace: Error: Can't open file Grace_kid.c\n", 42);\
    }\
)
#define START int main() {CODE();}

/*
    This is a comment
*/
START
