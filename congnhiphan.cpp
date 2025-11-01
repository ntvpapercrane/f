#include <iostream>

using namespace std;

string decToBin(int n) {
    string result = "";
    while (n > 0) {
        result = (char)(n % 2 + '0') + result;
        n = n / 2;
    }
    return result;
}

string plusBin(string a, string b) {
    string result = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result = (char)(sum % 2 + '0') + result;
        carry = sum / 2;
    }
    return result;
}

int binToDec(string bin) {
    int result = 0;
    for (char c : bin) {
        result = result * 2 + (c - '0');
    }
    return result;
}

int main() {
    int num1;
    int num2;

    cin >> num1 >> num2;

    string bin1 = decToBin(num1);
    string bin2 = decToBin(num2);

    cout << "Binary of " << num1 << " is " << bin1 << endl;
    cout << "Binary of " << num2 << " is " << bin2 << endl;

    string sum = plusBin(bin1, bin2);
    cout << "Sum of binaries is " << sum << " which is " << binToDec(sum) << " in decimal." << endl;

    return 0;
}