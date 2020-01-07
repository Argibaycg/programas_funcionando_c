################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/arrayEmployees.c \
../src/functions.c \
../src/informes.c \
../src/programa.c \
../src/trabajoPracticoDos.c \
../src/utn_gets.c 

OBJS += \
./src/arrayEmployees.o \
./src/functions.o \
./src/informes.o \
./src/programa.o \
./src/trabajoPracticoDos.o \
./src/utn_gets.o 

C_DEPS += \
./src/arrayEmployees.d \
./src/functions.d \
./src/informes.d \
./src/programa.d \
./src/trabajoPracticoDos.d \
./src/utn_gets.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


