#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/ktime.h>

void GetTime(int *phour, int *pmin, int *psec)
{	
	s64  uptime;
    uptime = ktime_divns(ktime_get_coarse_boottime(), NSEC_PER_SEC);
	*phour = uptime / 3600;
	*pmin  = (uptime-*phour*3600) / 60;
	*psec  = (uptime-*phour*3600-*pmin*60);

}

static int hello_init(void)
{
	int hour, min, sec;

    GetTime(&hour, &min, &sec);

    printk(KERN_ALERT "Hello, world\n");
	printk(KERN_ALERT"System's uptime is %02d:%02d:%02d\n", hour, min, sec);

    return 0;
}

static void hello_exit(void) {

	int hour, min, sec;

    GetTime(&hour, &min, &sec);

	printk(KERN_ALERT "Goodbye, cruel world\n");
	printk(KERN_ALERT"System's uptime is %02d:%02d:%02d\n", hour, min, sec);
}

module_init( hello_init );
module_exit( hello_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Assignment 2 - 2021 Spring CS-GY6233");
MODULE_AUTHOR("Chenyan Zhou");

