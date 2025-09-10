#ifndef PROGRESS_BAR_HPP
    #define PROGRESS_BAR_HPP

    #include <iostream>
    #include <iomanip>
    #include <functional>
    #include "aria.hpp"

    std::function<void(int)> createUpdateProgressBar(int steps);

    void progress_bar(int progress, int total, const std::string& color);
    void executeTaskWithProgressBar(std::vector<std::function<void()>>& tasks);

#endif