/***************************************************************************************************************************************************
*Author         :Utsava Kumar Singh
*Date           :Thu 12 Jan 2023
*File           :is_FileEmpty.c
*Title          :To check File Empty status.
*Description    :Function is used to check that file contains some comtent or it is empty
****************************************************************************************************************************************************/
#include "inverted_search.h"

int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        if(errno == ENOENT) 
        {
            return FILE_NOTAVAILABLE;
        }
    }
    fseek(fptr, 0, SEEK_END);
    if(ftell(fptr) == 0)
    {
        return FILE_EMPTY;
    }
}

