# so_long


![image](https://user-images.githubusercontent.com/83474704/200579677-8c0abce9-e508-4238-b982-62b774a27d8e.png)
#### Проект so_long - это реализация примитивного игрового 2D движка

-------------------------------
### Установка зависимостей и компиляция (Linux only)
```bash
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
sudo ./mlx_linux/configure
make
```
Можно ничего не устанавливать, а сразу скачать скомпилированный бинарник под linux **->** [so_long](https://github.com/onorridg/so_long/releases/tag/v1) 
### Запуск
Вторым аргументом должна передаваться карта. Карты лежат в папке `maps`
```bash
 ./so_long maps/map1.ber
```
