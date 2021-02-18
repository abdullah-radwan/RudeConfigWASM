# RudeConfigWASM
RudeConfig is a library that allows applications to (painlessly) read, modify, and create config / .ini files. 

RudeConfigWASM is a port of the RudeConfig library to Microsoft Flight Simulator WASM, so MSFS WASM module can use it.

## Installation
Go to releases and download the latest release. The release has 2 files: the header file to include in your module, and the library file.

To build against the library, move the library file to the same folder as your WASM file, open the project property pages window in Visual Studio, and go to Linker -> Input. 
At the Additional Dependencies option, add "RudeConfigWASM.a;" before "%(AdditionalDependencies)". If you haven't added anything, it should be like this: "RudeConfigWASM.a;%(AdditionalDependencies)".

## Build
Simply open the Visual Studio solution and build. The compiled file (RudeConfigWASM.a) will be in "Build\Debug" or "Build\Release" folder, based on the configuration.

## About
The library is based on the RudeConfig library, to enable Microsoft Flight Simulator WASM modules to have a configuration file.
Copyright © 2005 Matthew Flood, RudeConfig library
Copyright © 2021 Abdullah Radwan, RudeConfig library WASM port