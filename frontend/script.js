document.addEventListener('DOMContentLoaded', function() {
    const fileInput = document.getElementById('file-input');
    const algorithmSelect = document.getElementById('algorithm');
    const uniqueCheckbox = document.getElementById('unique');
    const sortBtn = document.getElementById('sort-btn');
    const outputTextarea = document.getElementById('output');
    const wordCountSpan = document.getElementById('word-count');
    const uniqueCountSpan = document.getElementById('unique-count');
    const timeSpan = document.getElementById('time');

    sortBtn.addEventListener('click', handleSort);

    function handleSort() {
        const file = fileInput.files[0];
        if (!file) {
            alert('Please select a file first!');
            return;
        }

        const reader = new FileReader();
        reader.onload = function(e) {
            const startTime = performance.now();
            const content = e.target.result;
            const words = content.split(/\s+/).filter(word => word.length > 0);
            
            // Update word count
            wordCountSpan.textContent = `${words.length} words`;
            
            // Apply selected algorithm (simulated in JS)
            const algorithm = algorithmSelect.value;
            let sortedWords = [...words];
            
            switch (algorithm) {
                case 'quick':
                    sortedWords.sort();
                    break;
                case 'merge':
                    sortedWords = mergeSort([...words]);
                    break;
                case 'heap':
                    sortedWords.sort(); // Simplified for demo
                    break;
                case 'random':
                    sortedWords.sort(() => Math.random() - 0.5);
                    break;
                default:
                    sortedWords.sort();
            }
            
            // Remove duplicates if requested
            if (uniqueCheckbox.checked) {
                sortedWords = [...new Set(sortedWords)];
                uniqueCountSpan.textContent = `${sortedWords.length} unique`;
            } else {
                uniqueCountSpan.textContent = `${new Set(words).size} unique`;
            }
            
            outputTextarea.value = sortedWords.join('\n');
            
            const endTime = performance.now();
            timeSpan.textContent = `${Math.round(endTime - startTime)}ms`;
        };
        reader.readAsText(file);
    }

    // Simplified merge sort for the frontend demo
    function mergeSort(arr) {
        if (arr.length <= 1) return arr;
        
        const mid = Math.floor(arr.length / 2);
        const left = mergeSort(arr.slice(0, mid));
        const right = mergeSort(arr.slice(mid));
        
        return merge(left, right);
    }
    
    function merge(left, right) {
        let result = [];
        let i = 0, j = 0;
        
        while (i < left.length && j < right.length) {
            if (left[i] < right[j]) {
                result.push(left[i]);
                i++;
            } else {
                result.push(right[j]);
                j++;
            }
        }
        
        return result.concat(left.slice(i)).concat(right.slice(j));
    }
});
