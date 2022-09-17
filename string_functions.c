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
    char* p;
    for ( p=new_arr ; *str1 || *str2;)
    {
        if (*str1)
        {
            *p = *str1;
            ++p;
            ++str1;
        }
        if (*str2)
        {
            *p = *str2;
            ++p;
            ++str2;
        }
    }
    return new_arr;
}

