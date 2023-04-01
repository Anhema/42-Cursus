#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    std::string line;

    if (argc != 2)
    {
        std::cout << "Error: could not open file.\n";
        return (0);
    }
    std::ifstream myfile;
    myfile.open (argv[1]);
    if (myfile.is_open())
    {
        while(getline(myfile, line, ','))
        {
            std::cout << line << "\n";
        }
        myfile.close();
    }
    else
    {
        std::cout << "Error: could not open file.\n";
        return (0);
    }
}
