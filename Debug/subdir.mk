################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Board.c \
../ButtonHALExample.c \
../ButtonHALFactory.c \
../FiniteStateMachine.c \
../LOGHALExample.c \
../LOGHALFactory.c \
../StateOFF.c \
../StateON.c \
../StatePROTECTED.c \
../TimerHALFactory.c \
../TimerHAlExample.c \
../main.c 

OBJS += \
./Board.o \
./ButtonHALExample.o \
./ButtonHALFactory.o \
./FiniteStateMachine.o \
./LOGHALExample.o \
./LOGHALFactory.o \
./StateOFF.o \
./StateON.o \
./StatePROTECTED.o \
./TimerHALFactory.o \
./TimerHAlExample.o \
./main.o 

C_DEPS += \
./Board.d \
./ButtonHALExample.d \
./ButtonHALFactory.d \
./FiniteStateMachine.d \
./LOGHALExample.d \
./LOGHALFactory.d \
./StateOFF.d \
./StateON.d \
./StatePROTECTED.d \
./TimerHALFactory.d \
./TimerHAlExample.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


