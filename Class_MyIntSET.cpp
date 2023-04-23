/*
1)Cài đặt lớp MyIntSet biểu diễn tập hợp chứa các giá trị int phân biệt. Lớp sử dụng mảng cấp phát động để lưu dữ liệu. Biến thành viên num để theo dõi số phần tử đã thêm vào tập hợp. Biến thành viên maxSize để theo dõi kích thước tối đa của mảng động.

class MyIntSet{
public:
    MyIntSet();
    MyIntSet(int a[], int n);
    ~MyIntSet();
    bool insertVal(int v);
    bool eraseVal(int v);
    void clearAll();
    bool findVal(int v) const;
    bool isEmpty() const;
    int getSize() const;
    const int* getBeginPtr() const;
    const int* getEndPtr() const;
private:
    int maxSize;
    int* elements;
    int num;
};

Hàm bool insertVal(int v) thêm giá trị v vào tập hợp. Thêm không thành công (giá trị v đã có) thì trả về false. Mảng đầy thì cấp phát kích thước mới maxSize = maxSize * 2 + 1.
Hàm bool eraseVal(int v) xóa giá trị v khỏi tập hợp. Xóa không thành công (giá trị v chưa có) thì trả về false.
Hàm void clearAll() xóa tất cả các giá trị trong tập hợp.
Hàm bool findVal(int v) const kiểm tra xem v có trong tập hợp không.
Hàm bool isEmpty() const kiểm tra xem tập hợp có rỗng không.
Hàm int getSize() const trả về số phần tử trong tập hợp.
Hàm const int* getBeginPtr() const trả về con trỏ tới phần tử đầu của tập hợp.
Hàm const int* getEndPtr() const trả về con trỏ tới phần tử cuối của tập hợp.

Test	                                                                      Result
MyIntSet is1;                                                               5 3
is1.eraseVal(6);
is1.insertVal(3);
is1.insertVal(3);
is1.insertVal(5);
vector<int> res;
for(auto p = is1.getBeginPtr(); p <= is1.getEndPtr(); p++){
    res.push_back(*p);
}
sort(res.begin(), res.end());
for(int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";

----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
class MyIntSet{
public:
    //Hàm cấp phát bộ nhớ
    MyIntSet(){
      maxSize = 100;
      num = 0 ;
      elements = new int[maxSize];
    }

    //Hàm khởi tạo 
    MyIntSet(int a[], int n){
        maxSize = n + 100;
        num = n;
        elements = new int[maxSize];
        for(int i = 0 ; i < n ; i++) elements[i] = a[i];
    }

    //Hàm giải phóng 
    ~MyIntSet() {
        delete[] elements;
    }

    /*thêm giá trị v vào tập hợp.(giá trị v đã có) thì trả về false.
    Mảng đầy thì cấp phát kích thước mới maxSize = maxSize * 2 + 1 */
    bool insertVal(int v){
        if(findVal(v)) return  false;
        if(num >= maxSize){
          int *newElements = new int[maxSize*2+1];
          for(int i=0 ; i< num ; i++) newElements[i] = elements[i];
          delete[] elements;
          elements = newElements;
          maxSize = maxSize*2+1;
        }
        elements[num++] = v;
        return true;
    }

    //xóa giá trị v khỏi tập hợp.(giá trị v chưa có) thì trả về false.
    bool eraseVal(int v){
      for(int i = 0; i < num; i++){
        if(elements[i] == v) {
          num--;
          elements[i] = elements[num];
          return true;
        }
      }
      return false;
    }

    //xóa tất cả các giá trị trong tập hợp.
    void clearAll(){
       num = 0;
    }

    //kiểm tra xem v có trong tập hợp không.
    bool findVal(int v) const{
      for(int i = 0; i < num ; i++){
        if(elements[i] == v) return true;
      }
      return false;
    }

    //Kiểm tra tập hợp rỗng 
    bool isEmpty() const{
      return (num == 0);
    }

    //hàm trả về kích thước 
    int getSize() const{
      return num;
    }

    const int* getBeginPtr() const{
      return elements;
    }

    const int* getEndPtr() const{
      return elements + num - 1;
    }

private:
    int maxSize;
    int* elements;
    int num;
};

/*=====================================================================================================================================================================
2)Cài đặt lớp MyIntSet biểu diễn tập hợp chứa các giá trị int phân biệt. Lớp sử dụng mảng kích thước cố định để lưu dữ liệu. Biến thành viên num để theo dõi số phần tử đã thêm vào tập hợp. Đề bài đã cung cấp 2 hàm tạo: 1 hàm tạo tập hợp rỗng, 1 hàm tạo tập hợp từ một mảng.

class MyIntSet{
public:
    MyIntSet():num(0){}

    MyIntSet(int a[], int n){
        if(n > MAX_SIZE) num = MAX_SIZE;
        else num = n;
        for(int i = 0; i < num; i++) elements[i] = a[i];
    }

    bool insertVal(int v);
    bool eraseVal(int v);
    void clearAll();
    bool findVal(int v) const;
    bool isEmpty() const;
    int getSize() const;
    const int* getBeginPtr() const;
    const int* getEndPtr() const;
private:
    static const int MAX_SIZE = 1000;
    int elements[MAX_SIZE];
    int num; // count real values in this set
};

Hàm bool insertVal(int v) thêm giá trị v vào tập hợp. Thêm không thành công (mảng đầy, giá trị v đã có) thì trả về false.
Hàm bool eraseVal(int v) xóa giá trị v khỏi tập hợp. Xóa không thành công (giá trị v chưa có) thì trả về false.
Hàm void clearAll() xóa tất cả các giá trị trong tập hợp.
Hàm bool findVal(int v) const kiểm tra xem v có trong tập hợp không.
Hàm bool isEmpty() const kiểm tra xem tập hợp có rỗng không.
Hàm int getSize() const trả về số phần tử trong tập hợp.
Hàm const int* getBeginPtr() const trả về con trỏ tới phần tử đầu của tập hợp.
Hàm const int* getEndPtr() const trả về con trỏ tới phần tử cuối của tập hợp.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

class MyIntSet{
public:
    // hàm tạo tập hợp rỗng
    MyIntSet():num(0){} 

    // hàm tạo tập hợp từ
    MyIntSet(int a[], int n){
        if(n > MAX_SIZE) num = MAX_SIZE;
        else num = n;
        for(int i = 0; i < num; i++) elements[i] = a[i];
    }

    // thêm giá trị v vào tập hợp.(mảng đầy, giá trị v đã có) thì trả về false.
    bool insertVal(int v){
        if(num >= MAX_SIZE ) return false;
        if(findVal(v)) return  false;
        elements[num++] = v;
        return true;
    }

    //xóa giá trị v khỏi tập hợp.(giá trị v chưa có) thì trả về false.
    bool eraseVal(int v){
      for(int i = 0; i < num; i++){
        if(elements[i] == v) {
          num--;
          elements[i] = elements[num];
          return true;
        }
      }
      return false;
    }

    //xóa tất cả các giá trị trong tập hợp.
    void clearAll(){
       num = 0;
    }

    //kiểm tra xem v có trong tập hợp không.
    bool findVal(int v) const{
      for(int i = 0; i < num ; i++){
        if(elements[i] == v) return true;
      }
      return false;
    }

    //kiểm tra xem tập hợp có rỗng không.
    bool isEmpty() const{
      return (num == 0);
    }

    // trả về số phần tử trong tập hợp.
    int getSize() const{
      return num;
    }

    // trả về con trỏ tới phần tử đầu của tập hợp.
    const int* getBeginPtr() const{
      return elements;
    }

    //trả về con trỏ tới phần tử cuối của tập hợp.
    const int* getEndPtr() const{
      return elements + num - 1;
    }

private:
    static const int MAX_SIZE = 1000;
    int elements[MAX_SIZE];
    int num; // count real values in this set
};
