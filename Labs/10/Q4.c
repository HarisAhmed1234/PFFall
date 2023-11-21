#include <stdio.h>
#include <stdlib.h> // Library for Dynamic Memory Allocation (DMA)
#include <string.h>

// Function to reverse a word using pointers
void reverseWord(char *start, char *end) {
    char temp;
    while (start < end) {
        temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

// Function to reverse each word in a sentence using DMA
void reverseSentenceWords(char *sentence) {
    // Both start and end pointers are initialized to the first address of the sentence
    char *start = sentence;
    char *end = sentence;

    // Calculating the length of the sentence
    int length = strlen(sentence);

    // Reverse the entire sentence
    reverseWord(start, start + length - 1);

    // Traverse the reversed sentence
    while (*end) {
        // If a space or end of sentence is encountered
        if (*end == ' ' || *end == '\0') {
            // Reverse the word
            reverseWord(start, end - 1);
            // Move to the next word
            start = end + 1;
        }
        end++;
    }

    // Reverse the first and last words as they don't conform to the space condition
    reverseWord(sentence, sentence + length - 1);
}

int main() {
    // Maximum length of the sentence
    int maxLength = 1000;

    // Dynamic Memory Allocation for the array 'sentence' on the heap
    char *sentence = (char *)malloc(maxLength * sizeof(char));

    // Input the sentence
    printf("Enter a sentence: ");
    
    // Input of the string
    fgets(sentence, maxLength, stdin);

    // Remove the newline character from the input
    sentence[strcspn(sentence, "\n")] = '\0';

    // Reverse each word in the sentence
    reverseSentenceWords(sentence);

    // Print the modified sentence
    printf("Modified sentence: %s\n", sentence);

    // Free dynamically allocated memory
    free(sentence);

    return 0;
}
