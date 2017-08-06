// https://en.wikipedia.org/wiki/Ackermann_function

#include<stdio.h>

long int ackermann(long int m, long int n) {
    long int m_stack[100000], n_stack[100000];
    long int m_size = 1, n_size = 1;
    m_stack[m_size] = m;
    n_stack[n_size] = n;
    while(m_size != 0) {
        m = m_stack[m_size];
        m_size -= 1;
        n = n_stack[n_size];
        n_size -= 1;
        if(m == 0) {
            n_size += 1;
            n_stack[n_size] = n + 1;
        } else if(n == 0) {
            m_size += 1;
            m_stack[m_size] = m - 1;
            n_size += 1;
            n_stack[n_size] = 1;
        } else {
            m_size += 1;
            m_stack[m_size] = m - 1;
            m_size += 1;
            m_stack[m_size] = m;
            n_size += 1;
            n_stack[n_size] = n - 1;
        }
    }
    long int out = n_stack[n_size];
    n_size -= 1;
    return out;
}

int main() {
    long int m, n;
    scanf("%d %d", &m, &n);
    long int value = ackermann(m, n);
    printf("%d", value);
    return 0;
}
