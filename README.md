# Leetcode-815.-Bus-Routes
# 🚍 Bus Routes - Minimum Number of Buses to Destination

## 🧩 Problem Description

You are given a list of bus routes. Each route is represented as an array of stops that the bus visits in a cycle. You are also given a source and a target bus stop. Your goal is to determine the **minimum number of buses** you need to take to travel from the source stop to the target stop. If it is not possible to reach the target, return `-1`.

---

## 🚀 Approach

### 🔄 Breadth-First Search (BFS)

- We treat each **bus route** as a node.
- Two routes are connected if they **share a common stop**.
- Start BFS from all the bus routes that include the **source stop**.
- Visit connected routes by hopping through shared bus stops.
- Stop the search when a bus route includes the **target stop**.

---

## 🧠 Key Ideas

- Use a map to store which buses go through each stop.
- Use a set to keep track of visited buses (to avoid re-processing).
- Use a queue to perform BFS on the buses that connect through stops.
- Count the number of **levels in BFS** as the number of buses taken.

---

## 📦 Time and Space Complexity

| Complexity        | Value                       |
|------------------|-----------------------------|
| **Time**         | O(N × R), N = stops, R = routes |
| **Space**        | O(N + R)                    |

---

## ✅ Example

```cpp
Input:
routes = [[1,2,7],[3,6,7]],
source = 1,
target = 6

Output:
2
