#include <vector>
#include <string>

void merge(std::vector<std::string>& words, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    std::vector<std::string> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = words[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = words[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            words[k] = L[i];
            i++;
        } else {
            words[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        words[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        words[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<std::string>& words, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(words, left, mid);
        mergeSort(words, mid + 1, right);
        merge(words, left, mid, right);
    }
}
