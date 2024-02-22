

### Структура предприятия - [Company.cs](https://github.com/dmtmlv/-11-1/blob/main/C%23/LAB2/Company.cs)
- исключение: PremiyaException  для отрицательного значения параметра 'Премия'
- исключене: OkladException возникает при попытке добавить сотрудника с отрицательным окладом


### Структура банка - [Bank.cs](https://github.com/dmtmlv/-11-1/blob/main/C%23/LAB2/Bank.cs)
- исключение: KolichestvoException для отрицательного значения параметра "Количество месяцев"
- исключение: VkladException для отрицательной суммы вклада

### Структура автоматизированного банкомата - [automated_ATM.cs](https://github.com/dmtmlv/-11-1/blob/main/C%23/LAB2/automated_ATM.cs)



- Структура банка:
- исключение: OstatokNaSchetException возникает при попытке создать счет с некорректным значением остатка на счете
- исключение: SnyatSoSchetaException возникает при попытке снять средства со счета, если сумма отрицательная или больше баланса счета
