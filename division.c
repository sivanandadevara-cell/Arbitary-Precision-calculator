#include "apc.h"

//Dividing the data..using the division function
int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR)
{
    int div=0;
    //Repeat subtraction until dividend < divisor
    while(compare_lists(*head1,*head2)!=-1)
    {
        subtraction(head1,tail1,head2,tail2,headR,tailR);
        div++;

        //Repeat the dividend with result..
        delete_list(head1,tail1);
        *head1=*headR;
        *tail1=*tailR;

        //Reset result list..
        *headR=NULL;
        *tailR=NULL;
    }  
    
    //store the result in quotient
    insert_at_first(headR,tailR,div);
    return SUCCESS;

}


