#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
	if ((argc == 3) && (strcmp(argv[1], argv[2]) != 0))
	{  //Make sure there are three parameters, and the source and destination file names are not the same.

		int fd_src, fd_dest, ret;

		//Open source files in read-only mode
		fd_src = open(argv[1], O_RDONLY);
		if (fd_src < 0)
		{
			perror("open argv[1]");
			return -1;
		}

		//New destination file
		fd_dest = open(argv[2], O_WRONLY | O_CREAT, 0755);
		if (fd_dest < 0)
		{
			close(fd_src);
			perror("open argv[2]");
			return -1;
		}

		do
		{
			char buf[1024] = { 0 };
			//Reading data from source file
			ret = read(fd_src, buf, sizeof(buf));

			//Write the data to the destination file, pay attention to the last parameter, and write the file size.
			write(fd_dest, buf, ret);
		} while (ret > 0);

		//Close open files
		close(fd_src);
		close(fd_dest);
	}

	return 0;
}
