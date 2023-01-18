#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<ctype.h>
#include<errno.h>

// definition macros
#define SUCCESS 0
#define FAILURE -1
#define FNAME_SIZE 15
#define WORD_SIZE 10
#define FILE_EMPTY -2
#define FILE_NOTAVAILABLE -3
#define REPEATATION -4

// Colors

#define CC_CLEAR "\x1b[0m" // Console Color CLEAR

// FG Colours
#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"

// FG Intense Colors
#define IBLACK "\x1b[30;1m"
#define IRED "\x1b[31;1m"
#define IGREEN "\x1b[32;1m"
#define IYELLOW "\x1b[33;1m"
#define IBLUE "\x1b[34;1m"
#define IMAGENTA "\x1b[35;1m"
#define ICYAN "\x1b[36;1m"
#define IWHITE "\x1b[37;1m"

// BG Colors
#define BGC_BLACK "\x1b[40m"
#define BGC_RED "\x1b[41m"
#define BGC_GREEN "\x1b[42m"
#define BGC_YELLOW "\x1b[43m"
#define BGC_BLUE "\x1b[44m"
#define BGC_MAGENTA "\x1b[45m"
#define BGC_CYAN "\x1b[46m"
#define BGC_WHITE "\x1b[47m"

char *fname;

typedef char data_t;

// Structure for file list
typedef struct file_node
{
    data_t file_name[FNAME_SIZE];
    struct file_node *link;
}Flist;

// Structure for link table
typedef struct linktable_node
{
    int word_count;
    data_t file_name[FNAME_SIZE];
    struct linktable_node *table_link;
}Ltable;

// Structure to store word count
typedef struct word_node
{
    int file_count;
    data_t word[WORD_SIZE];
    Ltable *Tlink;
    struct word_node *link;
}Wlist;

// To validate the file and making file list
int file_validation_n_file_list(Flist **f_head, char *argv[]);

// To check File Empty status
int isFileEmpty(char *filename);

// To create list of files
int to_create_list_of_files(Flist **f_head, char *name);

// To create the database
void create_database(Flist *f_head, Wlist *head[]);

// To process the files one by one
Wlist* read_datafile(Flist *file, Wlist *head[], char *filename);

// Create word list
int insert_at_last(Wlist **head, data_t *data);

// Update link table
int update_link_table(Wlist **head);

// Update word count
int update_word_count(Wlist **head, char *file_name);

// Print word count
int print_word_count(Wlist *head);

// To search the words
void search(Wlist *head, char *word);

// To validate the update file and updating the file list
int update_file_validation_n_update_file_list(Flist **f_head, char *file_name);

// To display  the results
void display_database(Wlist *head[]);

// Save database
void save_database(Wlist *head[]);

// Saves the details into the file
void write_databasefile(Wlist *head, FILE* databasefile);

// Update database
void update_database(Wlist *head[], Flist **f_head);

//For setting text background and forground color
void textcolor(char *color);

#endif
