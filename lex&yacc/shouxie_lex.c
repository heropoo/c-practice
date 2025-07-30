#include <stdio.h>
#include <ctype.h>

char *progname;

#define NUMBER 400
#define COMMENT 401
#define TEXT 402
#define COMMAND 403

int lexer();

int main(int argc, char *argv[])
{
    int val;
    while (val = lexer())
    {
        printf("value is %d\n", val);
    }

    return 0;
}

int lexer()
{
    int c;
    while ((c = getchar()) == ' ' || c == '\t')
        ;

    if (c == EOF)
        return 0;

    // 数字
    if (c == '.' || isdigit(c))
    {
        while ((c = getchar()) != EOF && isdigit(c))
            ;

        if (c == '.')
            while ((c = getchar()) != EOF && isdigit(c))
                ;

        ungetc(c, stdin);
        return NUMBER;
    }

    // 注释
    if (c == '#')
    {
        while ((c = getchar()) != EOF && c != '\n')
            ;

        ungetc(c, stdin);
        return COMMENT;
    }

    // 文本文字
    if (c == '"')
    {
        while ((c = getchar()) != EOF && c != '"' && c != '\n')
            ;

        if (c == '\n')
            ungetc(c, stdin);

        return TEXT;
    }

    // 检查是否是一个命令
    if (isalpha(c))
    {
        while ((c = getchar()) != EOF && isalnum(c))
            ;
        ungetc(c, stdin);
        return COMMAND;
    }

    return c;
}
