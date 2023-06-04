//STRUCT NGAY THANG NAM TIEP THEO
#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<fstream>

using namespace std;

int namnhuan(int year){
   return ((year % 100 != 0 && year % 4 == 0) || (year % 400 == 0));
}

int ngaythang(int month , int year){
   switch(month){
      case 1: case 3: case 5: case 7: case 8: case 10: case 12:{
         return 31;
         break;
      }
      case 2:{
         if(namnhuan(year)) return 29;
         else return 28;
         break;
      }
      case 4: case 6: case 9: case 11:{
         return 30;
         break;
      }
   }
   return 0;
}

struct date{
   int d,m,y;

   date(int day,int month,int year){
      d = day;
      m = month;
      y = year;
   }

   void getnextday(){
      int newday = d;
      int newmonth = m;
      int newyear = y;

      if(d > 0 && m > 0 && m < 13 && y > 0 && d <= ngaythang(m,y)){
         newday = d + 1;
         if(m != 12 && d == ngaythang(m,y)){ //ngay cuoi cung trong 1 thang 
            newday = 1;
            newmonth = m + 1;
         }else if(m == 12 && d == ngaythang(m,y)){
            newday = 1;
            newmonth = 1;
            newyear = y+1;
         }else if(m == 2){
            if(namnhuan(y)){
               newday = 1;
               newmonth = 3;
            }
         }
         cout << setw(2) << setfill('0') << newday << "/";
         cout << setw(2) << setfill('0') << newmonth << "/";
         cout << setw(2) << setfill('0') << newyear;
      }else{
         cout << "INVALID\n";
      }
   }
};

int main(){
   int d,m,y;
   char u,v;
   cin >> d >> u >> m >> v >> y;
   date k(d,m,y);
   k.getnextday();
}
//=======================================================================================

//SO PHUC 
#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<fstream>

using namespace std;

struct complex{
   int a,b;

   complex(int a_ = 0, int b_ = 0){
      a = a_;
      b = b_;
   }

   double abs(){
      return sqrt(a*a*1.0 + b*b*1.0);
   }

   void print(){
      if(a != 0 && b != 0){
         if(b == 1 || b == -1){
            if( b == -1) cout << a << "-i" << endl;
            else cout << a << "i"<<endl;
         }else{
            if(b > 0) cout << a << "+" << b << "i" << endl;
            else cout << a << b << "i" << endl;
         }
      }else{
         if(a == 0 && b == 0) cout << "0\n";
         else if(a==0 && b != 0){
            if(b > 0) cout << b << "i" << endl;
            else cout << b << "-i" << endl;
         }else if(a !=0 && b==0){
            cout << a << endl;
         }
      }
   }

   complex add(complex x, complex y){
      complex ans;
      ans.a = x.a + y.a;
      ans.b = x.b + y.b;
      return ans;
   }

};

int main(){
   complex x;
   x.a = 3;
   x.b = 4;
   x.print();
   cout << fixed << setprecision(2) << x.abs() << endl;
}
//=======================================================================================

//STRUCT STRING
#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<set>
#include<map>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<fstream>

using namespace std;

struct X{
   int len;
   char *str;

   X(const char *str_){
      int n = strlen(str_);
      str = new char[n+1];
      strcpy(str, str_);
   }

   ~X(){
      delete[] str;
   }

   void print(){
      cout << str << endl;;
   }

   void append(const char *s){
      strcat(str, s);
   }
};

int main(){
   char str1[100];
   cin.getline(str1, 100); //== getline(cin, str1) trong string
   char str2[100]; 
   cin.getline(str2, 100);
   X u(str1);
   u.print();
   u.append(str2);
   u.print();
}

//=======================================================================================

//STRUCT PIXELS
#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<set>
#include<map>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<fstream>

using namespace std;

struct image{
   int *pixels;
   int width;
   int height;
};

void print(const image& img){
   for(int i=0; i< img.height; i++){
      for(int j=0; j< img.width; j++){
         cout << img.pixels[i*img.width + j] << " ";
      }
      cout << endl;
   }
}

//Cap phat cho mang kich thuoc bang 1 nua anh 
image halve(const image& img){
   int newwidth = (img.width+1)/2;
   int newheight = (img.height+1)/2;
   int *newpixels = new int[newwidth*newheight];

   for(int i=0; i< newheight; i++){
      for(int j=0; j< newwidth; j++){
         newpixels[i*newwidth + j] = img.pixels[2*i*img.width + 2*j];
      }
   }
   image newimg = {newpixels, newwidth, newheight};
   return newimg;
}

int main(){
   int pixels[] = {
      1, 3, 0, 5, 2,
      4, 1, 8, 3, 1,
      3, 3, 1, 3, 2
   };
   image img = {pixels, 5, 3};
   print(img);
   print(halve(img));
}
//=======================================================================================

//STRUCT SINHVIEN
#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<set>
#include<map>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<fstream>

using namespace std;

struct student{
   string id;
   string name;
   double gpa;
};

void print(const vector<student>& studentlist){
   for(int i = 0; i < (int)studentlist.size(); i++){
      cout << studentlist[i].id << " " << studentlist[i].name << " " << studentlist[i].gpa << endl;
   }
}

int find(const vector<student>& studentlist, string id){
   for(int i = 0; i < (int)studentlist.size(); i++){
      if(studentlist[i].id == id) return i;
   }
   return -1;
}

bool compare(student& a, student& b){
   return a.gpa > b.gpa;
}

vector<student> top3(const vector<student>& studentlist){
   vector<student> ans = studentlist;
   sort(ans.begin(), ans.end(), compare);
   return ans;
}

int main(){
   vector<student> std = {{ "1", "Datmieu", 4.0}, {"2", "Dm" , 2.0} , {"3", "dm", 3.0}};
   vector<student> top = top3(std);
   print(top);
   cout << find(std, "2") << endl;
}
//=======================================================================================





































