################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/smartPointer/LearningCPlusPlus.cpp \
../src/smartPointer/Person.cpp \
../src/smartPointer/autoPtr.cpp \
../src/smartPointer/scopedArrayPtr.cpp \
../src/smartPointer/scopedPtr.cpp \
../src/smartPointer/sharedArrayPtr.cpp \
../src/smartPointer/sharedPtr.cpp \
../src/smartPointer/smartDerived.cpp \
../src/smartPointer/weakPtr.cpp 

OBJS += \
./src/smartPointer/LearningCPlusPlus.o \
./src/smartPointer/Person.o \
./src/smartPointer/autoPtr.o \
./src/smartPointer/scopedArrayPtr.o \
./src/smartPointer/scopedPtr.o \
./src/smartPointer/sharedArrayPtr.o \
./src/smartPointer/sharedPtr.o \
./src/smartPointer/smartDerived.o \
./src/smartPointer/weakPtr.o 

CPP_DEPS += \
./src/smartPointer/LearningCPlusPlus.d \
./src/smartPointer/Person.d \
./src/smartPointer/autoPtr.d \
./src/smartPointer/scopedArrayPtr.d \
./src/smartPointer/scopedPtr.d \
./src/smartPointer/sharedArrayPtr.d \
./src/smartPointer/sharedPtr.d \
./src/smartPointer/smartDerived.d \
./src/smartPointer/weakPtr.d 


# Each subdirectory must supply rules for building sources it contributes
src/smartPointer/%.o: ../src/smartPointer/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


