#ifndef __PX_FLASH_H__
#define __PX_FLASH_H__
/* =============================================================================
     ____    ___    ____    ___    _   _    ___    __  __   ___  __  __ TM
    |  _ \  |_ _|  / ___|  / _ \  | \ | |  / _ \  |  \/  | |_ _| \ \/ /
    | |_) |  | |  | |     | | | | |  \| | | | | | | |\/| |  | |   \  /
    |  __/   | |  | |___  | |_| | | |\  | | |_| | | |  | |  | |   /  \
    |_|     |___|  \____|  \___/  |_| \_|  \___/  |_|  |_| |___| /_/\_\

    Copyright (c) 2018 Pieter Conradie <https://piconomix.com>
 
    License: MIT
    https://github.com/piconomix/piconomix-fwlib/blob/master/LICENSE.md
    
    Title:          px_flash.h : Internal FLASH write routines
    Author(s):      Pieter Conradie
    Creation Date:  2018-11-21

============================================================================= */

/** 
 *  @ingroup STM32
 *  @defgroup AVR_FLASH px_flash.h : Internal FLASH write routines
 *  
 *  This module can erase a page and write a half page of internal FLASH.
 *  
 *  File(s):
 *  - arch/arm/stm32/px_flash.h
 *  - arch/arm/stm32/px_flash.c 
 *   
 *  @note 
 *  The flash erase and program functions must be executed from SRAM, not FLASH.
 *  
 */
/// @{

/* _____STANDARD INCLUDES____________________________________________________ */

/* _____PROJECT INCLUDES_____________________________________________________ */
#include "px_defines.h"
#include "px_lib_stm32cube.h"

#ifdef __cplusplus
extern "C" {
#endif
/* _____DEFINITIONS__________________________________________________________ */
#define PX_FLASH_BASE_ADR                 FLASH_BASE
#define PX_FLASH_PAGE_SIZE                128
#define PX_FLASH_HALF_PAGE_SIZE           (PX_FLASH_PAGE_SIZE / 2)
#define PX_FLASH_HALF_PAGE_SIZE_WORDS     (PX_FLASH_HALF_PAGE_SIZE / 4)

/* _____GLOBAL FUNCTION DECLARATIONS_________________________________________ */
/**
 *  Unlock FLASH for programming and erase.
 *  
 */
void px_flash_unlock(void);

/**
 *  Lock FLASH to prevent programming or erase.
 *  
 */
void px_flash_lock(void);

/**
 *  Function to erase a page.
 *  
 *  @param address  Page address
 */
void px_flash_erase_page(const uint32_t address);

/**
 *  Function to write a half page.
 *  
 *  @param address   Half page address
 *  @param data      Pointer to buffer containing data to write
 */
void px_flash_wr_half_page(const uint32_t address, const  uint32_t * data);

/* _____MACROS_______________________________________________________________ */

/// @}
#ifdef __cplusplus
}
#endif

#endif // #ifndef __PX_FLASH_H__
