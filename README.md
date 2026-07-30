# memo

> *Never miss something important again.*

A lightweight, minimal command-line reminder tool written in C. `memo` allows you to quickly add, list, and manage your daily notes and tasks directly from your terminal.

---

## Features

- **Fast & Lightweight:** Built in pure C with zero external dependencies.
- **Minimalist Design:** Out of the way until you need it.
- **Home Directory Integration:** Stores your reminders seamlessly in a persistent local data file.

---

## Installation

### Prerequisites

- A C compiler (`gcc` or `clang`)
- `bash` (for running installation scripts)

### Building from Source

1. **Clone the repository:**
   ```
   git clone [https://github.com/99Konss/memo.git](https://github.com/99Konss/memo.git)
   cd memo

    Compile the binary:
    Bash

    gcc -O2 main.c -o memo

    Install globally:
    Bash

    chmod +x install.sh
    ./install.sh

Usage
Add a reminder

To add a new reminder, pass your text inside quotes:
```
memo -a buy_dog_food (if you want multiple words, wrap them in double quotes)
```
List all reminders

To display all active reminders with line numbers:
```
memo -l
```

Clear the list

To clear the entire list:
```
memo -c
```
Configuration & Storage

Reminders are stored in plain text inside your home directory:
~/.reminders/data.txt

You can view or edit this file manually at any time using your preferred text editor.
License

This project is licensed under the MIT License.
