# Advanced Sort Tool

This project provides multiple implementations of a text sorting tool:

## C++ Backend
1. Compile: `cd backend && make`
2. Run: `./build/sorttool samples/test.txt`
3. Options:
   - `-u`: Remove duplicates
   - `-a <algorithm>`: Choose algorithm (quick, merge, heap, random)

## Web Frontend
1. Open `frontend/index.html` in a browser
2. Upload a text file and select options
3. Click "Sort Text"

## Python Version
1. Run: `python python_version/mysort.py python_version/test.txt`
2. Options:
   - `-u`: Remove duplicates
   - `-a <algorithm>`: Choose algorithm (quick, merge, heap, random)

## Sorting Algorithms
- Quick Sort
- Merge Sort
- Heap Sort
- Random Sort
