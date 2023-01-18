/***************************************************************************************************************************************************
*Author         :Utsava Kumar Singh
*Date           :Thu 16 Jan 2023
*File           :save_database.c
*Title          :To Save database.
****************************************************************************************************************************************************/
#include "inverted_search.h"

void save_database(Wlist *head[])
{
    int i;
    // prompt the user to enter filename
    char file_name[FNAME_SIZE];
    printf("\nEnter the file name to save the database : ");
    scanf("%s", file_name);

    // Open file in write mode
    FILE *fptr = fopen(file_name, "w");

    fprintf(fptr, "=========================================================================\n");
    fprintf(fptr, "Index        Word    File count    File/s:        File name    Word count\n");
    fprintf(fptr, "=========================================================================\n");
    for(i = 0; i < 27; i++)
    {
        if(head[i] != NULL)
        {
            write_databasefile(head[i], fptr);
        }
    }
    textcolor(BGC_MAGENTA);
    printf("\nINFO :");
    textcolor(CC_CLEAR);
    printf(" Database Saved\n");
}

