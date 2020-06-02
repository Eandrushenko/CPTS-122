#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact
{
	char name[100];
	char number[100];
	char email[100];
	char title[100];

}Contact;

typedef struct node
{
	Contact info;
	struct node *pNext;

}Node;


Node* makenode(Contact new_contact);
int insertorder(Node **pHead, Contact newcontact);
