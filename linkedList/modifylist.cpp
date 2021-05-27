#include <bits/stdc++.h>

using namespace std;

// ****************************************************************

// Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// *****************************************************************/
Node *pairsSwap(Node *head)
{
    //  Write your code here.
    if(head ==nullptr ||head->next ==nullptr){
        return head;
    }

    Node *cur = head, *ahead = head->next,*prev=nullptr;
    while(ahead!=nullptr){
        Node *temp = ahead->next;
        ahead->next = cur;
        cur->next = temp;
        if(prev ==nullptr){
            head = ahead;
        }else{
            prev->next = ahead;
        }
        prev = cur;
        cur = temp;
        if(cur==nullptr){
            break;
        }
        ahead = cur->next;
    }

    return head;
}
// *****************************************************************/
Node *getListAfterAddingNodes(Node *head, int k)
{
    //	Write your code here.
    if(head==nullptr){
        return head;
    }

    Node *temp = head;
    int c = 0, sum = 0;
    while (temp != nullptr)
    {
        c++;
        sum += (temp->data);
        if(c==k || temp->next==nullptr){
            Node *t = new Node(sum);
            Node *q = temp->next;
            temp->next = t;
            t->next = q;
            c = 0;
            sum = 0;
            temp = q;
        }else{
            temp = temp->next;
        }
    }
    return head;
}
// *****************************************************************/

Node * reverse(Node *head){
    Node *cur = head, *prev = nullptr;
    while(head!=nullptr){
        cur = head->next;
        head->next = prev;
        prev = head;
        head = cur;
    }
    return prev;
}

// *****************************************************************/
Node *addOne(Node *head)
{
    // Write Your Code Here.
    if(head == nullptr){
        return (new Node(1));
    }
    head = reverse(head);
    Node *temp = head;
    int carry = 1;
    while (temp != nullptr)
    {
        int sum = temp->data + carry;
        carry = 0;
        if (sum > 9)
        {
            carry = 1;
            sum = sum % 10;
        }
        temp->data = sum;

        if(temp->next==nullptr && carry){
            Node *t = new Node(1);
            temp->next = t;
            break;
        }
        temp = temp->next;
    }
    head = reverse(head);
    temp = head;
    while (temp != nullptr && temp->data == 0)
    {
        head = head->next;
        temp = temp->next;
    }

    return head;
}

// *****************************************************************/

Node *addNodes(Node *head, int n, int m)
{
    // Write your code here.
    if(head == nullptr){
        return head;
    }

    Node *temp = head, *t2;
    int c = 0;
    while (temp != nullptr)
    {
        c++;
        if(c==n){
            t2 = temp->next;
            Node *prev = temp;
            int j = 0;
            long long int sum = 0;
            while (t2 != nullptr && j < n)
            {
                j++;
                sum += t2->data;
                prev = t2;
                t2 = t2->next;
            }
            Node *node = new Node(sum);
            if (j)
            {
                Node *q = prev->next;
                prev->next = node;
                node->next = t2;
                c = 0;
                temp = t2;
            }
            else
            {
                break;
            }
        }else{
            temp = temp->next;
        }
    }
    return head;
}
// *****************************************************************/
// *****************************************************************/

int main()
{

    return 0;
}