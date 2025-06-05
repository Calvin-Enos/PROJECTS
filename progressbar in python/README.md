# Python Progress Bar

This directory contains a simple Python progress bar utility.

## Functionality

The `progressbar` function takes an iterable and displays a progress bar that updates in place in the console. It shows the progress percentage, a visual bar, and the current count versus the total count.

Key features:
- Updates in place (does not print a new line for each update).
- Displays a "Task Complete!" message when the iteration is finished.
- Customizable prefix message and bar size.

## Example Usage

The following example demonstrates how to use the progress bar:

```python
import time
from progressbar import progressbar # Assuming progressbar.py is in your PYTHONPATH or same directory

# Example loop
for i in progressbar(range(100), "Computing: ", 40):
    time.sleep(0.1) # Simulate some work

print("Task Complete!") # This line is in the example script
                        # The progressbar itself also ensures a newline
                        # before this, so it prints cleanly.
```

When you run a script with this code, you will see a progress bar in your console that updates on a single line, followed by "Task Complete!" once the loop finishes.

## Optimization

The progress bar is optimized to update in place using carriage returns (`\r`), which avoids cluttering the console with multiple lines of output. It does not use `os.system('clear')`, making it efficient and flicker-free.
