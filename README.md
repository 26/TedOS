![](https://raw.githubusercontent.com/Pancake/VimOS/master/docs/vimos-small.png)

VimOS
=====

![make kernel](https://github.com/Pancake/VimOS/workflows/make%20kernel/badge.svg)

**Please note the operating system is currently non-functional does not have Vim implemented yet.**

Running the OS
==============
The simplest way to run the OS is by using the emulator QEMU. If you haven't already, install QEMU by running the following command:

```
sudo apt-get install qemu-system
```

This command will install the QEMU-system package using Aptitude. Then run `make debug` to build the kernel and launch the emulator.

You can also build the kernel using `make kernel`, which you can then boot using your preferred method.
