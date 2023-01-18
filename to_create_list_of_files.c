/***************************************************************************************************************************************************
*Author         :Utsava Kumar Singh
*Date           :Thu 12 Jan 2023
*File           :to_create_list_of_files.c
*Title          :Function to create list of files
****************************************************************************************************************************************************/
#include "inverted_search.h"

int to_create_list_of_files(Flist **f_head, char *name)
{
    // Checking the file name linked list is empty or not
    // If empty then add file as a head
    if(*f_head == NULL)
    {
        Flist *new = malloc(sizeof(Flist));
        strcpy(new->file_name, name);
        new->link = NULL;
        *f_head = new;
        return SUCCESS;
    }
    else
    {
        Flist *curr = *f_head;
        Flist *prev = NULL;
        while(curr)
        {
            // check for the repeated file name ??
            if(!strcmp(curr->file_name, name))
            {
                return REPEATATION;
            }
            prev = curr;
            curr = curr->link;
        }

        Flist *new = malloc(sizeof(Flist));
        strcpy(new->file_name, name);
        new->link = NULL;

        prev->link = new;
        return SUCCESS;
    }
}

