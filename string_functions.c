//
// Created by edens on 15/09/2022.
//
#include "string_functions.h"


char* get_line(void)
{
    printf("enter an string:\n");
    fflush(stdout);
    char* buffer;
    size_t bufsize = 1024;
    getchar();
    buffer = (char*)calloc(bufsize,sizeof(char));
    gets(buffer);
    return buffer;
}

void str_rep_char(char* str, char find, char replace) // eden -> e -> a --> adan
{
    char *current_pos = strchr(str,find);
    while (current_pos) {
        *current_pos = replace;
        current_pos = strchr(current_pos, find);
    }
}

char* str_new_zigzag(const char* str1, const char* str2)
{
    size_t size_1 = strlen(str1);
    size_t size_2 = strlen(str2);
    char* new_arr = (char*) calloc((size_1+size_2)+1,sizeof(char));
    int index = 0;
    for (int i = 0,j=0; i < strlen(str1) , j<strlen(str2) ; ++i,++j) {
        // if index > i dont enter
        if(index<=i)
        {
            new_arr[index]=str1[i];
            ++index;
        }
//        new_arr[index]=str1[i];
//        ++index;
        if(index>=j)
        {
            new_arr[index]=str2[j];
            ++index;
        }
//        new_arr[index]=str2[j];
//        ++index;
    }
    return new_arr;
}

