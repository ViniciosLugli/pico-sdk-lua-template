# pico-sdk-template

This template is designed to help you get started quickly with your Raspberry Pi Pico projects using the official Raspberry Pi Pico SDK and Lua programming language suppoort. The template project has a simple example program that prints over USB serial communication the lua used version and a _hello world_ message. Follow the instructions below to set up, build your project, and use picotool for various operations.

## Prerequisites

Before starting, ensure you have the following installed:

-   CMake (version 3.13 or higher)
-   A C/C++ compiler toolchain (like GCC for ARM Cortex processors)
-   The Raspberry Pi Pico SDK (version 1.5.1 or later)
-   Python 3 (required for some SDK tools)
-   picotool (for interacting with the Raspberry Pi Pico)

## Setup Instructions

### Setting Up the SDK

1. **Set Environment Variables**: Make sure the `PICO_SDK_PATH` environment variable is set to the path of your Pico SDK directory. If you haven't already, download the SDK from [Raspberry Pi's GitHub](https://github.com/raspberrypi/pico-sdk) and set the environment variable accordingly. On Unix-based systems, you can add this line to your `.bashrc` or `.zshrc`:

    ```bash
    export PICO_SDK_PATH=/<path-to>/pico-sdk
    ```

2. **Clone the Template**: Clone or use the this template from github repository and update submodules.

    ```bash
    git clone git@github.com:ViniciosLugli/pico-sdk-template.git
    ```

    ```bash
    git submodule update --init --recursive
    ```

3. **Navigate to the Project Directory**: Change into the cloned project's directory:

    ```bash
    cd pico-sdk-template
    ```

4. **Initialize the Project**: Run CMake to generate the necessary build files:

    ```bash
    cmake -Bbuild -H.
    ```

5. **Build the Project**: Compile the project using the generated build files:

    ```bash
    cmake --build build
    ```

### Installing picotool

picotool is a command-line utility for interacting with a Raspberry Pi Pico board, including inspecting and programming the flash memory.

1. **Install picotool**: Follow the instructions on the [picotool GitHub repository](https://github.com/raspberrypi/picotool) to download and install picotool.

2. **Using picotool**: With the Pico connected to your computer (while holding the BOOTSEL button if necessary), you can use picotool commands. For example, to get information about your Pico, use:

    ```bash
    picotool info
    ```

## Flashing to the Pico

After building the project and having picotool installed, you can flash the `.uf2` file to your Raspberry Pi Pico:

1. Connect your Pico to your computer.
2. Run the following command to flash the `.uf2` file to the Pico:

    ```bash
    picotool load -x build/main.uf2 -f
    ```

The Pico will automatically reboot and start running your program.

## Troubleshooting

If you encounter any issues, ensure the following:

-   Your Raspberry Pi Pico SDK is updated and correctly set up.
-   picotool is correctly installed and in your system's PATH.
-   You have the correct permissions to access the Pico when connected to your computer.
-   The paths in your environment variables are correct.

For more help, refer to the [official Raspberry Pi Pico documentation](https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf) and the [picotool GitHub repository](https://github.com/raspberrypi/picotool).
