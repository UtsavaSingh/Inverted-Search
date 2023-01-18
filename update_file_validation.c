/***************************************************************************************************************************************************
*Author         :Utsava Kumar Singh
*Date           :Thu 17 Jan 2023
*File           :update_file_validation.c
*Title          :To validate the update file and updating the file list
****************************************************************************************************************************************************/

#include "inverted_search.h"

int update_file_validation_n_update_file_list(Flist **f_head, char *file_name)
{
    int empty, ret_val;

    empty = isFileEmpty(file_name);

    if(empty == FILE_NOTAVAILABLE)
    {
        textcolor(BGC_RED);
        printf("Failed :");
        textcolor(CC_CLEAR);
        textcolor(CYAN);
        printf(" Entered file %s is not available \n", file_name);
        printf("Hence, the %s file is not adding to the linked list\n\n", file_name);
        textcolor(CC_CLEAR);
    }
    else if(empty == FILE_EMPTY)
    {
        textcolor(BGC_RED);
        printf("Failed :");
        textcolor(CC_CLEAR);
        textcolor(CYAN);
        printf(" Entered file %s is not having any contents in it\n", file_name);
        printf("Hence, the %s file is not adding to the linked list\n\n", file_name);
        textcolor(CC_CLEAR);
    }
    else
    {
        // If file is not empty and it is available then creating the file name linked list
        ret_val = to_create_list_of_files(f_head, file_name);

        if(ret_val == SUCCESS)
        {
            textcolor(BGC_GREEN);
            printf("Successful :");
            textcolor(CC_CLEAR);
            textcolor(CYAN);
            printf(" Inserting the file name : %s into the file linked list\n\n",file_name);
            textcolor(CC_CLEAR);
            return SUCCESS;
        }
        else if(ret_val == REPEATATION)
        {
            textcolor(RED);
            printf("The file name : %s is repeated, hence we are not adding into the linked list\n\n", file_name);
            textcolor(CC_CLEAR);
        }
        else
        {
            return FAILURE;
        }
    }
}
