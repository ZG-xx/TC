REVOKE ALL PRIVILEGES ON * . * FROM 'triora'@'localhost';

REVOKE ALL PRIVILEGES ON `world` . * FROM 'triora'@'localhost';
REVOKE GRANT OPTION ON `world` . * FROM 'triora'@'localhost';

REVOKE ALL PRIVILEGES ON `characters` . * FROM 'triora'@'localhost';
REVOKE GRANT OPTION ON `characters` . * FROM 'triora'@'localhost';

REVOKE ALL PRIVILEGES ON `auth` . * FROM 'triora'@'localhost';
REVOKE GRANT OPTION ON `auth` . * FROM 'triora'@'localhost';

DROP USER 'triora'@'localhost';

DROP DATABASE IF EXISTS `world`;
DROP DATABASE IF EXISTS `characters`;
DROP DATABASE IF EXISTS `auth`;
