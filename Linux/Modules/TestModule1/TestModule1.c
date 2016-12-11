
#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void)
{
	printk(KERN_INFO "INIT_MODULE enter\n");
	printk(KERN_INFO "INIT_MODULE leave\n");
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "CLEANUP_MODULE enter\n");
	printk(KERN_INFO "CLEANUP_MODULE leave\n");
}

static int test_param1=442;
module_param(test_param1, int, 0644);

static uint test_param2=0xFFFFFFFF;
module_param(test_param2, uint, 0644);

MODULE_LICENSE("GPL"); 
MODULE_AUTHOR("Pavlo M");
MODULE_DESCRIPTION("Simple driver");

MODULE_PARM_DESC(test_param1, "Module test parameter 1"); 
MODULE_PARM_DESC(test_param2, "Module test parameter 2"); 

MODULE_SUPPORTED_DEVICE("TestDevice1");
