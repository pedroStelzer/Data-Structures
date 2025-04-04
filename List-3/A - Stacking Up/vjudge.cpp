#include <iostream>
using namespace std;

class Node
{
    public:

        int data;
        Node *next;

        Node(int value) : data(value), next(nullptr) {}
};

template <typename T> class Stack
{
    private:

        Node *topNode;
        int size;

    public:

        Stack() : size(0), topNode(nullptr) {};
        ~Stack()
        {
            while(!this->empty())
            {
                this->pop();
            }
        };

        void push(T value)
        {
            Node *newNode = new Node(value);
            newNode->next = topNode;
            topNode = newNode;
            size++;
        };

        T pop()
        {
            if(!this->empty())
            {
                Node *temp = topNode;
                topNode = topNode->next;
                T value = temp->data;
                delete temp;
                size--;
                return value;
            }
        };

        void add()
        {
            Node *temp = topNode;

            while(temp != nullptr)
            {
                temp->data++;
                temp = temp->next;
            }
        };

        void debug()
        {
            Node *temp = topNode;

            cout << "\n\n Comecou debug \n\n";

            while(temp != nullptr)
            {
                cout << temp->data;
                temp = temp->next;
            }

            cout << "\n\n Terminou debug \n\n";
        }

        T top() 
        {
            if(!empty()) 
                return topNode->data;
        };

        T next()
        {
            if(!empty() && topNode->next != nullptr)
                return topNode->next->data;
        };

        bool empty() 
        {
            return topNode == nullptr;
        };

        int lenght() 
        {
            return size;
        };
};

int main()
{
    Stack<int> nums;
    Stack<char> resultStack;
    string result = "";
    int numElements = 0;

    cin >> numElements;

    for(int i = 0; i < numElements; i++)
    {   
        int num;
        cin >> num;
        nums.push(num);
    }

    while(!nums.empty())
    {
        if(nums.lenght() > 1 && nums.top() > 1 && (nums.top() == nums.next()))
        {
            nums.pop();
            resultStack.push('d');
        }
        else if(nums.top() > 1)
        {
            int temp = nums.pop()-1;
            nums.add();

            nums.push(temp);
            nums.push(1);

            resultStack.push('+');
        }
        else if(nums.top() == 1)
        {
            nums.pop();
            resultStack.push('1');
        }
        else
        {
            nums.top();
        }
    }

    while(!resultStack.empty()) result += resultStack.pop();

    cout << result;

    return 0;
}