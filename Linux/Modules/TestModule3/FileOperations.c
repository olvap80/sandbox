#include "FileOperations.h"



///"VMT" for filesystem item
static const struct file_operations exposedFops = {
/*	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release*/
};

///Expose methods to outside world
const struct file_operations* TestModule3FileOperations(void){
	return &exposedFops;
}