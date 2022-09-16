#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
// #include <linux/cdev.h>

// struct file_data {
//     struct cdev cdev;
//     /* file data starts here */
//     //...
// };
static int file_open(struct inode *inode, struct file *file)
{
    printk("File opened.\n");
    return 0;
}
static int file_release(struct inode *inode, struct file *f)
{
    printk("File released.\n");
	return 0;
}

ssize_t file_read (struct file *file, char __user *user_buffer, size_t length, loff_t *offset)
{
    printk("File read.\n");
    return 0;
}
ssize_t file_write (struct file *file, const char __user *user_buffer, size_t length, loff_t *offset)
{
    printk("File being written to.\n");
    // struct file_data *my_data = (struct file_data *) file->private_data;
    // ssize_t len = min(my_data->size - *offset, length);

    // if (len <= 0)
    //     return 0;

    // /* read data from user buffer to my_data->buffer */
    // if (copy_from_user(my_data->buffer + *offset, user_buffer, len))
    //     return -EFAULT;

    // *offset += len;
    return 0;
}

static const struct file_operations file_ops = {
	.owner = THIS_MODULE,
    .open = file_open,
    .release = file_release,
    .read = file_read,
    .write = file_write
};

static int __init mod_init(void)
{
    printk("Character driver init.\n");
    register_chrdev(200, "Test Character Driver", &file_ops);
    return 0;
}
static void __exit mod_exit(void)
{
    printk("Character driver exit.\n");
    unregister_chrdev(200, "Test Character Driver");
}
module_init(mod_init);
module_exit(mod_exit);

MODULE_AUTHOR("Aditya Choubey");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Character Driver");