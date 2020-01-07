################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/LinkedList.c \
../src/Parser.c \
../src/Revelados.c \
../src/main.c \
../src/utn.c 

OBJS += \
./src/LinkedList.o \
./src/Parser.o \
./src/Revelados.o \
./src/main.o \
./src/utn.o 

C_DEPS += \
./src/LinkedList.d \
./src/Parser.d \
./src/Revelados.d \
./src/main.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


