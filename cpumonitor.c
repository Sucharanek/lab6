#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/timer.h>
#include <linux/jiffies.h>
#include <linux/cpufreq.h>



static struct timer_list cpu_timer;
static unsigned int interval=10;

module_param(interval, uint, 0644);
MODULE_PARM_DESC(interval, "Interval in seconds between log updates");



void uzycie(struct timer_list *t) {

	unsigned int cpu  =0 ;	
	pr_info("CPU %d Uzycie: %lu\n",cpu,cpufreq_get(cpu));
    	mod_timer(&cpu_timer, jiffies + interval * HZ);
}



static int __init wloczenie(void) {
	timer_setup(&cpu_timer, uzycie, 0);
    mod_timer(&cpu_timer, jiffies + interval * HZ);
    pr_info("wloczono\n");
    return 0;
}
static void __exit wyloczenie(void) {
    del_timer_sync(&cpu_timer);
    pr_info("wyloczono\n");
}
module_init(wloczenie);
module_exit(wyloczenie);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A module to log CPU usage at regular intervals");

