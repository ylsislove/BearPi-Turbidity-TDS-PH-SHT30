#ifndef RT_CONFIG_H__
#define RT_CONFIG_H__

/* Generated by Kconfiglib (https://github.com/ulfalizer/Kconfiglib) */

/* RT-Thread Kernel */

#define RT_NAME_MAX 8
#define RT_ALIGN_SIZE 4
#define RT_THREAD_PRIORITY_32
#define RT_THREAD_PRIORITY_MAX 32
#define RT_TICK_PER_SECOND 1000
#define RT_USING_OVERFLOW_CHECK
#define RT_USING_HOOK
#define RT_USING_IDLE_HOOK
#define RT_IDLE_HOOK_LIST_SIZE 4
#define IDLE_THREAD_STACK_SIZE 256
#define RT_USING_TIMER_SOFT
#define RT_TIMER_THREAD_PRIO 4
#define RT_TIMER_THREAD_STACK_SIZE 512
#define RT_DEBUG
#define RT_DEBUG_COLOR

/* Inter-Thread communication */

#define RT_USING_SEMAPHORE
#define RT_USING_MUTEX
#define RT_USING_EVENT
#define RT_USING_MAILBOX
#define RT_USING_MESSAGEQUEUE
/* end of Inter-Thread communication */

/* Memory Management */

#define RT_USING_MEMPOOL
#define RT_USING_SMALL_MEM
#define RT_USING_HEAP
/* end of Memory Management */

/* Kernel Device Object */

#define RT_USING_DEVICE
#define RT_USING_CONSOLE
#define RT_CONSOLEBUF_SIZE 256
#define RT_CONSOLE_DEVICE_NAME "uart1"
/* end of Kernel Device Object */
#define RT_VER_NUM 0x40003
/* end of RT-Thread Kernel */
#define ARCH_ARM
#define RT_USING_CPU_FFS
#define ARCH_ARM_CORTEX_M
#define ARCH_ARM_CORTEX_M4

/* RT-Thread Components */

#define RT_USING_COMPONENTS_INIT
#define RT_USING_USER_MAIN
#define RT_MAIN_THREAD_STACK_SIZE 2048
#define RT_MAIN_THREAD_PRIORITY 10

/* C++ features */

/* end of C++ features */

/* Command shell */

#define RT_USING_FINSH
#define FINSH_THREAD_NAME "tshell"
#define FINSH_USING_HISTORY
#define FINSH_HISTORY_LINES 5
#define FINSH_USING_SYMTAB
#define FINSH_USING_DESCRIPTION
#define FINSH_THREAD_PRIORITY 20
#define FINSH_THREAD_STACK_SIZE 4096
#define FINSH_CMD_SIZE 80
#define FINSH_USING_MSH
#define FINSH_USING_MSH_DEFAULT
#define FINSH_USING_MSH_ONLY
#define FINSH_ARG_MAX 10
/* end of Command shell */

/* Device virtual file system */

/* end of Device virtual file system */

/* Device Drivers */

#define RT_USING_DEVICE_IPC
#define RT_PIPE_BUFSZ 512
#define RT_USING_SERIAL
#define RT_SERIAL_RB_BUFSZ 64
#define RT_USING_I2C
#define RT_USING_I2C_BITOPS
#define RT_USING_PIN
#define RT_USING_ADC

/* Using USB */

/* end of Using USB */
/* end of Device Drivers */

/* POSIX layer and C standard library */

#define RT_USING_LIBC
/* end of POSIX layer and C standard library */

/* Network */

/* Socket abstraction layer */

/* end of Socket abstraction layer */

/* Network interface device */

/* end of Network interface device */

/* light weight TCP/IP stack */

/* end of light weight TCP/IP stack */

/* AT commands */

#define RT_USING_AT
#define AT_USING_CLIENT
#define AT_CLIENT_NUM_MAX 1
#define AT_USING_CLI
#define AT_CMD_MAX_LEN 128
#define AT_SW_VERSION_NUM 0x10301
/* end of AT commands */
/* end of Network */

/* VBUS(Virtual Software BUS) */

/* end of VBUS(Virtual Software BUS) */

/* Utilities */

/* end of Utilities */
/* end of RT-Thread Components */

/* RT-Thread online packages */

/* IoT - internet of things */

#define PKG_USING_BC28_MQTT
#define PKG_USING_BC28_AT_CLIENT_DEV_NAME "uart3"
#define PKG_USING_BC28_MQTT_BAUD_RATE_9600
#define PKG_USING_BC28_MQTT_BAUD_RATE 9600
#define PKG_USING_BC28_MQTT_OP_BAND_8
#define PKG_USING_BC28_MQTT_OP_BAND 8
#define PKG_USING_BC28_RESET_PIN 5
#define PKG_USING_BC28_ADC0_PIN -1
#define PKG_USING_BC28_MQTT_PRODUCT_KEY ""
#define PKG_USING_BC28_MQTT_DEVICE_NAME ""
#define PKG_USING_BC28_MQTT_DEVICE_SECRET ""
#define PKG_USING_BC28_MQTT_KEEP_ALIVE 300
#define PKG_USING_BC28_MQTT_LATEST_VERSION

/* Wi-Fi */

/* Marvell WiFi */

/* end of Marvell WiFi */

/* Wiced WiFi */

/* end of Wiced WiFi */
/* end of Wi-Fi */

/* IoT Cloud */

/* end of IoT Cloud */
/* end of IoT - internet of things */

/* security packages */

/* end of security packages */

/* language packages */

/* end of language packages */

/* multimedia packages */

/* LVGL: powerful and easy-to-use embedded GUI library */

/* end of LVGL: powerful and easy-to-use embedded GUI library */

/* u8g2: a monochrome graphic library */

/* end of u8g2: a monochrome graphic library */
/* end of multimedia packages */

/* tools packages */

/* end of tools packages */

/* system packages */

/* acceleration: Assembly language or algorithmic acceleration packages */

/* end of acceleration: Assembly language or algorithmic acceleration packages */

/* Micrium: Micrium software products porting for RT-Thread */

/* end of Micrium: Micrium software products porting for RT-Thread */
/* end of system packages */

/* peripheral libraries and drivers */

#define PKG_USING_SHT3X
#define PKG_USING_SHT3X_V100
/* end of peripheral libraries and drivers */

/* AI packages */

/* end of AI packages */

/* miscellaneous packages */

/* samples: kernel and components samples */

/* end of samples: kernel and components samples */

/* entertainment: terminal games and other interesting software packages */

/* end of entertainment: terminal games and other interesting software packages */
/* end of miscellaneous packages */
/* end of RT-Thread online packages */

/* samples: kernel and components samples */

/* end of samples: kernel and components samples */
#define RT_STUDIO_BUILT_IN

#endif