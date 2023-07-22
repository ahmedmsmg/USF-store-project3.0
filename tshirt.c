//including Header files
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"tshirt.h"
#include"read_line.h"


//Help function that is executed inside the main function
void help() {
printf("List of operation codes:\n");
printf("\t'a' for adding a t-shirt to the inventory;\n");
printf("\t'h' for help;\n");
printf("\t'o' for searching t-shirts by organization;\n");
printf("\t's' for searching t-shirts by size;\n");
printf("\t'p' for printing the inventory;\n");
printf("\t'q' for quit.\n");
}

struct tshirt * add_to_inventory(struct tshirt *inventory) {

//creating linkedlists

struct tshirt *new_tshirt;
  new_tshirt=malloc(sizeof(struct tshirt));
struct tshirt *temp;
struct tshirt *prev;

//taking inputs from user
printf("Enter Org name: ");
read_line(new_tshirt->org_name,ORG_NAME_LEN+1);

printf("Enter tshirt size: ");
read_line(new_tshirt->size,SIZE_LEN+1);

    printf("Enter price \n ");
        scanf("%lf",&new_tshirt->price);
        printf("Enter Quantity \n ");
        scanf("%d",&new_tshirt->quantity);

prev=inventory;
temp=NULL;

//while statement to go over the list to check if the shirt exists or no
//strcmp is used to sort the list
while(prev!=NULL)
        {
            if(strcmp(prev->org_name,new_tshirt->org_name)>0){
                break;
            }

            if(strcmp(prev->org_name,new_tshirt->org_name)==0)
            {

            if(strcmp(prev->size,new_tshirt->size)>0){

            break;

            
                printf(" this t-shirt already exists\n");
         
                return inventory;
                
            }
            }
            temp=prev;
            prev=prev->next;

        }

      

        new_tshirt->next=prev;

        if(temp==NULL)
        return new_tshirt;
        else{
            temp->next=new_tshirt;
            return inventory;

        }
}
void search_by_organization(struct tshirt *inventory) {

//creating a linked list
struct tshirt *p = inventory;
char word[ORG_NAME_LEN+1];

printf("Enter Org name: ");
read_line(word,ORG_NAME_LEN+1);
int flag = 0;

//while statement to check if the item exists or no
while(p != NULL) {
	if(strcmp(p->org_name, word)==0) {
		printf("A tshirt of this %s organization exists.\n",word);
		if(flag == 1){

                printf("|----------------------------------------------------|-----|-------|------|\n");
                printf("| Student organization | Sz. | Price | Qty. |\n");
                printf("|----------------------------------------------------|-----|-------|------|\n");
                printf("| %-50s | %-3s | %5.2f | %4d |\n",p->org_name, p->size, p->price, p->quantity);
                printf("|----------------------------------------------------|-----|-------|------|\n");
                return;
        }
            p = p->next;
    }
	 if(flag == 0)
                printf("t-shirt not found!");

}
  }
void search_by_size(struct tshirt *inventory) {

    
    struct tshirt *temp = inventory;
    char word[SIZE_LEN+1];
    printf("Enter T-shirt size: ");
    read_line(word,SIZE_LEN+1);
    int flag = 0;
    while(temp!=NULL)
    { 
      
      flag=1;
//cheching if the size exists or not
        if(strcmp(temp->size,word)==0)
        {
            printf("tshirt of size : %s, exists.\n",word);
            printf("T-shirt details\n");
	    
	    if(flag ==1){}
 
            printf("|----------------------------------------------------|-----|-------|------|\n");
            printf("| Student organization | Sz. | Price | Qty. |\n");
            printf("|----------------------------------------------------|-----|-------|------|\n");
            printf("| %-50s | %-3s | %5.2f | %4d |\n",temp-> org_name,temp-> size, temp->price,temp-> quantity);
            printf("|----------------------------------------------------|-----|-------|------|\n");
        }
        
	temp = temp->next;
            

	if(flag == 0){
		printf("t-shirt not found!");
    }
      }
}
void print_inventory(struct tshirt *inventory) {

struct tshirt *temp = inventory;

//Going over every item in the linked list
while(temp!=NULL) {

	char org[ORG_NAME_LEN+1];
	strcpy(org, temp->org_name);

	char size[SIZE_LEN+1];
	strcpy(size,temp->size);

	double price = temp->price;
	int quantity = temp->quantity;
	temp = temp->next;

printf("|----------------------------------------------------|-----|-------|------|\n");
printf("| Student organization                               | Sz. | Price | Qty. |\n");
printf("|----------------------------------------------------|-----|-------|------|\n");
printf("| %-50s | %-3s | %5.2f | %4d |\n", org, size, price, quantity);
printf("|----------------------------------------------------|-----|-------|------|\n");
}
	if(inventory == NULL){
              printf("No t-shirt found!");
}

}
void clear_inventory(struct tshirt *inventory) {
struct tshirt *temp=inventory;
  while(temp!= NULL)
  {
      struct tshirt *done = temp;
      temp = temp->next;
      if( temp!= NULL)
           free(done);
  }
}
