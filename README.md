# ECE 220 MPs in CMake

ECE 220 ZJUI FA2023

Written by Yao Xinchen, Dec 2023

## Intro

This project is a CMake version of the ECE 220 course at UIUC.

Original ECE 220 MPs are built with Makefile. \
The recommended editor in the course is VSCode.

Built with CMake, this project is hoped to be more easily debugged with CLion. \
Files can be organized in a more reasonable way.

> This project is only used for debugging. \
> You need to copy your code to the original MP folder for submission.
>

## Branches

- `main`: The main branch. \
  My answers to the MPs are in this branch.
- `vacant`: A branch with empty files. \
  You can use this branch to start your own project.

If you do not want to be disturbed by my answers, \
please check out to the `vacant` branch.

```shell
git checkout vacant
```

## Usage

### Terminal

```shell
git clone https://github.com/Yao-Xinchen/ECE220
cd ECE220
mkdir build
cd build
cmake ..
```

### CLion

Open the project in CLion. \
Select a configuration and run. \
Running parameters can be set in `Run/Debug Configurations`.

## Disconnect

To disconnect this project from this repository, \
you can remove the remote origin.
```shell
git remote rm origin
```