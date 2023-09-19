// TASK 4: TO-DO LIST

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void viewTasks(const vector<string>& taskList) {
    cout << "Task List:" << endl;
    for (size_t i = 0; i < taskList.size(); ++i) {
        cout << i + 1 << ". " << taskList[i] << endl;
    }
}

void saveTasks(const vector<string>& taskList, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const string& task : taskList) {
            file << task << endl;
        }
    } else {
        cout << "Unable to save tasks to " << filename << endl;
    }
}

void loadTasks(vector<string>& taskList, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string task;
        while (getline(file, task)) {
            taskList.push_back(task);
        }
    } else {
        cout << "No saved tasks found in " << filename << endl;
    }
}

void markTaskCompleted(vector<string>& taskList, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < static_cast<int>(taskList.size())) {
        cout << "Task marked as completed: " << taskList[taskIndex - 1] << endl;
        taskList.erase(taskList.begin() + (taskIndex - 1));
    }
    if (taskIndex = 1) {
        cout << "Task marked as completed: " << taskList[taskIndex] << endl;
        taskList.erase(taskList.begin() + (taskIndex));
    }
    else {
        cout << "Invalid task index." << endl;
    }
}

void removeTask(vector<string>& taskList, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < static_cast<int>(taskList.size())) {
        cout << "Task removed: " << taskList[taskIndex - 1] << endl;
        taskList.erase(taskList.begin() + (taskIndex - 1));
    } else {
        cout << "Invalid task index." << endl;
    }
}


int main() {
    vector<string> taskList;
    const string filename = "D://tasks.txt"; // Name of the file to store tasks

    // Load tasks from the file at the beginning of the program
    ifstream inputFile(filename);
    string task;
    while (getline(inputFile, task)) {
        taskList.push_back(task);
    }
    inputFile.close();

    cout << "\t\t\tNashwah's To-Do List" << endl;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cin.ignore(); // Clear the newline character from the buffer
            string description;
            cout << "Enter task description: ";
            getline(cin, description);
            taskList.push_back(description);

            // Automatically save tasks after adding
            saveTasks(taskList, filename);
        } else if (choice == 2) {
            viewTasks(taskList);
        } else if (choice == 3) {
            int taskIndex;
            cout << "Enter the task number to mark as completed: ";
            cin >> taskIndex;
            markTaskCompleted(taskList, taskIndex);
            saveTasks(taskList, filename); // Save the updated tasks to the file
        } else if (choice == 4) {
            int taskIndex;
            cout << "Enter the task number to remove: ";
            cin >> taskIndex;
            removeTask(taskList, taskIndex);
            saveTasks(taskList, filename); // Save the updated tasks to the file
        } else if (choice == 5) {
            cout << "Goodbye!" << endl;
            break; // Exit the program
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
