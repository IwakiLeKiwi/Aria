#include "utils/progressBar.hpp"

void progress_bar(int progress, int total, const std::string& color) {
    float percent = 100.0f * (static_cast<float>(progress) / total);
    int filled_blocks = static_cast<int>(percent);
    int empty_blocks = 100 - filled_blocks;
    std::string bar(filled_blocks, '=');
    bar += std::string(empty_blocks, '-');
    std::cout << color << "\r[" << bar << "] " << std::fixed << std::setprecision(2) << percent << "% " << std::flush;
    if (progress == total) {
        std::cout << "\r" << "\033[1;32m" << "\r[" << bar << "] " << std::fixed << std::setprecision(2) << percent << "%\u001b[0m" << std::flush;
        std::cout << std::endl;
    }
}

std::function<void(int)> createUpdateProgressBar(int steps) {
    return [steps](int currentStep) {
        progress_bar(currentStep, steps, currentStep == steps ? "\033[1;32m" : "\033[1;33m");
    };
}

/**
 * @param tasks
 */
void executeTaskWithProgressBar(std::vector<std::function<void()>>& tasks) {
    try {
        auto updateProgress = createUpdateProgressBar(tasks.size());

        for (size_t i = 0; i < tasks.size(); i++) {
            tasks[i]();
            updateProgress(i + 1);
        }
    } catch (const std::exception &e) {
        Aria::err("File create error: " + std::string(e.what()));
    }
}