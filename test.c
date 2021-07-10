//محمد محمد زكي محمد شاهين SEC:3 BN:44
//مينا حنا فايز وهبة SEC:4 BN:31
//محمد هشام محمد عبد المنغم  SEC:3 BN:47
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include <time.h>
//TIME COMPLEXITY FOR LIST INSERTION
    //INSERT AT BEG 2.99*10^(-6), AT END 2.69*10^(-6)
    //IN THE MIDDLE OF LIST OF SIZE 10 AVERAGE TIME 1.89*10^(-5) AND 1.975*10^(-5) ,IT INCREASES AS SIZE INCREASES

//TIME COMPLEXITY FOR ARRAY INSERTION
    //INSERT AT BEG 1.077*10^(-5), AT END 1.0142*10^(-5)
    //IN THE MIDDLE OF ARRAY OF SIZE 10 AVERAGE TIME 2.245*10^(-5) AND 1.924*10^(-5) ,IT INCREASES AS SIZE INCREASES


int N;

//The structure has a total size of 56 bytes
typedef struct st
{
    int id;
    char name[40];
    int birth_year;
    int birth_month;
    int birth_day;
}st;

//one node has a total size of 68 bytes
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
/* contructing the linked list */

void list (void)
{
    N = 0;
    node *head = NULL;
    node *tail = NULL;
    printf("\nNumber of students in the list intially: ");
    scanf("%i" , &N);
    //fflush(stdin);
    if( N== INT_MAX )
    {
        return;
    }

    for (int i=0; i < N; i++)
    {
        node *n = malloc (sizeof(node));
        if (!n)
        {
            return;
        }

        printf("\nenter student %i info \n", i+1);
        get_info(n);

        if (head)
        {
            for (node *ptr = head; ptr != NULL; ptr = ptr -> next )
            {
                if(ptr-> next == NULL)
                {
                   ptr-> next = n;
                   break;
                }
            }
        }
        else
        {
            head = n;
        }

        if ( i == N-1 )
        {
            tail = n;
        }
    }

    printf("\nInsert student in the begining of list");
    insertbeg(&head);


    printf("\nInsert student in the end of list");
    insertend(&tail);

    int x;
    printf("\nindex of new student in list (note that index start from 0 and ends at %i): ", N);
    scanf("%i" , &x);
    fflush(stdin);

    if (x == N)
    {
        insertend(&tail);
    }
    else if (x == 0)
    {
        insertbeg(&head);
    }
    else if( x > 0 && x < N)
    {
        insertmiddle(head,x);
    }
    else
    {
        printf("index is not correct\n");
    }

    printf("\nIDs and names of students in list\n");
    for (node *ptr = head; ptr != NULL; ptr = ptr -> next )
    {
        printf("%i\t%s\n", ptr -> stu.id,ptr -> stu.name );
    }



    /* deleting allocated memory */
    node *ptr = head;
    while(ptr != NULL)
    {
        node *nxt = ptr -> next;
        free(ptr);
        ptr = nxt;
    }
}

/* functions of list */

void get_info(struct node  *n)
{

        printf("student id: ");
        scanf("%i" , &(n->stu.id));
        fflush(stdin);
        printf("student birth year : ");
        scanf("%i" , &(n->stu.birth_year));
        fflush(stdin);
        printf("student birth month : ");
        scanf("%i" , &(n->stu.birth_month));
        fflush(stdin);
        printf("student birth day : ");
        scanf("%i" , &(n->stu.birth_day));
        fflush(stdin);

        n -> next = NULL;

        printf("student name: ");
        scanf("%s" , (n->stu.name));
        fflush(stdin);
}

void insertbeg(node **headp)/*this function takes about 2.99e-06 average time to insert at the beginning*/
{
        node *n = (node*)malloc (sizeof(node));
        if (!n)
        {
            return;
        }

        printf("\nenter student info \n");
        get_info(n);
        //n->stu.id = 2;
        //n->stu.birth_year = 2;
        //n->stu.birth_month= 2;
        //n->stu.birth_day = 2;
        //strcpy(n->stu.name , "mohamed" ) ;

        n -> next = *headp;
        *headp = n;
        N++;
}

void insertend(node **tailp)/*this function takes the same time as inserting the element from the begining as we are using a tail around 2.69e-06 seconds*/
{
        node *n = (node*)malloc (sizeof(node));
        if (!n)
        {
            return;
        }

        printf("\nenter student info \n");
        get_info(n);
        //n->stu.id = 2;
        //n->stu.birth_year = 2;
        //n->stu.birth_month= 2;
        //n->stu.birth_day = 2;
        //strcpy(n->stu.name , "mohamed" ) ;
        (*tail) -> next = n;
        *tailp = n;
        N++;
}

void insertmiddle(node *head, int x)
{/*this function takes average time of 1.89765e-05 for inserting at any elements from the begining and 1.974925e-05 to insert at any element from end of 10 elements list 
 and that number increases as the number of element increases*/

        node *n = (node*)malloc (sizeof(node));
        if (!n)
        {
            return;
        }
        printf("\nenter student info \n");
        get_info(n);
        //n->stu.id = 2;
        //n->stu.birth_year = 2;
        //n->stu.birth_month= 2;
        //n->stu.birth_day = 2;
        //strcpy(n->stu.name , "mohamed" ) ;
        node *pre = head;
        for (int k = 0; k < x-1; k++)
        {
            pre = pre -> next;
        }
        n -> next = pre -> next;
        pre -> next = n;
        N++;
}
