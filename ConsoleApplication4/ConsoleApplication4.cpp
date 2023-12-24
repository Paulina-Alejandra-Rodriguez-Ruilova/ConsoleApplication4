#include <iostream>
#include <vector>

class Node {
public:
    int key;
    Node* p;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->key = value;
        newNode->p = top;
        top = newNode;
    }

    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
            top = top->p;
            std::cout << "You have deleted an element: " << temp->key << std::endl;
            delete temp;
        }
        else {
            std::cout << "The stack is empty." << std::endl;
        }
    }

    void remove() {
        while (!isEmpty()) {
            pop();
        }
        std::cout << "The stack has been deleted." << std::endl;
    }

    void copy(Stack& otherStack) {
        Node* temp = top;
        while (temp != nullptr) {
            otherStack.push(temp->key);
            temp = temp->p;
        }
        std::cout << "The stack has been copied." << std::endl;
    }

    int length() {
        int count = 0;
        Node* temp = top;
        while (temp != nullptr) {
            count++;
            temp = temp->p;
        }
        return count;
    }

    void displayContent() {
        Node* temp = top;
        std::cout << "Stack Contents: ";
        while (temp != nullptr) {
            std::cout << temp->key << " ";
            temp = temp->p;
        }
        std::cout << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Stack myStack;
    Stack newStack;

    while (true) {
        std::cout << "\nSelect an operation:\n";
        std::cout << "1. Add an item\n";
        std::cout << "2. Delete an item and display it on the screen\n";
        std::cout << "3. Clear the entire stack\n";
        std::cout << "4. Get the stitch length\n";
        std::cout << "5. Output the contents of the stack\n";
        std::cout << "6. Copy the stack to a new object\n";
        std::cout << "7. Exit the program\n";
        std::cout << "Choice: ";

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            int element;
            std::cout << "Enter the item to add: ";
            std::cin >> element;
            myStack.push(element);
            std::cout << "The element has been added." << std::endl;
            break;

        case 2:
            myStack.pop();
            break;

        case 3:
            myStack.remove();
            break;

        case 4:
            std::cout << "Stitch Length: " << myStack.length() << std::endl;
            break;

        case 5:
            myStack.displayContent();
            break;

        case 6:
            myStack.copy(newStack);
            std::cout << "A new stack has been created." << std::endl;
            break;

        case 7:
            return 0;

        default:
            std::cout << "There is no such option." << std::endl;
            break;
        }
    }


    return 0;
}