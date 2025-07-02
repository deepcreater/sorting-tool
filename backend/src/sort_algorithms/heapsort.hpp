#include <vector>
#include <string>

void heapify(std::vector<std::string>& words, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && words[left] > words[largest])
        largest = left;
    
    if (right < n && words[right] > words[largest])
        largest = right;
    
    if (largest != i) {
        std::swap(words[i], words[largest]);
        heapify(words, n, largest);
    }
}

void heapSort(std::vector<std::string>& words) {
    int n = words.size();
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(words, n, i);
    
    for (int i = n - 1; i > 0; i--) {
        std::swap(words[0], words[i]);
        heapify(words, i, 0);
    }
}
