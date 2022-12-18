################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ISFINALPROJECT.cpp \
../src/curso.cpp \
../src/user.cpp \
../src/utils.cpp 

CPP_DEPS += \
./src/ISFINALPROJECT.d \
./src/curso.d \
./src/user.d \
./src/utils.d 

OBJS += \
./src/ISFINALPROJECT.o \
./src/curso.o \
./src/user.o \
./src/utils.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/ISFINALPROJECT.d ./src/ISFINALPROJECT.o ./src/curso.d ./src/curso.o ./src/user.d ./src/user.o ./src/utils.d ./src/utils.o

.PHONY: clean-src

