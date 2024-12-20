# CLion Nova BOF Template

A reusable template for developing Beacon Object Files (BOFs) in CLion.

## Features

- **CMake Integration**: Simplifies BOF development with a structured build system.
- **Cross-Platform Support**: Includes `build.sh` scripts for cross-compiling BOFs for both 32-bit and 64-bit architectures.
- **Examples**: Multiple example BOFs to learn from or modify for your own use.
- **Test Suite**: A comprehensive set of tests to validate BOF functionality.
- **Reusable Template**: Start your BOF development quickly with a pre-configured structure.

## Project Structure

CLion-nova-bof-template/
├── CMakeLists.txt          # CMake configuration for building BOFs
├── LICENSE                 # License information
├── examples/               # Example BOFs to reference and modify
│   ├── hello/              # Example for a simple “hello” BOF
│   │   ├── hello.c         # BOF source code
│   │   ├── build.sh        # Build script for cross-compiling
│   │   └── hello.cna       # Cobalt Strike script
│   └── …                 # Other examples
├── include/                # Shared headers (e.g., beacon.h)
│   └── beacon.h            # Header file for BOF development
├── src/                    # User-defined BOF directory
│   └── user_bof.c          # Placeholder for user-defined BOFs
├── tests/                  # Test cases for BOF functionality
│   ├── src/                # Individual test source files
│   ├── build.sh            # Build script for running tests
│   └── bof_test_runner.cna # Cobalt Strike test runner script
└── readme.md               # Documentation for the project

---

## Getting Started

### Clone the Repository
To start using the template, clone the repository:
```bash
git clone https://github.com/incendiary/CLion-nova-bof-template.git
cd CLion-nova-bof-template

Open in CLion

Open the project in CLion:

clion .

Create Your BOF
	1.	Add your BOF logic in the src/ directory.
	2.	Use the placeholder file user_bof.c as a starting point:

#include "beacon.h"

void go(char * args, int len) {
    // Your BOF logic here
}


	3.	Modify the CMakeLists.txt if additional libraries or configurations are required.

Examples

This template includes several examples to help you get started with BOF development. You can find them in the examples/ directory. Each example includes:
	•	BOF Source Code (.c files): The actual BOF implementation.
	•	Cobalt Strike Aggressor Script (.cna files): Scripts to load and test the BOF in a Cobalt Strike environment.
	•	Build Scripts (build.sh): Shell scripts for cross-compiling the BOF for both 32-bit and 64-bit architectures.

Available Examples

Example	Description
cs_beacon_info	Retrieves and displays information about the beacon.
cs_beacon_syscalls	Demonstrates using direct system calls from the beacon.
cs_format_example	Shows how to format and output data from the beacon.
cs_key_value	Implements a key-value storage mechanism.
cs_read_virtual_memory	Example for reading virtual memory of a target process.
demo	A simple demo BOF to demonstrate basic functionality.
hello	A “Hello, World” BOF to get started quickly.
helloWorld	Another variant of the “Hello, World” BOF.

Running Examples

To build and test an example:
	1.	Navigate to the example directory:

cd examples/<example_name>


	2.	Use the provided build.sh script to compile the BOF:

./build.sh


	3.	Load the .o file into Cobalt Strike using the corresponding .cna script.

Running Tests

A set of test cases is included in the tests/ directory. To run the tests:
	1.	Navigate to the tests/ directory:

cd tests


	2.	Use the build.sh script to compile and run the tests:

./build.sh


	3.	Load the compiled test files into your Cobalt Strike environment using bof_test_runner.cna.

