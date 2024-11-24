/*DEPRACATED
Please Look at source.cpp instead.*/
#include <iomanip>
#include <ostream>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

struct DiseaseData {
    int disease_code;
    std::string county;
    unsigned int year;
    std::string sex;
    unsigned int count;
    long long population;
};

struct DiseaseInformation {
    int disease_code;
    std::string disease;
};

std::istream& operator>>(std::istream& content, DiseaseData& data) {
    content >> data.disease_code >> data.county >> data.year >> data.sex >> data.count >> data.population;
    return content;
}

std::istream& operator>>(std::istream& content, DiseaseInformation& data) {
    content >> data.disease_code >> data.disease;
    return content;
}

void viewCidDataByCountyGenderYear(std::string disease_info_file, std::string disease_data_file, std::string county_name, std::string sex, unsigned int year);

int main() {
    viewCidDataByCountyGenderYear("test_cid_data.txt", "test_disease_info.txt", "Alpine", "Male", 2001);
    std::cin.get();
    return 0;
}

void viewCidDataByCountyGenderYear(std::string disease_info_file, std::string disease_data_file, std::string county_name, std::string sex, unsigned int year) {
    std::ifstream disease_info_stream(disease_info_file, std::ios::in);
    std::ifstream disease_data_stream(disease_data_file, std::ios::in);
    std::string buffer;

    int total_count = 0;
    int record_count = 0;
    float rate_count = 0;

    std::getline(disease_info_stream, buffer);
    std::getline(disease_data_stream, buffer);

    DiseaseData states;
    DiseaseInformation ailment;

    std::cout << "COUNTY NAME\t" << county_name << '\n';
    std::cout << "GENDER/SEX \t" << sex << '\n';
    std::cout << "YEAR       \t" << year << '\n';
    std::cout << std::string((50 + 13 + 13 + 4), '=') << std::endl;

    std::cout << std::left << std::setw(13) << "DIS-CODE"
              << std::setw(50) << "DIS-NAME" << std::setw(13) << "COUNT"
              << std::setw(13) << "RATE\n";

    while (std::getline(disease_info_stream, buffer)) {
        std::istringstream d_i_string(buffer);
        d_i_string >> states;

        if (states.county == county_name && states.sex == sex && states.year == year) {
            disease_data_stream.clear();
            disease_data_stream.seekg(0, std::ios::beg);
            std::getline(disease_data_stream, buffer); // Skip header

            while (std::getline(disease_data_stream, buffer)) {
                std::istringstream d_d_string(buffer);
                d_d_string >> ailment;

                if (states.disease_code == ailment.disease_code) {
                    std::cout << std::left << std::setw(13) << ailment.disease_code
                              << std::setw(50) << ailment.disease << std::setw(13) << states.count
                              << std::setw(13) << (states.count * 100000 / states.population) << '\n';

                    total_count += states.count;
                    rate_count += static_cast<float>(states.count) * 100000 / states.population;
                    record_count++;
                }
            }
        }
    }

    float average_count = static_cast<float>(total_count) / record_count;

    std::cout << std::setw((50 + 13 + 13 + 4)) << std::setfill('=') << '\n';
    std::cout << std::left << "TOTAL" << std::setw(50 + 13 + 13 + 13) << std::right << total_count << '\n';
    std::cout << "NUMBER OF RECORDS(N)" << std::setw(50 + 13 + 13) << record_count << '\n';
    std::cout << "AVERAGE COUNT" << std::setw(50 + 13 + 13) << average_count << '\n';
}
