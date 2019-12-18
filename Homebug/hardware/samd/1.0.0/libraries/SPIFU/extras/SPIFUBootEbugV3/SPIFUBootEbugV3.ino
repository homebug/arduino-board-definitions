/*
  Copyright (c) 2019 JP Meijers.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "src/SPIMemory/SPIMemory.h"
#include "src/SpiFlashMap.h"
#include <FlashStorage.h>

FlashClass internalFlash;
SPIFlash externalFlash(0);

// Initialize C library
extern "C" void __libc_init_array(void);

int main() {
  init();

  __libc_init_array();

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);

  if (!externalFlash.error()) {

    externalFlash.begin();

    if(externalFlash.getCapacity() >= 524288) {
      // If the flash has been initialised to a smaller capacity, something is wrong

      bool updateFlashed = false;
  
      struct SpiFlashConfig spiFlashConfig;
      externalFlash.readAnything(SPIFLASH_LOCATION_CONFIG, spiFlashConfig);
      
      if(spiFlashConfig.writeNewFirmwareMagic == WRITE_FIRMWARE_MAGIC) {
        // Load new firmware flag has been set
    
        if (spiFlashConfig.newFirmwareSize > SPIFU_SIZE) {
          // Only update if new firmware contains a bootloader
          digitalWrite(LED_BUILTIN, LOW);
          delay(200);
          digitalWrite(LED_BUILTIN, HIGH);
          delay(200);
          digitalWrite(LED_BUILTIN, LOW);
          delay(200);
          digitalWrite(LED_BUILTIN, HIGH);
          delay(200);
//          for(;;) {
//            digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
//            delay(200);
//          }
        
          // skip the SPIFU section
          uint32_t updateSize = spiFlashConfig.newFirmwareSize - SPIFU_SIZE;
    
          uint32_t flashAddress = (uint32_t)SKETCH_START;
    
          // erase the pages
          internalFlash.erase((void*)flashAddress, updateSize);
    
          uint8_t buffer[512];
    
          // write the pages
          for (uint32_t i = 0; i < updateSize; i += 512) {
            // Start reading from after the SPIFU section
            if(externalFlash.readByteArray(SPIFLASH_LOCATION_FIRMWARE + SPIFU_SIZE + i, buffer, 512)) {
              internalFlash.write((void*)flashAddress, buffer, 512);
            } else if(externalFlash.readByteArray(SPIFLASH_LOCATION_FIRMWARE + SPIFU_SIZE + i, buffer, 512)) {
              // Try once more
              internalFlash.write((void*)flashAddress, buffer, 512);
            }
    
            flashAddress += 512;
          }
    
          updateFlashed = true;
  
          digitalWrite(LED_BUILTIN, LOW);
          delay(200);
          digitalWrite(LED_BUILTIN, HIGH);
          delay(200);
          digitalWrite(LED_BUILTIN, LOW);
          delay(200);
          digitalWrite(LED_BUILTIN, HIGH);
          delay(200);
        }
      }
      // Reset flag so that we don't perform the update again
      spiFlashConfig.writeNewFirmwareMagic = 0xFFFFFF;
      spiFlashConfig.newFirmwareSize = 0;
      externalFlash.eraseSector(SPIFLASH_LOCATION_CONFIG); // Erases one 4k sector
      externalFlash.writeAnything(SPIFLASH_LOCATION_CONFIG, spiFlashConfig);
    }
  }

  digitalWrite(LED_BUILTIN, LOW);

  // jump to the sketch
  __set_MSP(*SKETCH_START);

  //Reset vector table address
  SCB->VTOR = ((uint32_t)(SKETCH_START) & SCB_VTOR_TBLOFF_Msk);

  // address of Reset_Handler is written by the linker at the beginning of the .text section (see linker script)
  uint32_t resetHandlerAddress = (uint32_t) * (SKETCH_START + 1);
  // jump to reset handler
  asm("bx %0"::"r"(resetHandlerAddress));
}
