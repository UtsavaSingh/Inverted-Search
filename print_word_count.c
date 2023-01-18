/***************************************************************************************************************************************************
*Author         :Utsava Kumar Singh
*Date           :Thu 12 Jan 2023
*File           :print_word_count.c
*Title          :To Print word count.
*Description    :Function to print the count number of words that are present in the file
****************************************************************************************************************************************************/
#include "inverted_search.h"

int print_word_count(Wlist *head)
{
    int flag;
    // transverse through the Wlist
    while(head != NULL)
    {
        flag = 0;
        printf("%5d  %10s    %10d    File/s:  ", tolower(head->word[0]) % 97, head->word, head->file_count);

        Ltable *Thead = head->Tlink;

        // traverse through the Ltable
        while(Thead)
        {
            if(flag == 1)
            {
                printf("%44c", ' ');
            }
            printf("%15s    %10d\n", Thead->file_name, Thead->word_count);
            Thead = Thead->table_link;
            flag = 1;
        }
        printf("_________________________________________________________________________\n");
        head = head->link;
    }
}

