#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

struct DiseaseData{
    int Disease_Code;
    std::string County;
    int Year;
    std::string Sex;
    int Count;
    size_t Population;
};

struct DiseaseInfo{
    int Disease_Code;
    std::string Disease;
};

std::istream& operator >> (std::istream& is, DiseaseData& data){
    is >> data.Disease_Code >> data.County >> data.Year >> data.Sex >> data.Count >> data.Population;
    return is; 
}


std::istream& operator >> (std::istream& is, DiseaseInfo& data){
    is >> data.Disease_Code >> data.Disease;
    return is; 
}


void viewCidDataByYear(std::string disease_info, std::string disease_data, std::string county, std::string sex, int year);


int main() {
    viewCidDataByYear("test_cid_data.txt", "test_disease_info.txt", "California", "Male", 2001);
    std::cin.get();
    return 0;
}


void viewCidDataByYear(std::string disease_info, std::string disease_data, std::string county, std::string sex, int year){
    std::ifstream disease_data_stream(disease_info, std::ios::in);
    std::ifstream disease_info_stream(disease_data, std::ios::in);
    std::string buffer;
    
    std::getline(disease_info_stream,buffer);
    std::getline(disease_data_stream,buffer);
    
    DiseaseInfo di_info;
    DiseaseData di_data;
    
    int total_count = 0, total_rate = 0;

    std::cout << "COUNTY NAME\t" << county << '\n';
    std::cout << "GENDER/SEX \t" << sex << '\n';
    std::cout << "YEAR       \t" << year << '\n';
    std::cout << std::string((50 + 13 + 13 + 4), '=') << std::endl;

    std::cout << std::left;
    std::cout << std::setw(13) << "DIS-CODE"
              << std::setw(50) << "DIS-NAME" << std::setw(13) << "COUNT"
              << std::setw(13) << "RATE" << std::endl;
     
    std::cout << std::string((50 + 13 + 13 + 4), '=') << std::endl;
    int record_count;
    while(std::getline(disease_data_stream,buffer)){
        std::istringstream d_d_stream(buffer);
        d_d_stream >> di_data;
        
        if(di_data.County == county && di_data.Sex == sex && di_data.Year == year){
            while(std::getline(disease_info_stream, buffer)){
                std::istringstream d_i_stream(buffer);
                d_i_stream >> di_info;

                if(di_info.Disease_Code == di_data.Disease_Code){
                              std::cout << std::left;
                              std::cout<<std::setw(13) << di_info.Disease_Code
                              << std::setw(50) << di_info.Disease << std::setw(13) << di_data.Count
                              << std::setw(13) << ((di_data.Count * 100000) / (di_data.Population)) << std::endl;

                    total_count+=di_data.Count;
                    total_rate += ((di_data.Count * 100000)/(di_data.Population)); 
                    record_count++;
                }
                
            }
            disease_info_stream.clear();
            disease_info_stream.seekg(1);
        }
    }

    float average_count = static_cast<float>(total_count) / record_count;

    std::cout << std::string((50 + 13 + 13 + 4), '=') << std::endl;
    std::cout << std::left << "TOTAL" << std::setw(13 + 13 + 13) << std::right << total_count << std::setw(50) <<std::right << total_rate <<std::endl;
    std::cout << "NUMBER OF RECORDS(N)" << std::setw(50 + 13 + 13) << record_count << std::endl;
    std::cout << "AVERAGE COUNT" << std::setw(50 + 13 + 13) << average_count << std::endl;
}

