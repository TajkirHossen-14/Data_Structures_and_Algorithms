# 📚 Data Structures and Algorithms (DSA) 

Welcome to the **DSA_Algorithms** repository!  
This repository contains implementations of fundamental **Data Structures and Algorithms**.  
It is organized by category to make learning, revision and practice easier.

---

## 📂 Repository Structure

- **DSA_Algorithms**
  - 📁 1_Data_Structures
  - 📁 2_Dynamic_Programming
  - 📁 3_Graph
    - BFS.c
    - DFS.c
    - Dijkstra.c
    - Kruskals_Algorithm.c
    - Prims_Algorithm.c
  - 📁 4_Greedy
    - Fractional_Knapsack.c
    - Coin_Change.c
  - 📁 5_Searching
    - Binary_Search_Using_Given_Array.c
    - Binary_Search.c
    - Linear_Search.c
    - Ternary_Search_Using_Given_Array.c
    - Ternary_Search.c
  - 📁 6_Sorting
    - Bubble_Sort.c
    - Insertion_Sort.c
    - Merge_Sort.c
    - Quick_Sort.c
    - Selection_Sort.c

---

## 📘 Data Structures

This section includes fundamental data structures that are essential for solving algorithmic problems efficiently.

### 🔹 Covered Concepts
- Arrays
- Linked Lists
- Stacks
- Queues
- Trees
- Graph representations

These structures form the backbone of most algorithm implementations.

---

## 🧠 Dynamic Programming

Dynamic Programming (DP) is used to solve complex problems by breaking them into smaller overlapping subproblems and storing intermediate results.

### 🔹 Key Characteristics
- Optimal Substructure
- Overlapping Subproblems
- Memoization / Tabulation

This section contains implementations demonstrating these principles.

---

## 🌐 Graph Algorithms

This folder contains fundamental graph traversal and shortest path / spanning tree algorithms.

### 🔹 BFS (Breadth First Search)
- Traverses level by level
- Uses Queue
- Time Complexity: **O(V + E)**

### 🔹 DFS (Depth First Search)
- Traverses depth-wise
- Uses Stack / Recursion
- Time Complexity: **O(V + E)**

### 🔹 Dijkstra.c
- Finds shortest path from a source vertex
- Works for graphs with **non-negative weights**
- Time Complexity: **O(V²)** (basic implementation)

### 🔹 Kruskal's Algorithm.c
- Finds Minimum Spanning Tree (MST)
- Uses Greedy strategy
- Based on edge sorting
- Time Complexity: **O(E log E)**

### 🔹 Prim's Algorithm.c
- Finds Minimum Spanning Tree (MST)
- Expands tree one vertex at a time
- Time Complexity: **O(V²)** (basic implementation)

---

## 🎯 Greedy Algorithms

Greedy algorithms make the best local choice at each step.

### 🔹 Fractional Knapsack
- Items can be taken fractionally
- Uses value/weight ratio sorting
- Time Complexity: **O(n log n)**

### 🔹 Coin Change.c
- Uses greedy strategy for minimum coins
- Works correctly for canonical coin systems

---

## 🔎 Searching Algorithms

Searching algorithms are used to locate an element in a dataset.

### 🔹 Linear Search.c
- Checks elements sequentially
- Time Complexity: **O(n)**

### 🔹 Binary Search.c
- Works on sorted arrays
- Time Complexity: **O(log n)**

### 🔹 Binary Search [Using Given Array].c
- Binary search using predefined array

### 🔹 Ternary Search.c
- Divides array into three parts
- Time Complexity: **O(log n)**

### 🔹 Ternary Search [Using Given Array].c
- Implementation using predefined sorted array

---

## 🔃 Sorting Algorithms

Sorting algorithms arrange elements in ascending or descending order.

### 🔹 Bubble Sort.c
- Repeatedly swaps adjacent elements
- Time Complexity: **O(n²)**

### 🔹 Insertion Sort.c
- Builds sorted portion gradually
- Time Complexity: **O(n²)**

### 🔹 Selection Sort.c
- Selects minimum element in each iteration
- Time Complexity: **O(n²)**

### 🔹 Merge Sort.c
- Divide and Conquer algorithm
- Stable sort
- Time Complexity: **O(n log n)**

### 🔹 Quick Sort.c
- Divide and Conquer
- Average Time Complexity: **O(n log n)**
- Worst Case: **O(n²)**

