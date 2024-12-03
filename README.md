
# **StackProject**

This project demonstrates a stack implementation in C++ using object-oriented programming principles. It provides a custom stack data type (`stackType`) with common stack operations like `push`, `pop`, and `top`, and includes operator overloading for stack comparisons.

---

## **Features**

- Implements a stack data structure with templated support for different data types.
- Provides the following operations:
  - Initialize stack (`initializeStack`)
  - Check if the stack is empty or full (`isEmptyStack`, `isFullStack`)
  - Add and remove elements (`push`, `pop`)
  - Retrieve the top element (`top`)
- Includes operator overloading for:
  - Assignment (`=`) 
  - Equality (`==`)
- Supports stack comparison through custom logic.

---

## **File Structure**

- **`main.cpp`**: The main program demonstrating stack operations and comparisons.
- **`myStack.h`**: Header file defining the `stackType` class, implementing all stack operations.
- **`stackADT.h`**: Abstract base class defining the interface for stack operations.

---

## **How to Use**

1. Clone the repository:
   ```bash
   git clone https://github.com/owensjones10/StackProject.git
   ```
2. Navigate to the project directory:
   ```bash
   cd StackProject
   ```
3. Compile the project using a C++ compiler:
   ```bash
   g++ -o stack main.cpp
   ```
4. Run the program:
   ```bash
   ./stack
   ```

---

## **Example Output**

The program compares two stacks and outputs whether they are equal:

```plaintext
stack1 and stack2 are equal.
stack1 and stack2 are not equal.
```

---

## **Technologies Used**

- C++ with templates and object-oriented programming.

---

## **Future Enhancements**

- Add support for additional stack operations.
- Improve error handling for stack overflow and underflow.
- Create a graphical interface for visualizing stack operations.

---

## **License**

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

## **Contributing**

Contributions are welcome! Please fork the repository, create a new branch for your changes, and submit a pull request.

---
