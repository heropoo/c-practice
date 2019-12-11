#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char name[100];
    char *description;

    strcpy(name, "Zara Ali");

    // 动态分配内存
    description = (char *) malloc (1 * sizeof(char));
    if(description == NULL){
        fprintf(stderr, "Error: unable to allocate required memory\n");
    }else{
        strcpy(description, "Zara ali a DPS student in class 10th 1231231231231111111111111111111111111111111111111111111111111111111111111111111");
    }

    printf("Name is %s\n", name);
    printf("Description is %s\n", description);

    //释放内存
    free(description);
}
