#include "apc.h" 

//adding the data..using the addition function
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR)
{
  Dlist *temp1=*tail1;
  Dlist *temp2=*tail2;
  int carry=0;
  int res;

  //checking the temparory variables...
  while(temp1 || temp2)
  {
    //checking the condition for temp is not equal to NULL
    if(temp1!=NULL && temp2!=NULL)
    {
      res=temp1->data+temp2->data+carry;
    }
    //checking the condition for temp2 is not equal and temp1 is equal to NULL 
    else if(temp1==NULL && temp2!=NULL)
    {
      res=0+temp2->data+carry;  
    }
    //checking the another condition is temp1 is not equal and temp2 is equal to NULL
    else if(temp1!=NULL && temp2==NULL)
    {
      res=temp1->data+0+carry;
    }
    //if the result value greater than 9.then take carry
    if(res>9)
    {
      carry=1;
      res=res%10;
    }
    else
    {
      carry=0;
    }
    insert_at_first(headR,tailR,res);
    if(temp1) temp1=temp1->prev;
    if(temp2) temp2=temp2->prev;
  }
  //if carry is one use the function insert at first to storing the result
  if(carry==1)
  {
    insert_at_first(headR,tailR,carry);
  }
  return SUCCESS;
}
