#include"test.h"

void JustDown(HPDataType* a, size_t n, int root)
{
	assert(hp);
	int parent = root;
	int child = parent*2+1;

	while(child < n)
	{
		if(child + 1 < n && a[child + 1] < a[child] ) ++child;
		if(a[child] > a[parent])
		{
			HPDataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;

			parent = child;
			child = parent*2+1;
		}
		else
		{
			break;
		}
	}
}

void HeapInit(Heap* hp, HPDataType* a, int n)
{
	int i = 0;
	assert(hp && a);
	hp ->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp ->_size = hp ->_capacity = n;
	memcpy(hp ->_a  , a , sizeof(HPDataType)*n);

	for(int i = (hp ->_size - 2)/2; i >= 0; i-- )
	{
		JustDown(hp ->_a , hp ->_size ,i);
	}
}

void JustUp(HPDataType* a, size_t n)
{
	int child = n - 1;
	int parent = (n - 2)/2;
	while(parent >= 0)
	{
		if(a[child] > a[parent])
		{
			HPDataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;

			child = parent;
			parent = (child - 1)/2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	CheckCapacity(hp);
	hp ->_a [hp ->_size ] = x;
	++hp ->_size;
	if(hp ->_a[hp ->_size - 1] > hp ->_a[(hp ->_size - 2)/2])
	{
	    JustUp(hp ->_a ,hp ->_size);
	}
}

void CheckCapacity(Heap* hp)//¼ì²é¶ÑµÄÈÝÁ¿
{
	if(hp ->_size == hp ->_capacity )
	{
		hp ->_capacity *= 2;
		hp ->_a = ralloc(hp ->_a ,sizeof(HPDataType)*hp ->_capacity );
	}
}

void HeapPop(Heap* hp)
{
	int i = 0;
	assert(hp);
	HPDataType tmp = hp ->_a[0];
	hp ->_a[0] = hp ->_a[hp ->_size-1];
	hp ->_a[hp ->_size-1] = tmp;
	hp ->_size--; 
	for(int i = (hp ->_size - 2)/2; i >= 0; i-- )
	{
		JustDown(hp ->_a , hp ->_size ,i);
	}
}


void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp ->_a);
	hp ->_a = NULL;
	hp ->_capacity = 0;
	hp ->_size = 0;
}