add_executable(${target_name}
        main.c
        )

target_compile_definitions(${target_name} PRIVATE SKM_PIO_USB_PIN_DP=${PIO_USB_PIN_DP})

# dependencies
target_compile_options(${target_name} PRIVATE -DPICO_STDIO_USB_ENABLE_RESET_VIA_VENDOR_INTERFACE=0)
target_link_libraries(${target_name} pico_stdlib pico_multicore pico_pio_usb)

# create map/bin/hex file etc.
pico_add_extra_outputs(${target_name})

pico_enable_stdio_usb(${target_name} 1) 
pico_enable_stdio_uart(${target_name} 1) 

# print memory usage, enable all warnings
target_link_options(${target_name} PRIVATE -Xlinker --print-memory-usage)
target_compile_options(${target_name} PRIVATE -Wall -Wextra)