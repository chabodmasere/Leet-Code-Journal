// Loop examples

int main() {
    // While loop
    cout << "While loop:" << endl;
    int i = 1;
    while (i <= 5) {
        cout << i << " ";
        i = i + 1;
    }
    cout << endl;
    
    // For loop
    cout << "For loop:" << endl;
    for (int j = 1; j <= 5; j = j + 1) {
        cout << j << " ";
    }
    cout << endl;
    
    // Nested loops
    cout << "Multiplication table:" << endl;
    for (int x = 1; x <= 3; x = x + 1) {
        for (int y = 1; y <= 3; y = y + 1) {
            int product = x * y;
            cout << product << " ";
        }
        cout << endl;
    }
    
    return 0;
}
