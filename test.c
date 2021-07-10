//محمد محمد زكي محمد شاهين SEC:3 BN:44
//مينا حنا فايز وهبة SEC:4 BN:31
//محمد هشام محمد عبد المنغم  SEC:4 BN:47
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include <time.h>



int N;

//The structure has a total size of 60 bytes
typedef struct st
{
    int id;
    char name[40];
    int birth_year;
    int birth_month;
    int birth_day;
}st;

//one node has a total size of 72 bytes
typedef struct node
{
    st stu;
    struct node *next;
}node;

void get_info(node  *n);
void insertend(node **tailp);
void insertbeg(node **headp);
void insertmiddle(node *head, int x);
void list (void);

void get_infoarr(struct st  *arr);
void array(void);
void insertendarr(st *arr);
void insertbegarr(st **a);
void insertmidarr(st **a, int x);


int main()
{
    printf("hello to students Data structure program \n");
    array();
    list();
}


