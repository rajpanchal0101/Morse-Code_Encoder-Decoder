# Morse Code Encoder / Decoder

Encodes and decodes messages using a binary-tree-based Morse code implementation. The program reads Morse code mappings from a text file, builds a binary tree to store them, and lets the user encode or decode arbitrary messages.

## Tech Used

- C++

## Files

| File | Description |
|------|-------------|
| `a5_header.h` | Header file with function declarations for encoding, decoding, and tree construction. Included in `a5_endecutils.cpp`. |
| `a5_main.cpp` | Entry point — reads `morse_code.txt`, builds the Morse tree, and handles user input for encoding/decoding. |
| `a5_endecutils.cpp` | Implements the encoder, decoder, and tree-building functions. Included in `a5_main.cpp`. |
| `morse_code.txt` | Text file mapping letters to their Morse code sequences (input data). |
| `a5_executable.exe` | Pre-built executable binary. |

## How to Build & Run

```bash
g++ a5_main.cpp -o morse && ./morse
```

Or run `a5_executable.exe` directly on Windows. Make sure `morse_code.txt` is in the same directory.
