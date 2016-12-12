
#include <linux/module.h>
#include <linux/kernel.h>

//module parameters
static int test_param1=442;
module_param(test_param1, int, 0644);

static uint test_param2=0xFFFFFFFF;
module_param(test_param2, uint, 0644);


static int __init OnInitModule(void)
{
	printk(KERN_INFO "INIT_MODULE enter %d, %u\n",
		test_param1, test_param2);
	printk(KERN_INFO "INIT_MODULE leave\n");
	return 0;
}

static void __exit OnExitModule(void)
{
	printk(KERN_INFO "CLEANUP_MODULE enter\n");
	printk(KERN_INFO "CLEANUP_MODULE leave %d, %u\n",
		test_param1, test_param2);
}

module_init(OnInitModule)
module_exit(OnExitModule)


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pavlo M");
MODULE_DESCRIPTION("Simple driver2");

MODULE_PARM_DESC(test_param1, "Module test parameter 1");
MODULE_PARM_DESC(test_param2, "Module test parameter 2");

MODULE_SUPPORTED_DEVICE("TestDevice2");
