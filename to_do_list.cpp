#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task
{
    string description;
    bool completed;
};

void addTask(vector<Task> &tasks, const string &desc)
{
    tasks.push_back({desc, false});
}

void viewTasks(const vector<Task> &tasks)
{
    if (tasks.empty())
    {
        cout << "No tasks available." << endl;
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed)
            cout << " [Completed]";
        else
            cout << " [Pending]";
        cout << endl;
    }
}

void markTaskCompleted(vector<Task> &tasks, int index)
{
    if (index < 1 || index > tasks.size())
    {
        cout << "Invalid task number." << endl;
        return;
    }
    tasks[index - 1].completed = true;
}

void removeTask(vector<Task> &tasks, int index)
{
    if (index < 1 || index > tasks.size())
    {
        cout << "Invalid task number." << endl;
        return;
    }
    tasks.erase(tasks.begin() + index - 1);
}

int main()
{
    vector<Task> tasks;
    int choice;
    do
    {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cin.ignore();
            string desc;
            cout << "Enter task description: ";
            getline(cin, desc);
            addTask(tasks, desc);
        }
        else if (choice == 2)
        {
            viewTasks(tasks);
        }
        else if (choice == 3)
        {
            int num;
            cout << "Enter task number to mark as completed: ";
            cin >> num;
            markTaskCompleted(tasks, num);
        }
        else if (choice == 4)
        {
            int num;
            cout << "Enter task number to remove: ";
            cin >> num;
            removeTask(tasks, num);
        }
        else if (choice != 5)
        {
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);

    cout << "Goodbye!" << endl;
    return 0;
}
