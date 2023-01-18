/***************************************************************************************************************************************************
*Author         :Utsava Kumar Singh
*Date           :Thu 12 Jan 2023
*File           :read_datafile.c
*Title          :To read the contents of the file
*Description    :Open the file “FileList” and read the names of the files. This is an iterative process which reads one file name from the
		 :FileList and open that file in read mode.
****************************************************************************************************************************************************/
#include "inverted_search.h"

Wlist* read_datafile(Flist *file, Wlist *head[], char *filename)
{
    int flag = 1;

    // open the file in read mode
    FILE *fptr = fopen(filename, "r");

    // declare an array to store the words
    char word[WORD_SIZE];

    fname = filename;
    while(fscanf(fptr, "%s", word) != EOF)
    {
        //index
        int index = tolower(word[0]) % 97;

        // other than alphabets
        if(!(index >= 0 && index <= 25))
            index = 26;

        // check whether words are repeated or not
        if(head[index] != NULL)
        {
            Wlist *temp = head[index];

            // compare the words at each node with new word
            while(temp)
            {
                if(!strcmp(temp->word, word))
                {
                    update_word_count(&temp, filename);
                    flag = 0;
                    break;
                }
                temp = temp->link;
            }
        }

        if(flag == 1)
        {
            // words are not repeated
            insert_at_last(&head[index], word);
        }
    }
}

