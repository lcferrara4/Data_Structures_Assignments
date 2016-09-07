// Challenge 02: Adding List-Based Integers

#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

// struct for Node
template <typename T>
struct Node{
	T data;
	Node<T>* next;
};

// struct for LinkedList
template <typename T>
struct LinkedList{
	Node<T> head;
	void push_front(T);
	void empty();
	void print();
};
 
// LinkedList add to front function   
template <typename T>
void LinkedList<T>::push_front(T value){
	head.next = new Node<T>{value, head.next};
}

// LinkedList empty nodes function
template <typename T>
void LinkedList<T>::empty(){
	Node<T>* tmp;
	Node<T>* curr;
	for (curr = head.next; curr != nullptr; curr = curr->next){
		tmp = curr;
		delete(curr);
		curr = tmp;
	}
	head.next = nullptr;
}

// LinkedList print function
template <typename T>
void LinkedList<T>::print(){
        for (Node<T>* curr = head.next; curr != nullptr; curr = curr->next){
		cout << curr->data;
	}
	cout << endl;
}

template <typename T>
LinkedList<T> findListSum (LinkedList<T> &, LinkedList<T> &, LinkedList<T> &);

// Main Execution

int main(int argc, char *argv[]) {

	// Initialize lists and strings for storing integers
	LinkedList<char> list1; 	// for 1st integer
	list1.head.next = nullptr;

	LinkedList<char> list2;		// for 2nd integer
	list2.head.next = nullptr;

	LinkedList<char> sum;
	sum.head.next = nullptr;

    	string integer1;
    	string integer2;


    	while (getline(cin, integer1, ' ')){
		// Get other integer
        	getline(cin, integer2);
       	
		// Put 1st integer into linked list in reverse order	
		for ( int i = 0; i < integer1.length(); i++ ){
			list1.push_front(integer1[i]);
			//return 0;
		}

		// Put 2nd integer into linked list in reverse order
		for ( int i = 0; i < integer2.length(); i++ ){
			list2.push_front(integer2[i]);		
		}

        	// Add
		sum = findListSum( list1, list2, sum );        

        	// Print result
		sum.print();

        	// Empty lists 
		list1.empty();
		list2.empty();	
		sum.empty();
    	}

    	return 0;
}

// function to find the sum of two lists
template <typename T>
LinkedList<T> findListSum (LinkedList<T>& list1, LinkedList<T>& list2, LinkedList<T>& sumList){

	char carryOut = '0';
	int longer = 0;
	string sum;	
	char digit;

	Node<char>* curr2 = list2.head.next;
	Node<char>* curr;
	
	for (curr = list1.head.next; curr != nullptr; curr = curr->next){
	
		sum = to_string((curr->data - '0') + (curr2->data - '0') + (carryOut - '0'));
		if (sum.length() > 1){
			carryOut = sum[0];
			digit = sum[1];
		}
		else{
			carryOut = '0';
			digit = sum[0];
		}
		sumList.push_front(digit);
	
		// check for differences in lengths of linked lists	
		if (curr->next == nullptr && curr2-> next != nullptr){
			curr2 = curr2->next;
			longer = 2;
			break;
		}
		else if (curr2->next == nullptr){
			curr = curr->next;
			longer = 1;
			break;
		}
		else{
			curr2 = curr2->next;
		}
	}

	// take care of remaining digits and carryout
	if (longer == 1){

		while( curr != nullptr ){
                       	sum = to_string((curr->data - '0') + (carryOut - '0'));
         		
			// check for carry out
			if (sum.length() > 1){
                	        carryOut = sum[0];
                        	digit = sum[1];
                	}
                	else{
                        	carryOut = '0';
                        	digit = sum[0];
                	}
			
			// add digit to sum 
                       	sumList.push_front(digit);
                        curr = curr->next;
                }

	} else if (longer == 2){
	
		while( curr2 != nullptr ){
                	sum = to_string((curr2->data - '0') + (carryOut - '0'));

                        // check for carry out
                        if (sum.length() > 1){
                                carryOut = sum[0];
                                digit = sum[1];
                        }
                        else{
                                carryOut = '0';
                                digit = sum[0];
                        }
                          
			sumList.push_front(digit);
			curr2 = curr2->next;
		}
	
	}

	// add extra carry out
	if (carryOut != '0'){
		sumList.push_front(carryOut);
	}	

	return sumList;	
}
