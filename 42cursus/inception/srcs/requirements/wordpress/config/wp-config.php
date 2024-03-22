<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/documentation/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'database_name_here' );

/** Database username */
define( 'DB_USER', 'username_here' );

/** Database password */
define( 'DB_PASSWORD', 'password_here' );

/** Database hostname */
define( 'DB_HOST', 'localhost' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         '7!7_`-hhX8F1<wVSa;Ee^8.%1bp8Ei`}d9z-l~ahVMR;+Y)5FCE6 |2-SQ;yLRx0' );
define( 'SECURE_AUTH_KEY',  'pL_pL(Zim=JZ/SAe>?e1)%Q8#2qq_I=Ath>1C;`?G-QCzpC)uoo0Yl:0WO|aFGbb' );
define( 'LOGGED_IN_KEY',    'Kvt9U.62Ed{@i@|L;/h&QSa5k!/hqrK#+MqJ qZB,RtEZ[=LmK1_^=B,_mx|kD6x' );
define( 'NONCE_KEY',        'LzNh+bA+i9KuayZ%-E]B<9`/U:H0.*%,)X@`&qo {1imMcH+RCG(r#yJ_S2]nFwu' );
define( 'AUTH_SALT',        '-H:c|xN&4k1kBS;7g<S-/)V3LnEB0V~~*,_#2S~boztga,LgXk]F:GC.`FKdS&,_' );
define( 'SECURE_AUTH_SALT', '/C6-g(0aps_&$!i}L>&.%&`-/n1TQ2JRUXABjT_^S)iF7+s|K+RH+qBrT/WwWaa!' );
define( 'LOGGED_IN_SALT',   'hml apb:xMC.|D|o=Y|npGm]{bwqED$`*W^[<+Mp*~hp8Ueol3!8(]{,dTxHZMIf' );
define( 'NONCE_SALT',       '9xPaZ1pu_5PKAHbd&EY/<uu3!!A,Rb9*~<>FJIEX9CAH~l)v*yoQp<O(CV-war8f' );

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/documentation/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
