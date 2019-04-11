################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/namePipe/namePipe.cpp \
../src/namePipe/namePipe1.cpp \
../src/namePipe/namePipe2.cpp 

OBJS += \
./src/namePipe/namePipe.o \
./src/namePipe/namePipe1.o \
./src/namePipe/namePipe2.o 

CPP_DEPS += \
./src/namePipe/namePipe.d \
./src/namePipe/namePipe1.d \
./src/namePipe/namePipe2.d 


# Each subdirectory must supply rules for building sources it contributes
src/namePipe/%.o: ../src/namePipe/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


