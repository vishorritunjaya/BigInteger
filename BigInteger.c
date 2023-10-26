#include<stdio.h>
#include<stdlib.h>

#include"BigInteger.h"

void display(struct BigInteger a)
{
    struct node *temp=a.L;
    while(temp)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}
struct BigInteger initialize(char *s)
{
    struct BigInteger a;
    a.L='\0';
        for(int i=0;s[i];i++)
        {
            insertNode(&a.L,s[i]-48);
        }
        return a;
}
void insertNode(struct node **head, int d)
{
    struct node *newNode= (struct node*)malloc(sizeof(struct node));
    newNode->data=d;
    newNode->next=*head;
    *head=newNode;
}


struct BigInteger add(struct BigInteger a, struct BigInteger b)
{

    struct BigInteger s;
    s.L='\0';
    int carry=0,sum;
    while(a.L||b.L)
    {
        if(a.L)
        {
            sum=a.L->data;
            a.L=a.L->next;
        }
        if(b.L)
        {
            sum+=b.L->data;
            b.L=b.L->next;
        }

        sum+=carry;
        carry=sum/10;

        insertNode(&s.L,sum%10);
    }
    return s;
}

struct BigInteger sub(struct BigInteger a, struct BigInteger b)
{
    struct BigInteger d;
    d.L='\0';
    int borrow=0;
    while(a. L||b.L)
    {
        int diff;
        if(a.L)
        {
            diff=a.L->data;
            a.L=a.L->next;
        }
        else
        {
           diff=0;
        }
        if(b.L)
        {
            diff-=(b.L->data+borrow);
            b.L=b.L->next;
        }else
        {
            diff-=borrow;
        }
        if(diff<0)
        {
            diff+=10;
            borrow=1;
        }else{
        borrow=0;}
        if(diff!=0||borrow)
        {
            insertNode(&d.L, diff);
        }
    }
    return d;
}


struct BigInteger mul(struct BigInteger a,struct BigInteger b)
{
	struct node *ptr=a.L,*qtr=b.L,*temp='\0',*rtr='\0';
	struct BigInteger p;
	p.L='\0';
  	p.length=0;
	int carry=0;
	int l1=a.length;
	int l2=b.length;
	if(l1<l2)
	{
		struct node *temp;
		temp=a.L;
		a.L=b.L;
		b.L=temp;
	}
	reverseLL(&a.L);
	reverseLL(&b.L);
	ptr=a.L;
	qtr=b.L;
	if(qtr!='\0')
	{
		carry=0;
		ptr=a.L;
		while(ptr!='\0')
		{
			struct node *newNode=(struct node *)malloc(sizeof(struct node));
			int multi=((ptr->data)*(qtr->data))+carry;
			newNode->next='\0';
			newNode->data=multi%10;

			carry=multi/10;
			if(p.L=='\0')
			{
				p.L=newNode;
				rtr=p.L;
			}
			else
			{
				rtr->next=newNode;
				rtr=rtr->next;
			}
			ptr=ptr->next;
			p.length++;
		}
		if(carry!=0)
		{
			struct node *newNode=(struct node *)malloc(sizeof(struct node));
			newNode->data=carry;
			newNode->next='\0';
			rtr->next=newNode;
			rtr=rtr->next;
			p.length++;
		}
	}

	qtr=(b.L)->next;
	struct node *wtr=p.L->next,*mtr;

	carry=0;
	int mol;
	while(qtr!='\0')
	{
			ptr=a.L;
			mtr=wtr;
			while(mtr!='\0' && ptr!='\0')
			{
				mol=mtr->data+(ptr->data*qtr->data)+carry;
				mtr->data=mol%10;
				carry=mol/10;
				mtr=mtr->next;
				ptr=ptr->next;

			}
			while(ptr!='\0')
			{
				struct node *newNode=(struct node *)malloc(sizeof(struct node));
				newNode->next='\0';
				mol=(ptr->data*qtr->data)+carry;
				newNode->data=mol%10;
				carry=mol/10;
				rtr->next=newNode;
				rtr=rtr->next;
				ptr=ptr->next;
				p.length++;
			}


		qtr=qtr->next;
		wtr=wtr->next;
	}
		if(carry!=0)
		{
			struct node *newNode=(struct node *)malloc(sizeof(struct node));
			newNode->data=carry;
			newNode->next='\0';
			rtr->next=newNode;
			rtr=rtr->next;
			p.length++;
		}
		reverseLL(&p.L);
	return p;
}
void reverseLL(struct node **start)
{
	struct node *curr,*prev,*next;
	curr=*start;
	prev='\0';
	next='\0';
	while(curr!='\0')
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	*start=prev;
}


struct BigInteger div1(struct BigInteger a, struct BigInteger b)
{
    struct BigInteger r;
    r.L='\0';
    struct BigInteger current=a;

    while (current.L!='\0')
    {
        int q = 0;
        while (compare(current.L,b.L)) {
            current = sub(current,b);
            q++;
        }

        insertNode(&r.L,q);

        if (current.L == '\0')
        {
            break;
        }

        current.L = (current.L)->next;
    }

    return r;
}

int compare(struct node *a, struct node* b)
{
    while (a&&b)
    {
        if (a->data< b->data)
        {
            return -1;
        }
        else if (a->data > b->data)
        {
            return 1;
        }
        a = a->next;
        b = b->next;
    }

    if (a) {
        return 1;
    }
    else if (b) {
        return 0;
    }

    return 1;
}



