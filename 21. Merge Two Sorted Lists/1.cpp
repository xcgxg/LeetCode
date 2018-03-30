#include <iostream>
#include <stdio.h>

using namespace std;

struct ListNode 
{
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);

int main()
{

}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *head_tmp = head, *l1_tmp = l1, *l2_tmp = l2;

	head_tmp->next=NULL;

	while(NULL != l1_tmp && NULL != l2_tmp)
	{
		struct ListNode *s = (struct ListNode*)malloc(sizeof(struct ListNode));
		if(l1_tmp->val<l2_tmp->val)
		{
			s->val = l1_tmp->val;
			s->next = NULL;

			head_tmp->next = s;
			head_tmp = s;

			l1_tmp = l1_tmp->next;
		}
		else
		{
			s->val = l2_tmp->val;
			s->next = NULL;

			head_tmp->next = s;
			head_tmp = s;

			l2_tmp = l2_tmp->next;
		}
	}

	while(NULL != l1_tmp)
	{
		struct ListNode *s = (struct ListNode*)malloc(sizeof(struct ListNode));
		
		s->val = l1_tmp->val;
		s->next = NULL;

		head_tmp->next = s;
		head_tmp = s;

		l1_tmp = l1_tmp->next;
	}

	while(NULL != l2_tmp)
	{
		struct ListNode *s = (struct ListNode*)malloc(sizeof(struct ListNode));
		
		s->val = l2_tmp->val;
		s->next = NULL;

		head_tmp->next = s;
		head_tmp = s;

		l2_tmp = l2_tmp->next;
	}

	head_tmp = head;

	head = head->next;
	free(head_tmp);

	return head;

}