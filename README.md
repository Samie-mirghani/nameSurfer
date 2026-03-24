# NameSurfer

A command-line application that queries and visualizes U.S. baby name popularity rankings across decades (1900–2010), powered by a custom sorted linked list data structure.

## Overview

NameSurfer lets users explore how the popularity of baby names has changed over more than a century. It parses a dataset of **4,400+ names** with decade-by-decade rankings and provides two interactive query modes:

1. **Name Lookup** — Enter any name to see its popularity trajectory from 1900 to 2010, displayed as an ASCII bar chart.
2. **Decade Comparison** — Select a specific decade and compare the rankings of multiple names side by side.

Rankings are displayed using a visual star-based scale where fewer stars indicate higher popularity (lower rank number = more popular).

## Key Features

- **Interactive CLI menu** with name search and decade comparison modes
- **ASCII bar chart visualization** of name popularity rankings across 12 decades
- **Case-insensitive search** — queries are normalized for reliable matching
- **Sorted linked list database** — names are stored in alphabetical order using a custom generic linked list, enabling efficient ordered traversal
- **Templatized data structures** — the linked list and node classes are fully generic (`template <class NODETYPE>`), making them reusable beyond this project
- **Comprehensive dataset** — includes 4,400+ names with rankings from the 1900s through the 2010s

## Tech Stack

| Component       | Technology           |
|-----------------|----------------------|
| Language        | C++ (C++11)          |
| Build System    | GNU Make             |
| Data Structures | Custom templatized sorted linked list |
| Dataset         | U.S. Social Security Administration baby name rankings (1900–2010) |

## System Architecture

```
NamesData.txt ──▶ NameSurferDataBase ──▶ linked_list<NameSurferEntry>
                    (file parser)           (sorted alphabetically)
                         │
                         ▼
                      main.cpp
                    (interactive CLI)
                         │
               ┌─────────┴─────────┐
               ▼                   ▼
         Name Lookup         Decade Comparison
      (single name,         (multiple names,
      all decades)           single decade)
               │                   │
               ▼                   ▼
         ASCII bar chart      Side-by-side
           (1900–2010)        ranking display
```

**Data flow:**
1. `NameSurferDataBase` reads `NamesData.txt` and parses each line into a `NameSurferEntry` object containing a name and a vector of 11 decade rankings.
2. Each entry is inserted in alphabetical order into a `linked_list<NameSurferEntry>` using the `InsertInOrder` method.
3. The CLI menu in `main.cpp` accepts user input, searches the database via `findEntry()`, and renders results as ASCII bar charts.

## Setup & Installation

### Prerequisites

- **g++** with C++11 support
- **GNU Make**

### Build & Run

```bash
# Clone the repository
git clone https://github.com/samie-mirghani/namesurfer.git
cd namesurfer

# Build the project
make

# Run the application
./a.out
```

### Clean Build Artifacts

```bash
make clean
```

### Usage Example

```
Menu
1. Enter a name to be searched
2. Enter a year
3. Exit

Choose and option:
1
Please enter a name:
Emily
You selected Emily
1900****-224
1910***-191
1920****-216
1930****-228
1940****-214
1950****-224
1960*****-273
1970****-241
1980***-174
1990*-25
2000-6
2010******-312
```

## Project Structure

```
namesurfer/
├── main.cpp                 # Entry point and interactive CLI menu
├── NameSurferEntry.h/.cpp   # Name entry model (name + decade rankings)
├── NameSurferDataBase.h/.cpp# Database: file parser and search interface
├── linked_list.h/.cpp       # Generic sorted linked list implementation
├── single_node.h/.cpp       # Generic linked list node
├── NamesData.txt            # Dataset (4,400+ names, rankings 1900–2010)
└── makefile                 # Build configuration
```

## Suggested Topics / Tags

`cpp` `data-structures` `linked-list` `name-popularity` `cli-application` `baby-names` `data-visualization` `ascii-chart`
