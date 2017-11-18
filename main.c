#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    char t;
    struct data *next,*prev;
}txt;

txt *head=NULL,*tail=NULL,*themp,*baru,*ptt;
int w=0;

void header()
{
    system("cls");
    fflush(stdin);
    printf("\t\t|PROGRAM EDIT TEXT|\n");
    printf("\t\t|_________________|\n\n");
}

void add()
{
        baru = (txt*) malloc(sizeof(txt));
        printf("\nMasukan 1 charakter\nAdd  : ");
        fflush(stdin);
        scanf("%c",&baru->t);
    if (head==NULL)
    {
        head=baru;
        tail=baru;
        themp=head;
        head->next=NULL;
        head->prev=NULL;
    }
    else if (themp->next==NULL)
    {
        themp->next=baru;
        tail=baru;
        baru->prev=themp;
        themp=baru;
        tail->next=NULL;
    }
    else if (themp->prev==NULL)
    {
        baru->next=themp->next;
        baru->prev=themp;
        baru->next->prev=baru;
        themp->next=baru;
        themp=themp->next;
    }
    else
    {
        baru->next = themp->next;
        baru->prev = themp;
        themp->next=baru;
        baru->next->prev=baru;
        themp=themp->next;
    }
}
void del()
{
   if(themp==head&&themp==tail)
   {
       free(themp);
       head=NULL;
       tail=NULL;
       themp=NULL;
   }
   else if(themp==head)
   {
       themp=themp->next;
       themp->prev=NULL;
       free(head);
       head=themp;
   }
   else if(themp==tail)
   {
       themp=themp->prev;
       themp->next=NULL;
       free(tail);
       tail=themp;
   }
   else
   {
       baru=themp->next;
       themp=themp->prev;
       themp->next=baru;
       free(baru->prev);
       baru->prev=themp;
   }
    printf("\n\nData Berhasil di hapus\n");
    system("pause");
}



void print()
{
    ptt=head;
    printf("\nTampil : ");
    if(head!=tail)
    {
         while(ptt!=NULL)
        {
            printf("%c",ptt->t);
            ptt=ptt->next;
        }
    }
    else if(head!=NULL) printf("%c",ptt->t);
    printf("\n");
   system("pause");
}

void Sright()
{
    if(themp->next==NULL)
    {
        printf("pointer sudah paling kanan");
        w=1;
    }
    else
    {
        printf("pointer tergeser ke kanan");
        themp=themp->next;
    }
    printf("\n");
    system("pause");
}

void Sleft()
{
    if(themp->prev==NULL)
    {
        printf("pointer sudah paling kiri");
        w=1;
    }
    else
    {
        printf("pointer tergeser ke kiri");
        themp=themp->prev;
    }
    printf("\n");
    system("pause");
}

int main()
{
   int pil,z,v;
    menu: system("cls");
    header();
    printf("input banyak perulagan :");
    scanf("%d", &z);
    for(v=0;v<z;v++)
    {
        system("cls");
        header();
        printf("Menu : \nTotal(%d)\n",v+1);
        printf("1) Print\n2) Add data\n3) Del data\n4) S-right\n5) S-left\nPilihan :");
        scanf("%d",&pil);
        switch(pil)
        {
            case 1 : print(); break;
            case 2 : add(); break;
            case 3 : del(); break;
            case 4 : Sright(); if(w==1)v--; break;
            case 5 : Sleft(); if(w==1)v--; break;
            default: main();
        }
    }
    return 0;
}
