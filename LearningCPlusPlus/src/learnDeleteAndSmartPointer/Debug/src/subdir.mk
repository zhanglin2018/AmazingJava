################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LearningCPlusPlus.cpp \
../src/Person.cpp \
../src/TestDelete.cpp \
../src/autoPtr.cpp \
../src/scopedArrayPtr.cpp \
../src/scopedPtr.cpp \
../src/sharedArrayPtr.cpp \
../src/sharedPtr.cpp \
../src/smartDerived.cpp \
../src/weakPtr.cpp 

OBJS += \
./src/LearningCPlusPlus.o \
./src/Person.o \
./src/TestDelete.o \
./src/autoPtr.o \
./src/scopedArrayPtr.o \
./src/scopedPtr.o \
./src/sharedArrayPtr.o \
./src/sharedPtr.o \
./src/smartDerived.o \
./src/weakPtr.o 

CPP_DEPS += \
./src/LearningCPlusPlus.d \
./src/Person.d \
./src/TestDelete.d \
./src/autoPtr.d \
./src/scopedArrayPtr.d \
./src/scopedPtr.d \
./src/sharedArrayPtr.d \
./src/sharedPtr.d \
./src/smartDerived.d \
./src/weakPtr.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


