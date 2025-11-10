#include "_.h"
#include <stdio.h>
#include <stdlib.h>

type (At(FILE)) File;
type (unique At(fixed Character)) FileName, FilePermissions;
type (unique File) Stream;
type (unique At) WriteBuffer;
type (At(fixed Void)) ReadBuffer;

Size stream(Stream input, Stream output);

Function(File, FileName, FilePermissions) open = fopen;
Function(Size, WriteBuffer, Size, Count, Stream) read = fread;
Function(Size, ReadBuffer, Size, Count, Stream) write = fwrite;
Function(Integer, File) close = fclose;
fixed local error = perror;

fixed Size bufferSize = 4096;

Status main(Integer n, Arguments(n) arguments)
{
    if (n == 1)
    {
        stream(stdin, stdout);
    }
    else
    {
        File file;
        FileName fileName;

        for (Integer i = 1; i < n; i += 1)
        {
            fileName = arguments[i];
            file = open(fileName, "r");
            if (file == null)
            {
                error(fileName);
                continue;
            }
            stream(file, stdout);
            close(file);
        }
    }
}

Size stream(Stream input, Stream output)
{
    static Array(Character, bufferSize) buffer;
    static fixed At(Array(Character, bufferSize)) bufferAddress = at(buffer);

    Size readSize = read(bufferAddress, 1, bufferSize, input);

    while (readSize > 0)
    {
        write(bufferAddress, 1, readSize, output);
        readSize = read(bufferAddress, 1, bufferSize, input);
    }

    return readSize;
}
