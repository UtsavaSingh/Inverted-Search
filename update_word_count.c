/***************************************************************************************************************************************************
*Author         :Utsava Kumar Singh
*Date           :Thu 12 Jan 2023
*File           :update_word_count.c
*Title          :To Update word count.
****************************************************************************************************************************************************/
#include "inverted_search.h"

int update_word_count(Wlist **head, char *file_name)
{
    Wlist *temp = *head;
    Ltable *curr = temp->Tlink;
    Ltable *prev = NULL;

    // checking whether filenames are same or not
    while(curr)
    {
        // If the filenames are same, incrementing the word count
        if(!strcmp(curr->file_name, file_name))
        {
            curr->word_count++;
            return SUCCESS;
        }
        prev = curr;
        curr = curr->table_link;
    }

    // If filenames are different, incrementing the file count and creating new Ltable
    (temp->file_count)++;
    Ltable *new = malloc(sizeof(Ltable));
    if(new == NULL)
    {
        return FAILURE;
    }
    strcpy(new->file_name, file_name);
    new->word_count = 1;
    new->table_link = NULL;

    // making new Ltable the last
    prev->table_link = new;
}

