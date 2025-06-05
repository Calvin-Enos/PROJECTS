# C Progress Bar

This project demonstrates a simple progress bar implemented in C. It has been refactored for better modularity.

## Functionality

The `progressbar` function displays a progress bar in the console that updates in place. It shows:
- A prefix message.
- A visual bar (e.g., `[◼◼◼.......]`).
- The current progress as a ratio (e.g., `50/100`).

The progress bar updates on the same line using carriage returns (`\r`) and `fflush(stdout)`. After the main task completion, a "Task Complete!" message is displayed on a new line.

## Refactoring

The progress bar code is organized into:
- `progressbar.h`: Header file defining the `progressbar` function interface.
- `lib_progressbar.c`: Source file containing the implementation of the `progressbar` function.
- `progessbar.c`: Source file containing the `main` function with example usage.

This separation allows for easier reuse and maintenance. The `lib_progressbar.c` also includes checks for `total = 0` to prevent division by zero errors.

## Compilation and Execution

To compile and run the example, follow these steps:

1.  **Compile the library code:**
    ```bash
    gcc -c progessbar in C/lib_progressbar.c -o progessbar in C/lib_progressbar.o
    ```

2.  **Compile the main program and link with the library:**
    ```bash
    gcc progessbar in C/progessbar.c progessbar in C/lib_progressbar.o -o progessbar in C/progressbar_example
    ```
    *(Note: The output paths like "progessbar in C/lib_progressbar.o" are illustrative. You can adjust them as needed, e.g., just `lib_progressbar.o` if you `cd` into the directory first.)*


3.  **Run the executable:**
    ```bash
    ./progessbar in C/progressbar_example
    ```

## Example Output

The console will show the progress bar updating:
```
Computing: [◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼....................] 50/100
```
(The bar will fill up as it runs)

Followed by:
```
Computing: [◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼] 100/100
Task Complete!
Testing with total = 0:
Test (0/0): [........................................] 0/0
Done.
Testing with current > total:
Test (120/100): [◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼◼] 100/100
Done.
Testing with current = 0, total = 50:
Test (0/50): [........................................] 0/50
Done.
```

## Author
This code was originally written by [Calvin-Enos](https://github.com/Calvin-Enos) and subsequently refactored and updated.
