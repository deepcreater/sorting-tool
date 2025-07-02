#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <random>
#include <functional> // for std::hash

// Include sorting algorithms
#include "sort_algorithms/quicksort.hpp"
#include "sort_algorithms/mergesort.hpp"
#include "sort_algorithms/heapsort.hpp"

void printUsage() {
    std::cout << "Usage:\n"
              << "  ./sorttool <input_file>\n"
              << "  ./sorttool -u <input_file>\n"
              << "  ./sorttool -a <algorithm> <input_file>\n"
              << "  ./sorttool -a random -u <input_file>\n\n"
              << "Algorithms: quick, merge, heap, random\n";
}

std::vector<std::string> readFile(const std::string& filename) {
    std::vector<std::string> words;
    std::ifstream file(filename);
    std::string word;
    
    while (file >> word) {
        words.push_back(word);
    }
    
    return words;
}

void writeOutput(const std::vector<std::string>& words) {
    for (const auto& word : words) {
        std::cout << word << "\n";
    }
}

std::vector<std::string> removeDuplicates(const std::vector<std::string>& words) {
    std::unordered_set<std::string> uniqueWords(words.begin(), words.end());
    return std::vector<std::string>(uniqueWords.begin(), uniqueWords.end());
}

void randomSort(std::vector<std::string>& words) {
    std::hash<std::string> hasher;
    auto seed = std::random_device()();
    std::default_random_engine rng(seed);
    
    std::sort(words.begin(), words.end(), [&](const std::string& a, const std::string& b) {
        return hasher(a) < hasher(b);
    });
}

int main(int argc, char* argv[]) {
    std::string algorithm = "quick";
    bool unique = false;
    std::string filename;
    
    // Parse command line arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-a" && i + 1 < argc) {
            algorithm = argv[++i];
        } else if (arg == "-u") {
            unique = true;
        } else if (arg[0] != '-') {
            filename = arg;
        }
    }
    
    if (filename.empty()) {
        printUsage();
        return 1;
    }
    
    auto words = readFile(filename);
    
    // Apply selected sorting algorithm
    if (algorithm == "quick") {
        quickSort(words, 0, words.size() - 1);
    } else if (algorithm == "merge") {
        mergeSort(words, 0, words.size() - 1);
    } else if (algorithm == "heap") {
        heapSort(words);
    } else if (algorithm == "random") {
        randomSort(words);
    } else {
        std::sort(words.begin(), words.end());
    }
    
    // Remove duplicates if requested
    if (unique) {
        words = removeDuplicates(words);
    }
    
    writeOutput(words);
    return 0;
}
