/***************************************************************************************************************************************************
*Author         :Utsava Kumar Singh
*Date           :Thu 12 Jan 2023
*File           :insert_at_last.c
*Title          :To Create word list.
****************************************************************************************************************************************************/
#include "inverted_search.h"

int insert_at_last(Wlist **head, data_t *data)
{
    // Create the node
    Wlist *new = malloc(sizeof(Wlist));

    if(new == NULL)
    {
        return FAILURE;
    }

    // Update node
    new->file_count = 1;
    strcpy(new->word, data);
    new->Tlink = NULL;
    new->link = NULL;

    // call function to update link table
    update_link_table(&new);

    // Check Wlist is empty or not
    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    // non empty
    Wlist *temp = *head;

    // traverse through the Wlist
    while(temp->link)
    {
        temp = temp->link;
    }

    temp->link = new;

    return SUCCESS;
}
