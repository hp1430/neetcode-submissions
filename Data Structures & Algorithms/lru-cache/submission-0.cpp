class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node *next;
        Node *prev;
    public:
        Node(int key, int val) {
            this->key=key;
            this->val=val;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int capacity;
    unordered_map<int, Node*>m;

    void addNode(Node *newNode) {
        Node *temp = head->next;
        newNode->next=temp;
        head->next=newNode;
        temp->prev=newNode;
        newNode->prev=head;
    }

    void deleteNode(Node *delNode) {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next=delNext;
        delNext->prev=delPrev;
    }

public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        m.clear();
        head->next=tail;
        head->prev=NULL;
        tail->prev=head;
        tail->next=NULL;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        Node *foundNode = m[key];
        deleteNode(foundNode);
        addNode(foundNode);
        return foundNode->val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()) {
            Node *foundNode = m[key];
            foundNode->val=value;
            deleteNode(foundNode);
            addNode(foundNode);
        }
        else {
            if(m.size()==capacity) {
                Node *foundNode = tail->prev;
                m.erase(foundNode->key);
                deleteNode(foundNode);
            }
            Node *newNode = new Node(key, value);
            addNode(newNode);
            m[key] = newNode;
        }
    }
};
