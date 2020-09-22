#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


struct table1* readnum(struct table1* mass, int* size);
void listnum(struct table1* mass, int* size, int mark);
void freemass(struct table1* mass, int* size);
int convertd(struct table1* mass, int* size);
char* readstr1();
struct table1 {
    char* binar;
    int decimal;
};

struct table1* readnum(struct table1 *mass, int *size)
{
    char* string = readstr1();

    if (string != NULL) {
        mass = realloc(mass, sizeof(struct table1) * (*size));
        mass[(*size) - 1].binar = string;
       
        mass[(*size) - 1].decimal = convertd(mass, size);
        
        (*size)++;
    }
    else {
        printf("Wrong numbers");
    }
    return (mass);
}
int convertd(struct table1* mass, int* size)
{
    int i = strlen(mass[(*size) - 1].binar);
    int s = 0;
    int a = 0;

    while (i > 0) {
        a = a + (mass[(*size) - 1].binar[i - 1] - '0')*(int)pow(2, s);
        i--;
        s++;
    }
    return a;

}

void listnum(struct table1 *mass, int* size, int fl)
{
    int i = 1;
    
    if (fl == 0) {
        while (i < (*size)) {
            printf("%s\n", mass[i - 1].binar);
            i++;
        }
    }
    else {
        while (i < (*size)) {
            printf(" %d\n",  mass[i - 1].decimal);
            i++;
        }
    }
}
void freemass(struct table1* mass, int* size)
{
    int i = 0;
    while (i < *size) {
        free(mass[i].binar);

            i++;
    }

}
char* readstr1()
{
    int c;
    char* str = NULL;
    int i = 0;
    while ((c = getchar()) != '\n')
    {
        
            switch (c)
            {
            case '1':
                i++;
                str = (char*)realloc(str, (i + 1) * sizeof(char));
                str[i - 1] = c;
                
                break;
            case '0':
                i++;
                str = (char*)realloc(str, (i + 1) * sizeof(char));
                str[i - 1] = c;
                //c = getchar();
                break;
            default:
                //c = getchar();
                break;
            }
    }
    fflush(stdin); // очищаем поток ввода
    if (i != 0) {
        str[i] = '\0';
         return str;
    }
     return NULL;
}

int main() {
    int mark = 0;
    int fl1 = 0;
    int fl2 = 0;
    int razm1 = 1;
    int* size1;
    size1 = &razm1;
    int razm2 = 1;
    int* size2;
    size2 = &razm2;
    struct table1* mass1 = (struct table1*) malloc(sizeof(struct table1) * (*size1));
    struct table1* mass2 = (struct table1*) malloc(sizeof(struct table1) * (*size2));
    int c;
    printf("\nMenu\nAdd number in first set - 1\nAdd number in second set - 2\nList all sets - 3\nExit - e\n");
    //c = getchar();
    
    while ((c = getchar()) != 'e') {
        
        mark = 1;
        switch (c) {
        case '1':
            c = getchar();
            mass1 = readnum(mass1,  size1);
            if (mark != 0) {
                printf("\nMenu\nAdd number in first set - 1\nAdd number in second set - 2\nList all sets - 3\nChange numbersystem in first set - 4 \nChange numbersystem in second set - 5 \nExit - e\n");
            }
            break;
        case '2':
            c = getchar();
            mass2 = readnum(mass2, size2);
            if (mark != 0) {
                printf("\nMenu\nAdd number in first set - 1\nAdd number in second set - 2\nList all sets - 3\nChange numbersystem in first set - 4 \nChange numbersystem in second set - 5 \nExit - e\n");
            }
            break;
        case '3':
            printf("\n First set\n");
            listnum(mass1, size1, fl1);
            printf("\n Second set\n");
            listnum(mass2, size2, fl2);
            if (mark != 0) {
                printf("\nMenu\nAdd number in first set - 1\nAdd number in second set - 2\nList all sets - 3\nChange numbersystem in first set - 4 \nChange numbersystem in second set - 5 \nExit - e\n");
            }
            break;
        case '4':
            if (fl1 == 0) {
                fl1 = 1;
                printf("\n First set changed to decimal\n");
            }
            else {
                fl1 = 0;
                printf("\n First set changed to binar\n");
            }
            break;
        case '5':
            if (fl2 == 0) {
                fl2 = 1;
                printf("\n Second set changed to decimal\n");
            }
            else {
                fl2 = 0;
                printf("\n Second set changed to binar\n");
            }
            break;
        case '\n':
            break;
        case ' ':

            break;
        default:
            printf("error: unknown command \n");
            break;
        }
        
        
        //printf("sym %d \n", c);
    }
    freemass(mass1, size1);
    free(mass1);
    freemass(mass2, size2);
    free(mass2);
}

