/***************************************************************************************************************************************************
*Author         :Utsava Kumar Singh
*Date           :Thu 12 Jan 2023
*File           :create_database.c
*Title          :To create the database
****************************************************************************************************************************************************/
#include "inverted_search.h"

void create_database(Flist *f_head, Wlist *head[])
{
    // traverse through the file linked list
    while(f_head)
    {
        read_datafile(f_head, head, f_head->file_name);
        textcolor(BGC_GREEN);
        printf("\nSuccessful :");
        textcolor(CC_CLEAR);
        printf(" Creation of database for file : %s\n", f_head->file_name);
        f_head = f_head->link;
    }
}

