#include"test.h"

void SeqListInit(SeqList* ps, size_t capacity)
{
	assert(ps);	
	ps -> arry = (SqListType*)malloc(sizeof(SqListType)*capacity);
	ps -> capicity = capacity;
	ps -> size = 0;
	CheckCapacity(ps);
}

void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps -> arry);
	ps -> arry = NULL;
	ps -> capicity = 0;
	ps -> size = 0;
}
void CheckCapacity(SeqList* ps)
{
	assert(ps);
	if(ps -> size == ps -> capicity)
	{
		ps -> capicity *= 2;
		ps ->arry = realloc(ps -> arry,sizeof(int)* ps->capicity);
	}
}
void SeqListPushBack(SeqList* ps, SqListType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps ->arry[ps -> size] = x;
	++ps ->size; 
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	if(ps -> size > 0)
	{
		--ps->size; 
	}
}
void SeqListprintf(SeqList* ps)
{
	size_t i = 0;
	assert(ps);
	for(i = 0; i < ps ->size ; i++)
	{
		printf("%d ",ps ->arry[i] );
	}
	printf("\n");
}

void SeqListPushFront(SeqList* ps, SqListType x)
{
	int end = 0;	
	CheckCapacity(ps);
	end = ps -> size - 1; 
	assert(ps);
	while(end >= 0)
	{
		ps -> arry[end + 1] = ps ->arry [end];
		--end;
	}
	ps ->arry[0] = x;
	ps -> size++;
}

void SeqListPopFront(SeqList* ps)
{
	size_t start = 0;
	assert(ps);
	while(start < ps ->size - 1)
	{
		ps ->arry[start] = ps ->arry[start + 1];
		++start;
	}
	ps ->size--;
	
}

void SeqListInsert(SeqList* ps, size_t pos, SqListType x)
{
	int end = 0;
	assert(ps && pos <= ps ->size);
	CheckCapacity(ps);
	end = ps -> size - 1;
	while(end >= (int)pos)
	{
		ps ->arry[end + 1] = ps ->arry[end];
		--end;
	}
	ps ->arry[pos] = x;
	ps ->size++;
	/*end = ps -> size;
	while(end > pos)
	{
		ps ->arry[end] = ps ->arry[end - 1];
		--end;
	}
	ps ->arry[pos] = x;
	ps ->size++;*/
}
void SeqListErase(SeqList* ps, size_t pos)
{
	size_t start = 0;
	assert(ps);
	start = pos;
	while(start <= ps ->size - 1)
	{
		ps -> arry[start] = ps -> arry[start + 1];
		++start;
	}
	ps -> size--; 
}

int SeqListFind(SeqList* ps, SqListType x)
{
	assert(ps);
	if(ps ->size >= 0)
	{
		while(ps ->size - 1)
		{
			if(ps ->arry[ps ->size - 1])
			{
				return ps ->size - 1; 
			}
		}
	}
	else
	{
		return -1;
	}
	return -1;
}
void SeqListModify(SeqList* ps, size_t pos, SqListType x)//ÐÞ¸ÄË³Ðò±í
{
	assert(ps);
	if(pos < ps -> size)
	{
		ps ->arry[pos] = x; 
	}
	return;
}

void SeqListBubbleSort(SeqList* ps)//Ã°ÅÝÅÅÐò
{
	int i = 0;
	int tmp = 0,count = ps ->size;
	assert(ps);
	while(--count)
	{
		for(i = 0; i < (int)ps ->size - 1; i++)
	    {
		    if(ps ->arry[i] > ps ->arry [i+1])
		    {
			    tmp = ps ->arry [i];
			    ps ->arry [i] = ps ->arry [i+1];
			    ps ->arry [i+1] = tmp;
		    }
	    }
	}
}
int SeqListBinaryFind(SeqList* ps, SqListType x)
{
	int start = 0;
	int end = ps ->size;
	int mid = 0;
	while(start < end)
	{
		mid = (start + end)/2;
		if(ps ->arry[mid] == x)
		{
			return mid;
		}
		else if(ps ->arry[mid] > x)
		{
			end = mid;
		}
		else
		{
			start = mid + 1;
		}
	}
	return -1;
}

void SeqListRemoveAll(SeqList* ps, SqListType x)
{
	int i = 0,j = 0;
	assert(ps);
	while(i < (int)ps ->size)
	{
		if(ps->arry[i] != x)
		{
			ps ->arry[j] = ps ->arry[i];
			++j;
		}
		++i;
	}
	ps ->size = j;
}
