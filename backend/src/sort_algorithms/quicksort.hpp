#include <vector>
#include <string>

int partition(std::vector<std::string>& words, int low, int high) {
    std::string pivot = words[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (words[j] < pivot) {
            i++;
            std::swap(words[i], words[j]);
        }
    }
    std::swap(words[i + 1], words[high]);
    return i + 1;
}

void quickSort(std::vector<std::string>& words, int low, int high) {
    if (low < high) {
        int pi = partition(words, low, high);
        quickSort(words, low, pi - 1);
        quickSort(words, pi + 1, high);
    }
}
