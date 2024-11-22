#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/timer.h>
#include <linux/jiffies.h>
#include <linux/cpufreq.h>



static struct timer_list cpu_timer; 
static unsigned int interval=10; // ustawienie interwału sprawdzanie cpu na 10 sekund

module_param(interval, uint, 0644); // definiowanie parametru interval 
MODULE_PARM_DESC(interval, "Interwał logów "); 



void uzycie(struct timer_list *t) {

	unsigned int cpu  =0 ;	//posiadam tylko jedno cpu na maszynie
	pr_info("CPU %d Uzycie: %lu\n",cpu,cpufreq_get(cpu)); // sprawdzenie zuzycia funkcja cpufreq_get oraz wpisanie wyniku do modułu za poocą pr_info
    	mod_timer(&cpu_timer, jiffies + interval * HZ); //czas sprawdzenia
}



static int __init wloczenie(void) { //funcja init wywoływana przy właczaniu modułu
	timer_setup(&cpu_timer, uzycie, 0); //wywołanie funkcji sprawdzającej 
    mod_timer(&cpu_timer, jiffies + interval * HZ);  
    pr_info("wloczono\n");
    return 0;
}
static void __exit wyloczenie(void) { // wyłącznie timera oraz informacja o zakończeniu sie modułu
    del_timer_sync(&cpu_timer);
    pr_info("wyloczono\n");
}
module_init(wloczenie);
module_exit(wyloczenie);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Modul monitorujacy cpu");

