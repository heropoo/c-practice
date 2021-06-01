#include <stdio.h>

int main(int argc, char *argv[])
{
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
        "Ala", "Franky",
        "玛丽", "John", "Lisa"};

    int count = sizeof(ages) / sizeof(int);
    printf("sizeof ages: %ld, sizeof names:%ld\n", sizeof(ages), sizeof(names));

    printf("--------------------------------\n");

    
    int i = 0;

    for (i = 0; i < count; i++)
    {
        printf("%d, %s has %d years alive.\n", i, names[i], ages[i]);
    }

    printf("--------------------------------\n");

    // setup the pointers to the start of the arrays
    int *cur_age = ages;
    char **cur_name = names;

    for (i = 0; i < count; i++)
    {
        printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
    }

    printf("--------------------------------\n");
    for (i = 0; i < count; i++)
    {
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }

    printf("--------------------------------\n");

    // fourth way with pointers in a stupid complex way
    for (cur_name = names,
        cur_age = ages;
         (cur_age - ages) < count;
         cur_name++, cur_age++)
    {
        printf("%s lived %d years so far.\n",
               *cur_name, *cur_age);
    }

    return 0;
}