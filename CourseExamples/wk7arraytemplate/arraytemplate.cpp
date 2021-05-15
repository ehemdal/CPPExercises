#include <iostream>
#include <cstdlib>

using namespace std;


template <class T>
class Array{
private:
    T *m_ptr;
    int m_size;
public:
    Array<T>(T* ptr, int size = 0);
    Array<T>(int size = 0); // init all elements by 0;
    Array<T>(const Array<T> &); // copy ctor

    /* Overloading [] operator
       will be used as  arr[5] = 25;
    */
    T &operator[] (int);

    /*
       Another overloading [] operator
       will be used as int val = arr[5];
    */
    T operator [] (int) const;
    // overloading copy assignment operator
    Array<T>& operator=(const Array<T>& other);

    Array<T>& operator ++(); // pre-increment
    Array<T> operator ++(int); // post-increment
    Array<T>& operator --(); // pre-decrement
    Array<T> operator --(int); // post-decrement

    Array<T>& operator+=(const T& rhs) // compound assignment (does not need to be a member,
    {                           // but often is, to modify the private members)
    /* addition of rhs to *this takes place here */
      return *this; // return the result by reference
    }

    /*
      overloading << operator. We have to declare it as friend to access private members
      m_ptr and m_size
    */

    friend std::ostream& operator<<(std::ostream& os, const Array<T>& arr) {
        for(int i = 0; i < arr.m_size; i++)
        os<<arr.m_ptr[i]<<" ";
        os<<endl;
        return os;
    }

    friend bool operator==(const Array<T>& left, const Array<T>& right) {
        if(left.m_size != right.m_size) {
            return false;
        }

        for(int i=0;i<left.m_size;i++) {
            if(left.m_ptr[i] != right.m_ptr[i]) {
                return false;
            }
        }
        return true;
    }

    friend bool operator!=(const Array& left, const Array& right) {
        return !operator==(left, right);
    }


};


template <class T>
Array<T>::Array(T *ptr, int size)
{
    m_size = size;
    m_ptr = NULL;
    if (size != 0)
    {
        m_ptr = new T[size];
        for (int i = 0; i < size; i++)
            m_ptr[i] = ptr[i];
    }
}

template <class T>
Array<T>::Array(int size)
{
    m_size = size;
    m_ptr = NULL;
    if (size != 0)
    {
        m_ptr = new T[size];
        for (int i = 0; i < size; i++)
            m_ptr[i] = 0.0;
    }
}

template <class T>
Array<T>::Array(const Array<T> &other)
{
     m_ptr = new T[other.m_size];
     m_size = other.m_size;

     for(int i=0;i<m_size;i++)
        m_ptr[i] = other.m_ptr[i];
}


template <class T>
T& Array<T>::operator[](int index)
{
    if (index >= m_size)
    {
        // It should be exception here
        cout << "Array index is bigger that the size of array, terminating the program";
        exit(0);
    }
    return m_ptr[index];
}

template <class T>
T Array<T>::operator [] (int index) const {
    if (index >= m_size){
        // It should be exception here
        cout << "Array index is bigger that the size of array, terminating the program";
        exit(0);
    }
    return m_ptr[index];
}

//Overloaded assignment operator
template <class T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
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


template <class T>
Array<T>& Array<T>::operator ++(){
    for(int i=0;i<m_size;i++)
        m_ptr[i]++;
    return *this;
}

template <class T>
Array<T> Array<T>::operator ++(int dummy){
    Array temp = *this;
    for(int i=0;i<m_size;i++)
        m_ptr[i] = m_ptr[i] + 1;
    return temp;
}

template <class T>
Array<T>& Array<T>::operator --(){
    for(int i=0;i<m_size;i++)
        m_ptr[i]--;
    return *this;
}

template <class T>
Array<T> Array<T>::operator --(int dummy){
    Array<T> temp = *this;
    for(int i=0;i<m_size;i++)
        m_ptr[i] = m_ptr[i] - 1;
    return temp;
}


int main()
{
    cout << "Let's begin!" << endl;

    Array<int> a(5);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = -1;

    Array<int> b(2);
    b[0] = 1;
    b[1] = 2;
    a[2] = 3;

    cout <<a<<b;

    Array<int> c = a;

    cout <<c;

    c = b;
    cout <<c;

    cout <<"another set of tests\n";

    a[2] = -10;
    cout <<a;

    if(c == b) {
        cout <<"c == b" << endl;
    }

    if(c != a) {
        cout <<"c != a" << endl;
    }

    cout <<"pre and post-increment set of tests\n";

    Array<int> e = c++;
    cout << e++;
    cout << ++e;
    cout << e;
    cout << --e;

    cout <<"Array of doubles tests\n";

    Array<double>ard(2);

    ard[0] = 1.5;
    ard[1] = 2.5;

    cout <<ard<<endl;

    ++ard;

    cout <<ard<<endl;


    return 0;
}

