// m_b ������(BB ������ �����), BB("param") ��ü�� ������ m_b�� copy��.
// BB�� ������Ʈ�� �ι� ������.
class AAA {
public:
    AAA() {
        m_b = BB("param");
    }
private:
    BB m_b;
};

// �ٷ� m_b�� ����� ���� ���� BB�� �����ڰ� �����. �ٷ� �ʱ�ȭ��.
// BB�� ������Ʈ�� �ѹ� ������.
// �̰� ����.
class AAA {
public:
    AAA(): m_b("param") {}
private:
    BB m_b;
};