#include <stdio.h>
#include <stdbool.h>

// FIFO Page Replacement Algorithm
int fifo_page_faults(int reference_string[], int n, int frame_size) {
    int page_table[frame_size];
    int page_faults = 0;
    int front = 0;

    for (int i = 0; i < frame_size; i++) {
        page_table[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        bool page_found = false;
        int page = reference_string[i];

        for (int j = 0; j < frame_size; j++) {
            if (page_table[j] == page) {
                page_found = true;
                break;
            }
        }

        if (!page_found) {
            page_table[front] = page;
            front = (front + 1) % frame_size;
            page_faults++;
        }
    }

    return page_faults;
}

int main() {
    int reference_string[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int n = sizeof(reference_string) / sizeof(reference_string[0]);
    int frame_size = 3;

    int fifo_faults = fifo_page_faults(reference_string, n, frame_size);
    

    printf("FIFO Page Faults: %d\n", fifo_faults);
    

    return 0;
}