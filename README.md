[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `Sam Skinner`  
### **Student ID:** `130254316`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)
This project, similar to the example, implements a text-based RPG using a binary decision tree. Each successive step is a child node of the overall parent node.
This game represents multiple entrepreneurial journeys that young founders can go down when starting out. If mistakes are made
throughout the journey, null pointers (signaling -1, end of journey) are reached. There are multiple pathways, however,
some pathways converge, such as the dropshipping pathway intersecting with the drop shipping pathway in Node 30. Parsing through the decision tree
is done by loading story.txt -- an external file -- which contains the architecture for the decision tree.

Example:
> This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The storyline is loaded from an external text file (`story.txt`), which is parsed to construct the decision tree. The game ends when a leaf node (with `-1` as left and right children) is reached.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `This file is used to call an instance of the GameDecisionTree class. It loads the story data from story.txt and commences the game by invoking the tree traversal.`  
- **`GameDecisionTree.h`** → `This file contains the declaration of the GameDecisionTree class. In the first function, the file is loaded and the text is parsed. From there the decision tree is constructed, and then through user input, it is parsed accordingly.`  
- **`Node.h`** → `The node file stores information about a given node in the decision tree. Each node, outside of the root nodes, have pointers that extend to other nodes, containing more data. `  
- **`Story.h`** → `This file declares the Story class, where the event number, the description of the node at that event number, and the options for left and right event numbers are provided, serving the purpose of the next decision on the binary tree.`  
- **`story.txt`** → `The story.h file contains the game narrative data. Essentially, each node is comprised of a description, number in the tree, and they have left and right pointers if they are not roots. This file specifies that.`  

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file?  
- How are nodes linked based on left and right event numbers?  
- What happens if an event has `-1` as left or right children?  

The story objects are creates from the text file by using a file input stream to read each line. Then, for each line, a string stream is used to get the respective tokens based off of the delimiter. The tokens are then sorted properly through the eventNumber, description, leftEventNumber, and rightEventNumber where they are passed to the Story class's constructor to create a new object. 
The nodes are linked based on the corresponding event numbers that are separate by delimiters at the end of a description at a given event number. First come the left pointers, and the right pointers become second.
If an event has a -1 as a left or right child, the program terminates, and tells the user that their venture has collapsed. This means that the program is referencing a null pointer with no existing data or description.

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?  
- What happens when the player reaches a leaf node?  
- Explain the special case where multiple events lead to the same outcome.  

The user input is everything when it comes to the path taken. If the user selects 1, they progress with the left pointer, and vice versa for right. 
When a player reaches a leaf node, or -1, the program terminates and offers words of encouragement after their failed journey. 
A special case of convergence occurs when multiple events lead to the same outcome. This is when multiple parent nodes have pointers that reference the same child node. These pointers are close by eventNumber proximity within the decision tree, but they both converge at the specified same node.

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?  
- How do you ensure nodes are properly linked?  
- Any challenges faced while handling file input?  

The file is read and parsed using an ifstream that ensures that the right text file is being called. From here getLine reads each line, and a secondary getLine gets the delimiter used, to extract the proper integers.
We ensure that all nodes are properly linked through two steps. The first step is to create the Story object, where all of the nodes are created then stored in an unordered map where the event number is the key.  The second step iterates over the map, checks for root nodes (denoted by -1), then looks up these nodes in the map where the pointers are then assigned. 
The challenges that I faced when handling file input were that the working directory was improperly set to /cmake-build-debug when we need story.txt that is located in the main directory. 

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)

Example:
> Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.

Challenge #1: One debugging challenge that I faced was with linking nodes in game decision tree. The if statements I utilized were not boolean.
Solution #1: The solution I used here was assessing why my if statements were causing errors and terminating the program, even when the IDE was not giving me the warning. I ended up adding "!= nodeMap.end()" to my if statement at the end to make the second part of the if statement boolean!
Challenge #2: Another debugging challenge I faced was when my working directory was set to the cmake-build-debug folder. This made it so that the story.txt file was not being called
Solution #2: I implemented a debugging step: "cout << "Get cwd: " << filesystem::current_path() << endl;" that allowed me to see that I was working in the cmake-build-debug folder, and subsequently edited the configurations for where my program was being run, setting it to CS210P2/programming-assign..., allowing it to work effectively. 
---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)

You embark on your entrepreneurial journey: there exist two paths. // opening description of the great-great-great grandparent node
Enter path: 1 = left, 2 = right. 1 // choosing left child node

The "right" path is for innovators: you begin building a tech startup. // left node description
Enter path: 1 = left, 2 = right. 2 // choosing right child node

You begin reading books on machine learning engineering.
Enter path: 1 = left, 2 = right. 1

You decide to seek mentorship from serial entrepreneurs.
Enter path: 1 = left, 2 = right. 1

You name your company LayUp and build out an MVP, then launch your GTM.
Enter path: 1 = left, 2 = right. 1

Financial Freedom! You scaled your company and got acquired!
Your venture ends here, but you may continue with your imagination! // termination of the program as a null pointer is reached

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(n)`  
- **Searching for an event in the tree** → `O(n)`  
- **Game traversal efficiency** → `O(log(n))`  

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.
> An edge case that I tested was when a player inputs something other than 1 or 2 for their decision. This displays a warning message that their input was invalid and that they have another opportunity to reenter the correct path.
> Another edge case that I tested was when a leaf node was reached, the program is terminated effective immediately with an exit message.

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.
> I added massive depth to the decision tree with multiple convergences to a similar node to provide greater narrative and creative structure. I went as far as 6 levels deep with this exercise because I wanted to see how convergences can occur in different levels of binary decision trees towards the same node. 

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  Done!
- **Code must compile and run** → `(Code that does not run will receive a 0).`  Done!
- **Do not modify provided skeleton code** → `(You may only add to it).`  Done!

---
