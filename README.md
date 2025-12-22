# EFI Signing Binary

A lightweight C++ utility that extends `sbctl` functionality to recursively sign all EFI binaries within a target directory and its subdirectories.

While `sbctl` is excellent for managing Secure Boot keys, it lacks native support for batch-signing files within a folder structure. This tool solves that by walking through a specified path, identifying `.efi` binaries, and signing them automatically using your configured `sbctl` keys.

## Prerequisites

* **sbctl**: This tool wraps around `sbctl`, so it must be installed and configured with your keys.
* **C++ Compiler**: `g++` (GCC) or `clang++`.
* **Linux**: Developed for Linux environments (Arch, Fedora, etc.).

## Installation & Compilation

1. **Clone the repository:**
```bash
git clone https://github.com/your-username/efi_signing_binary.git
cd efi_signing_binary
```


2. **Compile the binary:**
You can use either G++ or Clang. Run **one** of the following commands:
```bash
# Using G++
g++ sign.cpp -o sign_directory

# Using Clang
clang++ sign.cpp -o sign_directory
```


3. **(Optional) Move to a bin folder:**
To make it runnable from anywhere:
```bash
sudo mv sign_directory /usr/local/bin/
```



## Usage

Run the binary and provide the path to the directory containing your EFI files.

```bash
# Syntax
sudo ./sign_directory <path_to_folder>

# Example: Recursively sign everything in the boot partition
sudo ./sign_directory /boot/efi
```

> **Note:** Sudo privileges are usually required because `sbctl` needs root access to read the private keys and write the signed signatures to the EFI partition.
