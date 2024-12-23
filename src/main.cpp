#include <iostream>

namespace Filip
{
    int Main(int& argc, const char** args)
    {
        std::cout << "Ruleaza din " << args[0] << "!" << std::endl; // TODO: O functie care scoate un const char* care reprezinta directorul din care ruleaza programul
        return EXIT_SUCCESS;
    }
}

int main(int argc, const char** args)
{
    return Filip::Main(argc, args);
}