#include"apc.h"

//for subtracting the data perform subtraction
int subtraction(Dlist** head1, Dlist** tail1, Dlist** head2, Dlist** tail2, Dlist** headR, Dlist** tailR) 
{
    Dlist* temp1 = *tail1;
    Dlist* temp2 = *tail2;
    int res;
    int borrow = 0;
    int negative = 0; // flag for negative result

    // Determine if result should be negative using length
    int len1 = 0, len2 = 0;
    Dlist* temp3 = *head1;
    Dlist* temp4 = *head2;

    while(temp3)
    { 
        len1++; 
        temp3 = temp3->next; 
    }
    
    while(temp4) 
    { 
        len2++; 
        temp4 = temp4->next; 
    }

    if (len1 < len2) 
    {
        negative = 1;
    }
    else if (len1 == len2) 
    {
        // Compare digit by digit if lengths equal
        temp3 = *head1; temp4 = *head2;
        while (temp3 && temp4) 
        {
            if (temp3->data < temp4->data) 
            {   
                negative = 1; 
                break; 
            }
            else if (temp3->data > temp4->data) 
            { 
                negative = 0; 
                break; 
            }
            temp3 = temp3->next;
            temp4 = temp4->next;
        }
    }

    // Swap operands if negative so we always subtract smaller from larger
    if (negative) 
    {
        temp1 = *tail2;
        temp2 = *tail1;
    }

    while (temp1 || temp2) 
    {
        int a1 = (temp1) ? temp1->data : 0;
        int a2 = (temp2) ? temp2->data : 0;

        res = a1 - a2 - borrow;

        if (res < 0) 
        {
            res = res + 10;
            borrow = 1;
        } else 
        {
            borrow = 0;
        }

        insert_at_first(headR, tailR, res);

        if (temp1) temp1 = temp1->prev;
        if (temp2) temp2 = temp2->prev;
    }


    // Remove leading zeros
    while (*headR && (*headR)->data == 0 && (*headR)->next) 
    {
        Dlist* tmp = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(tmp);
    }
    
    // Prepend negative marker if result is negative
    if (negative) 
    {
        Dlist* negNode = malloc(sizeof(Dlist));
        negNode->data = -1; // negative marker
        negNode->prev = NULL;
        negNode->next = *headR;
        if (*headR) (*headR)->prev = negNode;
        *headR = negNode;
    }
    return SUCCESS;
}