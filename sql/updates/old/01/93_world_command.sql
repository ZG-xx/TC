DELETE FROM `command` WHERE `name` IN ('trans item mana','trans item agi','trans item str','trans item stam');
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('trans item mana', 2, 'Syntax: .trans item mana \nДает итем сет на ману для конкретного класса.'),
('trans item agi', 2, 'Syntax: .credits \nВывщдит количество кредитов имеющиеся у игрока.'),
('trans item str', 2, 'Syntax: .credits \nВывщдит количество кредитов имеющиеся у игрока.'),
('trans item stam', 2, 'Syntax: .credits \nВывщдит количество кредитов имеющиеся у игрока.');
