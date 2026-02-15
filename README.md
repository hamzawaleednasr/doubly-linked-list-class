# Doubly Linked List (C++ Template) 🔗

A **generic doubly linked list implementation** written in **C++** using templates, designed to provide flexible data storage with bidirectional traversal, indexed access, and explicit control over memory management.

The implementation focuses on correctness, pointer safety, and clear separation of list operations.

---

## ✨ Key Features

- Generic implementation using **C++ templates**
- Doubly linked node structure (`prev` / `next`)
- Constant-time insertion at the beginning
- Indexed access through sequential traversal
- In-place list reversal without extra memory
- Explicit memory management using `new` / `delete`
- Support for dynamic list resizing and updates

---

## 🧩 Data Structure Design

Each node stores:
- A value of generic type `t`
- A pointer to the previous node
- A pointer to the next node

```cpp
struct node {
    node* prev;
    node* next;
    t value;
};
```

The list maintains a single head pointer and a private size counter for efficient state tracking.

---

## ⚙️ Supported Operations

**Insertion**

- Insert at beginning
- Insert at end
- Insert after a given node
- Insert after a specific index


**Deletion**

- Delete by value
- Delete first node
- Delete last node
- Clear entire list safely
- Access & Update
- Retrieve node by index
- Access element by index
- Update element at a specific index
- Search for a value


**Utilities**

- Check list size
- Check if empty
- Print list contents
- Reverse list order

---

## 🔄 In-Place Reversal Algorithm

The `reverse()` function reverses the list in-place by swapping each node’s `prev` and `next` pointers during traversal.

**Key characteristics:**

- No additional memory allocation
- Single pass through the list
- Time complexity: O(n)
- Space complexity: O(1)

This demonstrates correct pointer manipulation in a doubly linked structure.

---

## 🧠 What This Implementation Demonstrates

- Proper use of templates for reusable data structures
- Safe pointer manipulation in a doubly linked list
- Manual memory lifecycle management in C++
- Designing index-based operations on pointer-based structures
- Writing non-trivial in-place algorithms on linked data structures
- Encapsulation of list behavior inside a single generic class

---

## ⚠️ Design Notes

- The list uses **sequential traversal** for indexed access, reflecting the natural cost of linked structures
- No STL containers are used, emphasizing low-level data structure implementation
- Memory ownership is fully controlled by the list implementation

## 👤 Author

**Hamza Waleed**