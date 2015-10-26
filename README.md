# Minimal boot

A little project to learn how to boot in an `i386` system. It started as a
kernel project but I don't know if I'll have the time to complete it.

Right now it contains the booting code and basic VGA output.

I'd want to port it to rust, and see how it evolves, we'll see how it goes :P

## Requirements

You need to have an i386 cross-compiler to compile and link the project, and
I'd recommend you to have qemu installed to test it.

To run it you need to use:

```
$ make run-i386
```
