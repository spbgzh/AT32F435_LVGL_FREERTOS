
/*
 * Auto generated Run-Time-Environment Configuration File
 *      *** Do not modify ! ***
 *
 * Project: 'Project' 
 * Target:  'Project' 
 */

#ifndef RTE_COMPONENTS_H
#define RTE_COMPONENTS_H


/*
 * Define the Device Header File: 
 */
#define CMSIS_device_header "at32f435_437.h"

/* ARM.FreeRTOS::RTOS:Config:FreeRTOS:10.5.1 */
#define RTE_RTOS_FreeRTOS_CONFIG        /* RTOS FreeRTOS Config for FreeRTOS API */
/* ARM.FreeRTOS::RTOS:Core:Cortex-M:10.5.1 */
#define RTE_RTOS_FreeRTOS_CORE          /* RTOS FreeRTOS Core */
/* ARM.FreeRTOS::RTOS:Coroutines:10.5.1 */
#define RTE_RTOS_FreeRTOS_COROUTINE     /* RTOS FreeRTOS Co-routines */
/* ARM.FreeRTOS::RTOS:Event Groups:10.5.1 */
#define RTE_RTOS_FreeRTOS_EVENTGROUPS   /* RTOS FreeRTOS Event Groups */
/* ARM.FreeRTOS::RTOS:Heap:Heap_4:10.5.1 */
#define RTE_RTOS_FreeRTOS_HEAP_4        /* RTOS FreeRTOS Heap 4 */
/* ARM.FreeRTOS::RTOS:Message Buffer:10.5.1 */
#define RTE_RTOS_FreeRTOS_MESSAGE_BUFFER /* RTOS FreeRTOS Message Buffers */
/* ARM.FreeRTOS::RTOS:Stream Buffer:10.5.1 */
#define RTE_RTOS_FreeRTOS_STREAM_BUFFER /* RTOS FreeRTOS Stream Buffers */
/* ARM.FreeRTOS::RTOS:Timers:10.5.1 */
#define RTE_RTOS_FreeRTOS_TIMERS        /* RTOS FreeRTOS Timers */
/* ArteryTek::Device:at32f435_437_firmware_library:acc:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_ACC
/* ArteryTek::Device:at32f435_437_firmware_library:adc:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_ADC
/* ArteryTek::Device:at32f435_437_firmware_library:can:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_CAN
/* ArteryTek::Device:at32f435_437_firmware_library:crc:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_CRC
/* ArteryTek::Device:at32f435_437_firmware_library:crm:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_CRM
/* ArteryTek::Device:at32f435_437_firmware_library:dac:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_DAC
/* ArteryTek::Device:at32f435_437_firmware_library:debug:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_DEBUG
/* ArteryTek::Device:at32f435_437_firmware_library:dma:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_DMA
/* ArteryTek::Device:at32f435_437_firmware_library:dvp:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_DVP
/* ArteryTek::Device:at32f435_437_firmware_library:edma:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_EDMA
/* ArteryTek::Device:at32f435_437_firmware_library:emac:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_EMAC
/* ArteryTek::Device:at32f435_437_firmware_library:ertc:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_ERTC
/* ArteryTek::Device:at32f435_437_firmware_library:exint:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_EXINT
/* ArteryTek::Device:at32f435_437_firmware_library:flash:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_FLASH
/* ArteryTek::Device:at32f435_437_firmware_library:gpio:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_GPIO
/* ArteryTek::Device:at32f435_437_firmware_library:i2c:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_I2C
/* ArteryTek::Device:at32f435_437_firmware_library:misc:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_MISC
/* ArteryTek::Device:at32f435_437_firmware_library:pwc:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_PWC
/* ArteryTek::Device:at32f435_437_firmware_library:qspi:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_QSPI
/* ArteryTek::Device:at32f435_437_firmware_library:scfg:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_SCFG
/* ArteryTek::Device:at32f435_437_firmware_library:sdio:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_SDIO
/* ArteryTek::Device:at32f435_437_firmware_library:spi:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_SPI
/* ArteryTek::Device:at32f435_437_firmware_library:tmr:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_TMR
/* ArteryTek::Device:at32f435_437_firmware_library:usart:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_USART
/* ArteryTek::Device:at32f435_437_firmware_library:usb:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_USB
/* ArteryTek::Device:at32f435_437_firmware_library:wdt:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_WDT
/* ArteryTek::Device:at32f435_437_firmware_library:wwdt:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_WWDT
/* ArteryTek::Device:at32f435_437_firmware_library:xmc:2.0.0 */
#define RTE_DEVICE_STDPERIPHERALS_XMC
/* LVGL.LVGL::LVGL:lvgl:Benchmark:8.3.6 */
/*! \brief enable demo:bencharmk */
#define LV_USE_DEMO_BENCHMARK         1
/* LVGL.LVGL::LVGL:lvgl:Essential:8.3.6 */
/*! \brief Enable LVGL */
#define RTE_GRAPHICS_LVGL
/* LVGL.LVGL::LVGL:lvgl:Extra Themes:8.3.6 */
/*! \brief use extra themes, widgets and layouts */
#define RTE_GRAPHICS_LVGL_USE_EXTRA_THEMES


#endif /* RTE_COMPONENTS_H */
