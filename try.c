#include <conio.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <math.h>
#include<ctype.h>
struct details
{
    char vno[20];
    char name[20];
    char bgrp[5];
    int myno;
    int eno;

}d[20];

struct node
{
    struct details* data;
    struct node* next;
};
struct node *head=NULL;

void Insert(struct details* x)
{
    struct node *newnode;
    struct node *temp;
    temp=head;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        temp=head;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        temp=newnode;
    }
}
void searching(char v[])
{
    struct node* temp;
    temp=head;
    while(temp!=NULL)
    {
        if(strcmp(temp->data->vno,v)==0)
        {
            FILE *fp2;
            fp2=fopen("accident.txt","w+");
            printf("Message has been sent to %d",temp->data->eno);
            fprintf(fp2,"NAME : %s\nMOBILE NO : %d\nVECHILE NO : %s\nHAS MET WITH AN ACCIDENT",temp->data->name,temp->data->myno,temp->data->vno);
            fclose(fp2);
            printf("\nopen accident.txt");
            return;
        }
        temp=temp->next;
    }
    printf("not found");
}
void display()
{
    struct node *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("empty");
    }
    while(temp!=NULL)
    {
        printf("%s ->",temp->data->vno);
        temp=temp->next;
    }
    printf("NULL");
}
int main()
{
    int row;
    int i;
    char v[20];
    FILE* fp = fopen("acc.csv", "r");
    if (!fp)
    {
        printf("Can't open file\n");
    }
    else
    {
        char buffer[8000];
        row = 0;
        int column = 0;
        while (fgets(buffer,8000, fp)) {
            column = 0;
            row++;
            if (row == 1)
                continue;
            char* value = strtok(buffer, ", ");
            i = row - 2;
            while (value) {
                if (column == 0) {
                    strcpy(d[i].name, value);
                }
                if (column == 1) {
                    strcpy(d[i].bgrp, value);

                }
                if (column == 2) {
                    d[i].myno=atoi(value);

                }
                if(column==3)
                {
                    d[i].eno=atoi(value);
                }
                if(column==4)
                {
                    strcpy(d[i].vno,value);
                }
                value = strtok(NULL, ", ");
                column++;

            }
        }
        fclose(fp);
    }
    for(i=0;i<row-1;i++)
    {
        Insert(&d[i]);
    }
    printf("enter vno.:");
    scanf(" %s",v);
    searching(v);
    return 0;
}
