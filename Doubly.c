#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct ELE
{
int data, id;
struct ELE *prev;
struct ELE *next;
} list_ele, *list_ptr;

void delete(int);
int insert(int);
void display();
void show(char *,list_ptr);
list_ptr new();


list_ele a[SIZE];
list_ptr head;
list_ptr tail;
list_ptr root;

int main(){
printf("I - Insert\nD - Delete\nP - Print\nQ - Quit\n");
printf("Enter the the command (I,D,P or Q):\n");
char input[50];
   while(input[0]!='Q'){
        printf("\nC > ");
        gets(input);
    if(input[0]=='D'){
        int data;
        printf("Enter value: ");
        scanf ("%d",&data);
        delete(data);
    }
    else if(input[0]=='I'){
        int data;
        printf("Enter value: ");
        scanf ("%d",&data);
        insert(data);
    }
    else if(input[0]=='P'){
            show("head\n",head);
    }
    else if(input[0]=='Q'){
       exit(0);
    }
   }
return 0;
}

list_ptr new() {

}
void show(char *c,list_ptr point){
 
    if(point == NULL)
    {
        printf("List is Empty \n");
        return 0;
    }
    
    printf("List: \n");
    while(point != NULL)
    {
        printf("id %d: %d", point->id, point->data);
        point = point->next;
    }
    printf("\n");

}
void delete(int data)
{
  list_ptr tmp = root;
  //If the node to be deleted is the head node
  if (tmp->data == data)
    {
     //Change the root pointer
      root = tmp->next;
    }
  else {
    while (tmp != NULL & tmp->data != data)
      {
    tmp = tmp->next;
      };
    tmp->prev->next = tmp->next;
  }
}

int insert(int data){

    list_ptr tmp = root;

    if(tmp->data == NULL)
    {
      root->data = data;
    }
    else if(head->data > data)
    {
      root->data = data;
      root->next = tmp;
      tmp->prev = root;
    }

    else if(tail->data < data)
    {
      tmp->data = tail->data;
      tmp->prev = tail->prev;
      tail->prev->next = tmp;
      tail->data = data;
      tail->prev = tmp;
    }
    else{

        while(tmp->next!= NULL){
            if(tmp->data< data & tmp->next->data > data)
            {
                list_ptr in;
                in->data =data;
                in->prev =tmp;
                in->next =tmp->next;
                tmp->next->prev = in;
                tmp->next = in;
            }
        }

    }
return 0;
}

