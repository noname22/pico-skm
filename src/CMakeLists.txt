add_executable(${target_name}
        main.c
        )

target_compile_definitions(${target_name} PRIVATE SKM_PIO_USB_PIN_DP=${PIO_USB_PIN_DP})

# dependencies
target_link_libraries(${target_name} pico_stdlib pico_multicore pico_pio_usb)

# create map/bin/hex file etc.
pico_add_extra_outputs(${target_name})

pico_enable_stdio_usb(${target_name} 1) 

# print memory usage, enable all warnings
target_link_options(${target_name} PRIVATE -Xlinker --print-memory-usage)
target_compile_options(${target_name} PRIVATE -Wall -Wextra)