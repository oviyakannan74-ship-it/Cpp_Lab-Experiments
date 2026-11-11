#include <iostream>
#include <cstring>
#include <chrono>
#include <utility>
using namespace std;
using namespace chrono;

class String
{
private:
    char* data;
    size_t length;
public:
    // Constructor
    String(const char* str = "")
    {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    // Copy Constructor
    String(const String& other)
    {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // Move Constructor
    String(String&& other) noexcept
    {
        data = other.data;
        length = other.length;

        other.data = nullptr;
        other.length = 0;
    }

    // Copy Assignment Operator
    String& operator=(const String& other)
    {
        if (this != &other)
        {
            delete[] data;

            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }

        return *this;
    }

    // Move Assignment Operator
    String& operator=(String&& other) noexcept
    {
        if (this != &other)
        {
            delete[] data;

            data = other.data;
            length = other.length;

            other.data = nullptr;
            other.length = 0;
        }

        return *this;
    }

    // Destructor
    ~String()
    {
        delete[] data;
    }

    void display() const
    {
        if (data != nullptr)
            cout << data << endl;
        else
            cout << "[Empty / Null]" << endl;
    }
};

// Perfect Forwarding Function
template <typename T>
String createString(T&& value)
{
    return String(forward<T>(value));
}
int main()
{
    cout << "Program started. Running benchmarks (this may take a few seconds)..." << endl;

    const int SIZE = 100000;

    String original(
        "This is a resource-heavy string used to demonstrate "
        "copy and move semantics in C++.");

    // Benchmark Copy Operations
    auto startCopy = high_resolution_clock::now();

    for (int i = 0; i < SIZE; i++)
    {
        String copy = original;
    }

    auto endCopy = high_resolution_clock::now();
    auto copyTime = duration_cast<milliseconds>(endCopy - startCopy);

    // Benchmark Move Operations
    auto startMove = high_resolution_clock::now();

    for (int i = 0; i < SIZE; i++)
    {
        String temp(
            "This is a resource-heavy string used for "
            "move semantics.");

        String moved = move(temp);
    }

    auto endMove = high_resolution_clock::now();
    auto moveTime = duration_cast<milliseconds>(endMove - startMove);

    // Perfect Forwarding Demonstration
    String forwarded = createString("Perfect Forwarding Example");

    cout << "\nPerfect Forwarding Result: ";
    forwarded.display();

    // Display Benchmark Results
    cout << "\nCopy Operation Time: " << copyTime.count() << " milliseconds" << endl;
    cout << "Move Operation Time: " << moveTime.count() << " milliseconds" << endl;

    // --- TEST CASE 1: Explicit Copy and Move Assignment Operators ---
    cout << "\n--- Test Case 1: Assignment Operators ---" << endl;
    String str1("Hello Assignment");
    String str2;

    str2 = str1; // Copy assignment
    cout << "After copy assignment (str2 = str1): ";
    str2.display();

    String str3("Temporary String");
    str3 = move(str1); // Move assignment
    cout << "After move assignment (str3 = move(str1)): " << endl;
    cout << "  str3: ";
    str3.display();
    cout << "  str1 (should be empty): ";
    str1.display();

    // --- TEST CASE 2: Self-Assignment Safety Test ---
    cout << "\n--- Test Case 2: Self-Assignment Safety ---" << endl;
    String str4("Self Assignment Test");

    str4 = str4; // Self-copy assignment
    cout << "After self-copy assignment (str4 = str4): ";
    str4.display();

    str4 = move(str4); // Self-move assignment
    cout << "After self-move assignment (str4 = move(str4)): ";
    str4.display();

    // Keep console window open if running locally
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
