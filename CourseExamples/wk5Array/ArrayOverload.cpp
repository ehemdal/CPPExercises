// Examples of operator overloading so we can use  +, <<, =, ==, and != on arrays.
// Adapted from chapter 10 case study in 
// Deitel & Deitel, C++ How to Program 10th ed (2017: Pearson Education).

#include <iostream>
#include <cstdlib>
#include <typeinfo>

using namespace std;

class IntArray {
// Private data: pointer to array memory and integer size
private:
    int* m_ptr;
    int m_size;

public:
    IntArray(int* ptr, int size);  // A
    IntArray(int size); // B
    IntArray(const IntArray&); // C

    // Overloading [] (subscript) operator, will be used as  arr[5] = 25;
    int& operator[] (int); // D

    // Another overloading [] operator, will be used as int val = arr[5];
    int operator [] (int) const; // E
    
    // overloading copy assignment operator
    IntArray& operator=(const IntArray& other); // F

    // Pre- and post-increment operators
    IntArray& operator ++(); // pre-increment // J
    IntArray operator ++(int); // post-increment // K
    IntArray& operator --(); // pre-decrement  // L
    IntArray operator --(int); // post-decrement // M

    IntArray operator +(const IntArray& addend); // N


    /*
      overloading << operator. We have to declare it as friend to access 
      private members m_ptr and m_size
    */
    friend std::ostream& operator<<(std::ostream&, const IntArray&);  // G

    friend bool operator==(const IntArray& lhs, const IntArray& rhs); // H
    friend bool operator!=(const IntArray& lhs, const IntArray& rhs); // I
};

// A: This constructor takes a size and a pointer to another array.
// It creates a new array of size size and copies from the other array
// What happens if the other array is smaller than the new one?
IntArray::IntArray(int* ptr = nullptr, int size = 0) //JEH fix, use nullptr
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
IntArray::IntArray(int size)
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
IntArray::IntArray(const IntArray& other)
{
    m_ptr = new int[other.m_size];
    m_size = other.m_size;

    for (int i = 0; i < m_size; i++)
        m_ptr[i] = other.m_ptr[i];
}

// D: [] operator: Return an array element at index as a modifiable value
int& IntArray::operator[](int index)
{
    if (index >= m_size)
    {
        throw std::invalid_argument("Index value is greater than array size");
    }
    return m_ptr[index];
}

// E: Return an array element as const (non-modifiable value)
int IntArray::operator [] (int index) const {
    if (index >= m_size)
    {
        throw std::invalid_argument("Index value is greater than array size");
    }
    return m_ptr[index];
}

// F: Overloaded assignment operator
IntArray& IntArray::operator=(const IntArray& other) {
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
std::ostream& operator<<(std::ostream& os, const IntArray& arr)
{
    os << typeid(arr).name() << endl;
    for (int i = 0; i < arr.m_size; i++)
        os << arr.m_ptr[i] << " ";
    os << endl;
    return os;
}

// H: equal-to operator
bool operator==(const IntArray& left, const IntArray& right) {
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
bool operator!=(const IntArray& left, const IntArray& right) {
    return !operator==(left, right);
}

// J: Pre-increment all elements of the array
IntArray& IntArray::operator ++() {
    for (int i = 0; i < m_size; i++)
        m_ptr[i]++;
    return *this;
}

// K: Post-increment. Save a dummy array, increment, return the dummy
IntArray IntArray::operator ++(int dummy) {
    IntArray temp = *this;
    for (int i = 0; i < m_size; i++)
        m_ptr[i] = m_ptr[i] + 1;
    return temp;
}

// L: Pre-decrement
IntArray& IntArray::operator --() {
    for (int i = 0; i < m_size; i++)
        m_ptr[i]--;
    return *this;
}
// M: Post-decrement
IntArray IntArray::operator --(int dummy) {
    IntArray temp = *this;
    for (int i = 0; i < m_size; i++)
        m_ptr[i] = m_ptr[i] - 1;
    return temp;
}

// N: Defining an addition operator for IntArray
IntArray IntArray::operator+(const IntArray& addend)  {
    IntArray answer = IntArray(*this);
    // set limit for the larger array
    int limit(0);
    m_size >= addend.m_size ? limit = m_size : limit = addend.m_size;
    for (int i = 0; i < limit; i++) 
    {
        // If beyond the end of the first addend, insert the second addend
        if (i > m_size) 
        {
            answer[i] = addend.m_ptr[i];
        }
        // If beyond the end of the second addend, insert the first
        else if (i > addend.m_ptr[i]) 
        {
            answer[i] = m_ptr[i];

        } 
        // Within the bounds of both, add the elements
        else answer[i] = m_ptr[i] + addend.m_ptr[i];
    }
    return answer;

}


int main()
{
    cout << "Examples of operator overloading for IntArray" << endl;

    IntArray a(5);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = -1;

    IntArray b(2);
    b[0] = 1;
    b[1] = 2;
    
    cout << "Display the contents of a and b" << endl;
    cout << "a: " << a << "b: " << b;

    cout << "Display the sum of a and b" << endl;
    cout << a + b << endl;

    cout << "Did we change a and b?" << endl;
    cout << a << b << endl;

    cout << "Create array c and initialize from a" << endl;
    IntArray c = a;
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

    IntArray e = c++;
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
