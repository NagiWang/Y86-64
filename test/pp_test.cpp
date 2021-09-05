#include <preprocessor.hpp>

int main()
{
    std::string filename;

    // while (true) {
        std::cout << "path:\n";
        std::getline(std::cin, filename);

        // if (filename != "q") break;

        auto lines = readlines(filename);
        std::ranges::for_each(lines, [](std::string_view str) { std::cout << str << '\n'; });
    // }

    return 0;
}
