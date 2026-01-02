This project has been created as part of the 42 curriculum by rgallego.

# Inception - Developer Documentation

## Table of Contents

- [Project Setup](#project-setup)
- [`.env`](#env)
- [`secrets/` folder](#secrets-folder)
- [Build and execution with Makefile and Docker Compose](#build-and-execution-with-makefile-and-docker-compose)
- [Volumes and persistence](#volumes-and-persistence)
- [Relevant commands](#relevant-commands)

## Project Setup

The project needs to be set in a VM or any other host with sudo access
-in this case a VM is needed-.

A shared folder can be used to
use all the Docker infraestructure created and to be copied the 
`vm-setup/copy.sh` script can be used to manage the correct
permissions. Previously,
[docker must be installed](https://docs.docker.com/engine/install/ubuntu/),
the command `sudo usermod -aG docker $USER` adds the current user
to docker group to run docker without privileges and the same command
but with `vboxsf` to access without sudo the shared folder files.

Once the configuration files, [Dockerfiles](https://docs.docker.com/reference/dockerfile/)
and [docker compose files](https://docs.docker.com/reference/compose-file/)
are in the VM we need to create some files under `srcs/` folder which
are `.env` and secrets files:

### `.env`

Needs to configure the following environment variables:

| variable | meaning |
| - | - |
|`DB_NAME=<env_variable_value>` | Name of the DB used by wordpress |
|`DB_USER=<env_variable_value>` | User used by wordpress |
|`DOMAIN=<env_variable_value>` | Domain of the wordpress site, the login aka `rgallego.42.fr` in this case |
|`WP_DEBUG=<env_variable_value>` | \[Optional\] Variable to set debugging in wordpress |
|`WP_DEBUG_LOG=<env_variable_value>` | \[Optional\] Variable to set debugging in wordpress |
|`WP_TITLE=<env_variable_value>` | Title shown in the tab of the wordpress site |
|`WP_ADMIN=<env_variable_value>` | Wordpress admin's username |
|`WP_ADMIN_EMAIL=<env_variable_value>` | Wordpress admin's email|
|`WP_USER=<env_variable_value>` | Wordpress user's username |
|`WP_USER_EMAIL=<env_variable_value>` | Wordpress user's email |

### `secrets/` folder

The next files need to be created with their values:
- db_root_password.txt
- db_user_password.txt
- wp_admin_password.txt
- wp_user_password.txt
- wp_auth_key.txt
- wp_auth_salt.txt
- wp_logged_in_key.txt
- wp_logged_in_salt.txt
- wp_nonce_key.txt
- wp_nonce_salt.txt
- wp_secure_auth_key.txt
- wp_secure_auth_salt.txt

## Build and execution with Makefile and Docker Compose

| command | purpose | translation |
| - | - | - |
| `make` / `make all` / `make up` | Raise the containers, they need to be build previously | `docker compose -f srcs/docker-compose.yml up -d` |
| `make up detachless` | Same as the previous command but whithout the detachless mode, all logs will be seen in the console | `docker compose -f srcs/docker-compose.yml up` |
| `make down` | Turns down all containers and networks | `docker compose -f srcs/docker-compose.yml down` |
| `make exec` | Executes a interactive `sh` console in the given service -`S=<service>` or `SERVICE=<service>`, defaults to mariadb- | `docker compose -f srcs/docker-compose.yml exec -it <service> sh` |
| `make ps` | See the state of running the services. With `PS_A=1` shows also the state of finished containers. | `docker compose -f srcs/docker-compose.yml ps` |
| `make fclean` | Does `clean` | - |
| `make logs` | Shows the docker logs of the services specified by `S` or `SERVICE` -defaults to mariadb- and with the `F` or `LOGFILE` variable shows the logs of the service inside the container | `docker compose -f srcs/docker-compose.yml logs <service>` / `docker compose -f srcs/docker-compose.yml exec <service> cat <logfile>` |
| `make fclean` | Does `build` and deletes the volumes of mariadb and wordpress | - |
| `make fclean` | Does `clean` | - |
| `make re` | Does `fclean`, `build` and `all` | - |

## Volumes and persistence

There are 2 volumes one for mariadb and one for wordpress shared with
NGINX.

The first one maps `/data` which is an alias for the symlink
`/var/lib/mysql` and is stored on the host on `/home/<login>/data/mariadb` where login is `rgallego`.

And `/var/www/html` mapped in the host in `/home/<login>/data/html`.

This assures that after each docker compose down and up, the DB and
wordpress information is the same and it is not lost. If you want to
start with a wordpress and/or db from scratch just delete both folders.

### Relevant commands
Among the commands and their translations stated on
[Build and execution with Makefile and Docker Compose](#build-and-execution-with-makefile-and-docker-compose),
there are a few other docker commands which can be used to manage the volumes such as:
- [`docker volume CMD`](https://docs.docker.com/reference/cli/docker/volume/): where CMD can be
`create`, `inspect` -get detailed information-, `ls`, `prune` -remove unused local volumes-, `rm`
and `update` -only for cluster volumes-
- [`docker inspect [OPTIONS] NAME|ID [NAME|ID...]`](https://docs.docker.com/reference/cli/docker/inspect/):
provides detailed information on constructs controlled by Docker, by default, docker inspect
will render results in a JSON array.