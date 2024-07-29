cmake_minimum_required(VERSION 3.29) #Минимально требуемая версия CMake
project(
    Homework5
    VERSION 1.0
    DESCRIPTION "Homework5"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17) #Стандарт языка, который будет использоваться
set(CMAKE_CXX_STANDARD_REQUIRED ON)#Указываем, что будет вестись проверка этого стандарта

add_executable(Homework5) #Добавляем целевой объект (программа собирается как иполняемый файл)

set(sources #Указываем из каких исходных файлов собирается целевой объект
    main.cpp    
)

target_sources(Homework5 PRIVATE ${sources})#Указываем, что файл исходного кода относится именно 
#к целевому объекту Homework5. Указывается ссылка через $ на source