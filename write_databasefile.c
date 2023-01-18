/***************************************************************************************************************************************************
*Author         :Utsava Kumar Singh
*Date           :Thu 12 Jan 2023
*File           :write_datbasefile.c
*Title          :Saves the details into the file
*Description    :All the files are opened and read. Words are listed. Now this list is to be stored.
		:For this a new file “DatabaseFile” is created and opened in write mode.
		:Now the words along with filelist (each node contents) are written to the Database file.
		:In the file also the word should be written in sorted order.
		:After that the file is closed properly.
****************************************************************************************************************************************************/
#include "inverted_search.h"

void write_databasefile(Wlist *head, FILE* databasefile)
{
    int flag;
    // transverse through the Wlist
    while(head != NULL)
    {
        flag = 0;
        fprintf(databasefile, "%5d  %10s    %10d    File/s:  ", tolower(head->word[0]) % 97, head->word, head->file_count);

        Ltable *Thead = head->Tlink;

        // traverse through the Ltable
        while(Thead)
        {
            if(flag == 1)
            {
                fprintf(databasefile, "%44c", ' ');
            }
            fprintf(databasefile, "%15s    %10d\n", Thead->file_name, Thead->word_count);
            Thead = Thead->table_link;
            flag = 1;
        }
        fprintf(databasefile, "_________________________________________________________________________\n");
        head = head->link;
    }
}

