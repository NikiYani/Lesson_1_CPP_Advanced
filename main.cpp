#include <QCoreApplication>
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <type_traits>
#include <vector>
#include <utility>

using namespace std;

struct s_1 {
    int foo() const {return 1;}
};

struct s_2 {
    s_2(const s_2&) {}
    int foo() const {return 1;}
};

enum e1 {};
enum class e2: int {};

template < typename T >
class A
{
public:
    A() = default;
    A( const A& ) = default;

    A( const T& _data )
        : data( _data )
    {
    }
    T data;
};

int foo()
{
    return 168;
}

template < typename T >
class TD; // TD == Type Displayer

template < typename T >
void f( T& param )
{
    TD< T > tType;
    TD< decltype( param ) > paramType;
}

template < typename T, typename U >
auto add( const T& first, const U& second ) -> decltype( first + second )
{
    return first + second;
}

const int&& foo2()
{
    return 2;
}

decltype(auto) fff()
{
    int x = 10;
    return (x);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Проверка типов данных переменных при использовании auto

    //    int a2 = 5;
    //    double b = 4.5;

    //    auto c = b;
    //    auto d = 4.f;

    //    cout << typeid (a2).name() << endl; // выводит i - int
    //    cout << typeid (c).name() << endl; // выводит d - double
    //    cout << typeid (d).name() << endl; // выводит f - float

    // C++17
    // Можно не писать тип данных

    //    vector a2 = {1, 2, 3, 4};

    //    pair p(3ul, 5ul);

    //    A temp(111);

    // Ссылка с использованием auto

    //    const int a2 = 10;
    //    auto& b = a2;
    //    cout << typeid(b).name() << endl;
    //    f(b);

    //    int a2 = 50;
    //    //...
    //    decltype(cout << "hello") b();

    //    cout << add(1, 2.5) << endl;
    //    f(b);

    //    map<string, int> mp;

    //    for (pair<string, int>& it : mp)
    //    {
    //    }

    //    for (const auto& it : mp)
    //    {
    //    }

    //    auto i = foo2();              //  i будет иметь тип int
    //    decltype(auto) i2 = foo2(); //  i2 будет иметь тип const int&&

    //    f(fff);

    //    bool e1_type = std::is_same<
    //            unsigned
    //            ,typename std::underlying_type<e1>::type
    //            >::value;

    //    bool e2_type = std::is_same<
    //            int
    //            ,typename std::underlying_type<e2>::type
    //            >::value;

    //    cout    << "'e1' = " << (e1_type? "unsigned" : "non-unsigned") << endl
    //            << "'e2' = " << (e2_type ? "int" : "non-int") << endl;

    decltype(s_1().foo()) n1 = 1;
//    decltype(s_2().foo()) n2 = n1; не скомпилируется, потому s_1 != s_2
    decltype(std::declval<s_2>().foo()) n2 = n1; // declval позволяет отдать lvalue ссылку с учетом наличия
                                                 // пользовательского конструктора копирования
    std::cout << "n2 = " << n2 << endl;

    return a.exec();
}
