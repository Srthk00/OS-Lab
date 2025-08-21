#include <stdio.h> 
#include <string.h> 
#define MAX_LINE_LENGTH 256 
 
void write_details_to_file(const char *filename, const char *details[], int num_details) { 
    FILE *file = fopen(filename, "w"); 
    if (file == NULL) { 
        perror("Error opening file"); 
        return; 
    } 
    for (int i = 0; i < num_details; i++) { 
        fprintf(file, "%s\n", details[i]); 
    } 
    fclose(file); 
} 
 
void find_matching_lines(const char *file1, const char *file2) { 
    FILE *f1 = fopen(file1, "r"); 
    FILE *f2 = fopen(file2, "r"); 
    if (f1 == NULL || f2 == NULL) { 
        perror("Error opening files"); 
        return; 
    } 
    char line1[MAX_LINE_LENGTH]; 
    char line2[MAX_LINE_LENGTH]; 
    while (fgets(line1, sizeof(line1), f1)) { 
        fseek(f2, 0, SEEK_SET); 
        while (fgets(line2, sizeof(line2), f2)) { 
            line1[strcspn(line1, "\n")] = 0; 
            line2[strcspn(line2, "\n")] = 0; 
            if (strcmp(line1, line2) == 0) { 
                printf("Matching line: %s\n", line1); 
            } 
        } 
    } 
    fclose(f1); 
    fclose(f2); 
} 
 
int main() { 
    const char *my_details[] = { 
        "Name: Sarthak Kothiyal", 
        "Roll No: 2319517", 
        "Course: CS",
        "Age: 20"
    }; 
    int my_details_count = sizeof(my_details) / sizeof(my_details[0]); 
    
    const char *friends_details[] = { 
        "Name: Friend", 
        "Roll No: 12345", 
        "Course: CS", 
        "Age: 20"
    }; 
    int friends_details_count = sizeof(friends_details) / sizeof(friends_details[0]); 
    write_details_to_file("my_details.txt", my_details, my_details_count); 
    write_details_to_file("friends_details.txt", friends_details, friends_details_count); 
    printf("\nMatching lines between my_details.txt and friends_details.txt:\n"); 
    find_matching_lines("my_details.txt", "friends_details.txt"); 
    return 0; 
}