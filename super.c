#include <linux/init.h>
#include <linux/module.h>

static struct file_system_type dummyfs_type = {
      .owner = THIS_MODULE,
      .name = "dummyfs",
      .mount = dummyfs_mount,
      .kill_sb = kill_block_super,
      .fs_flags = FS_REQUIRES_DEV, 
  };

static int __init dummyfs_init(void)
{
     pr_debug("dummyfs module loaded\n");
     return 0;
}

static void __exit dummyfs_fini(void)
{
     pr_debug("dummyfs module unloaded\n");
}

module_init(dummyfs_init);
module_exit(dummyfs_fini);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Peter Bona");
