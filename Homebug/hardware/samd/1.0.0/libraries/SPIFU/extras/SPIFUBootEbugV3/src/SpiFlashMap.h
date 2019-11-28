// This struct defines the locations and sizes of data objects stored in the SPI Flash chip.

// Never remove any elements from this struct. Only add new ones to the bottom.
// Also never re-order this struct.

// The assumption is that this struct will be located at the start of the flash, ie address 0
// The firmware image will most likely be located at adress 20'000, aka 256kB, 2mbit

// The flash can only be written after it has been erased. The smallest possible erasable blocks are 4k.
// Therefore always allign structs to a 4k block.

#define SPIFLASH_LOCATION_CONFIG   0x0
#define SPIFLASH_LOCATION_FIRMWARE 0x40000
#define FIRMWARE_MAX_SIZE          0x40000

// SPI Flash Updater
#define SPIFU_START    0x2000 // UF2 bootloader: The bootloader sits at 0x00000000, and the application starts at 0x00002000 (SAMD21) or 0x00004000 (SAMD51).
#define SPIFU_SIZE     0x4000
#define SKETCH_START   (uint32_t*)(SPIFU_START + SPIFU_SIZE)


#define SPIFLASH_LOCATION_CONFIG_FIELD(x) (SPIFLASH_LOCATION_CONFIG + offsetof(struct SpiFlashConfig, x))

struct SpiFlashConfig
{
  bool writeNewFirmware;
  char newFirmwareMD5[33];
  size_t newFirmwareStartAddress;
  size_t newFirmwareSize;
};


