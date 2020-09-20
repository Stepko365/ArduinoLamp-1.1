﻿# ArduinoLamp 

Это облегченная версия прошивки AlexGyver под ардуино.
(Оригинал здесь: ![Исходная версия](https://github.com/AlexGyver/GyverLamp/))

Обновления от:https://github.com/Norovl/GyverLamp_for_Arduino

## Краткое описание:

Лампа на адресных светодиодах, позволяющих получить красивые эффекты свечения:

Из оригинала было убрано:
- 	будильник;
- 	работа с Wi-Fi (у ардуинки его нет);

Что добавлено: ОООчень много эффектов, хотите посмотрите,
-	демо включается или выключается четырехкратным нажатием кнопки;      
- 	сохранение настроек всех эффектов, в т.ч. текущего режима в энергонезависимой
	памяти.	Производится пятикратным нажатием кнопки, подтверждением будет
	выключение и включение лампы;
- 	регулирование скорости (speed) эффектов путем двойного нажатия и удержания
	кнопки на втором нажатии;
- 	регулирование масштаба (scale) эффектов путем тройного нажатия и удержания 
	кнопки на третьем нажатии;
- 	индикация уровня яркости/скорости/масштаба вертикальной полосой	оранжевого/
	зеленого/синего цветов соответственно;

Регулировка уровня яркости/скорости/масштаба реверсивная, т.е. при повторном
регулировании изменения будут производиться в обратную сторону (сначала в бОльшую,
затем в мЕньшую).

Для работы всех режимов кнопки ОБЯЗАТЕЛЬНО нужно заменить у себя папку GyverButtonOld
на аналогичную с этого сайта. Совместимость с оригиналом сохранилась.
