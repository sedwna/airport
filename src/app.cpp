#include "../include/app.hpp"
#include "../include/airplane.hpp"
#include "../include/airport.hpp"

#include <iostream>
#include <iomanip>
#include <exception>

using namespace std;

App ::App()
{
    splashScreen();
}

void App::splashScreen() const
{
    cout << "     ______|______|______         \n";
    cout << "     |  || ======== ||  |         \n";
    cout << "     |  || ======== ||  |         \n";
    cout << " |___|__||_========_||__|_ __|   \n";
    cout << "   |=|===================|=|      \n";
    cout << "   |=|                   |=|      \n";
    cout << "   |=|  Airport Manager  |=|      \n";
    cout << "   |                       |      \n";
    cout << "   |=======================|      \n";
    cout << " ==|-------|||||||||-------|==    \n";
    cout << endl;
    cout << "[<!>] "
         << "Enter <help> command to guide you\n"
         << endl;
}

int App ::exec()
{
    do
    {
        try
        {
            string command;
            cout << "> ";
            getline(cin, command);
            lowercase(command);
            removeExtraSpaces(command);
            splitter(command);

            {
                /* code */
            }

            if (cin.eof() || command == "exit")
            {
                status = false;
            }
            else if (command == "help")
            {
                help();
            }
            else if (command == "airport")
            {
                airport_manager();
                manage = "airport";
            }
            else if (command == "travel")
            {
                travel_manager();
                manage = "travel";
            }
            else if (command == "add")
            {
                add();
            }

            else if (command == "clear")
            {
                clear();
            }
            else if (command.empty())
            {
                // to prevent print undefined command in empty command
            }
            else if (command == "log")
            {
                log();
            }
            else
            {
                throw "undefined command";
            }
        }
        catch (const char *message)
        {
            std::cerr << "[<!>] " << message << endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "[<!>] " << e.what() << endl;
        }

    } while (status);
}

void App::help() const
{
    cout << "[<!>] "
         << "app commands : (case insensitive)" << endl;
    cout << "\n\tEnter <airport> command to manage airport\n"
         << "\tEnter <travel> command to manage passenger\n"
         << "\n\tEnter <airport> command to manage airport\n"
         << endl;

    cout << "\thelp"
         << "\tKnow the commands of the app" << endl;
    cout << "\tclear"
         << "\tclear app screen" << endl;
    cout << "\texit"
         << "\texit app" << endl;
}

void App::clear() const
{
    std::system("cls");
    splashScreen();
}

void App::lowercase(string &str)
{
    if (cin.eof() || str.empty())
    {
        return;
    }

    for (char &ch : str)
    {
        ch = tolower(ch);
    }
}

void App::splitter(string &str)
{
    if (cin.eof() || str.empty())
    {
        return;
    }

    // separate argument
    size_t index = 0;

    for (const char &ch : str)
    {
        if (ch == ' ')
        {
            for (size_t i = index + 1; i < str.size(); i++)
            {
                argument.push_back(str.at(i));
            }

            if (argument.at(0) != '-')
            {
                throw invalid_argument("your command argument is invalid");
            }

            str.erase(str.begin() + index, str.end());
            break;
        }

        index++;
    }
}

void App::removeExtraSpaces(string &str)
{
    if (cin.eof() || str.empty())
    {
        return;
    }

    size_t index = 0;

    for (char &item : str)
    {
        if (item == ' ') // white spaces must decrease to one space
        {
            while (1)
            {
                size_t j = index;

                if (j == (str.size() - 1))
                {
                    break;
                }
                else if (str.at(j) == ' ' && str.at(j + 1) == ' ')
                {
                    str.erase(j + 1, 1);
                    j++;
                }
                else
                {
                    break;
                }
            }
        }

        index++;
    }

    // remove the remaining space from the first of string
    if (str.at(0) == ' ')
    {
        str.erase(0, 1);
    }
    // remove the remaining space from the end of string
    size_t i = str.size();

    if (str.at(--i) == ' ')
    {
        str.erase(i, 1);
    }
}
void App::airport_manager()
{
    cout << setw(15) << left << "\t  add -p" << setw(100) << left << "\tadd a pilot" << endl;
    cout << setw(15) << left << "\t  add -h" << setw(100) << left << "\tadd a host" << endl;
    cout << setw(15) << left << "\t  add -a" << setw(100) << left << "\tadd an airplane" << endl;
    cout << setw(15) << left << "\t  add -t" << setw(100) << left << "\tadd a Delivery truck" << endl;

    cout << endl;
}
void App::travel_manager()
{
    cout << setw(15) << left << "\t  add -f" << setw(100) << left << "\tadd a flight" << endl;
    cout << setw(15) << left << "\t  add -p" << setw(100) << left << "\tadd a passenger" << endl;
    cout << endl;
}

void App::add()
{
    string id;

    if (manage == "airport")
    {
        if (argument == "-a")
        {
            cout << "Enter airplane ID you want to create : ";
            getline(cin, id);
            Ob_air_plane.add(id);
        }
        else if (argument == "-t")
        {
            cout << "Enter delivery truck ID you want to create : ";
            getline(cin, id);
        }
        else if (argument == "-p")
        {
            cout << "Enter Pilot ID you want to create : ";
            getline(cin, id);
        }
        else if (argument == "-h")
        {
            cout << "Enter host ID you want to create : ";
            getline(cin, id);
        }
    }
    else if (manage == "travel")
    {
        if (argument == "-f")
        {
            cout << "Enter flight ID you want to create : ";
            getline(cin, id);
        }
        else if (argument == "-p")
        {
            cout << "Enter passenger ID you want to create : ";
            getline(cin, id);
        }
    }
}

void App::log() const
{
    string id;
    cout << "Enter an id: ";
    cin >> id;
    for (size_t i = 0; i < Ob_air_plane.air_plane.size(); i++)
    {
        if (Ob_air_plane.air_plane[i].get_id() == id)
        {
            cout << Ob_air_plane.air_plane[i].get_id() << endl;
            cout << Ob_air_plane.air_plane[i].get_company() << endl;
            cout << Ob_air_plane.air_plane[i].get_hour(0) << endl;
            cout << Ob_air_plane.air_plane[i].get_hour(1) << endl;
            break;
        }
    }
}
