Developer documentation This file must describe how a devel-
oper can:
◦ Set up the environment from scratch (prerequisites, configuration files, secrets).
.env
```
DB_NAME=<env_variable_value>
DB_USER=<env_variable_value>
DOMAIN=<env_variable_value>
WP_DEBUG=<env_variable_value>
WP_DEBUG_LOG=<env_variable_value>
WP_TITLE=<env_variable_value>
WP_ADMIN=<env_variable_value>
WP_ADMIN_EMAIL=<env_variable_value>
WP_USER=<env_variable_value>
WP_USER_EMAIL=<env_variable_value>
```
secrets folder:
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

◦ Build and launch the project using the Makefile and Docker Compose.
◦ Use relevant commands to manage the containers and volumes.
◦ Identify where the project data is stored and how it persists