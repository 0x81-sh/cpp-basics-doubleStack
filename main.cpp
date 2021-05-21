#include "Stack.h"
#include "TEST.h"

void testClass();
void testConst();
void testVolatile();

int main() {
    testClass();
    testConst();
    testVolatile();

    return 0;
}

void testClass() {
    T_UNIT("class", "constructor/defaults", {
        Stack test(10);

        T.EXPECT(test.getSize() == 10);
        T.EXPECT(test.getEleCnt() == -1);
        T.EXPECT(test.isEmpty());
        T.EXPECT(!test.isFull());
    })
}

void testConst() {
    T_UNIT("const", "peek/isFull", {
        Stack test(2);

        test.push(10);
        T.EXPECT(!test.isFull());

        test.push(20);
        T.EXPECT(test.isFull());

        T.EXPECT(test.peek() == 20);
        test.pop();

        T.EXPECT(test.peek() == 10);
        test.pop();
    })
}

void testVolatile() {
    T_UNIT("volatile", "push", {
        Stack test(2);
        test.push(10);

        T.EXPECT(test.peek() == 10);
        T.EXPECT(test.getEleCnt() == 0);
    })

    T_UNIT("volatile", "pop", {
        Stack test(2);

        test.push(10);
        test.push(20);

        T.EXPECT(test.pop() == 20);
        T.EXPECT(test.pop() == 10);
    })
}