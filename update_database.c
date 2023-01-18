/***************************************************************************************************************************************************
*Author         :Utsava Kumar Singh
*Date           :Thu 16 Jan 2023
*File           :update_database.c
*Title          :To Update database.
****************************************************************************************************************************************************/
#include "inverted_search.h"

void update_database(Wlist *head[], Flist **f_head)
{
    int ret_val;
    // prompt the user to enter new filename
    char file_name[FNAME_SIZE];
    printf("\nEnter the file name to update data: ");
    scanf("%s", file_name);

    // validate the file name and update the file list
    ret_val = update_file_validation_n_update_file_list(f_head, file_name);

    if(ret_val == SUCCESS)
    {
        Flist *temp = *f_head;

        while(temp)
        {
            if(!strcmp(temp->file_name, file_name))
            {
                create_database(temp, head);
            }
            temp = temp->link;
        }
    }
}

