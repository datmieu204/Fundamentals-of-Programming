#include <bits/stdc++.h>
using namespace std;

int N, K;

void generateWords( char chars[], string current) {
    if ((int)current.length() == K) {
        cout << current << endl;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (chars[i] != 0) {
            char c = chars[i];
            chars[i] = 0; // Đánh dấu ký tự đã chọn
            generateWords( chars, current + c);
            chars[i] = c; // Hủy đánh dấu ký tự đã chọn
        }
    }
}

int main() {
    cin >> N >> K;
    char chars[N];
    for (int i = 0; i < N; i++) {
        chars[i] = 'a' + i;
    }
    generateWords( chars, "");
    return 0;
}
