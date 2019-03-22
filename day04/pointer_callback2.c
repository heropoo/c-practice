#include<stdio.h>
#include<stdlib.h>

void populate_array(int *array, size_t array_size, int (*get_next_value)(void))
{
    for(size_t i=0; i < array_size; i++)
    {
        array[i] = get_next_value();
    }
}

int get_next_random_value(void)
{
    return rand();
}

int main()
{
    int my_array[10];
    populate_array(my_array, 10, get_next_random_value);
    for(int i=0; i < 10; i++)
    {
        printf("%d ", my_array[i]);
    }
    printf("\n");
    return 0;
}