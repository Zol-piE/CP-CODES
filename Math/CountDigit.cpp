#include <iostream>
#include<math.h>
using namespace std;

int countD(int n) {
    int ct = 0;
    if (n == 0) return 1;  // Edge case for 0
    if (n < 0) n = -n;     // Handle negative numbers
    while (n > 0) {
        n /= 10;
        ct++;
    }
    return ct;
}

int countDRec(int n) {
    if (n == 0) return 1;    // Base case for 0
    if (n < 0) n = -n;       // Handle negative numbers
    if (n < 10) return 1;    // Base case for single digit
    return 1 + countDRec(n / 10);
}
int countLog(int n)
{
    if(n==0) return 1;

    return floor(log10(n)+1);
}
int main() {
    cout << countD(1) << endl;       // Outputs: 1
    cout << countDRec(001) << endl;   // Outputs: 2
    cout<<countLog(123456)<<endl;
    return 0;
}
