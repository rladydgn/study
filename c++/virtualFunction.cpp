#include <iostream>

class A {
private:
    int i4;
public:
    void f();
};

class B : public A {
    public:
    void f();
};

class C {
private:
    int i4;
    // VTable *vt; 자동으로 생성됨
public:
    virtual void f();
};

class D : public C {
    public:
    void f();
};

int main() {
    std::cout << sizeof(A) << std::endl;
    // 4bytes

    std::cout << sizeof(C) << std::endl;
    // 4bytes + padding + 8bytes
}