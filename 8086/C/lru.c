#include <stdio.h>
#include <stdbool.h>

int lru_page_faults(int reference_string[], int n, int frame_size) {
    int page_table[frame_size];
    int page_faults = 0;

    for (int i = 0; i < frame_size; i++) {
        page_table[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        bool page_found = false;
        int page = reference_string[i];

        for (int j = 0; j < frame_size; j++) {
            if (page_table[j] == page) {
                page_found = true;
                // Move the accessed page to the end of the table (most recently used)
                for (int k = j; k < frame_size - 1; k++) {
                    page_table[k] = page_table[k + 1];
                }
                page_table[frame_size - 1] = page;
                break;
            }
        }

        if (!page_found) {
            // If a page fault occurs, replace the first page (least recently used)
            for (int j = 0; j < frame_size - 1; j++) {
                page_table[j] = page_table[j + 1];
            }
            page_table[frame_size - 1] = page;
            page_faults++;
        }
    }

    return page_faults;
}




int main() {
    int reference_string[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int n = sizeof(reference_string) / sizeof(reference_string[0]);
    int frame_size = 3;

   
    int lru_faults = lru_page_faults(reference_string, n, frame_size);
   

    
    printf("LRU Page Faults: %d\n", lru_faults);
    

    return 0;
}