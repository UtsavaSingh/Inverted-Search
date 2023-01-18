/***************************************************************************************************************************************************
*Author         :Utsava Kumar Singh
*Date           :Thu 12 Jan 2023
*File           :file_validation.c
*Title          :To validate the file and making file list
****************************************************************************************************************************************************/
#include "inverted_search.h"

int file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1, empty, ret_val;
    // If number of arguments is not null then checking the files are empty or file available
    while(argv[i] != NULL)
    {
        empty = isFileEmpty(argv[i]);

        if(empty == FILE_NOTAVAILABLE)
        {
            textcolor(BGC_RED);
            printf("Failed :");
            textcolor(CC_CLEAR);
            textcolor(CYAN);
            printf(" Entered file %s is not available \n", argv[i]);
            printf("Hence, the %s file is not adding to the linked list\n\n", argv[i]);
            textcolor(CC_CLEAR);
            i++;
            continue;
        }
        else if(empty == FILE_EMPTY)
        {
            textcolor(BGC_RED);
            printf("Failed :");
            textcolor(CC_CLEAR);
            textcolor(CYAN);
            printf(" Entered file %s is not having any contents in it\n", argv[i]);
            printf("Hence, the %s file is not adding to the linked list\n\n", argv[i]);
            textcolor(CC_CLEAR);
            i++;
            continue;
        }
        else
        {
            // If file is not empty and it is available then creating the file name linked list
            ret_val = to_create_list_of_files(f_head, argv[i]);

            if(ret_val == SUCCESS)
            {
                textcolor(BGC_GREEN);
                printf("Successful :");
                textcolor(CC_CLEAR);
                textcolor(CYAN);
                printf(" Inserting the file name : %s into the file linked list\n\n", argv[i]);
                textcolor(CC_CLEAR);
            }
            else if(ret_val == REPEATATION)
            {
                textcolor(RED);
                printf("The file name : %s is repeated, hence we are not adding into the linked list\n\n", argv[i]);
                textcolor(CC_CLEAR);
            }
            else
            {
                return FAILURE;
            }
        }
        i++;
    }
}
