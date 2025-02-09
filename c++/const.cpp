// const를 많이 사용하면, 실수를 줄일수 있고, 디버깅 시간이 줄어들고, 생산성이 증가한다.
// const는 상수. 즉 처음 할당 이후 변경이 불가능하다.
// 변수 뿐만 아니라 함수에도 사용이 가능하다.
// 함수에 사용할 때는 클래스의 맴버 변수가 바뀌지 않게 하기위해 사용 한다.

// const int g; 불가

class AAA {
public:
    void setSomething(const int& a);
    // 이 함수에서는 AAA의 맴버 변수의 값을 변경할 수 없다.
    void printSomething() const;
    const int& getInt();
};
int main() {
    // 이것보다
    int a = 10;
    a = 20;

    // 이게 낫다.
    const int b = 10;
    const int c = 10;
}
