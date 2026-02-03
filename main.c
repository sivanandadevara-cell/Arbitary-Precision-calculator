/*
Name:D SIVANANDA KUMAR
Reg no:25017_071
Project tile:Arbitrary Precision Calculator
Description: Arbitrary precision Caluclator sometimes infinite-precision arithmetic, indicates that calculations are performed on numbers
			whose digits of precision are limited only by the available memory of the host system.This
			contrasts with the faster fixed-precision arithmetic found in most arithmetic logic unit (ALU)
			hardware, which typically offers between 8 and 64 bits of precision.
Sample input: 9900 1100 1234 9999 + 0012 0100 0023 9999
Sample output:9912 1200 1257 9998
*/

#include "apc.h"


int main(int argc, char *argv[])
{

	/* Declare the pointers */
	Dlist *head1=NULL,*tail1=NULL;
	Dlist *head2=NULL,*tail2=NULL;
	Dlist *headR=NULL,*tailR=NULL;
 
	// validation of argument count i.e, argc must be equal to 4
    if (read_and_validate_args(argv) == FAILURE)
    {
        printf(RED"Error: Invalid arguments. Format: ./a.out <op1> <op> <op2>\n"RESET);
        return FAILURE;
    }
    printf(GREEN"Validation of the Arguments Successful\n"RESET);


	char option;
    char operator=argv[2][0];

	switch(operator)
	{
		case '+':
				printf(BLUE"You are performing Addition Operation\n"RESET);
 
				//Function to convert string digits into a doubly linked list 
                digit_to_list(&head1,&tail1,&head2,&tail2,argv);

				// perform addition
				addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			
				printf(GREEN"Result:"RESET);
				print_list(headR);
		        break;
		case '-':
			    printf(YELLOW"You are performing subtraction Operation\n"RESET);

				//Function to convert string digits into a doubly linked list
                digit_to_list(&head1,&tail1,&head2,&tail2,argv);
					
				// perform subtraction
				subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				
				printf(GREEN"Result:"RESET);
				print_list(headR);
			    break;
		case 'x':
                printf(MAGENTA"You are performing Multiplication Operation\n"RESET);

				//Function to convert string digits into a doubly linked list
                digit_to_list(&head1,&tail1,&head2,&tail2,argv);

		        //perform multiplication
                multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR);

				printf(GREEN"Result:"RESET);
				print_list(headR);
			    break;
		case '/':
		        printf(CYAN"You are performing Division Operation\n"RESET);
				if (isZero(head2))
                {
					printf(RED"Error: Division by zero is not allowed.\n"RESET);
					return FAILURE;
                }

			
				//Function to convert string digits into a doubly linked list
                digit_to_list(&head1,&tail1,&head2,&tail2,argv);

		        //perform division
                division(&head1,&tail1,&head2,&tail2,&headR,&tailR);

				printf(GREEN"Result:"RESET);
				print_list(headR);
			    break;
	    default :
            printf(RED"Invalid Input:-( Try again...\n"RESET);
	}
    return 0;
	
}


//checking the arguments.....
int read_and_validate_args(char *argv[])
{
	// Operand 1
	int i=0;
	if(argv[1] == NULL || argv[1][0] == '\0')
	{
	  return FAILURE;
	}

	for(int i=0;argv[1][i]!='\0';i++)
	{
		if(!is_digit(argv[1][i]))
		return FAILURE;
	}


    // Operand 2
	int j=0;
	if(argv[3] == NULL || argv[3][0] == '\0')
	{
	  return FAILURE;
	}

	for(int j=0;argv[3][j]!='\0';j++)
	{
		if(!is_digit(argv[3][j]))
		return FAILURE;
	}

	// Operator
	if(argv[2] == NULL || strlen(argv[2]) != 1)
	{
	  return FAILURE;
	}

	char op = argv[2][0];
	if(op != '+' && op != '-' && op != 'x' && op != '/')
	{
	  return FAILURE;
	}

	return SUCCESS;
}

// Checking if the Operands passed are digits or not
int is_digit(char c)
{
	if(c >= '0' && c <='9')
	{
	 return 1;
	}
	else
	{
	 return 0;
	}
}