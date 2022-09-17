#include "string_vector.h"
#include "string_functions.h"

typedef void(*StringVectorAction)(StringVector*);

typedef struct MenuItem {
    const char* description;
    StringVectorAction action;
} MenuItem;

//print function
void print_func(StringVector* sv);
//
//String Vector Actions
//
void size_updater_main(StringVector*);
//reads line from user and adds as a new string at end of vector
void action_add_string(StringVector *sv);
//reads index from user and deletes that string from the vector
void action_del_string(StringVector *sv);
//reads from input: index, and two characters
//inside string at index replaces all instances of the first character
//with the second character
void action_rep_char(StringVector *sv);
//reads from input: two characters
//replaces all instances of the first character
//found in any string in sv with the second character.
void action_rep_char_all(StringVector *sv);
//reads from input: two indexes
//adds a new string to sv that is a zigzag copy
//of the two string in the indexes
//(see helper.h:str_new_zigzag)
void action_zigzag_copy(StringVector *sv);

int main(void) {
   //StringVector  strvec = {0,0};
   StringVector strvec;
   sv_init(&strvec);

    MenuItem menu[5] = {
            {
                    menu[0].description = "Add string\n",
                    menu[0].action = &action_add_string
            },
            {
                    menu[1].description = "Delete string\n",
                    menu[1].action = &action_del_string
            },
            {
                    menu[2].description = "Replace character\n",
                    menu[2].action = &action_rep_char
            },
            {
                    menu[3].description = "Replace character from all\n",
                    menu[3].action = &action_rep_char_all
            },
            {
                    menu[4].description = "Zigzag copy\n",
                    menu[4].action = &action_zigzag_copy
            }
    };

    while (1)
    {
        print_func(&strvec);
        int operation;
        scanf_s("%d", &operation);
        switch (operation)
        {
            case 1:
                menu[operation - 1].action(&strvec);
                break;
            case 2:
                menu[operation - 1].action(&strvec);
                break;
            case 3:
                menu[operation - 1].action(&strvec);
                break;
            case 4:
                menu[operation - 1].action(&strvec);
                break;
            case 5:
                menu[operation - 1].action(&strvec);
                break;
            case 0:
                sv_clear(&strvec);
                return 0;

                // operator doesn't match any case constant //
            default:
                printf("Error! number is not correct try again\n");
        }

    }
}

void action_add_string(StringVector *sv)
{
   char* tmp=get_line();
    sv_add_last(sv,tmp);
}

void action_del_string(StringVector* sv)
{
    size_t index;
    printf("enter an index to be deleted:\n");
    fflush(stdout);
    scanf("%zu",&index);
    printf("%zu \n",sv->length);
    sv_remove_at(sv,index);
}

void action_rep_char(StringVector* sv)
{
    size_t index;
    char s;
    char d;
    printf("enter an index,first char & sec char:\n");
    fflush(stdout);
    scanf("%zu",&index);
    scanf(" %c",&s);
    scanf(" %c",&d);
    str_rep_char(sv->arr[index-1],s,d);
}

void action_rep_char_all(StringVector* sv)
{
    char find;
    char replace;
    printf("enter first char & sec char for all:\n");
    fflush(stdout);
    scanf(" %c",&find);
    scanf(" %c",&replace);
    for (int i = 0; i < sv->length; ++i)
    {
        char *current_pos = strchr(sv->arr[i],find);
        while (current_pos) {
            *current_pos = replace;
            current_pos = strchr(current_pos, find);
        }
    }
}

void action_zigzag_copy(StringVector* sv)
{
    size_t index_1;
    size_t index_2;
    printf("enter 2 indexes:\n");
    fflush(stdout);
    scanf("%zu",&index_1);
    scanf("%zu",&index_2);
    char *tmp = str_new_zigzag(sv->arr[index_1-1],sv->arr[index_2-1]);
    sv->arr=(char**) realloc(sv->arr,(sv->length+1) * (sizeof(char*)));
    size_updater_main(sv);
    sv->arr[sv->length-1]=tmp;
}

void print_func(StringVector* sv)
{
    printf("--------------------\n");
    if(sv->length!=0)
    {
        for (int i = 0 ,m=1; i < sv->length ; ++i,++m)
        {
            printf("%d) %s \n",m,sv->arr[i]);
        }
    }

    printf("\n");
    printf("1) Add string\n");
    printf("2) Delete string\n");
    printf("3) Replace character\n");
    printf("4) Replace character from all\n");
    printf("5) Zigzag copy\n");
    printf("0) quit\n");
    printf("select option:\n");
    fflush(stdout);
}
void size_updater_main(StringVector* sv)
{
    sv->length++;
}
