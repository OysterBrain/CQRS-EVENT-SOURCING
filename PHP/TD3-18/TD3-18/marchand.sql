-- phpMyAdmin SQL Dump
-- version 4.2.12deb2
-- http://www.phpmyadmin.net
--
-- Client :  localhost
-- Généré le :  Dim 27 Septembre 2015 à 19:33
-- Version du serveur :  5.6.25-0ubuntu0.15.04.1
-- Version de PHP :  5.6.4-4ubuntu6.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de données :  `marchand`
--

-- --------------------------------------------------------

--
-- Structure de la table `client`
--

CREATE TABLE IF NOT EXISTS `client` (
`CLINUM` bigint(20) NOT NULL,
  `CLINOM` varchar(200) NOT NULL,
  `CLIPRE` varchar(20) NOT NULL,
  `CLILOGIN` varchar(20)  NULL,
  `CLIPASS` varchar(50) NULL
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `client`
--

INSERT INTO `client` (`CLINUM`, `CLINOM`, `CLIPRE`, `CLILOGIN`, `CLIPASS`) VALUES
(1, 'Duchemin', 'Kevin', '', ''),
(2, 'Duchemin', 'Kevin', '', ''),
(3, 'Delmas', 'Paul', '', '');

-- --------------------------------------------------------

--
-- Structure de la table `produit`
--

CREATE TABLE IF NOT EXISTS `produit` (
`PRONUM` bigint(20) NOT NULL,
  `PROLIB` varchar(500) NOT NULL,
  `PROPRIXHT` float NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=91 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `produit`
--

INSERT INTO `produit` (`PRONUM`, `PROLIB`, `PROPRIXHT`) VALUES
(1, 'Table 4 pieds', 645),
(2, 'Bureau bois', 250),
(30, 'Table fer', 12),
(31, 'Chaise paille', 45),
(32, 'Fauteil rotin', 45),
(33, 'Ordinateur 17 pouces', 645),
(72, 'Micro-ordinateur 12 pouces', 245);

-- --------------------------------------------------------

--
-- Structure de la table `produit2`
--

CREATE TABLE IF NOT EXISTS `produit2` (
  `pronum` char(4) DEFAULT NULL,
  `prolib` char(50) DEFAULT NULL,
  `proprixht` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Contenu de la table `produit2`
--

INSERT INTO `produit2` (`pronum`, `prolib`, `proprixht`) VALUES
('1', 'Table 4 pieds', 645),
('2', 'Bureau bois', 250),
('30', 'Table fer', 12),
('31', 'Chaise paille', 45),
('32', 'Fauteil rotin', 45),
('33', 'Ordinateur 17 pouces', 645),
('71', 'test', 12),
('72', 'Micro-ordinateur 12 pouces', 245),
('73', 'test', 12),
('74', 'Micro-ordinateur 12 pouces', 245),
('75', 'Micro-ordinateur 12 pouces', 245),
('76', 'Micro-ordinateur 12 pouces', 245),
('77', 'test''#', 12),
('78', 'Micro-ordinateur 12 pouces', 245),
('79', 'Micro-ordinateur 12 pouces', 245),
('80', 'test', 12),
('81', 'test''#', 12),
('82', 'VÃ‰LO', 155),
('83', 'VÃ‰LOj', 155);

--
-- Index pour les tables exportées
--

--
-- Index pour la table `client`
--
ALTER TABLE `client`
 ADD PRIMARY KEY (`CLINUM`);

--
-- Index pour la table `produit`
--
ALTER TABLE `produit`
 ADD PRIMARY KEY (`PRONUM`);

--
-- Index pour la table `produit2`
--
ALTER TABLE `produit2`
 ADD FULLTEXT KEY `test` (`prolib`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `client`
--
ALTER TABLE `client`
MODIFY `CLINUM` bigint(20) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT pour la table `produit`
--
ALTER TABLE `produit`
MODIFY `PRONUM` bigint(20) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=91;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
