/*Thiết kế lớp Time để biểu diễn thời gian trong ngày thoả mãn các yêu cầu sau:

Cho phép tạo thời gian từ ba tham số nguyên giờ, phút, giây
Cho phép tạo thời gian từ hai tham số nguyên giờ, phút
Cho phép tạo thời gian từ một tham số nguyên giờ
Có thể dùng lệnh cout để in ra màn hình theo định dạng hh:mm:ss (ví dụ 08:20:10)
Các biến kiểu Time có thể so sánh với nhau (lớn hơn, nhỏ hơn, bằng, khác, lớn hơn hoặc bằng, nhỏ hơn hoặc bằng)
Có hàm thành viên int hour() trả về giờ hiện tại
Có hàm thành viên int minute() trả về phút hiện tại
Có hàm thành viên int second() trả về giây hiện tại*/

#include<bits/stdc++.h>

using namespace std;

class Time {

    int hours, minutes, seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) {
        hours = h;
        minutes = m;
        seconds = s;
        int sum = 3600*hours + 60*minutes + seconds;
        hours = sum / 3600;
        minutes = (sum - 3600*hours) / 60;
        seconds = sum - 3600*hours - 60*minutes;
    }

    friend ostream& operator<<(ostream& os, const Time& t){
        os <<setfill('0') <<setw(2) << t.hours << ":"
           <<setfill('0') <<setw(2) << t.minutes << ":"
           <<setfill('0') <<setw(2) << t.seconds;
        return os;
    }

    bool operator<(const Time& t) const {
        if (hours < t.hours) {
            return true;
        } else if (hours > t.hours) {
            return false;
        } else if (minutes < t.minutes) {
            return true;
        } else if (minutes > t.minutes) {
            return false;
        } else if (seconds < t.seconds) {
            return true;
        }
        return false;
    }

    //Con trỏ this tham chiếu tới thể hiện tại của Lớp 
    bool operator<=(const Time& t) const {
        return (*this < t || *this == t);
    }

    bool operator>(const Time& t) const {
        return !(*this <= t);
    }

    bool operator>=(const Time& t) const {
        return !(*this < t);
    }

    bool operator==(const Time& t) const {
        return (hours == t.hours && minutes == t.minutes && seconds == t.seconds);
    }

    bool operator!=(const Time& t) const {
        return !(*this == t);
    }

    int hour(){
        return hours;
    }

    int minute(){
        return minutes;
    }

    int second(){
        return seconds;
    }
};
