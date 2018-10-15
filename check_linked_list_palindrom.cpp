#include<iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node(int a)
        {
            data = a;
            next = NULL;
        }
};

class LinkedList
{
      public:
          Node* root;
          LinkedList()
          {
              root = NULL;
          }

          void insert(int a)
          {
              Node* node = new Node(a);
              node->next = root;
              root = node;
          }

          void print()
          {
              Node* temp = root;
              while(temp!=NULL)
              {
                  cout<<temp->data<<" ";
                  temp = temp->next;
              }
              cout<<endl;
          }

          int length(){
            Node* temp = root;
            int counter = 0;
            while(temp != NULL)
            {
                counter++;
                temp = temp->next;
            }
            return counter;
          }
};

Node* reverse(Node* node){
  if(node == NULL || node->next == NULL) return node;
  Node* temp;
  Node* prev=NULL;

  while(node != NULL){
    temp = node->next;
    node->next = prev;
    prev = node;
    node = temp;
  }

  return prev;
}

bool checkLinkedListPalindrom(LinkedList* l, Node* root){
  if(root == NULL || root->next == NULL) return true;

   int length = l->length();
   int mid = (length + 1)/2;

   Node* middle = root;
   while(mid > 1){
      middle = middle->next;
      mid--;
   }

   Node* mid_start = reverse(middle->next);
   middle->next = mid_start;

   for(int i=1; i<=(length+1)/2; i++){
     if(mid_start == NULL) break;
     if(mid_start->data != root->data)
     {
       return false;
     }

     root = root->next;
     mid_start = mid_start->next;
   }

   return true;
}

int main()
{
    LinkedList* linkedList = new LinkedList();
    int n = 10;
    linkedList->insert(12);
    linkedList->insert(21);
    linkedList->insert(2);
    linkedList->insert(21);
    // for(int i = 0 ;i< n;i++)
    // {
    //     linkedList->insert(min(i, n-1-i));
    // }
    linkedList->insert(12);
    linkedList->print();
    cout<<checkLinkedListPalindrom(linkedList, linkedList->root)<<endl;
    linkedList->print();
}
