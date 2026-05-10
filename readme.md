# CLion Nova BOF Template

A reusable project template for developing [Beacon Object Files (BOFs)](https://hstechdocs.helpsystems.com/manuals/cobaltstrike/current/userguide/content/topics/beacon-object-files_main.htm) in JetBrains CLion, using CMake and the [Nova](https://novapackage.helpsystems.com/) BOF testing framework.

> **Authorised use only.** BOFs produced with this template are for use in authorised red team engagements and security research only. Do not deploy against systems you do not own or have explicit written permission to test.

---

## Features

- **CMake integration** — structured build system with a top-level `CMakeLists.txt`
- **Cross-compilation scripts** — `build.sh` / `build.bat` in each example for 32-bit and 64-bit targets
- **Cobalt Strike Aggressor scripts** — `.cna` loader scripts included alongside each BOF
- **Example BOFs** — several ready-to-reference examples covering common patterns
- **Unit test suite** — Nova-based test runner to validate BOF behaviour without a live C2

---

## Repository structure

```
.
├── CMakeLists.txt          # Top-level CMake configuration
├── include/
│   └── beacon.h            # Cobalt Strike Beacon API header
├── src/
│   └── user_bof.c          # Placeholder for your own BOF code
├── examples/
│   ├── hello/              # "Hello World" BOF
│   ├── helloWorld/         # Alternate hello variant
│   ├── demo/               # Basic demo BOF
│   ├── cs_beacon_info/     # Dump Beacon memory layout and mask info
│   ├── cs_beacon_syscalls/ # Enumerate syscall addresses exposed by Beacon
│   ├── cs_format_example/  # Formatted output via BeaconFormatPrintf
│   ├── cs_key_value/       # Key-value data passing example
│   └── cs_read_virtual_memory/ # Read a remote process's virtual memory
└── tests/
    ├── src/                # Nova unit tests (integer, string, format, output, etc.)
    ├── build.sh            # Build and run test suite
    └── bof_test_runner.cna # Cobalt Strike test runner
```

Each example directory contains:
- `<name>.c` — BOF source
- `<name>.cna` — Aggressor script to load and invoke the BOF in Cobalt Strike
- `build.sh` / `build.bat` — cross-compile to `.o` for both architectures

---

## Getting started

### Prerequisites

- JetBrains CLion (or any CMake-capable toolchain)
- `mingw-w64` for cross-compilation on Linux/macOS: `brew install mingw-w64` / `apt install mingw-w64`
- Cobalt Strike (for `.cna` scripts and live testing)

### Clone

```bash
git clone https://github.com/incendiary/CLion-nova-bof-template.git
cd CLion-nova-bof-template
```

### Open in CLion

```bash
clion .
```

### Write your BOF

Add your logic to `src/user_bof.c` (entry point `void go(char *args, int alen)`), then update `CMakeLists.txt` if you need additional source files.

### Build an example

```bash
cd examples/cs_beacon_info
./build.sh       # produces cs_beacon_info.x64.o and cs_beacon_info.x86.o
```

Load the `.o` file into Cobalt Strike via the corresponding `.cna` Aggressor script.

### Run the test suite

```bash
cd tests
./build.sh
```

Or load `bof_test_runner.cna` into a live Cobalt Strike instance to run tests against a real Beacon.

---

## Examples reference

| Example | Description |
|---------|-------------|
| `hello` / `helloWorld` | Minimal "Hello World" — good starting point |
| `demo` | Basic demo with argument parsing |
| `cs_beacon_info` | Dumps Beacon's memory allocation map, heap records, and sleep mask |
| `cs_beacon_syscalls` | Enumerates syscall numbers and jump addresses exposed through Beacon's API |
| `cs_format_example` | Demonstrates `BeaconFormatAlloc` / `BeaconFormatPrintf` / `BeaconFormatToString` |
| `cs_key_value` | Passes structured key-value data from Aggressor to the BOF |
| `cs_read_virtual_memory` | Reads memory from a target process and returns it to the operator |
