// 21 задание 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <string>


struct vector2D {
    double x;
    double y;
};


vector2D add(const vector2D& a, const vector2D& b) {
    return { a.x + b.x, a.y + b.y };
}


vector2D subtract(const vector2D& a, const vector2D& b) {
    return { a.x - b.x, a.y - b.y };
}


vector2D scale(const vector2D& v, double s) {
    return { v.x * s, v.y * s };
}


double length(const vector2D& v) {
    return std::sqrt(v.x * v.x + v.y * v.y);
}


vector2D normalize(const vector2D& v) {
    double len = length(v);
    if (len == 0)  
    { 
        return { 0, 0 }; 
    }
    return { v.x / len, v.y / len };
}

int main() {
    std::string operation;

    while (true) {
        std::cout << "Enter operation (add, subtract, scale, length, normalize, exit): " << std::endl; 
        std::cin >> operation;

        if (operation == "exit") {
            std::cout << "Goodbuy!!!!!!" << std::endl; 
            break;
        }

        if (operation == "add") {
            vector2D v1, v2;
            std::cout << "Enter first vector (x y): " << std::endl; 
            std::cin >> v1.x >> v1.y;
            std::cout << "Enter second vector (x y): " << std::endl; 
            std::cin >> v2.x >> v2.y;

            vector2D result = add(v1, v2);
            std::cout << "Result: (" << result.x << ", " << result.y << ")" << std::endl; 

        }
        else if (operation == "subtract") {
            vector2D v1, v2;
            std::cout << "Enter first vector (x y): " << std::endl;
            std::cin >> v1.x >> v1.y;
            std::cout << "Enter second vector (x y): " << std::endl;
            std::cin >> v2.x >> v2.y;

            vector2D result = subtract(v1, v2);
            std::cout << "Result: (" << result.x << ", " << result.y << ")" << std::endl;

        }
        else if (operation == "scale") {
            vector2D v;
            double s;
            std::cout << "Enter vector (x y): " << std::endl;
            std::cin >> v.x >> v.y;
            std::cout << "Enter scalar: " << std::endl;
            std::cin >> s;

            vector2D result = scale(v, s);
            std::cout << "Result: (" << result.x << ", " << result.y << ")" << std::endl;

        }
        else if (operation == "length") {
            vector2D v;
            std::cout << "Enter vector (x y): " << std::endl;
            std::cin >> v.x >> v.y;

            double len = length(v);
            std::cout << "Length: " << len << std::endl; 

        }
        else if (operation == "normalize") {
            vector2D v;
            std::cout << "Enter vector (x y): " << std::endl;
            std::cin >> v.x >> v.y;

            vector2D norm = normalize(v);
            std::cout << "Normalized: (" << norm.x << ", " << norm.y << ")" << std::endl; 

        }
        else {
            std::cout << "Unknown operation!" << std::endl; 
        }
    }

    return 0;
}

