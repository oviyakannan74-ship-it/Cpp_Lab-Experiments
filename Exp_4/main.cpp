#include <iostream>
#include <stack>
#include <queue>
#include <chrono>
using namespace std;
using namespace chrono;

template <class T>
class MyStack
{
private:
    T data[10000];
    int top;
public:
    MyStack()
    {
        top = -1;
    }
    void push(T value)
    {
        if (top < 9999)
            data[++top] = value;
    }
    void pop()
    {
        if (top >= 0)
            top--;
    }
};

template <class T>
class MyQueue
{
private:
    T data[10000];
    int front, rear;
public:
    MyQueue()
    {
        front = 0;
        rear = -1;
    }
    void enqueue(T value)
    {
        if (rear < 9999)
            data[++rear] = value;
    }
    void dequeue()
    {
        if (front <= rear)
            front++;
    }
};

int main()
{
    // Test Case 1 (N = 2500)
    const int N1 = 2500;

    auto start = high_resolution_clock::now();
    MyStack<int> myStack1;
    for (int i = 0; i < N1; i++)
        myStack1.push(i);
    for (int i = 0; i < N1; i++)
        myStack1.pop();
    auto end = high_resolution_clock::now();
    auto customStackTime1 = duration_cast<microseconds>(end - start);

    start = high_resolution_clock::now();
    stack<int> stlStack1;
    for (int i = 0; i < N1; i++)
        stlStack1.push(i);
    for (int i = 0; i < N1; i++)
        stlStack1.pop();
    end = high_resolution_clock::now();
    auto stlStackTime1 = duration_cast<microseconds>(end - start);

    start = high_resolution_clock::now();
    MyQueue<int> myQueue1;
    for (int i = 0; i < N1; i++)
        myQueue1.enqueue(i);
    for (int i = 0; i < N1; i++)
        myQueue1.dequeue();
    end = high_resolution_clock::now();
    auto customQueueTime1 = duration_cast<microseconds>(end - start);

    start = high_resolution_clock::now();
    queue<int> stlQueue1;
    for (int i = 0; i < N1; i++)
        stlQueue1.push(i);
    for (int i = 0; i < N1; i++)
        stlQueue1.pop();
    end = high_resolution_clock::now();
    auto stlQueueTime1 = duration_cast<microseconds>(end - start);

    cout << "--- Test Case 1 (N = 2500) ---" << endl;
    cout << "Custom Stack Time: " << customStackTime1.count() << " microseconds" << endl;
    cout << "STL Stack Time: " << stlStackTime1.count() << " microseconds" << endl;
    cout << "Custom Queue Time: " << customQueueTime1.count() << " microseconds" << endl;
    cout << "STL Queue Time: " << stlQueueTime1.count() << " microseconds" << endl;

    // Test Case 2 (N = 5000)
    const int N2 = 5000;

    start = high_resolution_clock::now();
    MyStack<int> myStack2;
    for (int i = 0; i < N2; i++)
        myStack2.push(i);
    for (int i = 0; i < N2; i++)
        myStack2.pop();
    end = high_resolution_clock::now();
    auto customStackTime2 = duration_cast<microseconds>(end - start);

    start = high_resolution_clock::now();
    stack<int> stlStack2;
    for (int i = 0; i < N2; i++)
        stlStack2.push(i);
    for (int i = 0; i < N2; i++)
        stlStack2.pop();
    end = high_resolution_clock::now();
    auto stlStackTime2 = duration_cast<microseconds>(end - start);

    start = high_resolution_clock::now();
    MyQueue<int> myQueue2;
    for (int i = 0; i < N2; i++)
        myQueue2.enqueue(i);
    for (int i = 0; i < N2; i++)
        myQueue2.dequeue();
    end = high_resolution_clock::now();
    auto customQueueTime2 = duration_cast<microseconds>(end - start);

    start = high_resolution_clock::now();
    queue<int> stlQueue2;
    for (int i = 0; i < N2; i++)
        stlQueue2.push(i);
    for (int i = 0; i < N2; i++)
        stlQueue2.pop();
    end = high_resolution_clock::now();
    auto stlQueueTime2 = duration_cast<microseconds>(end - start);

    cout << "\n--- Test Case 2 (N = 5000) ---" << endl;
    cout << "Custom Stack Time: " << customStackTime2.count() << " microseconds" << endl;
    cout << "STL Stack Time: " << stlStackTime2.count() << " microseconds" << endl;
    cout << "Custom Queue Time: " << customQueueTime2.count() << " microseconds" << endl;
    cout << "STL Queue Time: " << stlQueueTime2.count() << " microseconds" << endl;

    // Test Case 3 (N = 10000)
    const int N3 = 10000;

    // Custom Stack Benchmark
    start = high_resolution_clock::now();
    MyStack<int> myStack;
    for (int i = 0; i < N3; i++)
        myStack.push(i);
    for (int i = 0; i < N3; i++)
        myStack.pop();
    end = high_resolution_clock::now();
    auto customStackTime = duration_cast<microseconds>(end - start);

    // STL Stack Benchmark
    start = high_resolution_clock::now();
    stack<int> stlStack;
    for (int i = 0; i < N3; i++)
        stlStack.push(i);
    for (int i = 0; i < N3; i++)
        stlStack.pop();
    end = high_resolution_clock::now();
    auto stlStackTime = duration_cast<microseconds>(end - start);

    // Custom Queue Benchmark
    start = high_resolution_clock::now();
    MyQueue<int> myQueue;
    for (int i = 0; i < N3; i++)
        myQueue.enqueue(i);
    for (int i = 0; i < N3; i++)
        myQueue.dequeue();
    end = high_resolution_clock::now();
    auto customQueueTime = duration_cast<microseconds>(end - start);

    // STL Queue Benchmark
    start = high_resolution_clock::now();
    queue<int> stlQueue;
    for (int i = 0; i < N3; i++)
        stlQueue.push(i);
    for (int i = 0; i < N3; i++)
        stlQueue.pop();
    end = high_resolution_clock::now();
    auto stlQueueTime = duration_cast<microseconds>(end - start);

    cout << "\n--- Test Case 3 (N = 10000) ---" << endl;
    cout << "Custom Stack Time: "
         << customStackTime.count() << " microseconds" << endl;
    cout << "STL Stack Time: "
         << stlStackTime.count() << " microseconds" << endl;
    cout << "Custom Queue Time: "
         << customQueueTime.count() << " microseconds" << endl;
    cout << "STL Queue Time: "
         << stlQueueTime.count() << " microseconds" << endl;

    return 0;
}
