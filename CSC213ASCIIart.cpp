#include <iostream>
#include <string>
#include <sstream>

std::string operator *(const std::string character, int number){
    std::string temporary;
    for(int i = 0; i <number; ++i){
        temporary+=character;
    }

    return temporary;
}

void draw1(std::string character1, std::string character2);
void draw2(std::string character1, std::string character2);

int main(){
    draw1("/","\\");
    draw2("/","\\");
    system("pause > NUL");
    return 0;
}

void draw1(std::string character1, std::string character2){
    //defining frame
    short int rows = 10,columns = 11;

    //configure spaces
    short int spaces = 5, slashes = 0, counter = 0;

    for(int i = 0; i < rows; ++i){
        //output +----------+ at appropriate intervals
        if(i == 0 || i == 9){
            std::cout << "+-----------+" << std::endl;
        }
        else{
            if(counter <= 3){
                std::cout <<"|" << std::string{" "}*spaces << character1*slashes << "*" << character2*slashes << std::string{" "}*spaces<<"|"<<std::endl;
                ++slashes;
                --spaces;                
            }
            else{
                --slashes;
                ++spaces;
                std::cout <<"|" << std::string{" "}*spaces << character2*slashes << "*" << character1*slashes << std::string{" "}*spaces<<"|"<<std::endl;                    
            }
            ++counter;            
        }
    }
    

}
void draw2(std::string character1, std::string character2){
    //defining frame
    short int rows = 10,columns = 11;

    //configure spaces
    short int spaces = 2, slashes = 3, counter = 0;

    for(int i = 1; i < rows; ++i){
        //output +----------+ at appropriate intervals
        if(i == 0 || i == 9){
            std::cout << "+-----------+" << std::endl;
        }
        else{
            if(counter <= 3){
                std::cout <<"|" << std::string{" "}*spaces << character2*slashes << "*" << character1*slashes << std::string{" "}*spaces<<"|"<<std::endl;
                --slashes;
                ++spaces;                
            }
            else{
                ++slashes;
                --spaces;
                std::cout <<"|" << std::string{" "}*spaces << character1*slashes << "*" << character2*slashes << std::string{" "}*spaces<<"|"<<std::endl;                    
            }
            ++counter;            
        }
    }
}