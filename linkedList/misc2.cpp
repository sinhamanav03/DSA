// ************************************************************

    // Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

// ************************************************************/
// *************************************************************
 
//     Following is the class structure of the Node class:
 
        class CNode
        {
        public:
            int x,y;
            CNode *next;
            CNode(int x, int y)
            {
                this->x = x;
                this->y = y;
                this->next = nullptr;
            }
        };
 
//************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int> *l1=first,*l2=second, *head=nullptr,*tail = nullptr;
    while(l1!=nullptr && l2!=nullptr){
        Node<int> * temp;
        if(l1->data < l2->data){
            temp = l1;
            l1=l1->next;
        }else{
            temp = l2;
            l2 = l2->next;
        }

        if(head==nullptr){
            head = tail = temp;
        }else{
            tail->next=temp;
            tail = tail->next;
        }
    }

    if(l1!=nullptr){
        if(head==nullptr){
            head = tail = l1;;
        }else{
	        tail->next = l1;        
        }
    }

    if(l2!=nullptr){
        if(head==nullptr){
            head = tail = l2;
        }else{
        	tail->next = l2;
        }
    }

    return head;
}
// ************************************************************/
CNode *connectMidPoints(CNode *head) {
    // Write your code here.
    CNode * temp = head,*newHead=nullptr,*tail =nullptr;
    while(temp!=nullptr){
        int x1 = temp->x ,y1=temp->y,x2=x1,y2=y1;
        if(temp->next!=nullptr && temp->next->x == x1){
            while(temp->next!=nullptr && temp->next->x==x1){
                x2=temp->next->x;
                y2=temp->next->y;
                temp = temp->next;
            }
        }else if(temp->next!=nullptr && temp->next->y==y1){
            while(temp->next!=nullptr && temp->next->y==y1){
                x2=temp->next->x;
                y2=temp->next->y;
                temp = temp->next;
            }
        }else{
            break;
        }
        CNode * node = new CNode((x1+x2)/2,(y1+y2)/2);
        if(newHead==nullptr){
            newHead = tail = node;
        }else{
//             cout<<node->x<<node->y;
            tail->next = node;
            tail = tail->next;
        }
    }
    return newHead;
}

// ************************************************************/
// ************************************************************/
// ************************************************************/
// ************************************************************/
// ************************************************************/
