//
// Created by edens on 15/09/2022.
//
#include "string_vector.h"
#include <stdlib.h>
#include <assert.h>

void size_updater(StringVector*);
// size updater

void size_decrease(StringVector*); // size & set last to null

//initialize sv (array NULL length 0)
void sv_init(StringVector *sv)
{
    sv->arr=0;
    sv->length=0;
}

//deallocates and clears sv as though it was initialized (array NULL length 0)
void sv_clear(StringVector *sv)
{
    for (int i = 0; i < sv->length; ++i) {
        free(sv->arr[i]);
    }
    free(sv->arr);
}

//adds str as last cell of sv.
//assumes str is a dynamically allocated C-String.
void sv_add_last(StringVector* sv, char* str)
{
    if(sv->length==0)
    {
           sv->arr=(char**)calloc(1,sizeof(char*));
           size_updater(sv);
    }
    else
    {
        sv->arr=(char**)realloc(sv->arr,(++sv->length)  * sizeof(char*));
    }
    sv->arr[sv->length-1]=str;
    //printf("print in sv_add_last -> %s \n",sv->arr[sv->length-1]);
}

//remove string at index. does not shrink allocation size
void sv_remove_at(StringVector* sv, size_t index) // 1 -> 0 // 2->1 // [3]USER -> [2] me
{
    free(sv->arr[index-1]);
    sv->arr[index-1]=NULL;
    for (int i = index; i < sv->length ; ++i)
    {
        sv->arr[i-1]=sv->arr[i];
    }
    size_decrease(sv);
    sv->arr[sv->length]=NULL;
}
void size_updater(StringVector* ptr)
{
    ptr->length++;
}
void size_decrease(StringVector* ptr)
{
    ptr->length--;
}