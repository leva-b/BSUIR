#include <iostream>

int binpow(int a, int n) {
    std::cout << "x = " << a << "\n";
    std::cout << "y = " << n << "\n";
    
    int res = 1;
    std::cout << "result = " << res << "\n";
    while (n != 0) {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
        std::cout << "x = " << a << "\n" << "y = " << n << "\n";
        std::cout << "result = " << res << "\n"; 
    }
    return res;
}

int main(){
    int x, y, z;
    std::cout << "Введите два натуральных числа ";
    std::cin >> x >> y;
    z = binpow(x,y);
    std::cout << "Результат возведения числа " << x << " в степень " << y << " равен " << z;
    return 0;
}