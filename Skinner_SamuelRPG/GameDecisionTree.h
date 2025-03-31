#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;
    unordered_map<int, Node<T>*> nodeMap;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}
    GameDecisionTree(Node<T>* root) : root(root) {}

    ~GameDecisionTree() {
        for (auto& pair : nodeMap) {
            delete pair.second;
        }
    }
    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const string& filename, char delimiter) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening the file provided: " << filename << std::endl;
            cout << "Current working directory: " << filesystem::current_path() << endl;
            return;
        }
        string line;
        while (getline(file, line)) { // creating the nodes
            stringstream ss(line);
            string token;
            int eventNumber, leftEvent, rightEvent;
            string description;
            /* When loading the story from file, we need to:
             * 1. Get the event number that we are currently on
             * 2. Get the description for the event, then get the available nodes that parent points to.
            */
            getline(ss, token, delimiter); // 1^
            eventNumber = stoi(token);

            getline(ss, token, delimiter); // 2^
            description = token;

            getline(ss, token, delimiter); // 2^
            try {
                leftEvent = stoi(token);
            } catch (const invalid_argument& e) {
                cerr << "Error: invalid left event number '" << token << "' in line: " << line << endl;
                continue;
            }

            getline(ss, token, delimiter); // 2^
            rightEvent = stoi(token);

            T story(eventNumber, description, leftEvent, rightEvent);
            Node<T>* newNode = new Node<T>(story);
            nodeMap[eventNumber] = newNode; // create new node from event number
            if (root == nullptr) {
                root = newNode;
            }
        }
        // linking the nodes in the game decision tree
        for (auto& pair : nodeMap) {
            T story = pair.second ->data;
            if (story.leftEventNumber != -1 && nodeMap.find(story.leftEventNumber) != nodeMap.end()) { // error arising; resolution: nodeMap.end if -1 arises
                pair.second->left = nodeMap[story.leftEventNumber]; // arrange unordered node map
            }
            if (story.rightEventNumber != -1 && nodeMap.find(story.rightEventNumber) != nodeMap.end()) {
                pair.second->right = nodeMap[story.rightEventNumber];
            }
        }

    }
    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        Node<T>* current = root;
        while (current != nullptr) {
            cout << current->data.description << endl; // enter decision tree
            if (current->data.leftEventNumber == -1 & current->data.rightEventNumber == -1) { // leaf node, end of story
                cout << "Your venture ends here, but you may continue with your imagination!" << endl;
                break;
            }
            cout << "  Enter path: 1 = left, 2 = right." << endl;
            int choice;
            cin >> choice;
            if (choice == 1) { // path of left pointer
                if (current ->left != nullptr) {
                    current = current->left;
                }
                else { // if current == nullptr, adventure ends.
                    cout << "Your venture ends here, but you may continue with your imagination!" << endl;
                    break;
                }
            }
            else if (choice == 2) { // path of right pointer
                if (current->right != nullptr) {
                    current = current->right;
                }
                else { // if current == nullptr, adventure ends.
                    cout << "Your venture ends here, but you may continue with your imagination!" << endl;
                    break;
                }
            }
            else { // edge case handling
                cout << "This pathway is invalid and deviates from the entrepreneurial journey. Try again: " << endl;
            }
        }

    }
};

#endif // GAMEDECISIONTREE_H