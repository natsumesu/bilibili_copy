SET NAMES utf8;

DROP DATABASE IF EXISTS bilibili;
CREATE DATABASE bilibili CHARSET=UTF8;
USE bilibili;


CREATE TABLE IF NOT EXISTS `users` (
  `user_id` int(11) PRIMARY KEY  AUTO_INCREMENT,
  `user_name` varchar(100),
  `user_pwd` varchar(100)
);

CREATE TABLE IF NOT EXISTS `AV4372342` (
  `content` varchar(1000),
  `time` float,
  `color` varchar(20)
);


INSERT INTO `users` VALUES(NULL, '857533953@qq.com', '18815274579');