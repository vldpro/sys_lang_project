# sys_lang_project

Структура виртуальной машины:

  - Контекстный стек ( реализован как связный список ) - хранит структуры типа vm_context_t,
    в которых содержится информация, необходимая для описания контекста исполнения функции.
    
  - Массив функций - массив загруженных из бинарного файла функций.
  
  - Пул констант - массив константных строк.
  
  
    
Контекст исполнения (vm_context_t):

  - Стек вычислений ( обертка над массивом ) - предназначен для передачи операндов командам
    и для приема результатов вычислений команд или функций. Выделяется свой для каждой функции.
    
  - Стек данных ( обертка над массивом ) - предназначен для хранения результатов вычислений.
    Выделяяется свой для каждой функции.
  
  - Счетчик команд
  
  - Указатель на исполняемую функцию
  
  - Указатель на предыдущий контекст исполнения
  
  
Функция (function_t):

  - name ID - смещение в констатном пуле. Указывает на то, где хранится имя функции.
  
  - Кол-во аргументов
  
  - Кол-во загруженных команд
  
  - Команды - массив байтов. Содержит коды команд.