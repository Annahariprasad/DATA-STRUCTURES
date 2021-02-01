void append()
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter node data :");
	scanf("%d",&temp->data);
	temp->link= NULL;
	if(root == NULL)
	{
		root = temp;
	}
	else 
	{
		struct node* p;
		p = root;
		while(p->link != NULL)
		{
			p = p->link;
		}
		p->link = temp;
	}
}

void addatbegin()
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter node data \n:");
	scanf("%d",&temp->data);
	temp->link= NULL;
	if(root == NULL)
	{
		root = temp;
	}
	else 
	{
		temp->link = root;
		root = temp;
	}
}


int length()
{
	int count = 0;
	struct node* temp;
	temp = root;
	while(temp != NULL)
	{
		count++;
		temp = temp->link;
	}
	return count;
}


void addatposition()
{
	struct node* temp ,*p ;
	int loc ,len, i = 1 ;
	printf("Enter positon.\n :");
	scanf("%d",&loc);
	len = length();
	if(loc>len)
	{
	printf("invalid positon \n");
	printf("Currently list haVing %d nodes ",len);
    }
    else
    {
    	p = root;
    	while (i<loc)
    	{
    		p = p->link;
    		i++;
		}
		temp = (struct node*)malloc(sizeof(struct node));
			printf("Enter node data :");
          	scanf("%d",&temp->data);
          	temp->link = p->link;
          	p->link = temp;
	}
}


void display()
{
	struct node* temp;
	temp = root;
	if(temp == NULL)
	{
		printf("No nodes in the SLL ..\n");
	}
	else
	{
		while(temp != NULL)
		{
			printf("%d\n",temp->data);
			temp = temp->link;
		}
	}
}
void  reversingnodes()
{
	int i,j,len,temp;
	struct node *p,*q;
	len = length();
	i = 0;
	j=len -1;
	p = q=root;
	while(i<j)
	{
		int k=0;
		while(k<j)
		{
			q=q->link;
			k++;
		}
		temp = p->data;
		p->data=q->data;
		q->data=temp;
		i++;
		j--;
		p=p->link;
		q=root;
	}
}

void delete()
{
	struct node* temp;
	int loc,len;
	printf("Enter location to delete :");
	scanf("%d",&loc);
	len=length();
	if(loc>len)
	{
		printf("Invalid location\n");
	}
	else if (loc==1)
	{
		temp = root;
		root = temp->link;
		temp->link=NULL;
		free(temp);
	}
	else 
	{
		struct node* p=root,*q;
		int i = 1;
		while(i<loc-1)
		{
			p = p->link;
			i++;
		}
		q=p->link;
		p->link= q->link;
		q->link=NULL;
		free(q);
	}
	
}
