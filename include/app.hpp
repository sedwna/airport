
#include <string>
#include "../include/airport.hpp"

class App
{
private:
    std::string manage;
    bool status;
    std::string argument;
    airport Ob_air_plane;
    
    void help() const;
    void clear() const;
    void lowercase(std::string &);
    void splitter(std::string &);
    void removeExtraSpaces(std::string &);
    void add();
    void remove();
    void log() const;
    void travel_manager();
    void airport_manager();
public:
    App();
    void splashScreen() const;
    int exec();

};
