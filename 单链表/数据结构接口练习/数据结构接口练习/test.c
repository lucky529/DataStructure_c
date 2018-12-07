#include"test.h"
int main()
{
	SeqList s;
	SeqListInit(&s, 2);
	SeqListPushBack(&s,1);//Œ≤≤Â
	SeqListPushBack(&s,1);
	SeqListPushBack(&s,9);
	SeqListPushBack(&s,2);
	SeqListPushBack(&s,4);
	SeqListPushBack(&s,6);
	SeqListPushBack(&s,5);
    SeqListprintf(&s);
	SeqListPopBack(&s);//Œ≤…æ
	SeqListprintf(&s);
	SeqListPushFront(&s,2);//Õ∑≤Â
	SeqListprintf(&s);
	SeqListPopFront(&s);
	SeqListprintf(&s);
	SeqListInsert(&s,0,6);//≤Â»Î
    SeqListprintf(&s);
	SeqListErase(&s,0);
	SeqListprintf(&s);
	SeqListFind(&s,1);
	printf("%d\n",SeqListFind(&s,1));
	SeqListModify(&s,0,66);//–ﬁ∏ƒÀ≥–Ú±Ì
	SeqListprintf(&s);
	SeqListBubbleSort(&s);
	SeqListprintf(&s);
	SeqListBinaryFind(&s,9);
	printf("%d\n",SeqListBinaryFind(&s,9));
	SeqListRemoveAll(&s,1);
    SeqListprintf(&s);
	SeqListDestory(&s);
	return 0;
}
