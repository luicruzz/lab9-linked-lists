/*
 * Course: COEN 2220 - Programming 2
 * Name: Luis D. Cruz Medina
 * Lab: Lab 9 - Linked Lists
 * Description: Practice - a linked list of study groups
 * Due date: [10/19/26]
 */

#include <iostream>
#include <string>
using namespace std;

class StudyGroupList
{
private:
    // ===== Part C: List representation =====

    struct Node
    {
        string groupCode;
        int meetingRoom;
        Node *next;
    };

    Node *head;
    int groupCount;

public:
    StudyGroupList()
    {
        head = nullptr;
        groupCount = 0;
    }

    // ===== Resolve these TODOs later (Part D) =====

        void addGroup(const string& newGroupCode, int newMeetingRoom)
    {
        Node *newNode = new Node;
        newNode->groupCode = newGroupCode;
        newNode->meetingRoom = newMeetingRoom;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *currentNode = head;

            while (currentNode->next != nullptr)
            {
                currentNode = currentNode->next;
            }

            currentNode->next = newNode;
        }

        groupCount++;
    }

    void displayGroups() const
    {
        Node *currentNode = head;

        while (currentNode != nullptr)
        {
            cout << "Study group: " << currentNode->groupCode
                 << " | Room: " << currentNode->meetingRoom << endl;

            currentNode = currentNode->next;
        }
    }

    int size() const
    {
        return groupCount;
    }
    // ===== Resolve these TODOs later (Part E) =====

    // TODO (Part E): Write containsGroup as a const member function
    // that searches by group code.

        bool containsGroup(const string& targetGroupCode) const
    {
        Node *currentNode = head;

        while (currentNode != nullptr)
        {
            if (currentNode->groupCode == targetGroupCode)
            {
                return true;
            }

            currentNode = currentNode->next;
        }

        return false;
    }
};


 int main()
{
    cout << boolalpha;

    StudyGroupList studyGroups;

    studyGroups.addGroup("MATH-201-A", 315);
    studyGroups.addGroup("COEN-2220-B", 204);
    studyGroups.addGroup("CHEM-105-C", 118);

    studyGroups.displayGroups();

    cout << "Registered groups: "
         << studyGroups.size() << endl;

    cout << "Contains COEN-2220-B: "
         << studyGroups.containsGroup("COEN-2220-B") << endl;

    cout << "Contains PHYS-110-A: "
         << studyGroups.containsGroup("PHYS-110-A") << endl;

    return 0;
}