/*
#include <iostream>

int ReadAge() {
    int age; // can be "bad alloc"
    std::cin >> age; // can be "incorrect value"
    if(age < 0 || age >=128){
        return -1;
    }
    return age;
}

int main() {
    if(int age = ReadAge(); age == -1) {
        std::cout<<"error"<<"\n";
    }else {
        std::cout<<"is not in the range"<<"\n";
    }

}
*/

#include <iostream>

struct WrongAgeException {
    int age;
};

int ReadAge() {
    std::cin.exceptions(std::istream::failbit);
    int age;
    std::cin >> age;
    if(age < 0 || age >=128){
        throw WrongAgeException(age);
    }
    return age;
}

int main() {
    try {
        int age = ReadAge();
    } catch (const WrongAgeException& ex) {
        std::cerr<<"Age is not correct:"<<ex.age<<"\n";
        return 1;
    } catch (const std::istream::failure& ex){
        std::cerr<<"Failed to read stream:"<<ex.what()<<"\n";
        return 1;
    } catch(...) {
        std::cout<<"Uknown exception\n";
        return 1;
    }
}
