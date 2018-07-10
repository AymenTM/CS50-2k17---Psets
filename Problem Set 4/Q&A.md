# Questions (given w/ the whodunit folder)

## What's `stdint.h`?

stdint.h is a header file in the C standard library. It provides a standard
set of typedefs that specify exact-width integer types together with the
defined minimum and maximum allowable values for each type.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Using well-defined types makes the code far easier and safer to port, as you
won't get any surprises when for example one machine interprets int as 16-bit
and another as 32-bit. With stdint.h, what you type is what you get.

  - `uint8_t` specifies that an unsigned integer will be exactly 8 bits of size.
  - `int32_t` specifies that an signed integer will be exactly 32 bits of size.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1, 4, 4, 2; (QWORD is 8 bytes.)

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

With an offest of 0 the first two bytes are: 0x42 0x4D in hexadecimal, BM in ASCII.
This signature, identifies the bfType, the file type.

## What's the difference between `bfSize` and `biSize`?

bfSize is the size of the whole bmp file, which includes the headerfiles.
biSize is the size of the BITMAPINFOHEADER header file (biSize is constant and it
equals 40 bytes).

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down DIB with the origin at the upper
left corner (device-independent bitmap).

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

copy.c:24 Might return 'NULL' for reasons such as:

   - The file doesn't exist
   - The file is opened in a mode that doesn't allow other accesses
   - The file exists, but you don't have permissions (some permission error occurred while
     accessing a file such as "Read-Only" or "Write-Protected")

copy.c:32 Might return 'NULL' for reasons such as:

   - The user is not authorize to create the file
   - The file is too large and there is not enough space for it

## Why is the third argument to `fread` always `1` in our code?

Because the number of element of data that we are reading is 1, the BITMAPFILEHEADER.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

'padding' is assigned the value 1.

## What does `fseek` do?

Repositions the file position indicator for the stream to a desired location specified in
the functions arguments.

## What is `SEEK_CUR`?

SEEK_CUR, a possible argument of fseek(), specifies that we want to reposition the file
position indicator for the stream starting from the current position.
