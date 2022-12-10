#pragma once
#include <string>
class airplane
{
private:
    std::string id;
    std::string company;
    int hour[2];

public:
    explicit airplane(std::string id_number);
    void set_id(std::string);
    void set_hour(int[2]);
    int get_hour(int index) const;
    std::string get_id() const;
    std::string get_company() const;
};
