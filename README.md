# File-encryptor-CPP# RLE Compressor & Decompressor in C++

A simple Run-Length Encoding (RLE) compressor and decompressor implemented in C++ using file streams.

---

## Overview

This program compresses and decompresses text files by encoding consecutive repeated characters as pairs of (character, count). Spaces are handled specially by encoding as `"32"` to avoid confusion with delimiters.

---

## Features

- Reads and writes files using `ifstream` and `ofstream`.
- Handles spaces explicitly during compression and decompression.
- Uses `input.get(ch)` to read every character including whitespace.
- Converts counts from strings to integers with `atoi()` during decompression.
- Outputs compressed data in a readable format with characters and counts separated by spaces.

---

## How It Works

### Compression

- Reads characters from `raw.txt`.
- Counts consecutive repeated characters.
- Writes compressed pairs to `compressed.txt`:
  - Spaces (`' '`) stored as `"32"`.
  - Example: `"aaa  bb"` → `"a 3 32 1 b 2 "`.

### Decompression

- Reads pairs (character, count) from `compressed.txt`.
- Converts `"32"` back to space.
- Reconstructs the original text by repeating characters.
- Writes output to `reconstructed.txt`.

---

## Code Snippet

```cpp
string rep(string s, int n) {
    string res;
    while (n--) res += s;
    return res;
}

// Usage example during decompression:
while (input_compressed >> t1 >> t2) {
    string character_ = (t1 == "32") ? " " : t1;
    int count = atoi(t2.c_str());
    string to_write = rep(character_, count);
    output_decompressed << to_write;
}
