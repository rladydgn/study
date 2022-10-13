#include <random>

int main() {
    // 1234�뒗 seed number
    std::mt19937 mt(1234);
    std::uniform_int_distribution<int> dist(0, 99);
    int randNum = dist(mt);

    printf("%d\n", randNum);

    // �셿�쟾�븳 �옖�뜡 紐뉖�? �뒓?���?.
    // 洹쇰?�� �븞�릺�뒗寃껉컳����뜲..
    std::random_device rd;
    std::mt19937 mt2(rd());
    std::uniform_int_distribution<int> dist2(0, 99);
    int randNum2 = dist2(mt2);

    printf("%d �ѱ�", randNum2);
}
