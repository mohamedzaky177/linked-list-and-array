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
    //WITH INDEX, IN A LIST OF SIZE 10 AVERAGE TIME IS ABOUT 1.89*10^(-5) AND 1.975*10^(-5) ,IT INCREASES AS SIZE INCREASES

//TIME COMPLEXITY FOR ARRAY INSERTION
    //INSERT AT END 1.0142*10^(-5)
    //AT BEG 1.077*10^(-5), AND IT INCREASES AS SIZE INCREASES, 1.924*10^(-5) FOR ARRAY OF SIZE 10
    //WITH INDEX,IN AN OF ARRAY OF SIZE 10 AVERAGE TIME IS ABOUT 2.245*10^(-5) ,IT INCREASES AS SIZE INCREASES


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

/* constructing the dynamic array */
void array(void)
{
    N = 0;
    printf("\nNumber of students intially in array: ");
    scanf("%i" , &N);
    fflush(stdin);
    if( N== INT_MAX )
    {
        return;
    }
    st *arr = malloc(sizeof(st)*N);
    for (int i=0; i < N; i++)
    {
        printf("\nenter student %i info \n", i+1);
        get_infoarr(arr+i);
    }

    //for (int i=0; i < N; i++)
    //{
    //    printf("%i\n", (arr+i) -> id);
    //}

    printf("\nInsert student in the begining of array");
    insertbegarr(&arr);


    printf("\nInsert student in the end of array");
    insertendarr(arr);


    int x;
    printf("\nindex of new student in array (note that index start from 0 and ends at %i): ", N);
    scanf("%i" , &x);

    fflush(stdin);
    if (x == N)
    {
        insertendarr(arr);
    }
    else if(x == 0)
    {
        insertbegarr(&arr);
    }
    else if( x > 0 && x < N)
    {
        insertmidarr(&arr ,x);
    }
    else
    {
        printf("index is not correct\n");
    }

    printf("\nIDs and names of students in array\n");
    for (int i=0; i < N; i++)
    {
        printf("%i", (arr+i) -> id);
        printf("\t%s\n",(arr+i) -> name);
    }

    free(arr);

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
        (*tailp) -> next = n;
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

/* functions of array */

void get_infoarr(struct st  *arr)
{

    printf("student id: ");
    scanf("%i" , &(arr->id));
    fflush(stdin);
    printf("student birth year : ");
    scanf("%i" , &(arr->birth_year));
    fflush(stdin);
    printf("student birth month : ");
    scanf("%i" , &(arr->birth_month));
    fflush(stdin);
    printf("student birth day : ");
    scanf("%i" , &(arr->birth_day));
    fflush(stdin);
    printf("student name: ");
    scanf("%s" , (arr->name));
    fflush(stdin);

}

void insertendarr(st *arr)
{   /*this function takes about average time of 1.0774e-05 seconds to execute */
    N++;
    st *temp = arr;
    arr = realloc(arr,sizeof(st)*N);
    printf("\nenter student info \n");
    get_infoarr(temp+N-1);
    //(arr+N-1)->id = 4;
    //(arr+N-1)->birth_year = 2;
    //(arr+N-1)->birth_month = 2;
    //(arr+N-1)->birth_day = 2;
    //strcpy((arr+N-1) -> name , "mohamed" ) ;
}
void insertbegarr(st **a)
{
    /*this function takes average time of 1.014198e-05 seconds to insert at the beginning with one element
    but that also depends on the number of element and it takes 1.9247e-05 for 10 elements*/
    N++;
    st *temp = malloc(sizeof(st)*N);
    for (int i=0; i < N-1; i++)
    {
        (temp + i + 1)->birth_day = ( (*a) + i )->birth_day;
        (temp + i + 1)->birth_month = ( (*a) + i )->birth_month;
        (temp + i + 1)->birth_year = ( (*a) + i )->birth_year;
        (temp + i + 1)->id = ( (*a) + i )->id;
        strcpy((temp + i + 1) -> name , ( (*a) + i ) -> name ) ;
    }
    free(*a);
    printf("\nenter student info \n");
    get_infoarr(temp);
    //temp->id = 2;
    //temp->birth_year = 2;
    //temp->birth_month = 2;
    //temp->birth_day = 2;
    //strcpy(temp -> name , "mohamed" ) ;
    *a = temp;
}
void insertmidarr(st **a, int x)
{
    /*this function takes about 2.245e-05 to insert an element at the middle and about 1.924e-05 to insert at the begining for an
    array of 10 elements and this time will increase as the number of elements increases*/
    N++;
    st *temp = malloc(sizeof(st)*N);
    for (int i=0; i < x; i++)
    {
        (temp + i )->birth_day = ( (*a) + i )->birth_day;
        (temp + i )->birth_month = ( (*a) + i )->birth_month;
        (temp + i )->birth_year = ( (*a) + i )->birth_year;
        (temp + i )->id = ( (*a) + i )->id;
        strcpy((temp + i
                ) -> name , ( (*a) + i ) -> name ) ;
    }
    printf("\nenter student info \n");
    get_infoarr(temp + x);
    //(temp + x)->id = 3;
    //(temp + x)->birth_year = 2;
    //(temp + x)->birth_month = 2;
    //(temp + x)->birth_day = 2;
    //strcpy((temp + x) -> name , "mohamed" ) ;

    for (int i = x + 1; i < N ; i++)
    {
        (temp + i )->birth_day = ( (*a) + i - 1)->birth_day;
        (temp + i )->birth_month = ( (*a) + i - 1)->birth_month;
        (temp + i )->birth_year = ( (*a) + i - 1)->birth_year;
        (temp + i )->id = ( (*a) + i - 1)->id;
        strcpy((temp + i ) -> name , ( (*a) + i - 1 ) -> name ) ;
    }
    free(*a);
    *a = temp;
}

//THE CODE FOR TIME COMPLEXIITY
    //#include <bits/stdc++.h>
    //#include <sys/time.h>
    //using namespace std;

    // A sample function whose time taken to
    // be measured
    //void fun()
    //{
    //    for (int i=0; i<10; i++)
    //    {
    //    }
    //}

    //int main()
    //{
        /* The function gettimeofday() can get the time as
           well as timezone.
           int gettimeofday(struct timeval *tv, struct timezone *tz);
          The tv argument is a struct timeval and gives the
          number of seconds and micro seconds since the Epoch.
          //struct timeval {
                   //time_t      tv_sec;     // seconds
                   //suseconds_t tv_usec;    // microseconds
               //};    */
        //struct timeval start, end;

        // start timer.
        //gettimeofday(&start, NULL);

        // unsync the I/O of C and C++.


        //fun();

        // stop timer.
        //gettimeofday(&end, NULL);

        // Calculating total time taken by the program.
        //double time_taken;

        //time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        //time_taken = (time_taken + (end.tv_usec -start.tv_usec)) * 1e-6;

    //    return 0;
    //}
