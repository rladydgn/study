#include <iostream>
// smart pointer
#include <memory>

class Cat {
public:
    Cat() {
        std::cout << "cat constructor" << std::endl;
    }
    ~Cat() {
        std::cout << "cat destructor" << std::endl;
    }
};

int main() {
    // 유니크 포인터
    std::unique_ptr<Cat> catPtr = std::make_unique<Cat>();
    // 포인터 이동 catPtr은 더이상 아무것도 가리키지 않음.
    std::unique_ptr<Cat> catPtr2 = std::move(catPtr);
    // 두개의 포인터가 참조할 경우 컴파일 에러 발생
    // std::unique_ptr<Cat> catPtr3 = catPtr;

    // 셰어드 포인터
    std::shared_ptr<Cat> catPtr4 = std::make_shared<Cat>();
    std::cout << "count: " << catPtr4.use_count() << std::endl;
    std::shared_ptr<Cat> catPtr5 = catPtr4;
    std::cout << "count: " << catPtr5.use_count() << std::endl;

    return 0;
}