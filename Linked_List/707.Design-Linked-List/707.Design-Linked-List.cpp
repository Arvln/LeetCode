class MyLinkedList {
    class Node {
    public:
        int val;
        Node *next=NULL;
        
        Node(){}
        Node(int _val)
        {
            val=_val;
        }
        Node(int _val, Node *_next)
        {
            val=_val;
            next=_next;
        }
    };
    Node *sentinal;
    int size;
public:
    MyLinkedList() {
        sentinal=new Node();
        size=0;
    }

    Node* getNode(int index)
    {
        if (index>=size) return NULL;
        else
        {
            Node *cur=sentinal->next;
            while (index>0)
            {
                cur=cur->next;
                index--;
            }
            return cur;
        }
    }
    
    int get(int index) {
        Node *node=getNode(index);
        if (node==NULL) return -1;
        else return node->val;
    }
    
    void addAtHead(int val) {
        sentinal->next=new Node(val, sentinal->next);
        size++;
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index==0) addAtHead(val);
        else
        {
            Node *node=getNode(index-1);
            if (node==NULL) return;

            node->next=new Node(val, node->next);
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (size==0) return;
        else if (index==0)
        {
            sentinal->next=sentinal->next->next;
            size--;
        }
        else
        {
            Node *node=getNode(index-1);
            if (node==NULL||node->next==NULL) return;

            Node *removed=node->next;
            node->next=removed->next;
            delete removed;
            size--;
        }
    }
};