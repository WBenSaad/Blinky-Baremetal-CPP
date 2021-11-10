# Blinky-Baremetal-CPP
A simpky Blinky in direct Register Programming


## Usage  
1-Create a Directory where CMake will generate its files  
```
mkdir cmake-build  
cd cmake-build
```  
2-We specify the Toolchain file in the Root Directory and the Type of Configuration we will use (DEBUG)  
```
cmake -G "MinGW Makefiles" -DCMAKE_TOOLCHAIN_FILE=../arm-none-eabi-gcc.cmake.txt -DCMAKE_BUILD_TYPE=Debug ..
```  
3-Build the Application since CMake generated a build system .
```
make
```


