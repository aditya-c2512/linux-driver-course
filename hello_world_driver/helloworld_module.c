#include <linux/module.h>
#include <linux/kernel.h>

static int __init entry_func(void)
{
    printk("Hello from init.\n");
    return 0;
}
static void __exit exit_func(void)
{
    printk("Bye from exit module.\n");
}
module_init(entry_func);
module_exit(exit_func);

MODULE_AUTHOR("Aditya Choubey");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple hello world module");