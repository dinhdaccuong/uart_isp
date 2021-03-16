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

#define PLAT_NAME		"uart_isp"


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Cuong D");
MODULE_DESCRIPTION("UART ISP DRIVER");
MODULE_VERSION("1.0.0");
/************************ UART DRIVER ********************************/
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

struct platform_driver uart_isp_plat_driver = 
{
	.probe = uart_isp_plat_probe,
	.shutdown = uart_isp_plat_shutdown,
	.suspend = uart_isp_plat_suspend,
	.resume = uart_isp_plat_resume
};

/****************************** INIT AND EXIT ********************************/
int __init uart_isp_init(void)
{
	return 0;
}

void __exit uart_isp_exit(void)
{

}

module_init(uart_isp_init);
module_exit(uart_isp_exit);