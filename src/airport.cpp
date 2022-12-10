#include "../include/airplane.hpp"
#include "../include/airport.hpp"
using namespace std;
#include <vector>
void airport::add(string id_number)
{
    airplane op(id_number);
    air_plane.push_back(op);
}