#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno;

int main()
{
    FILE *pf;
    int errnum;
    pf = fopen("unexist.txt", "rb");
    if (pf == NULL)
    {
        errnum = errno;
        fprintf(stderr, "errno is %d\n", errnum);
        perror("export error by perror");
        fprintf(stderr, "open file error: %s\n", strerror(errnum));
    }
    else
    {
        fclose(pf);
    }

    return 0;
}
