//
//  Stock.hpp
//  C++_Study
//
//  Created by yfm on 2022/9/15.
//

#ifndef Stock_hpp
#define Stock_hpp

#include <string>

/**
 结构的默认访问时public，类是private
 */
class Stock {
private: // 不必使用关键字，因为这是类对象默认访问控制
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};

#endif /* Stock_hpp */
