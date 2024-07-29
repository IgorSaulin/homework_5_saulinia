#include <iostream>
#include <string>
#include <cassert>

class Car
{
private:
    std::string Mark;      //Марка автомобиля.
    int Number_cylinders; //Число цилиндров.
    int Power;            //Мощность двигателя.

public:
    static inline unsigned counter_Car{};
    static inline unsigned counter_Lorry{};
    Car (std::string mark, int number_cylinders, int power) //Конструктор с параметром.
    {
        assert (number_cylinders >= 0); //Число цилиндров и мощность не могут быть < 0.
        assert (power >= 0);            //Мощность не может быть < 0.

        this->Mark = mark;
        this->Number_cylinders = number_cylinders;
        this->Power = power;

        ++counter_Car; //Счетчик количества экзепляров

    }
    Car() //Конструктор по умолчанию.
    {
       Mark="No name";
       Number_cylinders=0;
       Power=0;

       ++counter_Car; //Счетчик количества экземпляров
    }

    ~Car()  //Деструктор (выводит информацию об удалении объектов).
    {
        std::cout<<"Object: "<<Mark<<" delete"<<std::endl;
    }

    /*Объявление геттеров и сеттеров для всех членов класса*/
    std::string getMark () {return Mark;}
    void setMark(std::string Value_Mark) {Mark=Value_Mark;}

    int getNumber_cylinders () {return Number_cylinders;}
    void setNumber_cylinders (int Value_Number_cylinders) {Number_cylinders=Value_Number_cylinders;}

    int getPower () {return Power;}
    void setPower (int Value_Power) {Power=Value_Power;}

    void print() //Функция (метод), необходимая для вывода информации в консоль (В рамках задания не требуетя!!!).
    {
        std::cout<<"Marks: "<<Mark<<", Number cylinders: "<<Number_cylinders<<", Power: "<<Power<<std::endl;
    }

    friend void Number_of_class(Car &car)
    {
        std::cout<<"Number of created Car: "<<counter_Car<<std::endl;
        std::cout<<"Number of created Lorry: "<<counter_Lorry<<std::endl;
    }

    Car &operator = (const Car & car) //Перегрузка опкратора присваивания
    {
        Mark = car.Mark;
        Number_cylinders = car.Number_cylinders;
        Power = car.Power;

        return *this;   // возвращаем ссылку на текущий объект
    }


};

class Lorry: public Car
{
private:
    int Load_capacity;

public:
    Lorry(std::string mark, int number_cylinders, int power, int load_capacity): Car(mark, number_cylinders, power)
    {
        this->Load_capacity = load_capacity;

        ++counter_Lorry;
        --counter_Car;
        
    }
    Lorry() //Конструктор по умолчанию.
    {
       Load_capacity=0;

       ++counter_Lorry;
       --counter_Car;
    }

    Lorry (int load_capacity) //Конструктор с параметром.
    {
        assert (load_capacity >= 0); //Число цилиндров и мощность не могут быть < 0.
        Load_capacity=load_capacity;
    }

    /*Объявление геттеров и сеттеров для новых членов класса*/
    int getLoad_capacity () {return Load_capacity;}
    void setLoad_capacity (int Value_Load_capacity) {Load_capacity=Value_Load_capacity;}

    Lorry &operator = (const Lorry & lorry) //Перегрузка операторов присваивания.
    {
        Car::operator=(lorry);

        Load_capacity = lorry.Load_capacity;

        return *this;   // возвращаем ссылку на текущий объект
    }

};

/*Перегрузка операторов ввода и вывода информации*/
std::ostream& operator << (std::ostream &os, Car &car)
{
    return os <<"Marks: "<< car.getMark() << ", Number cylinders: " \
     << car.getNumber_cylinders()<<", Power: "<<car.getPower()<<std::endl;
}

std::ostream& operator << (std::ostream &os, Lorry &lorry) //Переопределения оператора вывода информации
{
    return os <<"Marks: "<< lorry.getMark() << ", Number cylinders: " \
     << lorry.getNumber_cylinders()<<", Power: "<<lorry.getPower()<<", Load capacity: " \
     <<lorry.getLoad_capacity()<<std::endl;
}

std::istream& operator >> (std::istream& in, Car &car)
{
    std::string mark;
    int number_cylinders;
    int power;

    in >> mark >> number_cylinders >> power;

    car.setMark(mark);
    car.setNumber_cylinders(number_cylinders);
    car.setPower(power);
    
    return in;
}

std::istream& operator >> (std::istream& in, Lorry &lorry)
{
    std::string mark;
    int number_cylinders;
    int power;
    int load_capacity;

    in >> mark >> number_cylinders >> power >> load_capacity;

    lorry.setMark(mark);
    lorry.setNumber_cylinders(number_cylinders);
    lorry.setPower(power);
    lorry.setLoad_capacity(load_capacity);
    
    return in;
}

int main()
{
    //Экзмепляр класса Car
    Car Audio {"Audio", 25, 25};
    Audio.setNumber_cylinders(50); //Присвоение информации используя метод сет.

    //Экземпляр класса Car с конструктором по умолчанию
    Car BMW;

    //Экзмепляр класса Lorry
    Lorry Sprinter {"Sprinter", 50, 50, 50};
    Sprinter.setNumber_cylinders(250);

    std::cout<<"---Output information about created object (use fun. print)---"<<std::endl;
    Audio.print();
    BMW.print();
    Sprinter.print();

    std::cout<<"---Output information about created object (use get methods)---"<<std::endl;
    std::cout<<Audio.getMark()<<std::endl; //Вывод информации используя метод гет.
    std::cout<<Sprinter.getMark()<<std::endl; //Вывод информации используя метод гет.

    std::cout<<"---Output information about created object (use overloaded func.)---"<<std::endl;
    std::cout<<Audio<<std::endl;
    std::cout<<Sprinter<<std::endl;

    std::cout<<"---Input information about creating object (use overloaded func.)---"<<std::endl;
    Car logan {"", 0, 0};
    std::cout << "Car object. Input mark, number cylinders, power: ";
    std::cin >> logan;
    std::cout <<logan<<std::endl;

    Lorry Kamaz {"", 0, 0, 0};
    std::cout << "Lorry object. Input mark, number cylinders, power, load capacity: ";
    std::cin >> Kamaz;
    std::cout <<Kamaz<<std::endl;

    std::cout<<"---Assignments logan to Megan (use overloaded func.)---"<<std::endl;
    Car Megan {"", 0, 0};
    Megan=logan;
    std::cout <<Megan<<std::endl;

    std::cout<<"---Assignments Kamaz to GAZ (use overloaded func.)---"<<std::endl;
    Lorry GAZ {"", 0, 0, 0};
    GAZ=Kamaz;
    std::cout <<GAZ<<std::endl; 

    std::cout<<"---Output information about all created object: car and lorry (use get methods)---" \
    <<std::endl;
    Number_of_class(GAZ);
}