#include<iostream>

using namespace std;

class ListNode
{
	public:
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(NULL) { }
};

void printNode(ListNode* next)
{
		while(next!=NULL)
		{
			cout<<next->val;
			next = next->next;
		}
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
{
	ListNode* result = NULL;
	ListNode* temp = NULL;
	int sum =0 , carry = 0;
	while(1)
	{
		sum = carry;
		if(l1!=NULL)
		{
			sum += l1->val;
			l1 = l1->next;
		}
		
		if(l2!=NULL)
		{
			sum+=l2->val;
			l2 = l2->next;
		}
			
		carry = sum/10;
		if(sum==0 && carry==0 && (l1==NULL && l2==NULL)) 
			break;
		ListNode* newtemp = new ListNode(sum%10);
		
		if(result == NULL)
		{
			result = newtemp;
			temp = newtemp;
			//printNode(result);
			//cout<<endl;
		}
		else
		{
			temp->next  = newtemp;
			temp = newtemp;
		//	printNode(result);
	//		cout<<endl;
		}
	}
	return result;
}

int main()
{
		ListNode* a = new ListNode(1);
		ListNode* temp = new ListNode(2);
		a->next  = temp;
		
		ListNode* b = new ListNode(4);
		temp = new ListNode(2);
		b->next  = temp;
		ListNode* c = addTwoNumbers(a,b);
		printNode(a);
		cout<<endl;
		printNode(b);
		cout<<endl;
		printNode(c);
		cout<<endl;
		
		
		
}
