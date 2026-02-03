#include"apc.h"

//Multiply the data..using the multiplication function
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    Dlist *headR1 = NULL, *tailR1 = NULL;
    Dlist *headR2 = NULL, *tailR2 = NULL;

    //Initialize result accumulator with 0 
    insert_at_first(&headR2, &tailR2, 0);

    int count = 0,j;

    //Multiply each digit of operand2 with operand1
    while (temp2)
    {
        if (*tail1) temp1 = *tail1;

        //Add positional zeroes (like shifting in manual multiplication)
        for (int i = 0; i < count; i++)
        {
            insert_at_first(&headR1, &tailR1, 0);
        }

        int digit = temp2->data, carry = 0;

        //Multiply operand1 by current digit of operand2 
        while (temp1)
        {
            int res = (temp1->data * digit) + carry;
            carry = res / 10;
            res %= 10;

            insert_at_first(&headR1, &tailR1, res);
            temp1 = temp1->prev;
        }
        // Insert leftover carry 
        if (carry)  
        {
            insert_at_first(&headR1, &tailR1, carry);
        }

        //Add partial result (R1) to accumulator (R2) 
        addition(&headR1, &tailR1, &headR2, &tailR2, headR, tailR);

        //Free temporary lists 
        delete_list(&headR1, &tailR1);
        delete_list(&headR2, &tailR2);

        //Update accumulator 
        headR2 = *headR;
        tailR2 = *tailR;

        //Reset current result list 
        *headR = NULL;
        *tailR = NULL;

        temp2 = temp2->prev;
        count++;
    }

    //Final result in headR2/tailR2 
    *headR = headR2;
    *tailR = tailR2;

    delete_zeroes_present_at_first(headR);

    return SUCCESS;
}
