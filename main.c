/***************************************************************************************************************************************************
*Author     :Utsava Kumar Singh
*Date       :Thu 12 Jan 2023
*File		:main.c
*Title		:Driver function
*Description	:This function acts like the driver function for the project inverted search
****************************************************************************************************************************************************/
#include "inverted_search.h"

int main(int argc, char *argv[])
{
    system("clear");
    int choice, flag = 0;
	char opt, responce;
    Wlist *head[27] = {NULL};
    // validate CLA
    if(argc <= 1)
    {
        textcolor(BGC_RED);
        printf("Failed :");
        textcolor(CC_CLEAR);
        textcolor(CYAN);
        printf(" Enter the valid number of arguments\n");
        printf("./Slist.exe f1.txt f2.txt.......\n\n");
        textcolor(CC_CLEAR);
        return 0;
    }

    // create list of files
    // declare file head pointer

    Flist *f_head = NULL;

    // validation of file

    file_validation_n_file_list(&f_head, argv);

    if(f_head == NULL)
    {
        textcolor(BGC_RED);
        printf("Failed :");
        textcolor(CC_CLEAR);
        textcolor(CYAN);
        printf(" No files are available in the file list\n");
        printf("Hence the process terminated\n\n");
        textcolor(CC_CLEAR);
        return 1;
    }

	do
	{
		if(flag == 1)
            system("clear");
        flag = 1;
		// prompt the user for choice
		textcolor(BGC_YELLOW);
		printf("\n    Select your choice among following options    \n\n");
		textcolor(CC_CLEAR);
		printf("1. Create DATABASE\n2. Display DATABASE\n3. Update DATABASE\n4. Search DATABASE\n5. Save DATABASE\n\n");
		textcolor(GREEN);
		printf("Enter you choice : ");
		textcolor(CC_CLEAR);
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				// create database
				create_database(f_head, head);
				break;

			case 2:
                // display database
				display_database(head);
				break;

			case 3:
				// update database
				update_database(head, &f_head);

				break;

			case 4:
				// search database
				{
				    char word[WORD_SIZE];
				    printf("Enter the word you want to search: ");
				    scanf(" %s", word);
				    printf("\n");
				    search(head[tolower(word[0])%97], word);

                    break;
				}

			case 5:
				// save database
				save_database(head);

				break;

			default:
				printf("Invalid input\n");
		}
		textcolor(GREEN);
		printf("\nDo you want to continue ?\nEnter Y/y to continue and N/n to discontinue : ");
		textcolor(CC_CLEAR);
		getchar();
		scanf(" %c", &responce);
	}
	while(responce == 'y' || responce == 'Y');
}

//For setting text background and foreground color
void textcolor(char *color)
{
    printf("%s", color);
}

