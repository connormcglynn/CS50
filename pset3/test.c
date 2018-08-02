biSizeImage // total size of image in bytes, includes pixels and padding

bi.biSizeImage =
    ((sizeof(RGBTRIPLE) * bi.biWidth) + padding) * abs(bi.biHeight);

bfSize // total size of file in bytes, includes pixels, padding and headers

bf.bfSize = bi.biSizeImage +
    sizeof(BITMAPFILEHEADER) +
    sizeof(BITMAPINFOHEADER);

/// RECOVER

required:

FILE *file = fopen(argv[1], "r");

fread(buffer, 512, 1, raw_file);

// for finding the end of the file:

if (buffer[0] == 0xff &&
    buffer[1] == 0xd8 &&
    buffer[2] == 0xff &&
    (buffer[3] & 0xf0) == 0xe0);


// when time to make new JPEG:

sprintf(filename, "%03i.jpg", 2);
    // filename: char array to store the resultant string

FILE *img = fopen(filename, "w");

// then write until 512 bytes found

fwrite(data, size, number, outptr)