// const�� ���� ����ϸ�, �Ǽ��� ���ϼ� �ְ�, ����� �ð��� �پ���, ���꼺�� �����Ѵ�.
// const�� ���. �� ó�� �Ҵ� ���� ������ �Ұ����ϴ�.
// ���� �Ӹ� �ƴ϶� �Լ����� ����� �����ϴ�.
// �Լ��� ����� ���� Ŭ������ �ɹ� ������ �ٲ��� �ʰ� �ϱ����� ��� �Ѵ�.

// const int g; �Ұ�

class AAA {
public:
    void setSomething(const int& a);
    // �� �Լ������� AAA�� �ɹ� ������ ���� ������ �� ����.
    void printSomething() const;
    const int& getInt();
};
int main() {
    // �̰ͺ���
    int a = 10;
    a = 20;

    // �̰� ����.
    const int b = 10;
    const int c = 10;
}
