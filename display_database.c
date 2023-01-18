/***************************************************************************************************************************************************
*Author         :Utsava Kumar Singh
*Date           :Thu 12 Jan 2023
*File           :display_database.c
*Title          :To display  the results.
****************************************************************************************************************************************************/
#include "inverted_search.h"

void display_database(Wlist *head[])
{
    printf("\n=========================================================================\n");
    textcolor(IRED);
    textcolor(BGC_YELLOW);
    printf("Index        Word    File count    File/s:        File name    Word count\n");
    textcolor(CC_CLEAR);
    printf("=========================================================================\n");

    // transverse through each index and display its content if present
    for(int i = 0; i < 27; i++)
    {
        if(head[i] != NULL)
        {
            print_word_count(head[i]);
        }
    }
}

