################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Arduino/hardware/arduino/avr/cores/arduino/WInterrupts.c \
D:/Arduino/hardware/arduino/avr/cores/arduino/hooks.c \
D:/Arduino/hardware/arduino/avr/cores/arduino/wiring.c \
D:/Arduino/hardware/arduino/avr/cores/arduino/wiring_analog.c \
D:/Arduino/hardware/arduino/avr/cores/arduino/wiring_digital.c \
D:/Arduino/hardware/arduino/avr/cores/arduino/wiring_pulse.c \
D:/Arduino/hardware/arduino/avr/cores/arduino/wiring_shift.c 

CPP_SRCS += \
D:/Arduino/hardware/arduino/avr/cores/arduino/CDC.cpp \
D:/Arduino/hardware/arduino/avr/cores/arduino/HardwareSerial.cpp \
D:/Arduino/hardware/arduino/avr/cores/arduino/HardwareSerial0.cpp \
D:/Arduino/hardware/arduino/avr/cores/arduino/HardwareSerial1.cpp \
D:/Arduino/hardware/arduino/avr/cores/arduino/HardwareSerial2.cpp \
D:/Arduino/hardware/arduino/avr/cores/arduino/HardwareSerial3.cpp \
D:/Arduino/hardware/arduino/avr/cores/arduino/IPAddress.cpp \
D:/Arduino/hardware/arduino/avr/cores/arduino/PluggableUSB.cpp \
D:/Arduino/hardware/arduino/avr/cores/arduino/Print.cpp \
D:/Arduino/hardware/arduino/avr/cores/arduino/Stream.cpp \
D:/Arduino/hardware/arduino/avr/cores/arduino/Tone.cpp \
D:/Arduino/hardware/arduino/avr/cores/arduino/USBCore.cpp \
D:/Arduino/hardware/arduino/avr/cores/arduino/WMath.cpp \
D:/Arduino/hardware/arduino/avr/cores/arduino/WString.cpp \
D:/Arduino/hardware/arduino/avr/cores/arduino/abi.cpp \
D:/Arduino/hardware/arduino/avr/cores/arduino/main.cpp \
D:/Arduino/hardware/arduino/avr/cores/arduino/new.cpp 

S_UPPER_SRCS += \
D:/Arduino/hardware/arduino/avr/cores/arduino/wiring_pulse.S 

C_DEPS += \
./arduino/WInterrupts.d \
./arduino/hooks.d \
./arduino/wiring.d \
./arduino/wiring_analog.d \
./arduino/wiring_digital.d \
./arduino/wiring_pulse.d \
./arduino/wiring_shift.d 

OBJS += \
./arduino/CDC.o \
./arduino/HardwareSerial.o \
./arduino/HardwareSerial0.o \
./arduino/HardwareSerial1.o \
./arduino/HardwareSerial2.o \
./arduino/HardwareSerial3.o \
./arduino/IPAddress.o \
./arduino/PluggableUSB.o \
./arduino/Print.o \
./arduino/Stream.o \
./arduino/Tone.o \
./arduino/USBCore.o \
./arduino/WInterrupts.o \
./arduino/WMath.o \
./arduino/WString.o \
./arduino/abi.o \
./arduino/hooks.o \
./arduino/main.o \
./arduino/new.o \
./arduino/wiring.o \
./arduino/wiring_analog.o \
./arduino/wiring_digital.o \
./arduino/wiring_pulse.o \
./arduino/wiring_shift.o 

S_UPPER_DEPS += \
./arduino/wiring_pulse.d 

CPP_DEPS += \
./arduino/CDC.d \
./arduino/HardwareSerial.d \
./arduino/HardwareSerial0.d \
./arduino/HardwareSerial1.d \
./arduino/HardwareSerial2.d \
./arduino/HardwareSerial3.d \
./arduino/IPAddress.d \
./arduino/PluggableUSB.d \
./arduino/Print.d \
./arduino/Stream.d \
./arduino/Tone.d \
./arduino/USBCore.d \
./arduino/WMath.d \
./arduino/WString.d \
./arduino/abi.d \
./arduino/main.d \
./arduino/new.d 


# Each subdirectory must supply rules for building sources it contributes
arduino/CDC.o: D:/Arduino/hardware/arduino/avr/cores/arduino/CDC.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/HardwareSerial.o: D:/Arduino/hardware/arduino/avr/cores/arduino/HardwareSerial.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/HardwareSerial0.o: D:/Arduino/hardware/arduino/avr/cores/arduino/HardwareSerial0.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/HardwareSerial1.o: D:/Arduino/hardware/arduino/avr/cores/arduino/HardwareSerial1.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/HardwareSerial2.o: D:/Arduino/hardware/arduino/avr/cores/arduino/HardwareSerial2.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/HardwareSerial3.o: D:/Arduino/hardware/arduino/avr/cores/arduino/HardwareSerial3.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/IPAddress.o: D:/Arduino/hardware/arduino/avr/cores/arduino/IPAddress.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/PluggableUSB.o: D:/Arduino/hardware/arduino/avr/cores/arduino/PluggableUSB.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/Print.o: D:/Arduino/hardware/arduino/avr/cores/arduino/Print.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/Stream.o: D:/Arduino/hardware/arduino/avr/cores/arduino/Stream.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/Tone.o: D:/Arduino/hardware/arduino/avr/cores/arduino/Tone.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/USBCore.o: D:/Arduino/hardware/arduino/avr/cores/arduino/USBCore.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/WInterrupts.o: D:/Arduino/hardware/arduino/avr/cores/arduino/WInterrupts.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/WMath.o: D:/Arduino/hardware/arduino/avr/cores/arduino/WMath.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/WString.o: D:/Arduino/hardware/arduino/avr/cores/arduino/WString.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/abi.o: D:/Arduino/hardware/arduino/avr/cores/arduino/abi.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/hooks.o: D:/Arduino/hardware/arduino/avr/cores/arduino/hooks.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/main.o: D:/Arduino/hardware/arduino/avr/cores/arduino/main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/new.o: D:/Arduino/hardware/arduino/avr/cores/arduino/new.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring.o: D:/Arduino/hardware/arduino/avr/cores/arduino/wiring.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring_analog.o: D:/Arduino/hardware/arduino/avr/cores/arduino/wiring_analog.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring_digital.o: D:/Arduino/hardware/arduino/avr/cores/arduino/wiring_digital.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring_pulse.o: D:/Arduino/hardware/arduino/avr/cores/arduino/wiring_pulse.S
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Assembler'
	avr-gcc -x assembler-with-cpp -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring_pulse.o: D:/Arduino/hardware/arduino/avr/cores/arduino/wiring_pulse.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring_shift.o: D:/Arduino/hardware/arduino/avr/cores/arduino/wiring_shift.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Users\admin\eclipse-workspace\freeRTOS\Source\include" -I"D:\Arduino\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


