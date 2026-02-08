// Function examples

int add(int a, int b) {
    return a + b;
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int x = 5;
    int y = 10;
    int sum = add(x, y);
    
    cout << x << " + " << y << " = " << sum << endl;
    
    int n = 5;
    int fact = factorial(n);
    cout << "Factorial of " << n << " = " << fact << endl;
    
    return 0;
}
