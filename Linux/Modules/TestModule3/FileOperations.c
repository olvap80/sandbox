#include "FileOperations.h"



static const struct file_operations fops = {
/*	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release*/
};

const struct file_operations* TestModule3FileOperations(void){
	return &fops;
}