/*Calculate the perimeter and area of a rectangle - console. BSC. IT*/

#include <iostream>

#ifdef _WIN32
#define cl "cls"
#else
#define cl "clear"
#endif

struct Rect{
    float x, y;
    float width, height;
};

void calculate_perimeter(const Rect& rectangle){
    std::cout << "Perimeter : " << ((rectangle.width * 2) + (rectangle.height * 2)) << '\n';
}

void calculate_area(const Rect& rectangle){
    std::cout << "Area : " << (rectangle.width * rectangle.height) << '\n';
}

void clean_up(){
    std::cin.clear();
    std::cin.ignore();
    system(cl);
}

void set_parameters(Rect& rectangle){
    float x, y, width, height;
    std::cout << "Enter x-axis : ";
    std::cin >> x;
    std::cout << "Enter y-axis : ";
    std::cin >> y;

    while(true){
        std::cout << "Enter width(length) : ";
        std::cin >> width;
        std::cout << "Enter height : ";
        std::cin >> height;

        if(width < 0.0 || height < 0.0){
            std::cerr << "It's a rectangle, you can't have negative proportions in width or height. Hit enter to reset.\n";
            std::cin.get();
            clean_up();
            continue;
        }else if(std::cin.fail()){
            std::cerr << "Only enter numeral values, please. Hit enter to reset.\n";
            std::cin.get();
            clean_up();
            continue;
        }
        break;
    }

    rectangle = {
        x,
        y,
        width,
        height
    };
}

int main(){
    Rect rectangle;
    set_parameters(rectangle);
    calculate_perimeter(rectangle);
    calculate_area(rectangle);

    std::cin.get();
    return 0;
}
