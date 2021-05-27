#include <bits/stdc++.h>

using namespace std;

// /****************************************************************

// Following is the class structure of the Node class:

class Node
{
public:
    char data;
    Node *next;
    Node(char data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// *****************************************************************/

void prinntList(Node *temp){
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// *****************************************************************/

Node *reverse(Node *head)
{
    Node *cur = head, *prev = nullptr;
    while (head != nullptr)
    {
        cur = head->next;
        head->next = prev;
        prev = head;
        head = cur;
    }
    return prev;
}

// *****************************************************************/

Node *removeStr(Node *head, string str)
{
    // Write your code here.
    int j = str.size();
    if (j == 0 || head == nullptr)
    {
        return head;
    }

    head = reverse(head);
    Node *cur = head, *prev = nullptr;
    int i = j - 1;
    while (cur != nullptr)
    {
        if (cur->data == str[i])
        {
            int c = 1, k = i - 1;
            Node *temp = cur->next;
            while (k > -1 && temp != nullptr && temp->data == str[k])
            {
                c++;
                k--;
                temp = temp->next;
            }
            if (c == j)
            {
                if (prev == nullptr)
                {
                    head = temp;
                }
                else
                {
                    prev->next = temp;
                }
                // prinntList(head);
                cur = head;
                prev = nullptr;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    head = reverse(head);
    return head;
}
// *****************************************************************/
// *****************************************************************/
// *****************************************************************/
// *****************************************************************/
// *****************************************************************/
// *****************************************************************/

int main()
{
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a>>b;
        Node *head = nullptr, *tail = nullptr;
        for (int i = 0; i < a.size(); ++i)
        {
            Node *temp = new Node(a[i]);
            if(head ==nullptr){
                head = tail = temp;
            }else{
                tail->next = temp;
                tail = tail->next;
            }
        }
        prinntList(head);
        head = removeStr(head, b);
        prinntList(head);
    }

    return 0;
}