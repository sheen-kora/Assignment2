#include <iostream>
#include <vector>

int main() {
    // Number of students and questions
    const int NUM_STUDENTS = 8;
    const int NUM_QUESTIONS = 10;

    // 2D vector storing answers for 8 students across 10 questions
    std::vector<std::vector<char>> answers = {
        {'A', 'B', 'A', 'C', 'C', 'C', 'D', 'E', 'E', 'D'}, // Student 0
        {'D', 'B', 'A', 'B', 'C', 'A', 'C', 'E', 'A', 'D'}, // Student 1
        {'E', 'D', 'D', 'A', 'C', 'B', 'D', 'E', 'A', 'D'}, // Student 2
        {'C', 'B', 'A', 'E', 'D', 'C', 'C', 'E', 'A', 'D'}, // Student 3
        {'A', 'B', 'D', 'C', 'C', 'D', 'C', 'E', 'A', 'D'}, // Student 4
        {'B', 'B', 'E', 'C', 'C', 'D', 'D', 'E', 'A', 'D'}, // Student 5
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}, // Student 6
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}  // Student 7
    };

    // 1D vector storing the correct answer key
    std::vector<char> key = {'D', 'B', 'D', 'C', 'C', 'A', 'D', 'E', 'A', 'D'};

    // Outer loop: iterate through each student
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        int correct_count = 0;

        // Inner loop: iterate through each question/answer for the current student
        for (int j = 0; j < NUM_QUESTIONS; ++j) {
            if (answers[i][j] == key[j]) {
                correct_count++;
            }
        }

        // Display the result for each student using std::cout
        std::cout << "Student " << i << ": " << correct_count << " / " << NUM_QUESTIONS << " correct answers\n";
    }

    return 0;
}