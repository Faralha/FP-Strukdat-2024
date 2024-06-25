#include <fstream>
#include <iostream>

int main()
{
    std::ofstream outFile("testcase.txt");
    if (!outFile.is_open())
    {
        std::cerr << "Failed to open file for writing.\n";
        return 1;
    }

    // Constants based on the constraints
    const long Kota = 100000;
    const long Jembatan = Kota - 1;
    const long Price = 100;
    const long T = 500000;

    // Write Kota, Jembatan, and Price
    outFile << Kota << " " << Jembatan << " " << Price << "\n";

    // Write initial prices
    for (long i = 1; i <= Kota; ++i)
    {
        outFile << 10 * i << (i < Kota ? " " : "\n");
    }

    // Write edges
    for (long i = 1; i < Kota; ++i)
    {
        outFile << i << " " << i + 1 << "\n";
    }

    // Write T
    outFile << T << "\n";

    // Generate and write transactions
    for (long i = 1; i <= T; ++i)
    {
        if (i % 2 == 0)
        { // Even: Move operation
            outFile << "2 " << (i % Kota) + 1 << "\n";
        }
        else
        { // Odd: Price update
            outFile << "1 " << (i % Kota) + 1 << " " << 10 * ((i % 100) + 1) << "\n";
        }
    }

    outFile.close();
    std::cout << "Testcase written to testcase.txt\n";

    return 0;
}