#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_map(int rows, int cols, int obstacle_prob) {
    // Characters for the map
    char empty = '.';
    char obstacle = 'x';

    // Print the map's first line (header)
    printf("%d.xy\n", rows);

    // Seed the random number generator
    srand(time(0));

    // Generate the map rows
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (rand() % 100 < obstacle_prob) {
                printf("%c", obstacle);  // Print obstacle with probability
            } else {
                printf("%c", empty);  // Print empty space
            }
        }
        printf("\n");  // Move to the next line
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <rows> <cols> <obstacle_probability>\n", argv[0]);
        return 1;
    }

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    int obstacle_prob = atoi(argv[3]);

    if (rows <= 0 || cols <= 0 || obstacle_prob < 0 || obstacle_prob > 100) {
        fprintf(stderr, "Invalid input. Ensure rows and cols are positive integers and obstacle probability is between 0 and 100.\n");
        return 1;
    }

    generate_map(rows, cols, obstacle_prob);

    return 0;
}