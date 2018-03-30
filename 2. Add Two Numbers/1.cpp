#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct ListNode 
{
	int val;
    struct ListNode *next;
};

struct ListNode* creasteNode(int num, int *nums);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

int main()
{
	int num;
	int nums[100]={};
	struct ListNode *l1, *l2, *l3;

	cin>>num;
	for (int i = 0; i < num; i++)
	{
		cin>>nums[i];
	}

	l1 = creasteNode(num, nums);

	cin>>num;
	for (int i = 0; i < num; i++)
	{
		cin>>nums[i];
	}

	l2 = creasteNode(num, nums);

	l3 = addTwoNumbers(l1, l2);

	while(NULL != l3)
	{
		cout<<l3->val<<' ';
		l3 = l3->next;
	}
	cout<<endl;
}

struct ListNode* creasteNode(int num, int *nums)
{
	struct ListNode *l, *l_t, *l_s;

	l_t = l = (struct ListNode*)malloc(sizeof(struct ListNode));
	l->val=nums[0];
	l->next = NULL;

	for (int i = 1; i < num; i++)
	{
		l_s = (struct ListNode*)malloc(sizeof(struct ListNode));
		l_s->val=nums[i];
		l_s->next=NULL;
		l_t->next=l_s;
		l_t=l_s;
	}

	return l;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *l1_t = l1;
    struct ListNode *l2_t = l2;
    struct ListNode *l3, *l3_t, *l3_s;

    int sum = 0;
    int add_flag = 0;
    int tmp;

    l3_t = l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3_t->next = NULL;

    while((NULL != l1_t)&&(NULL != l2_t))
    {
    	l3_s = (struct ListNode*)malloc(sizeof(struct ListNode));
    	tmp = l1_t->val + l2_t->val + add_flag;
    	l3_s->val = tmp % 10;
    	add_flag = tmp / 10;

    	l3_s->next = NULL;
    	l3_t->next = l3_s;
    	l3_t = l3_s;

    	l1_t = l1_t->next;
    	l2_t = l2_t->next;

		//cout<<"l1 "<<sum_l1<<endl;
    }

    while(NULL != l1_t)
    {
    	l3_s = (struct ListNode*)malloc(sizeof(struct ListNode));
    	tmp = l1_t->val + add_flag;
    	l3_s->val = tmp % 10;
    	add_flag = tmp / 10;

    	l3_s->next = NULL;
    	l3_t->next = l3_s;
    	l3_t = l3_s;
    	l1_t = l1_t->next;
    }

    while(NULL != l2_t)
    {
    	l3_s = (struct ListNode*)malloc(sizeof(struct ListNode));
    	tmp = l2_t->val + add_flag;
    	l3_s->val = tmp % 10;
    	add_flag = tmp / 10;
    	
    	l3_s->next = NULL;
    	l3_t->next = l3_s;
    	l3_t = l3_s;
    	l2_t = l2_t->next;
    }

    if(add_flag)
    {
    	l3_s = (struct ListNode*)malloc(sizeof(struct ListNode));
    	tmp = add_flag;
    	l3_s->val = tmp % 10;
    	add_flag = tmp / 10;
    	
    	l3_s->next = NULL;
    	l3_t->next = l3_s;
    	l3_t = l3_s;
    }

    l3_t = l3->next;
    free(l3);

    return l3_t;
}