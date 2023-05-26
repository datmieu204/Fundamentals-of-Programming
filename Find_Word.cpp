#include<bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main()
{
    int m, n;
    cin >> m >> n;

    string a[m];

    for(int i = 0; i < m; i++) cin >> a[i];

    int k;
    cin >> k;
    while(k--){
        string s;
        cin >> s;
        bool check = false;
        int len = s.length();
        for (int i = 0; i < len; i++)
            if (s[i] < 'a' || s[i] > 'z'){
                cout << "input error" << endl;
                check = true;
                break;
            }
        int end_x = 0, end_y = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++){
                end_x = j;
                end_y = i;
                string res = "";
                for (int dir = 0; dir < 8; dir++){
                    end_x = j;
                    end_y = i;
                    for (int k = 0; k < len; k++){
                        res = res + a[end_y][end_x];
                        if((int)res.length() == len) break;
                        end_x += dx[dir];
                        end_y += dy[dir];
                        if(end_x >= n || end_x < 0) end_x = abs(abs(end_x)-n);
                        if(end_y >= m || end_y < 0) end_y = abs(abs(end_y)-m);
                    }
                    if (res == s){
                        cout << i + 1 << " " << j + 1 << " " << end_y + 1 << " " << end_x + 1 << endl;
                        check = true;
                    }
                    res = "";
                }
            }
        if (!check) cout << "not found" << endl;
        }
        return 0;
}
