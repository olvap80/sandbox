#include "Common.h"
#include <linux/module.h>


//module parameters
static int test_param1=4422;
module_param(test_param1, int, 0644);

static uint test_param2=0xFFFFFFFF;
module_param(test_param2, uint, 0644);

static int num_array_params = 0;
static uint num_array[12];
module_param_array(num_array, uint, &num_array_params, 0644);


static int __init on_init_module(void)
{
	printk(KERN_INFO "INIT_MODULE3 enter %d, %u, %d\n",
		test_param1, test_param2, num_array_params);
	for(int i = 0; i < num_array_params; ++i){
		printk(KERN_INFO "INIT_MODULE3 num_array[%d] = %u\n",
			i, num_array[i]);
	}

	//TODO

	printk(KERN_INFO "INIT_MODULE3 leave\n");
	return 0;
}
module_init(on_init_module)

static void __exit on_exit_module(void)
{
	printk(KERN_INFO "CLEANUP_MODULE3 enter\n");

	//TODO

	printk(KERN_INFO "CLEANUP_MODULE3 leave %d, %u\n",
		test_param1, test_param2);
}
module_exit(on_exit_module)


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pavlo M");
MODULE_DESCRIPTION("Simple driver3");

MODULE_PARM_DESC(test_param1, "Module test parameter 1");
MODULE_PARM_DESC(test_param2, "Module test parameter 2");
MODULE_PARM_DESC(num_array, "Module test parameter num_array");

MODULE_SUPPORTED_DEVICE("TestDevice3");
