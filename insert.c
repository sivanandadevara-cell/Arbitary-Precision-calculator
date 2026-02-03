#include "apc.h"

// This function is used for storing the result
int insert_at_first(Dlist **headR, Dlist **tailR, int data)
{
  // allocating memory for new node
  Dlist *new = malloc(sizeof(Dlist));
  if (new == NULL)
  {
    printf(RED"Error:Memory allocation is failed\n"RESET);
    return FAILURE;
  }
  new->prev = NULL;
  new->data = data;
  new->next = *headR;
  // if tail and head both are null then store as new
  if (*headR == NULL)
  {
    *headR = *tailR = new;
  }

  else
  {
    (*headR)->prev = new;
    *headR = new;
  }
  return SUCCESS;
}

// This function is used for storing the data
int insert_at_last(Dlist **head, Dlist **tail, int data)
{
  // allocation memory for new node
  Dlist *new = malloc(sizeof(Dlist));
  if (new == NULL)
  {
    printf(RED"Memory allocation is failed\n"RESET);
    return FAILURE;
  }

  new->prev = *tail;
  new->data = data;
  new->next = NULL;
  // both head and tail are null then store new
  if (*head == NULL)
  {
    *head = *tail = new;
  }
  else
  {
    (*tail)->next = new;
    *tail = new;
  }
  return SUCCESS;
}

// Function to convert string digits into a doubly linked list
int digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[])
{
  char *str1 = argv[1];
  char *str2 = argv[3];

  // First number
  for (int i = 0; str1[i] != '\0'; i++)
  {
    if (str1[i] >= '0' && str1[i] <= '9')
    {
      int n1 = str1[i] - '0';
      if (insert_at_last(head1, tail1, n1) == FAILURE)
      {
        printf(RED"insert at last function is failed\n"RESET);
        return FAILURE;
      }
    }
  }
  printf(MAGENTA"List 1: "RESET);
  print_list(*head1);

  // Second number
  for (int j = 0; str2[j] != '\0'; j++)
  {
    if (str2[j] >= '0' && str2[j] <= '9')
    {
      int n2 = str2[j] - '0';
      if (insert_at_last(head2, tail2, n2) == FAILURE)
      {
        printf(RED"insert at last function is failed\n"RESET);
        return FAILURE;
      }
    }
  }
  printf(CYAN"List 2: "RESET);
  print_list(*head2);

  return SUCCESS;
}

// printing the result..
void print_list(Dlist *head)
{
  if (head == NULL)
  {
    printf(RED"Info:list is empty\n"RESET);
  }

  // Negative marker
  if (head->data == -1)
  {
    printf("-");
    head = head->next;
  }
  while (head)
  {
    printf("%d", head->data);
    head = head->next;
  }
  printf("\n");
}

// remove zeros at first
void delete_zeroes_present_at_first(Dlist **headR)
{
  if (!*headR)
  {
    return;
  }
  Dlist *temp;
  while ((*headR)->data == 0 && (*headR)->next != NULL)
  {
    temp = *headR;
    *headR = temp->next;
    (*headR)->prev = NULL;
    free(temp);
  }
}

// free the lists
int delete_list(Dlist **head, Dlist **tail)
{
  if (*head==NULL || head==NULL)
  {
    return FAILURE;
  }
  Dlist *temp = *head;
  while (temp)
  {
    Dlist *next = temp->next;
    free(temp);
    temp = next;
  }
  *head = *tail = NULL;
  return SUCCESS;
}

// Returns:
//  1 if list1 > list2
//  0 if list1 == list2
// -1 if list1 < list2
int compare_lists(Dlist *head1, Dlist *head2)
{
  // Step 1: Calculate lengths
  int len1 = 0, len2 = 0;
  Dlist *temp1 = head1, *temp2 = head2;
   
  while (temp1)
  {
    len1++;
    temp1 = temp1->next;
  }
  while (temp2)
  {
    len2++;
    temp2 = temp2->next;
  }
  if (len1 > len2)  return 1;
  if (len1 < len2) return -1;

  // Step 2: Lengths are equal, compare digit by digit
  while (head1 && head2)
  {
    if (head1->data > head2->data) return 1;
    if (head1->data < head2->data) return -1;
    head1 = head1->next;
    head2 = head2->next;
  }
  return 0;
}

// Function to check if a linked list represents 0
int isZero(Dlist *head)
{
  // If list is empty, treat it as zero
  if (head == NULL)
  {
    return 1;
  }

  // Traverse the list and check if all digits are zero
  while (head) 
  {
    if (head->data != 0)
    {
      return 0;  // Not zero
    }
    head = head->next;
  }

  return 1;  // All digits were zero
}
