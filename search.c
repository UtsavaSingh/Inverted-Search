/***************************************************************************************************************************************************
*Author         :Utsava Kumar Singh
*Date           :Thu 16 Jan 2023
*File           :search.c
*Title          :To search the words.
*Description    :Each word is now used to search in the linkedlist. The word has to be compared with
		        :each word in the linked list. When found, the file details can be retrieved.
****************************************************************************************************************************************************/
#include "inverted_search.h"

void search(Wlist *head, char *word)
{
    // check list is empty or not
    if(head == NULL)
    {
        textcolor(BGC_MAGENTA);
        printf("INFO :");
        textcolor(CC_CLEAR);
        printf(" Database is empty\n\n");
        return;
    }

    // traverse the list
    Wlist *temp = head;
    while(temp)
    {
        // compare the search word with available word in the list

        if(strcmp(temp->word, word) == 0)
        {
            printf("Word : ' %s ' is present in : %d file/s", word, temp->file_count);
            Ltable *Thead = temp->Tlink;

            while(Thead)
            {
                printf(", in the file : ' %s ', it is present : %d time/s", Thead->file_name, Thead->word_count);
                Thead = Thead->table_link;
            }
            printf("\n");
            return;
        }
        temp = temp->link;
    }
    textcolor(BGC_MAGENTA);
    printf("INFO :");
    textcolor(CC_CLEAR);
    printf(" Search word is not found\n\n");
}

