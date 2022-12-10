#include<iostream>
using namespace std;
#include "../include/airplane.hpp"
airplane::airplane(string id_number)
{
    id = id_number;
    hour[1] = hour[0] = -1;
}
void airplane::set_hour(int h[2])
{
    hour[0] = h[0];
    hour[1] = h[1];
}
void airplane::set_id(string id_number)
{
    id = id_number;
}

int airplane::get_hour(int index) const
{
    if (hour[index] == -1)
    {
        cout<< "time not set"<<endl;
        return -1;

    }
    return hour[index];//0 start and 1 end
}
string airplane::get_id() const
{
    return id;
}
string airplane::get_company() const
{
    return company;
}