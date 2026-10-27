
#include <iostream>
#include <cassert>
using namespace std;

class Matrix
{
private:
    int data[2][2];
public:
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0)
    {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    // Operator +
    Matrix operator+(const Matrix &m)
    {
        Matrix result;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result.data[i][j] = data[i][j] + m.data[i][j];
        return result;
    }

    // Operator *
    Matrix operator*(const Matrix &m)
    {
        Matrix result;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.data[i][j] = 0;
                for (int k = 0; k < 2; k++)
                    result.data[i][j] += data[i][k] * m.data[k][j];
            }
        }
        return result;
    }

    // Operator []
    int* operator[](int index)
    {
        return data[index];
    }

    // Operator <<
    friend ostream& operator<<(ostream &out, const Matrix &m)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                out << m.data[i][j] << " ";

            out << endl;
        }
        return out;
    }
};

int main()
{
    // --- Test Case 1 (Original) ---
    Matrix A(1, 2, 3, 4);
    Matrix B(5, 6, 7, 8);
    Matrix sum1 = A + B;
    Matrix product1 = A * B;

    // Unit Tests for Test Case 1
    assert(sum1[0][0] == 6);
    assert(sum1[1][1] == 12);
    assert(product1[0][0] == 19);
    assert(product1[0][1] == 22);
    assert(product1[1][0] == 43);
    assert(product1[1][1] == 50);

    // --- Test Case 2 (New) ---
    Matrix C(2, 0, 1, 3);
    Matrix D(1, 2, 0, 4);
    Matrix sum2 = C + D;
    Matrix product2 = C * D;

    // Unit Tests for Test Case 2
    assert(sum2[0][0] == 3);
    assert(sum2[1][1] == 7);
    assert(product2[0][0] == 2);
    assert(product2[0][1] == 4);
    assert(product2[1][0] == 1);
    assert(product2[1][1] == 14);

    Matrix E(1, 1, 0, 2);
    Matrix F(3, 0, 1, 4);
    Matrix sum3 = E + F;
    Matrix product3 = E * F;

    // Unit Tests for Test Case 3
    assert(sum3[0][0] == 4);
    assert(sum3[0][1] == 1);
    assert(sum3[1][0] == 1);
    assert(sum3[1][1] == 6);
    assert(product3[0][0] == 4);
    assert(product3[0][1] == 4);
    assert(product3[1][0] == 2);
    assert(product3[1][1] == 8);

    // Output results
    cout << "--- Test Case 1 Results ---" << endl;
    cout << "Matrix A:\n" << A;
    cout << "Matrix B:\n" << B;
    cout << "Addition (A + B):\n" << sum1;
    cout << "Multiplication (A * B):\n" << product1;

    cout << "\n--- Test Case 2 Results ---" << endl;
    cout << "Matrix C:\n" << C;
    cout << "Matrix D:\n" << D;
    cout << "Addition (C + D):\n" << sum2;
    cout << "Multiplication (C * D):\n" << product2;

    cout << "\n--- Test Case 3 Results ---" << endl;
    cout << "Matrix E:\n" << E;
    cout << "Matrix F:\n" << F;
    cout << "Addition (E + F):\n" << sum3;
    cout << "Multiplication (E * F):\n" << product3;

    cout << "\nAll unit tests passed successfully." << endl;
    return 0;
}

