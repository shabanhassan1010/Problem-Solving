#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* lchild;
    Node* rchild;
};

class Queue 
{
    private:
        Node* arr[100];
        int front, rear;
    public:
    Queue() 
    {
        front = -1;
        rear = -1;
    }

            bool isEmpty() 
            {
                return front == -1;
            }

            void enqueue(Node* node) 
            {
                if (rear == 99) {
                    cout << "Queue is full." << endl;
                    return;
                }
                if (front == -1) {
                    front = 0;
                }
                rear++;
                arr[rear] = node;
            }

            Node* dequeue() 
            {
                if (isEmpty()) {
                    cout << "Queue is empty." << endl;
                    return nullptr;
                }
                Node* temp = arr[front];
                front++;
                if (front > rear) {
                    front = rear = -1;
                }
                return temp;
            }

};

class Tree 
{
        Node* root;

    public:
        Tree() { root = nullptr; }
        void CreateTree();
        void Preorder() { Preorder(root); }
        void Preorder(Node* p);
        void Postorder() { Postorder(root); }
        void Postorder(Node* p);
        void Inorder() { Inorder(root); }
        void Inorder(Node* p);
        void Levelorder() { Levelorder(root); }
        void Levelorder(Node* p);
        int Height() { return Height(root); }
        int Height(Node* root);
};

void Tree::CreateTree() 
{
    Node* p, * t;
    int x;
    Queue q;
    
    printf("Enter root value: ");
    scanf("%d", &x);
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.enqueue(root);
    
    while (!q.isEmpty()) {
        p = q.dequeue();
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }
        
        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node* p) 
{
    if (p) {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node* p) 
{
    if (p) {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node* p) 
{
    if (p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void Tree::Levelorder(Node* root) 
{
    Queue q;
    printf("%d ", root->data);
    q.enqueue(root);
    
    while (!q.isEmpty()) {
        root = q.dequeue();
        if (root->lchild) {
            printf("%d ", root->lchild->data);
            q.enqueue(root->lchild);
        }
        if (root->rchild) {
            printf("%d ", root->rchild->data);
            q.enqueue(root->rchild);
        }
    }
}

int Tree::Height(Node* root) 
{
    if (root == nullptr)
        return 0;
    
    int leftHeight = Height(root->lchild);
    int rightHeight = Height(root->rchild);
    
    return max(leftHeight, rightHeight) + 1;
}

int main() 
{
    Tree t;
    t.CreateTree();
    cout << "Preorder: ";
    t.Preorder();
    cout << endl;
    
    cout << "Inorder: ";
    t.Inorder();
    cout << endl;

    cout << "Postorder: ";
    t.Postorder();
    cout << endl;

    cout << "Level Order: ";
    t.Levelorder();
    cout << endl;
    
    cout << "Height: " << t.Height() << endl;
    
    return 0;
}
