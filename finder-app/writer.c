#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <syslog.h>

#define LOG_ID "writer"


int main(int argc, char *argv[])
{
	openlog(LOG_ID, LOG_PID | LOG_NDELAY, LOG_USER);
	if(argc != 3)
	{
		syslog(LOG_ERR, "ERROR: insrt writefile and writestr arguments");
		return 1;
	}

	const char *writefile = argv[1];
	const char *writestr = argv[2];
	int fd;
	ssize_t nr;


	fd = creat(writefile, 0644);
	//fd = open("/home/vboxuser/Documents/assignment-1-NgaiNeville/finder-app/writefile.txt", O_WRONLY);
	fd = open(writefile, O_WRONLY);
	if(fd == 1)
	{
		syslog(LOG_ERR, "ERROR: Unable to open file %s",writefile);
		return 1;
	}

	nr = write(fd, writestr, strlen(writestr));
	syslog(LOG_DEBUG, "writing %s to %s", writestr, writefile);
	if(nr == 1)
        {
		syslog(LOG_ERR, "ERROR: Unable to write string %s",writestr);
                return 1;
        }

	int ii = close(fd);
	if(ii<0)
	{
                syslog(LOG_ERR, "ERROR: Unable to close file %s",writefile);
                return 1;
        }

	return 0;

}

