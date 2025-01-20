// WeakPtr.cpp: Adapted from https://www.geeksforgeeks.org/weak_ptr-in-cpp/

#include <iostream>
#include <memory>

class Object {
public:
    Object(int value) : data(value) {
        std::cout << "Object created with value: " << data << std::endl;
    }

    ~Object() {
        std::cout << "Object destroyed with value: " << data << std::endl;
    }

    // data is public because of how the access specifiers are placed.
    int data;
};

int main(void) {
    // Creating a shared pointer with resource ownership
    std::shared_ptr<Object> sharedObj = std::make_shared<Object>(42);

    // Creating a weak pointer to the shared object
    std::weak_ptr<Object> weakObj = sharedObj;

    // Access object using the shared_ptr
        std::cout << "The value via the sharedObj pointer: " << sharedObj->data << std::endl;

    // Access the object via the weak_ptr
    // We need to try to promote weakObj to a new shared_ptr by using lock()
    // If the lock fails, we get a nullptr back. 
    // "auto" here tells the compiler that we don't know the data type at compile time so
    // the compiler should infer the type based on the type of weakObj.

    if (auto new_ptr = weakObj.lock()) {
        std::cout << "The value via the weak_ptr: " << new_ptr->data << std::endl;
    }
    // Reset the shared pointer, destroying the object
    sharedObj.reset();

    // Check if the object still exists
    if (weakObj.expired()) {
        std::cout << "The object has been destroyed." << std::endl;
    }

    return 0;
}