#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_irq.h>
#include <linux/of_gpio.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/console.h>
#include <linux/clk.h>
#include <linux/tty.h>
#include <linux/tty_flip.h>
#include <linux/serial_core.h>
#include <linux/delay.h>


#define UART_ISP_MAJOR			200
#define UART_ISP_MINOR_START	70
#define UART_ISP_PORTS			1

#define PLAT_NAME		"uart_isp"
#define DRIVER_NAME		"uart_isp"
#define DEV_NAME		"uart_isp"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Cuong D");
MODULE_DESCRIPTION("UART ISP DRIVER");
MODULE_VERSION("1.0.0");
/************************ UART DRIVER ********************************/
struct uart_driver uart_isp_driver =
{
	.owner 			= THIS_MODULE,
	.driver_name 	= DRIVER_NAME,
	.dev_name		= DEV_NAME,
	.major			= UART_ISP_MAJOR,
	.minor			= UART_ISP_MINOR_START,
	.nr				= UART_ISP_PORTS
};

void uart_isp_start_tx(struct uart_port* port)
{

}

void uart_isp_stop_tx(struct uart_port* port)
{

}

void uart_isp_stop_rx(struct uart_port* port)
{

}


int uart_isp_startup(struct uart_port* port)
{
	return 0;
}

void uart_isp_shutdown(struct uart_port* port)
{

}

const char* uart_isp_type(struct uart_port* port)
{
	return NULL;
}
void uart_isp_config_port(struct uart_port* port, int flags)
{

}


int uart_isp_request_port(struct uart_port* port)
{
	return 0;
}

void uart_isp_release_port(struct uart_port* port)
{

}

unsigned int uart_isp_tx_empty(struct uart_port* port)
{
	return 0;
}

struct uart_ops uart_isp_ops = {
	.start_tx = uart_isp_start_tx,
	.stop_tx = uart_isp_stop_tx,
	.stop_rx = uart_isp_stop_rx,
	.startup = uart_isp_startup,
	.shutdown =  uart_isp_shutdown,
	.type = uart_isp_type,
	.config_port = uart_isp_config_port,
	.request_port = uart_isp_request_port,
	.release_port = uart_isp_release_port,
	.tx_empty = uart_isp_tx_empty
};


/***************************** PLATFORM DRIVER *******************************/

int uart_isp_plat_probe(struct platform_device* dev)
{
	return 0;
}

int uart_isp_plat_remove(struct platform_device *dev)
{
	return 0;
}

void uart_isp_plat_shutdown(struct platform_device *dev)
{

}

int uart_isp_plat_suspend(struct platform_device *dev, pm_message_t state)
{
	return 0;
}

int uart_isp_plat_resume(struct platform_device *dev)
{
	return 0;
}
static const struct of_device_id uart_isp_dt_ids[] = 
{
	{ .compatible =  "xlnx,xps-uartlite-1.00.a" },
	{											}
};

MODULE_DEVICE_TABLE(of, uart_isp_dt_ids);

struct platform_driver uart_isp_plat_driver = 
{
	.probe = uart_isp_plat_probe,
	.shutdown 	= uart_isp_plat_shutdown,
	.suspend 	= uart_isp_plat_suspend,
	.resume 	= uart_isp_plat_resume,
	.driver 	= 
			{
				.name = PLAT_NAME,	// same as this kernel module name	
				.of_match_table = of_match_ptr(uart_isp_dt_ids)
			}
};


/****************************** INIT AND EXIT ********************************/
int __init uart_isp_init(void)
{
	int retval = 0;
	
	retval = uart_register_driver(&uart_isp_driver);
	if(retval)
	{
		printk(KERN_INFO "uart isp register error\n");
		return retval;
	}
	
	retval = platform_driver_register(&uart_isp_plat_driver);
	if(retval)
	{
		printk(KERN_INFO "uart isp platform driver register error\n");
		return retval;
	}
	return 0;
}

void __exit uart_isp_exit(void)
{
	platform_driver_unregister(&uart_isp_plat_driver);
	uart_unregister_driver(&uart_isp_driver);
}

module_init(uart_isp_init);
module_exit(uart_isp_exit);