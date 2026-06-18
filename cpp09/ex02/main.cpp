#include "PmergeMe.hpp"

#define RED   "\033[31m"
#define RESET "\033[0m"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: No arguments provided.\n" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe pm;
        pm.parseArgs(argc, argv);

        std::vector<int> vec = pm.getVec();
        std::deque<int> deq = pm.getDeq();

        std::cout << "running Ford-Johnson algorithm using a vector...\nbefore: ";
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " ";
        std::cout << "\n";

        clock_t startClock = clock();
        vec = pm.sortVec(vec);
        clock_t endClock = clock();
        double vecElapsedTime = static_cast<double>(endClock - startClock) / CLOCKS_PER_SEC * 1000000;

        std::cout << "after:  ";
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " ";

        std::cout << "\n\nrunning Ford-Johnson algorithm using a deque...\nbefore: ";
        for (size_t i = 0; i < deq.size(); i++)
            std::cout << deq[i] << " ";
        std::cout << "\n";

        startClock = clock();
        deq = pm.sortDeq(deq);
        endClock = clock();
        double deqElapsedTime = static_cast<double>(endClock - startClock) / CLOCKS_PER_SEC * 1000000;

        std::cout << "after:  ";
        for (size_t i = 0; i < deq.size(); i++)
            std::cout << deq[i] << " ";

        std::cout << "\n\nTime to process " << vec.size() << " elements with a vector: "
                  << vecElapsedTime << " microseconds" << std::endl;
        std::cout << "Time to process " << deq.size() << " elements with a deque: "
                  << deqElapsedTime << " microseconds" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

