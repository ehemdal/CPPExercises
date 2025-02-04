// Examples of operator overloading so we can use <<, =, ==, and != on arrays.
#include <iostream>
#include <cstdlib>

using namespace std;

class Array {
// Private data: pointer to array memory and integer size
private:
    int* m_ptr;
    int m_size;

public:
    Array(int* ptr, int size);  // A
    Array(int size); // B
    Array(const Array&); // C

    // Overloading [] (subscript) operator, will be used as  arr[5] = 25;
    int& operator[] (int); // D

    // Another overloading [] operator, will be used as int val = arr[5];
    int operator [] (int) const; // E
    
    // overloading copy assignment operator
    Array& operator=(const Array& other); // F

    // Pre- and post-increment operators
    Array& operator ++(); // pre-increment // J
    Array operator ++(int); // post-increment // K
    Array& operator --(); // pre-decrement  // L
    Array operator --(int); // post-decrement // M


    /*
      overloading << operator. We have to declare it as friend to access 
      private members m_ptr and m_size
    */
    friend std::ostream& operator<<(std::ostream&, const Array&);  // G

    friend bool operator==(const Array& lhs, const Array& rhs); // H
    friend bool operator!=(const Array& lhs, const Array& rhs); // I
};

// A: This constructor takes a size and a pointer to another array.
// It creates a new array of size size and copies from the other array
// What happens if the other array is smaller than the new one?
Array::Array(int* ptr = nullptr, int size = 0) //JEH fix, use nullptr
{
    m_size = size;
    m_ptr = nullptr;
    if (size != 0)
    {
        m_ptr = new int[size];
        for (int i = 0; i < size; i++)
            m_ptr[i] = ptr[i];
    }
}

// B: Construct an array with all elements set to zero
Array::Array(int size)
{
    m_size = size;
    m_ptr = nullptr;
    if (size != 0)
    {
        m_ptr = new int[size];
        for (int i = 0; i < size; i++)
            m_ptr[i] = 0; //JEH fix: Don't put a double into an int
    }
}

// C: Copy constructor.  Make a new array using a reference to an existing one
Array::Array(const Array& other)
{
    m_ptr = new int[other.m_size];
    m_size = other.m_size;

    for (int i = 0; i < m_size; i++)
        m_ptr[i] = other.m_ptr[i];
}

// D: [] operator: Return an array element at index as a modifiable value
int& Array::operator[](int index)
{
    if (index >= m_size)
    {
        throw std::invalid_argument("Index value is greater than array size");
    }
    return m_ptr[index];
}

// E: Return an array element as const (non-modifiable value)
int Array::operator [] (int index) const {
    if (index >= m_size)
    {
        throw std::invalid_argument("Index value is greater than array size");
    }
    return m_ptr[index];
}

// F: Overloaded assignment operator
Array& Array::operator=(const Array& other) {
    if (this != &other) {
        if (other.m_size != m_size) {
            delete[] m_ptr;
            m_size = 0;
            m_ptr = nullptr;
            m_ptr = new int[other.m_size];
            m_size = other.m_size;
        }
        /* next line is identical to
           for(int i=0;i<m_size;i++)
              m_ptr[i] = other.m_ptr[i];
        */
        std::copy(other.m_ptr, other.m_ptr + other.m_size, m_ptr);
    }
    return *this;
}

// G: Ostream (output stream) operator for an array
std::ostream& operator<<(std::ostream& os, const Array& arr)
{
    for (int i = 0; i < arr.m_size; i++)
        os << arr.m_ptr[i] << " ";
    os << endl;
    return os;
}

// H: equal-to operator
bool operator==(const Array& left, const Array& right) {
    if (left.m_size != right.m_size) {
        return false;
    }

    for (int i = 0; i < left.m_size; i++) {
        if (left.m_ptr[i] != right.m_ptr[i]) {
            return false;
        }
    }
    return true;
}
// I: Not-equal-to operator
bool operator!=(const Array& left, const Array& right) {
    return !operator==(left, right);
}

// J: Pre-increment all elements of the array
Array& Array::operator ++() {
    for (int i = 0; i < m_size; i++)
        m_ptr[i]++;
    return *this;
}

// K: Post-increment. Save a dummy array, increment, return the dummy
Array Array::operator ++(int dummy) {
    Array temp = *this;
    for (int i = 0; i < m_size; i++)
        m_ptr[i] = m_ptr[i] + 1;
    return temp;
}

// L: Pre-decrement
Array& Array::operator --() {
    for (int i = 0; i < m_size; i++)
        m_ptr[i]--;
    return *this;
}
// M: Post-decrement
Array Array::operator --(int dummy) {
    Array temp = *this;
    for (int i = 0; i < m_size; i++)
        m_ptr[i] = m_ptr[i] - 1;
    return temp;
}



int main()
{
    cout << "Let's begin!" << endl;

    Array a(5);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = -1;

    Array b(2);
    b[0] = 1;
    b[1] = 2;
    cout << "Display the contents of a and b" << endl;
    cout << "a: " << a << "b: " << b;

    cout << "Create array c and initialize from a" << endl;
    Array c = a;
    cout << c;

    cout << "Set c == b and display c" << endl;
    c = b;
    cout << c;

    cout << "another set of tests\n";
    cout << "Set a[2] = -10" << endl;
    a[2] = -10;
    cout << a;

    if (c == b) {
        cout << "c == b" << endl;
    }

    if (c != a) {
        cout << "c != a" << endl;
    }

    cout << "pre and post-increment set of tests\n";

    Array e = c++;
    cout << e++;
    cout << ++e;
    cout << e;
    cout << --e;
    
    // This isn't going to work...
    try {
        cout << "Displaying an invalid index should fail:" << endl;
        cout << a[15] << endl;
    }
    catch (const std::exception& e) {
        cout <<  e.what() << endl;
    }
    return 0;
}
