/*
 * This file is part of the OpenMV project.
 *
 * Copyright (c) 2013-2021 Ibrahim Abdelkader <iabdalkader@openmv.io>
 * Copyright (c) 2013-2021 Kwabena W. Agyeman <kwagyeman@openmv.io>
 *
 * This work is licensed under the MIT license, see the file LICENSE for details.
 *
 * Board configuration and pin definitions.
 */
#ifndef __OMV_BOARDCONFIG_H__
#define __OMV_BOARDCONFIG_H__

// Architecture info
#define OMV_ARCH_STR            "OMV4P H7 32768 SDRAM" // 33 chars max
#define OMV_BOARD_TYPE          "H7"
#define OMV_UNIQUE_ID_ADDR      0x1FF1E800
#define OMV_UNIQUE_ID_SIZE      3 // 3 words

// Needed by the SWD JTAG testrig - located at the bottom of the frame buffer overlay stack.
#define OMV_SELF_TEST_SWD_ADDR  *((uint32_t *) 0x24000018)

#define OMV_XCLK_MCO            (0U)
#define OMV_XCLK_TIM            (1U)

// Sensor external clock source.
#define OMV_XCLK_SOURCE         (OMV_XCLK_TIM)

// Sensor external clock timer frequency.
#define OMV_XCLK_FREQUENCY      (12000000)

// Sensor PLL register value.
#define OMV_OV7725_PLL_CONFIG   (0x41)  // x4

// Sensor Banding Filter Value
#define OMV_OV7725_BANDING      (0x7F)

// OV5640 Sensor Settings
#define OMV_OV5640_XCLK_FREQ    (24000000)
#define OMV_OV5640_PLL_CTRL2    (0x64)
#define OMV_OV5640_PLL_CTRL3    (0x13)
#define OMV_OV5640_REV_Y_CHECK  (1)
#define OMV_OV5640_REV_Y_FREQ   (25000000)
#define OMV_OV5640_REV_Y_CTRL2  (0x54)
#define OMV_OV5640_REV_Y_CTRL3  (0x13)

// Enable hardware JPEG
#define OMV_HARDWARE_JPEG       (1)

// Enable MDMA sensor offload.
#define OMV_ENABLE_SENSOR_MDMA  (1)

// Enable sensor drivers
#define OMV_ENABLE_OV2640       (1)
#define OMV_ENABLE_OV5640       (1)
#define OMV_ENABLE_OV7690       (0)
#define OMV_ENABLE_OV7725       (1)
#define OMV_ENABLE_OV9650       (1)
#define OMV_ENABLE_MT9M114      (1)
#define OMV_ENABLE_MT9V0XX      (1)
#define OMV_ENABLE_LEPTON       (1)
#define OMV_ENABLE_HM01B0       (0)
#define OMV_ENABLE_PAJ6100      (1)
#define OMV_ENABLE_FROGEYE2020  (1)

// Enable sensor features
#define OMV_ENABLE_OV5640_AF    (0)

// Enable WiFi debug
#define OMV_ENABLE_WIFIDBG      (1)

// Enable self-tests on first boot
#define OMV_ENABLE_SELFTEST     (1)

// If buffer size is bigger than this threshold, the quality is reduced.
// This is only used for JPEG images sent to the IDE not normal compression.
#define JPEG_QUALITY_THRESH     (1920*1080*2)

// Low and high JPEG QS.
#define JPEG_QUALITY_LOW        50
#define JPEG_QUALITY_HIGH       90

// FB Heap Block Size
#define OMV_UMM_BLOCK_SIZE      256

// Core VBAT for selftests
#define OMV_CORE_VBAT           "3.3"

// USB IRQn.
#define OMV_USB_IRQN            (OTG_FS_IRQn)

//PLL1 48MHz for USB, SDMMC and FDCAN
#define OMV_OSC_PLL1M           (3)
#define OMV_OSC_PLL1N           (240)
#define OMV_OSC_PLL1P           (2)
#define OMV_OSC_PLL1Q           (20)
#define OMV_OSC_PLL1R           (2)
#define OMV_OSC_PLL1VCI         (RCC_PLL1VCIRANGE_2)
#define OMV_OSC_PLL1VCO         (RCC_PLL1VCOWIDE)
#define OMV_OSC_PLL1FRAC        (0)

// PLL2 200MHz for FMC and QSPI.
#define OMV_OSC_PLL2M           (3)
#define OMV_OSC_PLL2N           (100)
#define OMV_OSC_PLL2P           (2)
#define OMV_OSC_PLL2Q           (2)
#define OMV_OSC_PLL2R           (2)
#define OMV_OSC_PLL2VCI         (RCC_PLL2VCIRANGE_2)
#define OMV_OSC_PLL2VCO         (RCC_PLL2VCOWIDE)
#define OMV_OSC_PLL2FRAC        (0)

// PLL3 160MHz for ADC and SPI123
#define OMV_OSC_PLL3M           (3)
#define OMV_OSC_PLL3N           (80)
#define OMV_OSC_PLL3P           (2)
#define OMV_OSC_PLL3Q           (2)
#define OMV_OSC_PLL3R           (2)
#define OMV_OSC_PLL3VCI         (RCC_PLL3VCIRANGE_2)
#define OMV_OSC_PLL3VCO         (RCC_PLL3VCOWIDE)
#define OMV_OSC_PLL3FRAC        (0)

// Clock Sources
#define OMV_OSC_PLL_CLKSOURCE       RCC_PLLSOURCE_HSE
#define OMV_OSC_USB_CLKSOURCE       RCC_USBCLKSOURCE_HSI48
#define OMV_OSC_RNG_CLKSOURCE       RCC_RNGCLKSOURCE_HSI48
#define OMV_OSC_ADC_CLKSOURCE       RCC_ADCCLKSOURCE_PLL3
#define OMV_OSC_SPI123_CLKSOURCE    RCC_SPI123CLKSOURCE_PLL3

// HSE/HSI/CSI State
#define OMV_OSC_HSE_STATE       (RCC_HSE_ON)
#define OMV_OSC_HSI48_STATE     (RCC_HSI48_ON)

// Flash Latency
#define OMV_FLASH_LATENCY       (FLASH_LATENCY_2)

// Power supply configuration
#define OMV_PWR_SUPPLY          (PWR_LDO_SUPPLY)

// Linker script constants (see the linker script template stm32fxxx.ld.S).
// Note: fb_alloc is a stack-based, dynamically allocated memory on FB.
// The maximum available fb_alloc memory = FB_ALLOC_SIZE + FB_SIZE - (w*h*bpp).
#define OMV_MAIN_MEMORY         SRAM1       // data, bss and heap
#define OMV_STACK_MEMORY        ITCM        // stack memory
#define OMV_DMA_MEMORY          SRAM3       // Misc DMA buffers memory.
#define OMV_FB_MEMORY           DRAM        // Framebuffer, fb_alloc
#define OMV_JPEG_MEMORY         DRAM        // JPEG buffer memory buffer.
#define OMV_JPEG_MEMORY_OFFSET  (31M)       // JPEG buffer is placed after FB/fballoc memory.
#define OMV_VOSPI_MEMORY        SRAM4       // VoSPI buffer memory.
#define OMV_FB_OVERLAY_MEMORY   AXI_SRAM    // Fast fb_alloc memory.
#define OMV_FB_OVERLAY_MEMORY_OFFSET    (496*1024) // Fast fb_alloc memory size.

#define OMV_FB_SIZE             (20M)       // FB memory: header + VGA/GS image
#define OMV_FB_ALLOC_SIZE       (11M)       // minimum fb alloc size
#define OMV_STACK_SIZE          (64K)
#define OMV_HEAP_SIZE           (240K)
#define OMV_SDRAM_SIZE          (32 * 1024 * 1024) // This needs to be here for UVC firmware.

#define OMV_LINE_BUF_SIZE       (11 * 1024) // Image line buffer round(2592 * 2BPP * 2 buffers).
#define OMV_MSC_BUF_SIZE        (2K)        // USB MSC bot data
#define OMV_VFS_BUF_SIZE        (1K)        // VFS sturct + FATFS file buffer (624 bytes)
#define OMV_FIR_LEPTON_BUF_SIZE (1K)        // FIR Lepton Packet Double Buffer (328 bytes)
#define OMV_JPEG_BUF_SIZE       (1024*1024) // IDE JPEG buffer (header + data).

// Memory map.
#define OMV_FLASH_ORIGIN        0x08000000
#define OMV_FLASH_LENGTH        2048K
#define OMV_DTCM_ORIGIN         0x20000000  // Note accessible by CPU and MDMA only.
#define OMV_DTCM_LENGTH         128K
#define OMV_ITCM_ORIGIN         0x00000000
#define OMV_ITCM_LENGTH         64K
#define OMV_SRAM1_ORIGIN        0x30000000
#define OMV_SRAM1_LENGTH        256K        // SRAM1 + SRAM2 + 1/2 SRAM3
#define OMV_SRAM3_ORIGIN        0x30040000
#define OMV_SRAM3_LENGTH        32K
#define OMV_SRAM4_ORIGIN        0x38000000
#define OMV_SRAM4_LENGTH        64K
#define OMV_AXI_SRAM_ORIGIN     0x24000000
#define OMV_AXI_SRAM_LENGTH     512K
#define OMV_DRAM_ORIGIN         0xC0000000
#define OMV_DRAM_LENGTH         32M

// Flash configuration.
#define OMV_FLASH_FFS_ORIGIN    0x08020000
#define OMV_FLASH_FFS_LENGTH    128K
#define OMV_FLASH_TXT_ORIGIN    0x08040000
#define OMV_FLASH_TXT_LENGTH    1792K

// Domain 1 DMA buffers region.
#define OMV_DMA_MEMORY_D1       AXI_SRAM
#define OMV_DMA_MEMORY_D1_SIZE  (16*1024) // Reserved memory for DMA buffers
#define OMV_DMA_REGION_D1_BASE  (OMV_AXI_SRAM_ORIGIN+OMV_FB_OVERLAY_MEMORY_OFFSET)
#define OMV_DMA_REGION_D1_SIZE  MPU_REGION_SIZE_16KB

// Domain 2 DMA buffers region.
#define OMV_DMA_MEMORY_D2       SRAM3
#define OMV_DMA_MEMORY_D2_SIZE  (16*1024) // Reserved memory for DMA buffers
#define OMV_DMA_REGION_D2_BASE  (OMV_SRAM3_ORIGIN+(0*1024))
#define OMV_DMA_REGION_D2_SIZE  MPU_REGION_SIZE_32KB

// Domain 3 DMA buffers region.
#define OMV_DMA_MEMORY_D3       SRAM4
#define OMV_DMA_MEMORY_D3_SIZE  (64*1024) // Reserved memory for DMA buffers
#define OMV_DMA_REGION_D3_BASE  (OMV_SRAM4_ORIGIN+(0*1024))
#define OMV_DMA_REGION_D3_SIZE  MPU_REGION_SIZE_64KB

// AXI QoS - Low-High (0:15) - default 0
#define OMV_AXI_QOS_MDMA_R_PRI  15 // Max pri to move data.
#define OMV_AXI_QOS_MDMA_W_PRI  15 // Max pri to move data.

// Image sensor I2C
#define ISC_I2C                 (I2C1)
#define ISC_I2C_ID              (1)
#define ISC_I2C_AF              (GPIO_AF4_I2C1)
#define ISC_I2C_CLK_ENABLE()    __I2C1_CLK_ENABLE()
#define ISC_I2C_CLK_DISABLE()   __I2C1_CLK_DISABLE()
#define ISC_I2C_SCL_PORT        (GPIOB)
#define ISC_I2C_SCL_PIN         (GPIO_PIN_8)
#define ISC_I2C_SDA_PORT        (GPIOB)
#define ISC_I2C_SDA_PIN         (GPIO_PIN_9)
#define ISC_I2C_SPEED           (CAMBUS_SPEED_STANDARD)
#define ISC_I2C_FORCE_RESET()   __HAL_RCC_I2C1_FORCE_RESET()
#define ISC_I2C_RELEASE_RESET() __HAL_RCC_I2C1_RELEASE_RESET()

/* FIR I2C */
#define FIR_I2C                 (I2C2)
#define FIR_I2C_ID              (2)
#define FIR_I2C_AF              (GPIO_AF4_I2C2)
#define FIR_I2C_CLK_ENABLE()    __I2C2_CLK_ENABLE()
#define FIR_I2C_CLK_DISABLE()   __I2C2_CLK_DISABLE()
#define FIR_I2C_SCL_PORT        (GPIOB)
#define FIR_I2C_SCL_PIN         (GPIO_PIN_10)
#define FIR_I2C_SDA_PORT        (GPIOB)
#define FIR_I2C_SDA_PIN         (GPIO_PIN_11)
#define FIR_I2C_SPEED           (CAMBUS_SPEED_FULL)
#define FIR_I2C_FORCE_RESET()   __HAL_RCC_I2C2_FORCE_RESET()
#define FIR_I2C_RELEASE_RESET() __HAL_RCC_I2C2_RELEASE_RESET()

/* DCMI */
#define DCMI_TIM                (TIM1)
#define DCMI_TIM_PIN            (GPIO_PIN_8)
#define DCMI_TIM_PORT           (GPIOA)
#define DCMI_TIM_AF             (GPIO_AF1_TIM1)
#define DCMI_TIM_CHANNEL        (TIM_CHANNEL_1)
#define DCMI_TIM_CLK_ENABLE()   __TIM1_CLK_ENABLE()
#define DCMI_TIM_CLK_DISABLE()  __TIM1_CLK_DISABLE()
#define DCMI_TIM_PCLK_FREQ()    HAL_RCC_GetPCLK2Freq()

#define DCMI_RESET_PIN          (GPIO_PIN_10)
#define DCMI_RESET_PORT         (GPIOA)

#define DCMI_PWDN_PIN           (GPIO_PIN_7)
#define DCMI_PWDN_PORT          (GPIOD)

#define DCMI_FSYNC_PIN          (GPIO_PIN_4)
#define DCMI_FSYNC_PORT         (GPIOB)

#define DCMI_D0_PIN             (GPIO_PIN_6)
#define DCMI_D1_PIN             (GPIO_PIN_7)
#define DCMI_D2_PIN             (GPIO_PIN_10)
#define DCMI_D3_PIN             (GPIO_PIN_11)
#define DCMI_D4_PIN             (GPIO_PIN_4)
#define DCMI_D5_PIN             (GPIO_PIN_6)
#define DCMI_D6_PIN             (GPIO_PIN_5)
#define DCMI_D7_PIN             (GPIO_PIN_6)

#define DCMI_D0_PORT            (GPIOC)
#define DCMI_D1_PORT            (GPIOC)
#define DCMI_D2_PORT            (GPIOG)
#define DCMI_D3_PORT            (GPIOG)
#define DCMI_D4_PORT            (GPIOE)
#define DCMI_D5_PORT            (GPIOB)
#define DCMI_D6_PORT            (GPIOE)
#define DCMI_D7_PORT            (GPIOE)

#define DCMI_HSYNC_PIN          (GPIO_PIN_4)
#define DCMI_VSYNC_PIN          (GPIO_PIN_7)
#define DCMI_PXCLK_PIN          (GPIO_PIN_6)

#define DCMI_HSYNC_PORT         (GPIOA)
#define DCMI_VSYNC_PORT         (GPIOB)
#define DCMI_PXCLK_PORT         (GPIOA)

#define DCMI_RESET_LOW()        HAL_GPIO_WritePin(DCMI_RESET_PORT, DCMI_RESET_PIN, GPIO_PIN_RESET)
#define DCMI_RESET_HIGH()       HAL_GPIO_WritePin(DCMI_RESET_PORT, DCMI_RESET_PIN, GPIO_PIN_SET)

#define DCMI_PWDN_LOW()         HAL_GPIO_WritePin(DCMI_PWDN_PORT, DCMI_PWDN_PIN, GPIO_PIN_RESET)
#define DCMI_PWDN_HIGH()        HAL_GPIO_WritePin(DCMI_PWDN_PORT, DCMI_PWDN_PIN, GPIO_PIN_SET)

#define DCMI_FSYNC_LOW()        HAL_GPIO_WritePin(DCMI_FSYNC_PORT, DCMI_FSYNC_PIN, GPIO_PIN_RESET)
#define DCMI_FSYNC_HIGH()       HAL_GPIO_WritePin(DCMI_FSYNC_PORT, DCMI_FSYNC_PIN, GPIO_PIN_SET)

#define DCMI_VSYNC_EXTI_IRQN    (EXTI9_5_IRQn)
#define DCMI_VSYNC_EXTI_LINE    (7)
#define DCMI_VSYNC_EXTI_GPIO    (EXTI_GPIOB)
#define DCMI_VSYNC_EXTI_SHARED  (0)

#define WINC_SPI                (SPI2)
#define WINC_SPI_AF             (GPIO_AF5_SPI2)
#define WINC_SPI_TIMEOUT        (1000)
// SPI1/2/3 clock source is PLL2 (160MHz/4 == 40MHz).
#define WINC_SPI_PRESCALER      (SPI_BAUDRATEPRESCALER_4)
#define WINC_SPI_CLK_ENABLE()   __HAL_RCC_SPI2_CLK_ENABLE()

#define WINC_SPI_SCLK_PIN       (GPIO_PIN_13)
#define WINC_SPI_MISO_PIN       (GPIO_PIN_14)
#define WINC_SPI_MOSI_PIN       (GPIO_PIN_15)

#define WINC_SPI_SCLK_PORT      (GPIOB)
#define WINC_SPI_MISO_PORT      (GPIOB)
#define WINC_SPI_MOSI_PORT      (GPIOB)

#define WINC_EN_PIN             (GPIO_PIN_5)
#define WINC_CS_PIN             (GPIO_PIN_12)
#define WINC_RST_PIN            (GPIO_PIN_12)
#define WINC_IRQ_PIN            (pin_D13)

#define WINC_EN_PORT            (GPIOA)
#define WINC_CS_PORT            (GPIOB)
#define WINC_RST_PORT           (GPIOD)

#define WINC_CS_LOW()           HAL_GPIO_WritePin(WINC_CS_PORT, WINC_CS_PIN, GPIO_PIN_RESET)
#define WINC_CS_HIGH()          HAL_GPIO_WritePin(WINC_CS_PORT, WINC_CS_PIN, GPIO_PIN_SET)

#define SOFT_I2C_PORT                GPIOB
#define SOFT_I2C_SIOC_PIN            GPIO_PIN_10
#define SOFT_I2C_SIOD_PIN            GPIO_PIN_11

#define SOFT_I2C_SIOC_H()            HAL_GPIO_WritePin(SOFT_I2C_PORT, SOFT_I2C_SIOC_PIN, GPIO_PIN_SET)
#define SOFT_I2C_SIOC_L()            HAL_GPIO_WritePin(SOFT_I2C_PORT, SOFT_I2C_SIOC_PIN, GPIO_PIN_RESET)

#define SOFT_I2C_SIOD_H()            HAL_GPIO_WritePin(SOFT_I2C_PORT, SOFT_I2C_SIOD_PIN, GPIO_PIN_SET)
#define SOFT_I2C_SIOD_L()            HAL_GPIO_WritePin(SOFT_I2C_PORT, SOFT_I2C_SIOD_PIN, GPIO_PIN_RESET)

#define SOFT_I2C_SIOD_READ()         HAL_GPIO_ReadPin (SOFT_I2C_PORT, SOFT_I2C_SIOD_PIN)
#define SOFT_I2C_SIOD_WRITE(bit)     HAL_GPIO_WritePin(SOFT_I2C_PORT, SOFT_I2C_SIOD_PIN, bit);

#define SOFT_I2C_SPIN_DELAY         64

#define ISC_SPI                     (SPI3)
// SPI1/2/3 clock source is PLL3 (160MHz/8 == 20MHz) - Minimum (164*240*8*27 = 8,501,760Hz)
#define ISC_SPI_PRESCALER           (SPI_BAUDRATEPRESCALER_8)

#define ISC_SPI_IRQn                (SPI3_IRQn)
#define ISC_SPI_IRQHandler          (SPI3_IRQHandler)

#define ISC_SPI_DMA_IRQn            (DMA1_Stream0_IRQn)
#define ISC_SPI_DMA_STREAM          (DMA1_Stream0)

#define ISC_SPI_DMA_REQUEST         (DMA_REQUEST_SPI3_RX)
#define ISC_SPI_DMA_IRQHandler      (DMA1_Stream0_IRQHandler)

#define ISC_SPI_RESET()             __HAL_RCC_SPI3_FORCE_RESET()
#define ISC_SPI_RELEASE()           __HAL_RCC_SPI3_RELEASE_RESET()

#define ISC_SPI_CLK_ENABLE()        __HAL_RCC_SPI3_CLK_ENABLE()
#define ISC_SPI_CLK_DISABLE()       __HAL_RCC_SPI3_CLK_DISABLE()

#define ISC_SPI_SCLK_AF             (GPIO_AF6_SPI3)
#define ISC_SPI_MISO_AF             (GPIO_AF6_SPI3)
#define ISC_SPI_MOSI_AF             (GPIO_AF7_SPI3)
#define ISC_SPI_SSEL_AF             (GPIO_AF6_SPI3)

#define ISC_SPI_SCLK_PIN            (GPIO_PIN_3)
#define ISC_SPI_MISO_PIN            (GPIO_PIN_4)
#define ISC_SPI_MOSI_PIN            (GPIO_PIN_5)
#define ISC_SPI_SSEL_PIN            (GPIO_PIN_15)

#define ISC_SPI_SCLK_PORT           (GPIOB)
#define ISC_SPI_MISO_PORT           (GPIOB)
#define ISC_SPI_MOSI_PORT           (GPIOB)
#define ISC_SPI_SSEL_PORT           (GPIOA)

// SPI LCD Interface
#define OMV_SPI_LCD_CONTROLLER              (&spi_obj[1])
#define OMV_SPI_LCD_CONTROLLER_INSTANCE     (SPI2)

#define OMV_SPI_LCD_MOSI_PIN                (GPIO_PIN_15)
#define OMV_SPI_LCD_MOSI_PORT               (GPIOB)
#define OMV_SPI_LCD_MOSI_ALT                (GPIO_AF5_SPI2)

#define OMV_SPI_LCD_MISO_PIN                (GPIO_PIN_14)
#define OMV_SPI_LCD_MISO_PORT               (GPIOB)
#define OMV_SPI_LCD_MISO_ALT                (GPIO_AF5_SPI2)

#define OMV_SPI_LCD_SCLK_PIN                (GPIO_PIN_13)
#define OMV_SPI_LCD_SCLK_PORT               (GPIOB)
#define OMV_SPI_LCD_SCLK_ALT                (GPIO_AF5_SPI2)

#define OMV_SPI_LCD_RST_PIN                 (GPIO_PIN_12)
#define OMV_SPI_LCD_RST_PORT                (GPIOD)
#define OMV_SPI_LCD_RST_OFF()               HAL_GPIO_WritePin(OMV_SPI_LCD_RST_PORT, OMV_SPI_LCD_RST_PIN, GPIO_PIN_SET)
#define OMV_SPI_LCD_RST_ON()                HAL_GPIO_WritePin(OMV_SPI_LCD_RST_PORT, OMV_SPI_LCD_RST_PIN, GPIO_PIN_RESET)

#define OMV_SPI_LCD_RS_PIN                  (GPIO_PIN_13)
#define OMV_SPI_LCD_RS_PORT                 (GPIOD)
#define OMV_SPI_LCD_RS_OFF()                HAL_GPIO_WritePin(OMV_SPI_LCD_RS_PORT, OMV_SPI_LCD_RS_PIN, GPIO_PIN_SET)
#define OMV_SPI_LCD_RS_ON()                 HAL_GPIO_WritePin(OMV_SPI_LCD_RS_PORT, OMV_SPI_LCD_RS_PIN, GPIO_PIN_RESET)

#define OMV_SPI_LCD_CS_PIN                  (GPIO_PIN_12)
#define OMV_SPI_LCD_CS_PORT                 (GPIOB)
#define OMV_SPI_LCD_CS_HIGH()               HAL_GPIO_WritePin(OMV_SPI_LCD_CS_PORT, OMV_SPI_LCD_CS_PIN, GPIO_PIN_SET)
#define OMV_SPI_LCD_CS_LOW()                HAL_GPIO_WritePin(OMV_SPI_LCD_CS_PORT, OMV_SPI_LCD_CS_PIN, GPIO_PIN_RESET)

#define OMV_SPI_LCD_BL_PIN                  (GPIO_PIN_5)
#define OMV_SPI_LCD_BL_PORT                 (GPIOA)
#define OMV_SPI_LCD_BL_ON()                 HAL_GPIO_WritePin(OMV_SPI_LCD_BL_PORT, OMV_SPI_LCD_BL_PIN, GPIO_PIN_SET)
#define OMV_SPI_LCD_BL_OFF()                HAL_GPIO_WritePin(OMV_SPI_LCD_BL_PORT, OMV_SPI_LCD_BL_PIN, GPIO_PIN_RESET)

#define OMV_SPI_LCD_BL_DAC                  (DAC1)
#define OMV_SPI_LCD_BL_DAC_CHANNEL          (DAC_CHANNEL_2)
#define OMV_SPI_LCD_BL_DAC_CLK_ENABLE()     __HAL_RCC_DAC12_CLK_ENABLE()
#define OMV_SPI_LCD_BL_DAC_CLK_DISABLE()    __HAL_RCC_DAC12_CLK_DISABLE()
#define OMV_SPI_LCD_BL_DAC_FORCE_RESET()    __HAL_RCC_DAC12_FORCE_RESET()
#define OMV_SPI_LCD_BL_DAC_RELEASE_RESET()  __HAL_RCC_DAC12_RELEASE_RESET()

// FIR Module
#define OMV_ENABLE_FIR_MLX90621             (1)
#define OMV_ENABLE_FIR_MLX90640             (1)
#define OMV_ENABLE_FIR_MLX90641             (1)
#define OMV_ENABLE_FIR_AMG8833              (1)
#define OMV_ENABLE_FIR_LEPTON               (1)

// FIR Lepton
#define OMV_FIR_LEPTON_I2C_BUS              (FIR_I2C_ID)
#define OMV_FIR_LEPTON_I2C_BUS_SPEED        (FIR_I2C_SPEED)
#define OMV_FIR_LEPTON_CONTROLLER           (&spi_obj[1])
#define OMV_FIR_LEPTON_CONTROLLER_INSTANCE  (SPI2)

#define OMV_FIR_LEPTON_MOSI_PIN             (GPIO_PIN_15)
#define OMV_FIR_LEPTON_MOSI_PORT            (GPIOB)
#define OMV_FIR_LEPTON_MOSI_ALT             (GPIO_AF5_SPI2)

#define OMV_FIR_LEPTON_MISO_PIN             (GPIO_PIN_14)
#define OMV_FIR_LEPTON_MISO_PORT            (GPIOB)
#define OMV_FIR_LEPTON_MISO_ALT             (GPIO_AF5_SPI2)

#define OMV_FIR_LEPTON_SCLK_PIN             (GPIO_PIN_13)
#define OMV_FIR_LEPTON_SCLK_PORT            (GPIOB)
#define OMV_FIR_LEPTON_SCLK_ALT             (GPIO_AF5_SPI2)

#define OMV_FIR_LEPTON_CS_PIN               (GPIO_PIN_12)
#define OMV_FIR_LEPTON_CS_PORT              (GPIOB)
#define OMV_FIR_LEPTON_CS_HIGH()            HAL_GPIO_WritePin(OMV_FIR_LEPTON_CS_PORT, OMV_FIR_LEPTON_CS_PIN, GPIO_PIN_SET)
#define OMV_FIR_LEPTON_CS_LOW()             HAL_GPIO_WritePin(OMV_FIR_LEPTON_CS_PORT, OMV_FIR_LEPTON_CS_PIN, GPIO_PIN_RESET)

// Enable additional GPIO banks for DRAM...
#define OMV_ENABLE_GPIO_BANK_F
#define OMV_ENABLE_GPIO_BANK_G
#define OMV_ENABLE_GPIO_BANK_H
#define OMV_ENABLE_GPIO_BANK_I

#endif //__OMV_BOARDCONFIG_H__
