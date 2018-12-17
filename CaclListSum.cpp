#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode {
     int val;
     struct ListNode *next;
}Node;

struct ListNode *Head  = NULL;

/*打印*/
void printList()
{
    printf("Begin print...\n");
    if (NULL == Head || NULL == Head->next)
    {
        printf("List is null.");
        return;  
    }
    //~ Node* p = (Node*)malloc(sizeof(Node)); 
	Node*  p = Head->next;
    while (p->next)
    {
        printf("%d->",p->val);
        p = p->next;
    }
    printf("%d\n", p->val);
    printf("End print.\n");
}


void InsertNode(int val)
{
	if(NULL == Head)return;
	Node *p = Head;
	while(p->next){
		p = p->next;
	}
	Node *tmp = (struct ListNode*)malloc(sizeof(ListNode));
	tmp->val = val;
	tmp->next = NULL;
	p->next = tmp;
	//~ printf("tmp:%d|p:%d\n",tmp->val,p->val);
	//~ printf("Head:%d|Head->next:%d\n",Head->val,Head->next->val);
} 
 
 
struct ListNode* addTwoNumbers(struct ListNode* L1,struct ListNode* L2) {
	//Init Head
    Head = (struct ListNode*)malloc(sizeof(ListNode));
    Head->next = NULL;
    
    int nSumL1 = 0,nSumL2 = 0 ,nSumL3 = 0;
    for(int i = 1;;L1 = L1->next,i = i*10){
		nSumL1 +=  (L1->val * i);
		if(L1->next == NULL)break;
	}
	for(int j = 1;;L2 = L2->next,j = j*10){
		nSumL2 +=  (L2->val * j);
		if(L2->next == NULL)break;
	}
	nSumL3 = nSumL1 + nSumL2;
	printf("nSumL1：%d\n",nSumL1);
	printf("nSumL2：%d\n",nSumL2);
	printf("nSumL3：%d\n",nSumL3);
	
	int nNum = -1;
	for(int i = 10;;){
		nNum = nSumL3%i;
		nSumL3/=i;

		printf("num:%d\n",nNum);
		
		//单向链表插入
		InsertNode(nNum);
		
		if(nSumL3/i==0 && nSumL3%i ==0){
			//打印链表
			printList();
			break;
		}
		
	
		//~ printf("%d->%d->d\n",Head->val,Head->next->val);//,L3->next->next->val);
		//~ getchar();
	
	}

}

int main(){
	struct ListNode L1_3 = {3,NULL};
	struct ListNode L1_2 = {4,&L1_3};
	struct ListNode L1 = {2,&L1_2};
	//printf("%d->%d->%d\n",L1.val,L1.next->val,L1.next->next->val);
	struct ListNode L2_3 = {4,NULL};
	struct ListNode L2_2 = {6,&L2_3};
	struct ListNode L2 = {5,&L2_2};
	//~ struct ListNode L3 = 
	addTwoNumbers(&L1,&L2);
	//~ printf("%d->%d->%d\n",L3.val,L3.next->val,L3.next->next->val);
	return 0;
	//addTwoNumbers();
	
	return 0;
}
