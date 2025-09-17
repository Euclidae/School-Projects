#include <iostream>
#include <fstream>
#include <iomanip>

struct criminal_offense{
    int offence_code;
    std::string offence_code_group, UCR_part;
};

struct boston_crime_info{
    int incident_number, offence_code;
    std::string district;
    std::string reporting_area;
    char shooting;
    int year;
    int month;
    std::string day_of_week;
    int hour;
};

std::istream& operator >> (std::istream& is, criminal_offense& c){
    is >> c.offence_code >> c.offence_code_group >> c.UCR_part;
    return is;
}

std::istream& operator >> (std::istream& is, boston_crime_info& b){
    is >> b.incident_number >> b.offence_code >> b.district >> b.reporting_area >> b.shooting >> b.year >> b.month >> b.day_of_week >> b.hour;
    return is;
}


void do_something(std::string input_1, std::string input_2, int year, std::string day_of_week){
    std::ifstream criminal_stream(input_1, std::ios::in);
    if(criminal_stream.fail()){
        return;
    }
    criminal_offense c;
    boston_crime_info b;
    std::string buffer;
    std::getline(input_1,buffer);
    while(criminal_stream >> c){
        std::ifstream crime_stream(input_2, std::ios::in);
        std::getline(input_2,buffer);
        std::cout << "Offense code : " << c.offence_code <<'\n';
        std::cout << "Offense code group : " << c.offence_code_group << '\n';
        std::cout << "UCR_part : " << c.UCR_part <<'\n';
        std::cout <<std::setw(25) << "INC_NUMBER" <<std::setw(25) << "CODE" <<std::setw(25) << "DISTRICT" <<std::setw(25) << "AREA" <<std::setw(25) << "SHOOTING" <<std::setw(25) << "YEAR" <<std::setw(25) << "MONTH" <<std::setw(25) << "DAY_OF_WEEK" <<std::setw(25) << "HOUR" <<std::endl;
        while(crime_stream >> b){
            if(b.year == c.year && (day_of_week == b.day_of_week ||day_of_week == "ALL") ){
                if(day_of_week != "ALL"){
                    if(day_of_week == b.day_of_week){
                        std::cout << std::setw(25) << b.incident_number << std::setw(25) << b.code << std::setw(25) << b.district << std::setw(25) << b.area << std::setw(25) << b.shooting << std::setw(25) << b.year << std::setw(25) << b.month << std::setw(25) << b.day_of_week << std::setw(25) << b.hour << std::endl;
                    }
                }else if(day_of_week == "ALL"){
                    std::cout << std::setw(25) << b.incident_number << std::setw(25) << b.code << std::setw(25) << b.district << std::setw(25) << b.area << std::setw(25) << b.shooting << std::setw(25) << b.year << std::setw(25) << b.month << std::setw(25) << b.day_of_week << std::setw(25) << b.hour << std::endl;
                }
            }
        }

        crime_stream.close();

    }
    criminal_stream.close();
}

int main(){
    do_something("criminal_offense.txt", "boston_crime_info.txt", 2003, "ALL");
    return 0;
}