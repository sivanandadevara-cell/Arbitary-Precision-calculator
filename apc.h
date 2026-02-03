#ifndef APC_H
#define APC_H


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 0
#define FAILURE -1

#define RESET       "\033[0m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define YELLOW      "\033[0;33m"
#define BLUE        "\033[0;34m"
#define MAGENTA     "\033[0;35m"
#define CYAN        "\033[0;36m"

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

/* Read and Validate Command Line Arguments*/
int read_and_validate_args(char *argv[]);

/*Checking the argument passed is digit or not*/
int is_digit(char c);

/*checking the function for storing the result*/
int insert_at_first(Dlist **headR, Dlist **tailR, int data);

/*check the function for storing the data*/
int insert_at_last(Dlist **head, Dlist **tail,int data);

/*remove zeros at first*/
void delete_zeroes_present_at_first(Dlist **headR);

/*freeing the list*/
int delete_list(Dlist **head, Dlist **tail);

/*convert the input strings into doubly linked lists*/
int digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[]);

/*printing the result for Addition..*/
void print_list(Dlist *head);

/*Function to check if a linked list represents 0*/
int isZero(Dlist *head);

/*Returns: 1 if list1 > list2 0,if list1 == list2 -1,if list1 < list2*/
int compare_lists(Dlist* head1, Dlist* head2);

/*for adding the data use addition function..*/
int addition(Dlist **head1, Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR, Dlist **tailR);

/*for subtracting the data perform subtraction*/
int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*for Multiply the data..using the multiplication function*/
int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*for Dividing the data..using the division function*/
int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

#endif