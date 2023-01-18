/***************************************************************************************************************************************************
*Author         :Utsava Kumar Singh
*Date           :Thu 12 Jan 2023
*File           :update_link_table.c
*Title          :To Update link table.
****************************************************************************************************************************************************/
#include "inverted_search.h"

int update_link_table(Wlist **head)
{
    // Create node
    Ltable *new = malloc(sizeof(Ltable));
    // checking memory allocated or not
    if(new == NULL)
    {
        return FAILURE;
    }
    // saving the data in the new node
    new->word_count = 1;
    strcpy(new->file_name, fname);
    new->table_link = NULL;

    // updating the head link with new node address
    (*head)->Tlink = new;

    return SUCCESS;
}

