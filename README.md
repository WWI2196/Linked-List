# Linked List
This project provides a simple implementation of a singly linked list in C++. The `LinkedList` class supports basic operations such as adding, deleting, and searching for elements.

## Overview
The `LinkedList` class includes methods to:
- Add elements to the end of the list.
- Add elements to the start of the list.
- Add elements before or after a specified value.
- Display the list.
- Search for an element.
- Delete a specific value from the list.

### Class Definition

#### `Node` Class

The `Node` class represents a node in the linked list, containing:
- `data`: The value stored in the node.
- `next`: A pointer to the next node in the list.

#### `LinkedList` Class

The `LinkedList` class provides the following methods:

- **Constructor**: Initializes an empty list.
- **Destructor** (commented out): Intended to free memory allocated for nodes.
- **`addData_toEnd(int data)`**: Adds a new node with the specified value to the end of the list.
- **`addData_toStart(int data)`**: Adds a new node with the specified value to the start of the list.
- **`addData_afterValue(int afterData, int data)`**: Adds a new node with the specified value after a node with a given value.
- **`addData_beforeValue(int afterData, int data)`**: Adds a new node with the specified value before a node with a given value.
- **`display()`**: Prints the values of all nodes in the list.
- **`search(int data)`**: Searches for a node with the specified value.
- **`deleteValue(int data)`**: Deletes the first node with the specified value.
