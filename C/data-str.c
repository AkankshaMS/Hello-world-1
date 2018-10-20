// Stack of Objects
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int id;
    char name[20];
    int sem;
    struct node *next;
};
typedef struct node *NODEPTR
NODEPTR list = NULL;
NODEPTR getnode()
{
    NODEPTR r;
    r = (NODEPTR)malloc(sizeof(struct node));
    if(r==NULL)
    {
        printf("Node allocation failed \n");
        exit(1);
    }
    return r;
}
NODEPTR place(int sid, char sname[], int ssem)
{
    NODEPTR p,q,r;
    r = getnode();
    r->id = sid;
    strcpy(r->name,sname);
    r->sem = ssem;
    r->next = NULL;
    q=NULL;
    for(p=list;p!=NULL&&strcmp(sname,p->name)>0;p=p->next)
        q=p;
    if(q==NULL)
    {
        r->next = list;
        list = r;
    }
    else
    {
        r->next=q->next;
        q->next = r;
    }
}
void deleteitem(char sname[])
{
    NODEPTR p,q;
    p=list;
    q=NULL;
    if(list==NULL)
    {
        printf("Empty list\n");
        return;
    }
    if(strcmp(p->name,sname)==0)
    {
        list = p->next;
        free(p);
        printf("Student %s deleted\n",sname);
        return;
    }
    else
    {
        for(p=list;p!=NULL&&strcmp(p->name,sname)<0;p=p->next)
            q=p;
        if(p==NULL)
        {
            printf("Student name %s not found in the list\n",sname);
            return;
        }
        else
        {
            q->next = p->next;
            printf("Student name %s is deleted\n",sname);
            free(p);
        }
    }
}
