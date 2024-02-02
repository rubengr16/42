# Inception

## Dockerfile


| Instruction | Description |
| ----------- | ----------- |
| ``` FROM <image> ``` | Defines a base for your image |
| ``` RUN <command> ``` | Executes any commands in a new layer on top of the current image and commits the result. RUN also has a shell form for running commands. Use  ``` RUN --mount=type=bind ``` if you need to **add files from the build context to the container temporarily** to execute a RUN instruction |
| ``` WORKDIR <directory> ``` | Sets the working directory for any RUN, CMD, ENTRYPOINT, COPY, and ADD instructions that follow it in the Dockerfile.  |
| ``` COPY <src> <dest> ``` | Copies **new files or directories** from \<src> and adds them to the filesystem of the container at the path \<dest>. |
| ``` ADD <src> <dest> ``` | Copies new files, directories or remote file URLs from \<src> and adds them to the filesystem of the image at the path \<dest>. Note: better use ``` COPY ``` to copy files and directories and **only use ``` ADD ``` to access remote file URLS** -do not use a tool such as wget or tar- |
| ``` CMD <command> ``` | Lets you define the default program that is run once you start the container based on this image. Each Dockerfile only has one CMD, and only the last CMD instance is respected when multiple exist. |

## URLs

* [Dockerfile reference](https://docs.docker.com/engine/reference/builder/)  
* [Introduction to Dockerfile](https://docs.docker.com/build/building/packaging/)  
* [ADD or COPY](https://docs.docker.com/develop/develop-images/instructions/#add-or-copy)  
* [RUN --mount](https://docs.docker.com/engine/reference/builder/#run---mount)
