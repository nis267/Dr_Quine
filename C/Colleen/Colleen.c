#define CONTENT "#include <unistd.h>\n\n/*\n    I'am a another comment\n*/\n\nvoid print_content()\n{\n    int i;\n\n    i = 0;\n    write(1, \"#define CONTENT \\\"\", 17);\n    while (CONTENT[i])\n    {\n        if (CONTENT[i] == 10)\n            write(1, \"\\\\n\", 2);\n        else if (CONTENT[i] == 92)\n            write(1, \"\\\\\\\\\", 2);\n        else if (CONTENT[i] == 34)\n            write(1, \"\\\\\\\"\", 2);\n        else\n            write(1, &CONTENT[i], 1);\n        i++;\n    }\n    write(1, \"\\\"\\n\", 2);\n    i = 0;\n    while (CONTENT[i])\n    {\n        write(1, &CONTENT[i], 1);\n        i++;\n    }\n}\n\nint main(void)\n{\n    /*\n        I'am a comment\n    */\n    print_content();\n}\n"
#include <unistd.h>

/*
    I'am another comment
*/

void print_content()
{
    int i;

    i = 0;
    write(1, "#define CONTENT \"", 17);
    while (CONTENT[i])
    {
        if (CONTENT[i] == 10)
            write(1, "\\n", 2);
        else if (CONTENT[i] == 92)
            write(1, "\\\\", 2);
        else if (CONTENT[i] == 34)
            write(1, "\\\"", 2);
        else
            write(1, &CONTENT[i], 1);
        i++;
    }
    write(1, "\"\n", 2);
    i = 0;
    while (CONTENT[i])
    {
        write(1, &CONTENT[i], 1);
        i++;
    }
}

int main(void)
{
    /*
        I'am a comment
    */
    print_content();
}
