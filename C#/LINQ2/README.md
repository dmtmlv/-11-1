***Разработать консольное приложение для создания последовательностей на основе других последовательностей.***
**Разработать последовательности для хранения данных:**
- **грузовой автомобиль – марка автомобиля, грузоподъемность, дата выпуска, дата капитального ремонта, государственный номер, шифр автопарка;**
- **такси – марка автомобиля, количество посадочных мест, дата выпуска, государственный номер, шифр автопарка;**
- **автопарк – название, адрес размещения, площадь для размещения автомобилей, шифр.**

***Построить запросы:***
- выдать данные из последовательности «грузовой автомобиль» в отсортированном по дате выпуска виде;
- сгруппировать данные в последовательности «такси» по марке автомобиля и по дате выпуска;
- сформировать запрос для подсчета количества такси в автопарке;
- соединить последовательности «грузовой автомобиль» и «автопарк» по полю «шифр» и выдать данные: наименование автопарка, тип автомобиля, государственный номер автомобиля.



**1. Класс ГрузовойАвтомобиль:**
- **Марка (string):** *бренд грузового автомобиля.*
- **Грузоподъемность (int):** *максимальная грузоподъемность грузового автомобиля.*
- **ДатаВыпуска (DateTime):** *дата выпуска грузового автомобиля.*
- **ДатаКапремонта (DateTime):** *дата последнего капитального ремонта грузового автомобиля.*
- **ГосНомер (string):** *государственный номер грузового автомобиля.*
- **ШифрАвтопарка (string):** *шифр автопарка, к которому привязан грузовой автомобиль.*

**2. Класс Такси:**
- **Марка (string):** *бренд такси.*
- **КоличествоМест (int):** *количество пассажирских мест в такси.*
- **ДатаВыпуска (DateTime):** *дата выпуска такси.*
- **ГосНомер (string):** *государственный номер такси.*
- **ШифрАвтопарка (string):** *шифр автопарка, к которому привязано такси.*

**3. Класс Автопарк:**
- **Название (string):** *название автопарка.*
- **Адрес (string):** *адрес местоположения автопарка.*
- **Площадь (int):** *площадь автопарка*
- **Шифр (string):** *уникальный шифр автопарка.*
