class A {
public:
    static int n;
    static int sum;
public:
    A() {++n; sum += n;}
};

int A::n = 0;
int A::sum = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        A::n = 0;
        A::sum = 0;
        A * pA = new A[n];
        delete[] pA;
        return A::sum;
    }
};
