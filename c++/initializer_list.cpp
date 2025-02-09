// m_b 생성후(BB 생성자 실행됨), BB("param") 객체를 생성후 m_b에 copy함.
// BB의 오브젝트를 두번 생성함.
class AAA {
public:
    AAA() {
        m_b = BB("param");
    }
private:
    BB m_b;
};

// 바로 m_b가 만들어 지는 순간 BB의 생성자가 실행됨. 바로 초기화됨.
// BB의 오브젝트를 한번 생성함.
// 이게 좋다.
class AAA {
public:
    AAA(): m_b("param") {}
private:
    BB m_b;
};