// Challenge 07: Linked List Deduplication
#include <cstddef>
#include <unordered_set>
#include <iostream>
using namespace std;

// Structures
struct Node {
        int value;
        Node *next;
};

struct List {
        Node *head;
        size_t size;        

        List();
        ~List();

        void push_front(const int d);
        void push_back(const int d);
};

List::List() : head(nullptr), size(0) {
}

List::~List() {
        Node *next;
        for (Node *curr = head; curr != nullptr; curr = next) {
            next = curr->next;
            delete curr;
        }
}

void List::push_front(const int d) {
        head = new Node{d, head};
        size++;
}

void List::push_back(const int d){
        if( head == nullptr ){
            head = new Node{d, nullptr};
        }
        
        Node *curr = head;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = new Node{d, nullptr};
}

Node* deduplicate( Node *head ){
        unordered_set<int> nodes;
        Node* curr = head;
        while( curr != nullptr ){
            nodes.insert(curr->value);
            curr = curr->next;
        }
       
        Node *prev;
        curr = head;
        while( curr != nullptr ){
            if( nodes.find(curr->value) != nodes.end() ){
                nodes.erase(curr->value);
                prev = curr;
                curr = curr->next;
            } else{
                if( curr == head ){
                        head = curr->next;
                        delete curr;
                        curr = head;
                } else{
                        prev->next = curr->next;
                        delete curr;
                        curr = prev->next;
                }
            }
        }
        
        return head;
}

// Main Execution

int main(int argc, char *argv[]) {

    int N;
    // get input
    while( cin >> N ){

        List l = List();
        
        int d;
        // build linked list
        for( int i = 0; i < N; i++ ){
            cin >> d;
            l.push_back(d);
        }
        l.head = deduplicate(l.head);

        Node* curr = l.head;
        // print list
        while( curr->next != nullptr ){
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << curr->value << endl;

    }
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
