# Inception

## Docker Commands

In some systems the docker daemon starts automatically. To start it manually use: ```sudo systemctl start docker```

| Action | Command |
| -- | -- |
| Build image from Dockerfile | ```docker build [{-f \| --file} <name>.Dockerfile] <path_context>``` |
| List images | ```docker image ls```|
| Inspect image | ```docker inspect <id>``` |
| See run history | ```docker history``` |

## Dockerfile

Docker builds images by reading the instructions from a Dockerfile. A Dockerfile is a text file containing instructions for building your source code. Dockerfiles are crucial inputs for image builds and can facilitate automated, multi-layer image builds based on your unique configurations. 

| Instruction | Description |
| ----------- | ----------- |
| ``` FROM <image> ``` | Defines a **base for your image**. |
| ``` RUN <command> ``` | Executes any commands in a new layer on top of the current image and commits the result. RUN also has a shell form for running commands. Use  ``` RUN --mount=type=bind ``` if you need to **add files from the build context to the container temporarily** to execute a RUN instruction. |
| ``` WORKDIR <directory> ``` | **Sets the working directory** for any RUN, CMD, ENTRYPOINT, COPY, and ADD instructions that follow it in the Dockerfile. If the WORKDIR **doesn't exist, it will be created** even if it's not used in any subsequent Dockerfile instruction. |
| ``` COPY <src> <dest> ``` | Copies **new files or directories** from \<src> and adds them to the filesystem of the container at the path \<dest>. |
| ``` ADD <src> <dest> ``` | Copies new files, directories or remote file URLs from \<src> and adds them to the filesystem of the image at the path \<dest>. Note: better use ``` COPY ``` to copy files and directories and **only use ``` ADD ``` to access remote file URLS** -do not use a tool such as wget or tar- |
| ``` CMD <command> ``` | Lets you define the default program that is run once you start the container based on this image. **Each Dockerfile only has one CMD, and only the last CMD instance is respected when multiple exist**. |

## Docker Compose

Docker Compose is a tool for defining and running multi-container applications. It is the key to unlocking a streamlined and efficient development and deployment experience.

Compose simplifies the control of your entire application stack, making it easy to manage services, networks, and volumes in a single, comprehensible YAML configuration file. Then, with a single command, you create and start all the services from your configuration file.

The default path for a Compose file is **compose.yaml** (preferred) or compose.yml that is placed in the working directory. Compose also supports docker-compose.yaml and docker-compose.yml for backwards compatibility of earlier versions. If both files exist, Compose prefers the canonical compose.yaml.

## URLs

* [Docker glossary](https://docs.docker.com/glossary/#base-image)
* [Dockerfile reference](https://docs.docker.com/engine/reference/builder/)  
* [Introduction to Dockerfile](https://docs.docker.com/build/building/packaging/)  
* [ADD or COPY](https://docs.docker.com/develop/develop-images/instructions/#add-or-copy)  
* [RUN --mount](https://docs.docker.com/engine/reference/builder/#run---mount)  
* [Hello docker-compose.yaml](https://docs.docker.com/compose/gettingstarted/)
* [docker build showing commands output](https://stackoverflow.com/questions/64804749/why-is-docker-build-not-showing-any-output-from-commands/64805337#64805337)
