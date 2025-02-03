// Examples of operator overloading so we can use <<, =, ==, and != on arrays.
#include <iostream>
#include <cstdlib>

using namespace std;

class Array {
private:
    int* m_ptr;
    int m_size;
public:
    Array(int* ptr, int size);
    Array(int size); // init all elements by 0;
    Array(const Array&); // copy ctor

    /* Overloading [] operator
       will be used as  arr[5] = 25;
    */
    int& operator[] (int);

    /*
       Another overloading [] operator
       will be used as int val = arr[5];
    */
    int operator [] (int) const;
    // overloading copy assignment operator
    Array& operator=(const Array& other);

    Array& operator ++(); // pre-increment
    Array operator ++(int); // post-increment
    Array& operator --(); // pre-decrement
    Array operator --(int); // post-decrement

    /*
      we can try to overload move assignment operator of C++11
      but not today
    */

    /*
      overloading << operator. We have to declare it as friend to access private members
      m_ptr and m_size
    */
    friend std::ostream& operator<<(std::ostream&, const Array&);

    friend bool operator==(const Array& lhs, const Array& rhs);
    friend bool operator!=(const Array& lhs, const Array& rhs);
};


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

// JEH fix:  Don't assign a default value, compiler won't know which default constructor
// to use when calling Array(). Is it line 49 or this one?  By leaving the default "size = 0" here out,
// the compiler can resolve the ambiguity.
// Array::Array(int size = 0) <<<Original in course notes
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

Array::Array(const Array& other)
{
    m_ptr = new int[other.m_size];
    m_size = other.m_size;

    for (int i = 0; i < m_size; i++)
        m_ptr[i] = other.m_ptr[i];
}



int& Array::operator[](int index)
{
    if (index >= m_size)
    {
        throw std::invalid_argument("Index value is greater than array size");
    }
    return m_ptr[index];
}


int Array::operator [] (int index) const {
    if (index >= m_size) {
        // It should be exception here
        cout << "Array index is bigger that the size of array, terminating the program";
        exit(0);
    }
    return m_ptr[index];
}

//Overloaded assignment operator

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

std::ostream& operator<<(std::ostream& os, const Array& arr)
{
    for (int i = 0; i < arr.m_size; i++)
        os << arr.m_ptr[i] << " ";
    os << endl;
    return os;
}

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

bool operator!=(const Array& left, const Array& right) {
    return !operator==(left, right);
}

Array& Array::operator ++() {
    for (int i = 0; i < m_size; i++)
        m_ptr[i]++;
    return *this;
}

Array Array::operator ++(int dummy) {
    Array temp = *this;
    for (int i = 0; i < m_size; i++)
        m_ptr[i] = m_ptr[i] + 1;
    return temp;
}


Array& Array::operator --() {
    for (int i = 0; i < m_size; i++)
        m_ptr[i]--;
    return *this;
}

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
    a[2] = 3;

    cout << a << b;

    Array c = a;

    cout << c;

    c = b;
    cout << c;

    cout << "another set of tests\n";

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
        cout << a[15] << endl;
    }
    catch (const std::exception& e) {
        cout <<  e.what() << endl;
    }
    return 0;
}
