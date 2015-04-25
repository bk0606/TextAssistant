# TextAssistant

###Функциональные требования
F1. Обучить языковую модель на заданном корпусе. Корпус представлен папкой с текстовыми файлами. Аргументы этой функции:<br>	
--src-texts <путь к корпусу, обязательный аргумент><br>
--text-encoding <кодировка-текста в файлах корпуса><br>
-n <n-грамность><br>
--laplace // при наличии этого аргумента использовать сглаживание по Лапласу<br>
--good-turing // при наличии этого аргумента использовать сглаживание по Гуд-Тьюрингу (это опционально, за бонусы, см. ниже)<br>
// если ни один вид сглаживания не указан, сглаживать частоты не нужно<br>
--unknown-word-freq <частота, ниже которой слова в обуч. множестве считаются неизвестными><br>
-o <путь-куда-сохранить-сериализованную-языковую-модель, обязательный аргумент>.<br>
<br>
F2. Восстановить порядок слов в предложении. Аргументы:<br>
--lm <путь-к-сериализованной языковой-модели><br>
<список-токенов-разделенных-пробелом><br>
Вывод: восстановленное предложение.<br>
<br>
F3. Показать наиболее вероятные слова в местах предложения, обозначенных пропуском. Пропуск во входном предложении может быть несколько. <br>Аргументы:<br>
--lm <путь-к-сериализованной языковой-модели><br>
--guess-num <количество комбинаций слов, которые можно подставить в пропуски><br>
<предложение в виде токенов разделенных пробелом, пропуск обозначается спец. строкой <SKIP> ><br>
Вывод программы: упорядоченные по вероятности варианты восстановленного предложения, т.е., где вместо <SKIP> подставлены предсказанные слова.<br>
Пример входа:<br>
--guess-num=2 “Серию статей об <SKIP> я начал с <SKIP>”.<br>
Тогда, пример выхода:<br>
Серию статей об <UNK> я начал с негатива.<br>
Серию статей об излучении я начал с введения.<br>
<br>
F4. Генерация случайного предложения. Аргументы:<br>
--lm <путь-к-сериализованной языковой-модели><br>
На выходе: предложение.<br>
<br>
F5. [Опционально] Реализовать подсчет perplexity на заданном корпусе. Аргументы:<br>
--lm <путь-к-сериализованной языковой-модели><br>
<путь-к-тестовой-коллекции>.<br>
Выход: значение perplexity.<br>

### Зависимости от библиотек
 + MySql
 + boost.RegExp
 + libmysqlc++
 + mysqlclient++
 + mysqlcppconn++
 + libmysqlcppconn-dev

> В cmake уже прописано их подключение, надо только на комп установить. <br>
> Да, и надо свои конфиги подкл. к БД прописать в main.cpp

