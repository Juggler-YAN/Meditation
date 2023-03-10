# Chapter 7

### Q1

```
0-201-70353-X 4 24.99
0-201-82470-1 4 45.39
0-201-88954-4 2 15.00 
0-201-88954-4 5 12.00 
0-201-88954-4 7 12.00 
0-201-88954-4 2 12.00 
0-399-82477-1 2 45.39
0-399-82477-1 3 45.39
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00
```

```c++
// Sales_data.h
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

using namespace std;

struct Sales_data {
    string bookNo;
    unsigned units_sold;
    double revenue;
};
#endif
```

```c++
#include <iostream>
#include <string>
#include "Sales_data.h"

using namespace std;

int main() {
    double allprice, num;
    Sales_data sum;
    if (cin >> sum.bookNo >> sum.units_sold >> sum.revenue) {
        Sales_data item;
        allprice = sum.units_sold * sum.revenue;
        num = sum.units_sold;
        while (cin >> item.bookNo >> item.units_sold >> item.revenue) {
            if (sum.bookNo == item.bookNo) {
                allprice += item.units_sold * item.revenue;
                num += item.units_sold;
            }
            else {
                cout << sum.bookNo << " " << num << " " << allprice << " " << allprice/num << " " << endl;
                sum.bookNo = item.bookNo;
                sum.units_sold = item.units_sold;
                sum.revenue = item.revenue;
                allprice = sum.units_sold * sum.revenue;
                num = sum.units_sold;
            }
        }
        cout << sum.bookNo << " " << num << " " << allprice << " " << allprice/num << " " << endl;
    }
    else {
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}
```

### Q2

```c++
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

using namespace std;

struct Sales_data {

    string bookNo;
    unsigned units_sold;
    double revenue;

    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

#endif
```

### Q3

```
0-201-70353-X 4 24.99
0-201-82470-1 4 45.39
0-201-88954-4 2 15.00 
0-201-88954-4 5 12.00 
0-201-88954-4 7 12.00 
0-201-88954-4 2 12.00 
0-399-82477-1 2 45.39
0-399-82477-1 3 45.39
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00
```

```c++
#include <iostream>
#include <string>
#include "Sales_data.h"

using namespace std;

int main() {
    double allprice, num;
    Sales_data sum;
    if (cin >> sum.bookNo >> sum.units_sold >> sum.revenue) {
        Sales_data item;
        allprice = sum.units_sold * sum.revenue;
        num = sum.units_sold;
        while (cin >> item.bookNo >> item.units_sold >> item.revenue) {
            if (sum.isbn() == item.isbn()) {
                sum.combine(item);
            }
            else {
                cout << sum.bookNo << " " << num << " " << allprice << " " << allprice/num << " " << endl;
                sum.bookNo = item.bookNo;
                sum.units_sold = item.units_sold;
                sum.revenue = item.revenue;
                allprice = sum.units_sold * sum.revenue;
                num = sum.units_sold;
            }
        }
        cout << sum.bookNo << " " << num << " " << allprice << " " << allprice/num << " " << endl;
    }
    else {
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}
```

### Q4

```c++
#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

struct Person {
    string name;
    string address;
};

#endif
```

### Q5

?????????const?????????????????????????????????

```c++
#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

struct Person {
    string name;
    string address;
    string getName() const { return name; }
    string getAddress() const { return address; }
};

#endif
```

### Q6

```c++
istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}
```

### Q7

```
0-201-70353-X 4 24.99
0-201-82470-1 4 45.39
0-201-88954-4 2 15.00 
0-201-88954-4 5 12.00 
0-201-88954-4 7 12.00 
0-201-88954-4 2 12.00 
0-399-82477-1 2 45.39
0-399-82477-1 3 45.39
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00
```

```c++
// Sales_data.h
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

using namespace std;

struct Sales_data {

    string bookNo;
    unsigned units_sold;
    double revenue;

    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price() const {
	if (units_sold) {
		return revenue / units_sold;
    }
	else {
		return 0;
    }
}

istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

#endif
```

```c++
#include <iostream>
#include "Sales_data.h"

using namespace std;

int main() {
    Sales_data sum;
    if (read(cin, sum)) {
        Sales_data item;
        while (read(cin, item)) {
            if (sum.isbn() == item.isbn()) {
                sum.combine(item);
            }
            else {
                print(cout, sum) << endl;
                sum = item;
            }
        }
        print(cout, sum) << endl;
    }
    else {
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}
```

### Q8

??????read????????????????????????????????????print????????????

### Q9

```c++
#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

struct Person {
    string name;
    string address;
    string getName() const { return name; }
    string getAddress() const { return address; }
};

istream& read(istream& is, Person& item) {
    is >> item.name >> item.address;
    return is;
}

ostream& print(ostream& os, const Person& item) {
    os << item.name << " " << item.address;
    return os;
}

#endif
```

### Q10

????????????data1???data2????????????

### Q11

```c++
// Sales_data.h
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

using namespace std;

struct Sales_data {

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p) : 
               bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(istream &);

};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price() const {
	if (units_sold) {
		return revenue / units_sold;
    }
	else {
		return 0;
    }
}

istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

Sales_data::Sales_data(istream &is) {
	read(is, *this);
}

#endif
```

```c++
#include <iostream>
#include <string>
#include "Sales_data.h"

using namespace std;

int main() {
	Sales_data sales_data1;
	print(cout, sales_data1) << endl;

	Sales_data sales_data2("A");
	print(cout, sales_data2) << endl;

	Sales_data sales_data3("A", 1, 2);
	print(cout, sales_data3) << endl;

	Sales_data sales_data4(cin);
	print(cout, sales_data4) << endl;

	return 0;
}
```

### Q12

```c++
// Sales_data.h
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

using namespace std;

struct Sales_data;

istream &read(istream &, Sales_data &);
ostream &print(ostream &, const Sales_data &);
Sales_data add(const Sales_data &, const Sales_data &);

struct Sales_data {

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p) : 
               bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(istream &is) { read(is, *this); };

};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price() const {
	if (units_sold) {
		return revenue / units_sold;
    }
	else {
		return 0;
    }
}

istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

#endif
```

```c++
#include <iostream>
#include <string>
#include "Sales_data.h"

using namespace std;

int main() {
	Sales_data sales_data1;
	print(cout, sales_data1) << endl;

	Sales_data sales_data2("A");
	print(cout, sales_data2) << endl;

	Sales_data sales_data3("A", 1, 2);
	print(cout, sales_data3) << endl;

	Sales_data sales_data4(cin);
	print(cout, sales_data4) << endl;

	return 0;
}
```

### Q13

```
0-201-70353-X 4 24.99
0-201-82470-1 4 45.39
0-201-88954-4 2 15.00 
0-201-88954-4 5 12.00 
0-201-88954-4 7 12.00 
0-201-88954-4 2 12.00 
0-399-82477-1 2 45.39
0-399-82477-1 3 45.39
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00
```

```c++
// Sales_data.h
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data {

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p) : 
               bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(istream &);

};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price() const {
	if (units_sold) {
		return revenue / units_sold;
    }
	else {
		return 0;
    }
}

istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

Sales_data::Sales_data(istream &is) {
	read(is, *this);
}

#endif
```

```c++
#include <iostream>
#include "Sales_data.h"

using namespace std;

int main() {
    Sales_data sum;
    if (read(cin, sum)) {
        Sales_data item;
        while (read(cin, item)) {
            if (sum.isbn() == item.isbn()) {
                sum.combine(item);
            }
            else {
                print(cout, sum) << endl;
                sum = item;
            }
        }
        print(cout, sum) << endl;
    }
    else {
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}
```

### Q14

```c++
Sales_data() : bookNo(""), units_sold(0), revenue(0) {}
```

### Q15

```c++
#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

struct Person {
    string name{""};
    string address{""};
    string getName() const { return name; }
    string getAddress() const { return address; }
    Person() = default;
    Person(const string & n, const string & a) : name(n), address(a) {}
    Person(istream &is) { read(is, *this); }
};

istream& read(istream& is, Person& item) {
    is >> item.name >> item.address;
    return is;
}

ostream& print(ostream& os, const Person& item) {
    os << item.name << " " << item.address;
    return os;
}

#endif
```

### Q16

?????????????????????0????????????????????????????????????????????????????????????????????????????????????????????????????????????public??????????????????????????????????????????public???????????????????????????private??????????????????????????????????????????????????????????????????????????????????????????private??????????????????????????????????????????????????????

### Q17

struct????????????????????????public???class????????????????????????private???

### Q18

?????????????????????????????????,?????????????????????????????????1.?????????????????????????????????????????????????????????2.????????????????????????????????????????????????????????????????????????????????????????????????

### Q19

???????????????????????????????????????????????????

```c++
struct Person {
private:
    string name{""};
    string address{""};
public:
    string getName() const { return name; }
    string getAddress() const { return address; }
    Person() = default;
    Person(const string & n, const string & a) : name(n), address(a) {}
    Person(istream &is) { read(is, *this); }
};
```

### Q20

??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????

### Q21

```
0-201-70353-X 4 24.99
0-201-82470-1 4 45.39
0-201-88954-4 2 15.00 
0-201-88954-4 5 12.00 
0-201-88954-4 7 12.00 
0-201-88954-4 2 12.00 
0-399-82477-1 2 45.39
0-399-82477-1 3 45.39
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00
```

```c++
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

using namespace std;

struct Sales_data {

    friend istream &read(istream &, Sales_data &);
    friend ostream &print(ostream &, const Sales_data &);
    friend Sales_data add(const Sales_data &, const Sales_data &);

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

public:
    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p) : 
               bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(istream &);

};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price() const {
	if (units_sold) {
		return revenue / units_sold;
    }
	else {
		return 0;
    }
}

istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

Sales_data::Sales_data(istream &is) {
	read(is, *this);
}

#endif
```

```c++
#include <iostream>
#include "Sales_data.h"

using namespace std;

int main() {
    Sales_data sum;
    if (read(cin, sum)) {
        Sales_data item;
        while (read(cin, item)) {
            if (sum.isbn() == item.isbn()) {
                sum.combine(item);
            }
            else {
                print(cout, sum) << endl;
                sum = item;
            }
        }
        print(cout, sum) << endl;
    }
    else {
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}
```

### Q22

```c++
#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

struct Person {
    friend istream& read(istream&, Person&);
    friend ostream& print(ostream&, const Person&);
private:
    string name{""};
    string address{""};
public:
    string getName() const { return name; }
    string getAddress() const { return address; }
    Person() = default;
    Person(const string & n, const string & a) : name(n), address(a) {}
    Person(istream &is) { read(is, *this); }
};

istream& read(istream& is, Person& item) {
    is >> item.name >> item.address;
    return is;
}

ostream& print(ostream& os, const Person& item) {
    os << item.name << " " << item.address;
    return os;
}

#endif
```

### Q23

```c++
#ifndef SCREEN_H
#define SCREEN_H

#include <string>

using namespace std;

class Screen {
    public:
        using pos = string::size_type;

        Screen() = default;
        Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c){ }

        char get() const { return contents[cursor]; }
        inline char get(pos ht, pos wt) const;
        Screen &move(pos r, pos c);

    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        string contents;
};


inline Screen &Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

inline char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

#endif
```

### Q24

```c++
#ifndef SCREEN_H
#define SCREEN_H

#include <string>

using namespace std;

class Screen {
    public:
        using pos = string::size_type;

        Screen() = default;
        Screen(pos ht, pos wd) : height(ht), width(wd) {}
        Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) {}

        char get() const { return contents[cursor]; }
        inline char get(pos ht, pos wt) const;
        Screen &move(pos r, pos c);

    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        string contents;
};


inline Screen &Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

inline char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

#endif
```

### Q25

??????Screen???????????????????????????string???????????????????????????????????????

### Q26

```c++
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

using namespace std;

struct Sales_data {

    friend istream &read(istream &, Sales_data &);
    friend ostream &print(ostream &, const Sales_data &);
    friend Sales_data add(const Sales_data &, const Sales_data &);

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

public:
    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    inline double avg_price() const;

    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p) : 
               bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(istream &);

};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

inline double Sales_data::avg_price() const {
	if (units_sold) {
		return revenue / units_sold;
    }
	else {
		return 0;
    }
}

istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

Sales_data::Sales_data(istream &is) {
	read(is, *this);
}

#endif
```

### Q27

```c++
#ifndef SCREEN_H
#define SCREEN_H

#include <string>

using namespace std;

class Screen {
    public:
        using pos = string::size_type;

        Screen() = default;
        Screen(pos ht, pos wd) : height(ht), width(wd) {}
        Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) {}

        char get() const { return contents[cursor]; }
        inline char get(pos ht, pos wt) const;
        Screen &move(pos r, pos c);
        Screen &set(char);
        Screen &set(pos, pos, char);
        Screen &display(ostream &os) { do_display(os); return *this; }
        const Screen &display(ostream &os) const { do_display(os); return *this; }

    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        string contents;
        void do_display(ostream &os) const {os << contents;}
};


inline Screen &Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

inline char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
    contents[r*width + col] = ch;
    return *this;
}

#endif
```

```c++
#include <iostream>
#include "Screen.h"

using namespace std;

int main() {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
}
```

### Q28

```
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXX#XXXX
```

```
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
```

move???set???display????????????Screen????????????????????????set???display?????????????????????myScreen???

### Q29

```c++
#ifndef SCREEN_H
#define SCREEN_H

#include <string>

using namespace std;

class Screen {
    public:
        using pos = string::size_type;

        Screen() = default;
        Screen(pos ht, pos wd) : height(ht), width(wd) {}
        Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) {}

        char get() const { return contents[cursor]; }
        inline char get(pos ht, pos wt) const;
        Screen move(pos r, pos c);
        Screen set(char);
        Screen set(pos, pos, char);
        Screen display(ostream &os) { do_display(os); return *this; }
        const Screen display(ostream &os) const { do_display(os); return *this; }

    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        string contents;
        void do_display(ostream &os) const {os << contents;}
};


inline Screen Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

inline char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline Screen Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen Screen::set(pos r, pos col, char ch) {
    contents[r*width + col] = ch;
    return *this;
}

#endif
```

```c++
#include <iostream>
#include "Screen.h"

using namespace std;

int main() {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
}
```

### Q30

????????????????????????????????????????????????????????????

### Q31

```c++
#ifndef CLASSXY_H
#define CLASSXY_H

class Y;

class X {
    Y *y;
};
class Y {
    X x;
};

#endif
```

### Q32

```c++
#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <vector>

using namespace std;

class Screen;

class Window_mgr {
public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    vector<Screen> screens;
};

class Screen {

friend void Window_mgr::clear(ScreenIndex);

public:
    using pos = string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd) {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) {}

    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wt) const;
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(ostream &os) { do_display(os); return *this; }
    const Screen &display(ostream &os) const { do_display(os); return *this; }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    void do_display(ostream &os) const {os << contents;}
};


inline Screen &Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

inline char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
    contents[r*width + col] = ch;
    return *this;
}

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

#endif
```

### Q33

```c++
#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <vector>

using namespace std;

class Screen;

class Window_mgr {
public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    vector<Screen> screens;
};

class Screen {

friend void Window_mgr::clear(ScreenIndex);

public:
    using pos = string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd) {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) {}

    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wt) const;
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(ostream &os) { do_display(os); return *this; }
    const Screen &display(ostream &os) const { do_display(os); return *this; }
    pos size() const;

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    void do_display(ostream &os) const {os << contents;}
};


inline Screen &Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

inline char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
    contents[r*width + col] = ch;
    return *this;
}

inline Screen::pos Screen::size() const {
    return height * width;
}

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

#endif
```

### Q34

?????????dummy_fcn(pos height)??????pos?????????

### Q35

```c++
typedef string Type;
Type initVal(); // string
class Exercise {
public:
    typedef double Type;
    Type setVal(Type); // double,double
    Type initVal(); // double
private:
    int val;
};

Type Exercise::setVal(Type parm) {  // string,double
    val = parm + initVal();     // Exercise::initVal()
    return val;
}
```

```c++
typedef string Type;
Type initVal();
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();
private:
    int val;
};

Exercise::Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```

### Q36

???????????????????????????????????????????????????????????????????????????????????????rem????????????base???????????????rem????????????base?????????????????????

```c++
struct X {
    X (int i, int j): base(i), rem(i % j) {}
    int base, rem;
};
```

### Q37

```c++
Sales_data first_item(cin);   // Sales_data(istream &is): ????????????????????????

int main() {
  Sales_data next;  // Sales_data(string s = ""): bookNo = "", cnt = 0, revenue = 0.0
  Sales_data last("9-999-99999-9"); // Sales_data(string s = ""): bookNo = "9-999-99999-9", cnt = 0, revenue = 0.0
}
```

### Q38

```c++
Sales_data(istream &is = cin) { read(is, *this); }
```

### Q39

???????????????????????????Sale_data()???????????????

### Q40

```c++
#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book {

public:
    Book() = default;
    Book(unsigned int a, string b, string c) : 
        no(a), name(b), author(c) {}
    Book(istream &is) { is >> no >> name >> author; }

private:
    unsigned int no;
    string name;
    string author;

};

#endif
```

### Q41

```c++
// Sales_data.h
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data {

    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend Sales_data add(const Sales_data &, const Sales_data &);

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

public:
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    inline double avg_price() const;

    Sales_data(std::string s, unsigned n, double p) :
                bookNo(s), units_sold(n), revenue(p*n) {
                    std::cout << "Sales_data(const std::string &s, unsigned n, double p)" << std::endl;
                };
    Sales_data() : Sales_data("", 0, 0) {
        std::cout << "Sales_data()" << std::endl;
    }
    Sales_data(std::string s) : Sales_data(s, 0, 0) {
        std::cout << "Sales_data(std::string s)" << std::endl;
    }
    Sales_data(std::istream &is) : Sales_data() {
        read(is, *this);
        std::cout << "Sales_data(std::istream &is)" << std::endl;
    }

};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

inline double Sales_data::avg_price() const {
	if (units_sold) {
		return revenue / units_sold;
    }
	else {
		return 0;
    }
}

std::istream &read(std::istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

#endif
```

```c++
#include <iostream>
#include "Sales_data.h"

int main() {
    Sales_data item1;
    Sales_data item2("A");
    Sales_data item3("A",0,0);
    Sales_data item4(std::cin);
    return 0;
}
```

### Q42

```c++
#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {

public:
    Book(unsigned int a, std::string b, std::string c) : 
        no(a), name(b), author(c) {}
    Book() : Book(0,"","") {};
    Book(std::istream &is) : Book() { is >> no >> name >> author; }

private:
    unsigned int no;
    std::string name;
    std::string author;

};

#endif
```

### Q43

```c++
class NoDefault {
public:
    NoDefault(int) {};
};
class C {
public:
    C() : my_mem(0) {}
private:
    NoDefault my_mem;
};
```

### Q44

???????????????NoDefault???????????????????????????

### Q45

?????????C????????????????????????

### Q46

1. ???a??????????????????????????????????????????????????????????????????????????????
2. ???b?????????????????????????????????????????????????????????????????????????????????????????????????????????
3. ???c??????????????????????????????????????????????????????????????????
4. ???d???????????????????????????????????????????????????????????????????????????????????????????????????????????????

### Q47

??????
1. ???????????????????????????
2. ????????????????????????????????????????????????

### Q48

??????????????????

### Q49

1. ???a????????????
2. ???b????????????combine???????????????????????????????????????????????????????????????????????????????????????Sales_data &combine(const Sales_data&)????????????
3. ???c???????????????????????????const?????????this???????????????

### Q50

```c++
#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person {
    friend std::istream& read(std::istream&, Person&);
    friend std::ostream& print(std::ostream&, const Person&);
private:
    std::string name{""};
    std::string address{""};
public:
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    Person() = default;
    Person(const std::string & n, const std::string & a) : name(n), address(a) {}
    explicit Person(std::istream &is) { read(is, *this); }
};

std::istream& read(std::istream& is, Person& item) {
    is >> item.name >> item.address;
    return is;
}

std::ostream& print(std::ostream& os, const Person& item) {
    os << item.name << " " << item.address;
    return os;
}

#endif
```

### Q51

string?????????????????????const char*??????????????????????????????????????????????????????????????????string????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????explicit??????string?????????vector?????????????????????int???????????????????????????????????????vector???????????????????????????????????????vector?????????????????????int?????????????????????int??????????????????vector????????????????????????????????????????????????vector?????????????????????????????????explicit??????????????????

### Q52

??????????????????

```c++
struct Sales_data {
    string bookNo;
    unsigned units_sold;
    double revenue;
};
```

### Q53

```c++
#ifndef DEBUG_H
#define DEBUG_H

class Debug {
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(h), other(o) {}
    constexpr bool any() { return hw || io || other; }
    void set_hw(bool b) { hw = b; }
    void set_io(bool b) { io = b; }
    void set_other(bool b) { other = b; }
private:
    bool hw;
    bool io;
    bool other;
};

#endif
```

### Q54

constexpr???????????????const???

### Q55

?????????string?????????????????????

### Q56

1. ??????????????????????????????????????????????????????????????????????????????????????????
2. ??????????????????????????????????????????????????????????????????????????????????????????????????????????????????
3. ??????????????????????????????????????????????????????????????????????????????????????????

### Q57

```c++
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double newRate) { interestRate = newRate; }
private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate(){ return 4.0; }
};
double Account::interestRate = initRate();

#endif
```

### Q58

```c++
// example.h
class Example {
public:
    static double rate;
    static const int vecSize = 20;
    static vector<double> vec;
};
```

```c++
// example.C
#include "example.h"
double Example::rate = 6.5;
vector<double> Example::vec(vecSize);

int main() {
    Sales_data item = {"9999",36,15.88};
    return 0;
}
```