import sys
import time
import random
import argparse
from heapq import heappush, heappop

def read_file(filename):
    with open(filename, 'r') as file:
        words = file.read().split()
    return words

def write_output(words):
    print('\n'.join(words))

def remove_duplicates(words):
    return list(dict.fromkeys(words))

def quick_sort(words):
    if len(words) <= 1:
        return words
    pivot = words[len(words) // 2]
    left = [x for x in words if x < pivot]
    middle = [x for x in words if x == pivot]
    right = [x for x in words if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

def merge_sort(words):
    if len(words) <= 1:
        return words
    
    mid = len(words) // 2
    left = merge_sort(words[:mid])
    right = merge_sort(words[mid:])
    
    result = []
    i = j = 0
    
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    
    result.extend(left[i:])
    result.extend(right[j:])
    return result

def heap_sort(words):
    h = []
    for word in words:
        heappush(h, word)
    return [heappop(h) for _ in range(len(h))]

def random_sort(words):
    random.shuffle(words)
    return words

def main():
    parser = argparse.ArgumentParser(description='Advanced Sort Tool')
    parser.add_argument('filename', help='Input file to sort')
    parser.add_argument('-u', '--unique', action='store_true', help='Remove duplicate words')
    parser.add_argument('-a', '--algorithm', choices=['quick', 'merge', 'heap', 'random'], 
                        default='quick', help='Sorting algorithm to use')
    
    args = parser.parse_args()
    
    start_time = time.time()
    
    words = read_file(args.filename)
    
    if args.algorithm == 'quick':
        sorted_words = quick_sort(words)
    elif args.algorithm == 'merge':
        sorted_words = merge_sort(words)
    elif args.algorithm == 'heap':
        sorted_words = heap_sort(words)
    elif args.algorithm == 'random':
        sorted_words = random_sort(words)
    else:
        sorted_words = sorted(words)
    
    if args.unique:
        sorted_words = remove_duplicates(sorted_words)
    
    write_output(sorted_words)
    
    end_time = time.time()
    print(f"\nSorted {len(words)} words ({len(set(words))} unique)", file=sys.stderr)
    print(f"Algorithm: {args.algorithm}, Time: {(end_time - start_time)*1000:.2f}ms", file=sys.stderr)

if __name__ == '__main__':
    main()
