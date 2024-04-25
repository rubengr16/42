# Inception

## Table of Contents
* [Docker commands](#docker-commands)
* [Dockerfile](#dockerfile)
* [Docker Compose](#docker-compose)
* [Docker Compose commands](#docker-compose-commands)
* [Docker Compose file](#docker-compose-file)
* [NGINX](#nginx)
* [Resources](#resources)

## Docker commands

In some systems the docker daemon starts automatically. To start it manually use: ```sudo systemctl start docker```

| Command | Action |
| -- | -- |
| ```docker build [{-f \| --file} <name>.Dockerfile] <path_context> [-t <image_name>]``` | Build image from Dockerfile. |
| ```docker run [-it] [-p host_port:container_port] <image_id> [<command>]``` | Run the chosen image -downloads it if is not present in the system- and optionally executes the chosen command. You can interact through terminal with ```-it``` flags. By using the ```{-p \[Dockerfile](#dockerfile)| --publish}``` flags you can set the port bindings and expose ports from the container -it is recommended to read ```EXPOSE``` on [Dockerfile](#dockerfile)-. |
| ```docker exec [-it] <container_id> <command>``` | Run the command inside the specified container. As in ```docker run```, you can interact through terminal with ```-it``` flags. |
| ```docker ps``` | List running docker processes. |
| ```docker image ls``` | List images. |
| ```docker image tag <image_id> <image_repository>[:<tag>]``` | Set the given name to the image with the selected id, tag is optional to indicate the version. |
| ```docker inspect <image_id>``` | Inspect image. |
| ```docker history``` | See run history. |
| ```docker cp <container_id>:<host_file_path> <local_path>``` | Copies the ```<host_file_path>``` from the ```<container_id>``` to the``` <local_path>```, useful to extract container's files into the local host |

## Dockerfile

Docker builds images by reading the instructions from a ```Dockerfile```. A ```Dockerfile``` is a text file containing instructions for building your source code. ```Dockerfile```s are crucial inputs for image builds and can facilitate automated, multi-layer image builds based on your unique configurations. 

| Instruction | Description |
| -- | -- |
| ``` FROM <image> ``` | Defines a **base for your image**. |
| ``` RUN <command> ``` | Executes any commands in a new layer on top of the current image and commits the result. ```RUN``` also has a shell form for running commands. Use  ``` RUN --mount=type=bind ``` if you need to **add files from the build context to the container temporarily** to execute a RUN instruction. Remind to set any default option as the ```Dockerfile``` cannot have human interaction. |
| ``` WORKDIR <directory> ``` | **Sets the working directory** for any ```RUN```, ```CMD```, ```ENTRYPOINT```, ```COPY```, and ```ADD``` instructions that follow it in the Dockerfile. If the ```WORKDIR``` **doesn't exist, it will be created** even if it's not used in any subsequent Dockerfile instruction. |
| ``` COPY <src> <dest> ``` | Copies **new files or directories** from \<src> and adds them to the filesystem of the container at the path \<dest>. |
| ``` ADD <src> <dest> ``` | Copies new files, directories or remote file URLs from \<src> and adds them to the filesystem of the image at the path \<dest>. Note: better use ``` COPY ``` to copy files and directories and **only use ``` ADD ``` to access remote file URLS** -do not use a tool such as wget or tar- |
| ``` CMD <command> ``` | Lets you define the default program that is run once you start the container based on this image. **Each Dockerfile only has one CMD, and only the last CMD instance is respected when multiple exist**. |
| ```EXPOSE <port>``` | The ```EXPOSE``` instruction **informs** Docker that the container listens on the specified network ports at runtime, it just informs, **does not carry out any binding neither expose the ports**. |

## Docker Compose

### Docker Compose commands

| Command | Action |
| -- | -- |
| ```docker compose up [-d]``` | Builds, (re)creates, starts, and attaches to containers for a service. Use ```-d``` for detached mode -run containers in the background-. |
| ```docker compose down``` | Stops containers and removes containers, networks, volumes, and images created by ```up```. Use ```-v``` to remove named volumes declared in the "volumes" section of the Compose file and anonymous volumes attached to containers. |
| ```docker compose run <service> [<command>]``` | Runs a one-time command against a service. |
| ```docker compose stop``` | Stops your services if you have started them with ```docker compose up -d```. |
| ```docker compose ps``` | Lists containers for a Compose project, with current status and exposed ports. |
| ```docker compose config``` | Renders the actual data model to be applied on the Docker Engine. It merges the Compose files set by -f flags, resolves variables in the Compose file, and expands short-notation into the canonical format. |

### Docker Compose file

Docker Compose is a tool for defining and running multi-container applications. It is the key to unlocking a streamlined and efficient development and deployment experience.

Compose simplifies the control of your entire application stack, making it easy to manage services, networks, and volumes in a single, comprehensible YAML configuration file. Then, with a single command, you create and start all the services from your configuration file.

The default path for a Compose file is **```compose.yaml```** (preferred) or ```compose.yml``` that is placed in the working directory. Compose also supports ```docker-compose.yaml``` and ```docker-compose.yml``` for backwards compatibility of earlier versions. If both files exist, Compose prefers the canonical ```compose.yaml```.

#### .env file

An ```.env``` file in Docker Compose is a text file used to define environment variables that should be made available to Docker containers when running ```docker compose up```. This file typically contains key-value pairs of environment variables -values can be optionally single/double quoted-, and it allows you to centralize and manage configuration in one place. The ```.env``` file is useful if you have multiple environment variables you need to store.  

The ```.env``` file is the default method for setting environment variables in your containers. The ```.env``` file should be placed at the root of the project directory next to your ```compose.yaml``` file. In the ```compose.yaml``` use ```${<NAME>}``` where you want to interpoate a variable -```<NAME>``` is he key of the pair, braces are optional-.

**Be cautious about including sensitive data in environment variables**. Consider using [Secrets](https://docs.docker.com/compose/use-secrets/) for managing sensitive information.


#### Networking in Compose

By default Compose sets up a single network for your app. Each container for a service joins the default network and is both reachable by other containers on that network, and discoverable by the service's name.  
Your app's network is given a name based on the ```project_name``` -the network will be called ```<project_name>.default```, which is based on the name of the directory it lives in.  

```
<service>:
	networks:
		- <network_name>
	ports:
		- "<host_port>:<container_port>"

networks:
	[<network_name>:
		[[driver: <driver_name>]
		[driver_opts:
			[<opt1>: "<define_opt1>"]*]]]
```

It is important to note the distinction between ```host_port``` and ```container_port```. Networked service-to-service communication uses the ```container_port```. When ```host_port``` is defined, the service is accessible outside the swarm as well.

![Interaction with ports](./imgs/networking.png)

**Reference containers by name**, not IP, whenever possible. Otherwise you’ll need to constantly update the IP address you use.  

#### Compose for production

Consider defining an additional Compose file, for example ```production.yml```, which specifies production-appropriate configuration. This configuration file only needs to include the changes you want to make from the original Compose file. The additional Compose file is then applied over the original ```compose.yml``` to create a new configuration.  

Once you have a second configuration file, you can use it with the -f option:

```
docker compose -f compose.yml -f production.yml up -d
```

#### Deploying changes
When you make changes to your app code, remember to rebuild your image and recreate your app's containers:

```
docker compose build <modified_container_name>
docker compose up --no-deps -d <modified_container_name>
```
This first command rebuilds the image for ```<modified_container_name>``` and then stops, destroys, and recreates just the ```<modified_container_name>``` service. The --no-deps flag prevents Compose from also recreating any services which ```<modified_container_name>``` depends on.

#### Services top-level elements

A service is an abstract definition of a computing resource within an application which can be scaled or replaced independently from other components. Services are backed by a set of containers, run by the platform according to replication requirements and placement constraints. As services are backed by containers, they are defined by a Docker image and set of runtime arguments. All containers within a service are identically created with these arguments.  

---
##### ```services```
A Compose file must declare a ```services``` top-level element as a map whose keys are string representations of service names, and whose values are service definitions. A service definition contains the configuration that is applied to each service container.  

----
##### ```build```

Also the ```args``` can be set here, those ```args``` will be used later in the ```Dockerfile``` by the ```ARG``` reference.

---
##### ```depends_on```

Expresses startup and shutdown dependencies between services.  

The short syntax receives a list -set by a ```-```- of the needed service's names to be started before the dependent service, on shutdown the dependent service is the first to be removed.  

The long one defines the needed services without a list. Inside each dependency service can be defined fields such as: ```restart``` when set to ```true``` it restarts after an update of the dependency service; ```condition``` which needs to be satisfied, can be chosen from ```service_started``` -equivalent to the short syntax behaviour-, ```service_healthy``` -a dependency needs to be "healthy" before starting the dependent service- or ```service_completed_successfully``` -a dependency is expected to run to successful completion before starting a dependent service-; finally, ```required``` set to ```false``` only warns when the dependency service is not started or available -by default is set to ```true```-.  
```
<service_name>:
	build:
		context: <path_to_dockerfile>
		args:
			<arg_name>: {value | ${env_vble_name}}
```

---



---
##### ```deploy```
Each service defines runtime constraints and requirements to run its containers. The ```deploy``` section groups these constraints and allows the platform to adjust the deployment strategy to best match containers' needs with available resources. If not implemented the ```deploy``` section is ignored and the Compose file is still considered valid.  

## NGINX

## MariaDB

\> mariadb-install-db --no-defaults --skip-test-db --user=mysql 
\> mariadbd-safe --datadir=/data --init-file=/init.sql # Levanta la base de datos en el datadir indicado
init file necesita la ruta ABSOLUTA
Revisar la config en:
/etc/my.cnf.d/mariadb-server.cnf
Comentar el skip-networking y descomentar el bind a la dirección de broadcasting

mariadb --help
Default options are read from the following files in the given order:  
/etc/my.cnf /etc/mysql/my.cnf ~/.my.cnf 

## Wordpress + PHP-fpm

---  

For the configuration 

## Resources

* [Docker glossary](https://docs.docker.com/glossary/)
* [docker build showing "docker build" output](https://stackoverflow.com/questions/64804749/why-is-docker-build-not-showing-any-output-from-commands/64805337#64805337)
* [Docker CLI Reference](https://docs.docker.com/engine/reference/commandline/)
* [Dockerfile reference](https://docs.docker.com/engine/reference/builder/)  
* [Introduction to Dockerfile](https://docs.docker.com/build/building/packaging/)  
* [RUN --mount](https://docs.docker.com/engine/reference/builder/#run---mount)  
* [ADD or COPY](https://docs.docker.com/develop/develop-images/instructions/#add-or-copy)  
* [Hello docker-compose.yaml](https://docs.docker.com/compose/gettingstarted/)  
* [Docker Compose file reference](https://docs.docker.com/compose/compose-file/)
* [args](https://docs.docker.com/compose/compose-file/build/#args)

* [Alpine NGINX installation](https://wiki.alpinelinux.org/wiki/Nginx)
* [NGINX Docs](https://nginx.org/en/docs/)
* [Creating NGINX Plus and NGINX Configuration Files](https://docs.nginx.com/nginx/admin-guide/basic-functionality/managing-configuration-files/#:~:text=By%20default%20the%20file%20is,local%2Fetc%2Fnginx)
* [Nginx SSL Certificate Self-Signed](https://tech.sadaalomma.com/nginx/nginx-ssl-certificate-self-signed/)
* [Certificate Attributes](https://docs.oracle.com/cd/E24191_01/common/tutorials/authz_cert_attributes.html)
* [SSL Country Codes](https://www.ssl.com/country-codes/)
* [Generating a self-signed certificate using OpenSSL](https://www.ibm.com/docs/en/api-connect/2018.x?topic=overview-generating-self-signed-certificate-using-openssl)

* [Alpine MariaDB installation](https://wiki.alpinelinux.org/wiki/MariaDB)
* [Sed options](https://www.gnu.org/software/sed/manual/sed.html#Command_002dLine-Options)
* [Starting and stopping MariDB automatically](https://mariadb.com/kb/en/starting-and-stopping-mariadb-automatically/)
* [mariadb-safe](https://mariadb.com/kb/en/mariadbd-safe/)
* [mysqld_safe](https://mariadb.com/kb/en/mysqld_safe/)
* [mariadbd](https://mariadb.com/kb/en/mariadbd-options/)
* [mariadbd --init_file](https://mariadb.com/kb/en/server-system-variables/#init_file)

* [Alpine WordPress Installation](https://wiki.alpinelinux.org/wiki/WordPress)

THE KEY
* [bootstrap](https://dev.mysql.com/doc/refman/5.7/en/server-options.html#option_mysqld_bootstrap)
* [mariadb-install-db --extra-file](https://man.archlinux.org/man/extra/mariadb/mariadb-install-db.1.en)
* [CREATE USER](https://dev.mysql.com/doc/refman/8.3/en/create-user.html)
* [CREATE DATABASE](https://dev.mysql.com/doc/refman/8.3/en/create-database.html)
* [CREATE ROLE](https://dev.mysql.com/doc/refman/8.0/en/create-role.html)
* [GRANT](https://dev.mysql.com/doc/refman/8.0/en/grant.html)
* [FLUSH](https://dev.mysql.com/doc/refman/8.0/en/flush.html)
* [DROP USER](https://dev.mysql.com/doc/refman/8.0/en/drop-user.html)
* [How to Reset the Root Password](https://dev.mysql.com/doc/refman/8.0/en/resetting-permissions.html)
* [What is the difference between the Bash operators \[\[ vs \[ vs ( vs ((?](https://unix.stackexchange.com/a/306115)

https://test-dockerrr.readthedocs.io/en/latest/userguide/containers/dockervolumes/#mount-a-host-file-as-a-data-volume


* [Alpine WordPress installation](https://wiki.alpinelinux.org/wiki/Apache_with_php-fpm)
* [PHP packages](https://pkgs.alpinelinux.org/packages?name=php83*&branch=v3.19&repo=&arch=&maintainer=)

* [Wordpress download releases](https://wordpress.org/download/releases/)
* [How to install WordPress](https://developer.wordpress.org/advanced-administration/before-install/howto-install/)
* [Editing wp-config.php](https://developer.wordpress.org/advanced-administration/wordpress/wp-config/)
