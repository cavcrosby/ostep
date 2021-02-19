# initial-xv6

This project is an introduction to kernel hacking. This uses a kernel developed by MIT that is a port of the original Unix (version 6).

I should note the code in this directory are the changes I made to complete the project. Hence, the somewhat more complicated setup.

## How To Run (For Unix Shells)

```sh
    ./setup-project
```

* See below for distro specfic steps to finish setup and to run xv6

### Ubuntu/Ubuntu-Like-Distros

<code>qemu</code> and <code>git</code> should be installed. Should be noted the Ubuntu <code>qemu</code> package is a dummy package, various architectures are supported through the package <code>qemu-system</code>.

The installation notes from 'https://github.com/remzi-arpacidusseau/ostep-projects/blob/master/INSTALL-xv6.md' for xv6 mention using the toolprefix 'i386-elf-' when running make. However I had better success using the toolprefix 'x86_64-linux-gnu-', which is the prebuilt toolchain from the <code>gcc</code> package from Ubuntu repos (I had version '4:9.3.0-1ubuntu2' at the time of running this), so your milage may vary here.

To ensure all of this is in place, run the following (assumes apt is installed):

```sh
    sudo apt install qemu-system git gcc --assume-yes
```

To build and run:

```sh
    make TOOLPREFIX=x86_64-linux-gnu- qemu-nox
```
