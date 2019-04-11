################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DataLogger.cpp \
../src/LearningUnix.cpp \
../src/learnThread.cpp \
../src/testFockFun.cpp 

OBJS += \
./src/DataLogger.o \
./src/LearningUnix.o \
./src/learnThread.o \
./src/testFockFun.o 

CPP_DEPS += \
./src/DataLogger.d \
./src/LearningUnix.d \
./src/learnThread.d \
./src/testFockFun.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/opt/parametricTest-1.1_0_gf228a2e/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


