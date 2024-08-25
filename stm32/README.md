## STM32 - unHALtered  
The purpose of this repo is to document the progress I have made with STM32 and to house general notes for future reference
I am running specifically on the STM32F030x8 series and doing everything Register Level (besides a few HAL_Delays for debugging) 

### STM32 without Cube
1. Generate code/toolchain for the target ucontroller you wish
2. Can modify in whatever IDE of your choice
3. Build by going to Debug/ or Release and running `make`
4. Convert the .elf file into a bin file: `arm-none-eabi-objcopy -O binary timer_interrupt.elf timer_interrupt.bin`
5. Flash using st-tools: `/usr/bin/st-flash write timer_interrupt.bin 0x08000000`

### Examples
- [X] `led_on_off_toggle`: Toggling off LED
- [X] `button_led`: Using a button to toggle and LED
- [X] `tim_int`: Using a timer interrupt to toggle an LED at different freqs
- [X] `uart_register_level`: Using the built in USART communication stack for FTDI comms
- [ ] `uart_bitbanging`: Bitbanging UART to simulate the USART communication stack  
