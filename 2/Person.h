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