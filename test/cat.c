#include <_.h>

#include <unistd.h>
#include <stdio.h>

Type(FILE) File;

Type(struct {
	Size size;
	Byte data[];
}) Buffer;

Void cat(File *input, File *output, Buffer *buffer);

Integer main(Integer arity, Byte *arguments[arity])
{
	File *input = stdin;
	File *output = stdout;
	Bit streamed = 0;
	Integer opt;

	// TODO getopt -u set buffered to 0
	Size bufferDataSize = streamed ? 1 : 4096;

	Buffer *buffer = malloc(size(Buffer) + bufferDataSize);
	buffer->size = bufferDataSize;

	if (arity <= 1)
	{
		cat(input, output, buffer);
	}
	else
	{
		for (Integer i = optind; i < arity; i++)
		{
			input = fopen(arguments[i], "r");
			cat(input, output, buffer);
		}
	}

	free(buffer);
}

Void cat(File *input, File *output, Buffer *buffer)
{
	Size readSize;

	while ((readSize = fread(buffer->data, 1, buffer->size, input)) > 0)
	{
		fwrite(buffer->data, 1, readSize, output);
	}
}
