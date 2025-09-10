-- --

<div align="center">
    <img src="./resources/badge.png">
</div>

-- --

<div align="center">

![Made with](https://img.shields.io/badge/Made%20with-C++-blue?style=for-the-badge) 
![Compiled with](https://img.shields.io/badge/Compiled%20with-CMake-%236E39BB?style=for-the-badge)
[![Made by](https://img.shields.io/badge/Made%20by-Iwaki-red?style=for-the-badge)](https://github.com/IwakiLeKiwi/)
[![GitHub License](https://img.shields.io/github/license/IwakiLeKiwi/Aria?style=for-the-badge)](https://mit-license.org/)

</div>

<b>Aria</b> is a C++ console application that connects via SSH and uses Docker on your remote server to facilitate the execution of certain processes using custom commands.

## Features

- SSH connection to a remote server.
- Execution of Docker commands on the remote server.
- Utilization of custom commands to simplify operations.

## Setup
To configure and use Aria, follow these steps:

### Code Setup (IDE)

**1.** Clone the repository:

- Open your preferred IDE.
- Clone the Aria repository using the following command in your IDE's terminal:
```bash
git clone https://github.com/IwakiLeKiwi/Aria.git
```

**2.** Modify the Configuration File:

- ename the file ``config.h.in.example`` to ``config.h.in``.
- Open the newly created ``config.h.in`` file and enter your connection credentials for the SSH server.

**3.** Install Required Tools:

- Ensure that you have the Microsoft Visual Studio C++ Build Tools installed on your system. You can install them through the Visual Studio Installer, making sure to include the "Desktop development with C++" workload.
  
**4.** Install vcpkg and Required Libraries:

- Install vcpkg if you haven't already, following the instructions on the <a href="https://github.com/microsoft/vcpkg/">vcpkg GitHub page</a>.
- Run the installation commands:
```bash
.\bootstrap-vcpkg.bat
.\vcpkg.exe integrate install
```
- Install the required libraries:
```bash
.\vcpkg.exe install libssh2
.\vcpkg.exe install nlohmann-json
.\vcpkg.exe install discord-rpc
```

**5.** Compile with CMake:
- Make sure you have CMake installed on your system.
- Compile the project with CMake to generate the executable. You can do this using the following commands in your IDE's terminal:
```bash
cd Aria
mkdir build
cd build
cmake ..
cmake --build .
```
- This will generate the Aria executable, ready to use.

## Author

- [@IwakiLeKiwi](https://www.github.com/IwakiLeKiwi/)


## Licence
Aria is licensed under the [MIT License](./LICENSE).