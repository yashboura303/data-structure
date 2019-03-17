#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>

void sleep(unsigned int);
void screen(void);

struct node
{
    int number;
    char name[20] ;
    int days;
	int room_no;
	struct node *next;
};

struct node *start=NULL;
struct node *create(struct node *);
struct node *search(struct node *);
struct node *display(struct node *);
struct node *sort_list(struct node *);
struct node *delete_node(struct node *);
int main()
{

   printf("\n\t\t\t\t****************************");
   printf("\n\t\t\t\t* HOTEL MANAGEMENT PROJECT *");
   printf("\n\t\t\t\t****************************");
    sleep(1000);
    printf("\n\n\n\n\t\tMade By:");
    sleep(1000);
    printf(" YASH && VISHAL");
    sleep(1000);
    printf("\n\n\n\n\n\t\t\t\tWELCOME!!");
    //getch();
    screen();
    //getch();
	return 0;
}
void screen()
{
    int choice;

    do
    {


        printf("\n\t\t\t\t\t\t*****************");
        printf("\n\t\t\t\t\t\t* Ritz-Carlton *");
        printf("\n\t\t\t\t\t\t*****************");
        printf("\n\n\n\t\t\t\t\t1.Book A Room");
        printf("\n\t\t\t\t\t2. Show Customer Record");
        printf("\n\t\t\t\t\t3. Search in the record ");
        printf("\n\t\t\t\t\t4.Sort Record according to Room Number");
        printf("\n\t\t\t\t\t5.Delete a record");
        printf("\n\t\t\t\t\t6.Exit");
        printf("\n\n\t\t\t\t\tEnter Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
		{
			case 1: start=create(start);
				break;
			case 2: start=display(start);
				break;
			case 3: start=search(start);
				break;
            case 4: start=sort_list(start);
				break;
            case 5: start=delete_node(start);
				break;
    }
    } while(choice!=6);


}
void sleep( unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (
           goal > clock()
           );
}
struct node *create (struct  node *start )
{

   struct node *new_node, *ptr;
int days,number,i,n,room_no;
char name[20];
int j=1;
printf("Enter the number of rooms to book\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
new_node = (struct node*)malloc(sizeof(struct node));
printf("Enter details of Customer Number--->>%d\n\n",j);
printf("Enter details for room \n");
printf(" Enter number of days of staying-\n");
		scanf("%d",&days);
printf("  Enter Customer Name-\n");
		scanf("%s",new_node->name);
printf(" Enter Customer Contact Number-\n");
		scanf("%d",&number);
printf(" Enter the Room Number-");
	scanf("%d",&room_no);
	j++;

new_node->number=number;
new_node->days=days;
new_node->room_no=room_no;
if(start==NULL)
{
new_node -> next = NULL;
start = new_node;
}
else
{
ptr=start;
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next = new_node;
new_node->next=NULL;
}
}
return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    int i=1;
	ptr=start;
	if(start==NULL)
	{
        		printf("The hotel record is empty is empty!\n");
	}
	else
	{
    		printf("The Booked list is:\n");
    		while(ptr!=NULL)
		{

        			printf("%d.|Room no.-%d|\t| Name of customer- %s |\t| contact no.- %d|\n",i,ptr->room_no,ptr->name,ptr->number);
			ptr=ptr->next;
			i++;
    		}
    	}
	return start;
}
struct node *search(struct node *start)
{
    char name[20]; int room_no;
	struct node *ptr;
	int val,flag,c=0;
	printf("Enter the name of customer to search:\n ");
scanf("%s",name);
	ptr=start;
	while(ptr!=NULL)
	{
		if(strcmp(ptr->name,name) == 0)
		{
			flag=1;
			c++;
			break;
		}
		else
		{
			flag=0;
			c++;
		}
			ptr=ptr->next;
	}
	if(flag==1)
	{
		printf("Customer registered at room no. %d as per directory!\n",ptr->room_no);
	}
	else
	{
		printf("Record does not exist!\n");
	}
	return start;
}
struct node *sort_list(struct node *start)
{
struct node *ptr1, *ptr2;
int temp;
ptr1 = start;
while(ptr1 -> next != NULL)
{
ptr2 = ptr1 -> next;
while(ptr2 != NULL)
{
if(ptr1 ->room_no > ptr1->next->room_no)
{
temp = ptr1 -> room_no;
ptr1 -> room_no = ptr2 -> room_no;
ptr2 -> room_no = temp;
}
ptr2 = ptr2 -> next;
}
ptr1 = ptr1 -> next;
}


return start;
}
struct node *delete_node(struct node *start)
{
struct node *ptr, *preptr;
int val;
char name[20];
printf("\n Enter the name of the customer in record which has to be deleted : ");
scanf("%s", name);
ptr = start;
if( strcmp(ptr->name,name) == 0)
{
start = start -> next;
free(ptr);
return start;
printf("Record deleted\n");
}
else
{
while(strcmp(ptr->name,name) != 0)
{
preptr = ptr;
ptr = ptr -> next;
}
preptr -> next = ptr -> next;
free(ptr);
printf("Record deleted\n");
return start;
}
}

