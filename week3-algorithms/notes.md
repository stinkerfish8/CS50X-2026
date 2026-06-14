# Week 3: Algorithms

## Counting Methods & Visualizing Algorithms

When we need to solve a problem, like counting the total number of people in a room, the efficiency of our program depends entirely on the algorithm we choose.

### 1. Linear Counting (The Naive Approach)
This is the most basic method, equivalent to the "verbalized algorithm" used in Week 0 to count pages one by one.
* **How it works:** One counter walks through the room, pointing at each person and incrementing the total by 1 ($1, 2, 3, 4...$).
* **Characteristics:** It is slow but simple. If there are $n$ people, it takes exactly $n$ steps.

### 2. Recursive Counting (The CS50 Audience Experiment)
Instead of using a single counter, this approach divides the problem into identical sub-problems.
* **How it works:** 
  1. Every person stands up and holds the value `1`.
  2. People pair up. One person adds both values together, while the partner sits down.
  3. The remaining people repeat the process with their new, larger values.
* **Characteristics:** The problem size splits in half during each cycle. Eventually, only one person remains standing, holding the total sum.

### 3. Key Distinction: Iteration vs. Recursion
* **Iteration:** Solving a problem by repeating a process using loops (like `for` or `while` statements) over a dataset.
* **Recursion:** A technical concept where a function solves a problem by calling a smaller version of itself. 
  * *Note: We will implement the code for this later in the lecture.*

---

## Understanding Big O Notation

In computer science, we don't measure the speed of an algorithm in seconds, because a faster computer will always execute code quicker than an older one. Instead, we measure **Time Complexity**: *how the number of steps increases as the size of the input grows.*

**Big O notation** is the mathematical language we use to describe the **worst-case scenario** of an algorithm (the absolute maximum number of steps required to finish the job).

Think of the capital **O** as standing for *"On the order of"*.

### Common Big O Running Times (From Slowest to Fastest Growth)

#### 1. $O(n)$ — Linear Time
* **Meaning:** The number of steps grows proportionally to the size of the input ($n$).
* **Example:** The basic, page-by-page or person-by-person counting method. If you have 100 people, it takes 100 steps. If you have 1,000 people, it takes 1,000 steps.

#### 2. $O(\log n)$ — Logarithmic Time
* **Meaning:** The problem space is divided in half at every single step. As the input grows huge, the number of steps increases very slowly.
* **Example:** **Binary Search** (the phone book experiment where you flip to the middle and tear pages in half) or the **Recursive Counting** experiment with the audience. Even if you double the number of people in the theater, it only adds *one extra step* to the whole process.

#### 3. $O(1)$ — Constant Time
* **Meaning:** The algorithm always takes the exact same number of steps, regardless of how big the input is.
* **Example:** Checking if a single number is even or odd, or looking at the value held by the very last person standing in the theater. It takes 1 step whether there are 10 people or 10,000.

## Running Time and Time Complexity

**Running Time** (or **Time Complexity**) refers to the efficiency of an algorithm. It does not measure time in seconds, but rather the number of mathematical or computational steps required to solve a problem as the size of the input ($n$) grows.

In computer science, we use **Big O Notation** to categorize an algorithm's running time based on its **worst-case scenario** (the absolute maximum number of steps it could take).

### Terminology & Descriptions

When describing how fast or efficient an algorithm is, we can say:
* *"This algorithm has a **linear running time**."* or *"This algorithm is **linear**."*
* In Italian, we refer to this concept as **Complessità Temporale** (e.g., *"Questo algoritmo ha una complessità logaritmica"*).

### Summary of Running Times (From Worst to Best)

| Big O Notation | Pronunciation (EN / IT) | Technical Name | Algorithm Example |
| :--- | :--- | :--- | :--- |
| **$O(n)$** | *"Big O of n"*<br>• *"O di enne"* | **Linear Time**<br>• *Tempo Lineare* | **Linear Search** (checking every element one by one) |
| **$O(\log n)$** | *"Big O of log n"*<br>• *"O di log enne"* | **Logarithmic Time**<br>• *Tempo Logaritmico* | **Binary Search** (dividing the dataset in half each step) |
| **$O(1)$** | *"Big O of 1"*<br>• *"O di uno"* | **Constant Time**<br>• *Tempo Costante* | **Direct Lookup** (instantly checking a single known index) |
