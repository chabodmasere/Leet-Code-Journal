// Fibonacci sequence calculator

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    cout << "Fibonacci Sequence:" << endl;
    
    for (int i = 0; i <= 10; i = i + 1) {
        int fib = fibonacci(i);
        cout << "F(" << i << ") = " << fib << endl;
    }
    
    return 0;
}
