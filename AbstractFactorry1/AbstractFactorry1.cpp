#include <iostream>
#include <locale.h>

// абстрактные продукты
struct PostCard { // открытки
    virtual void create() = 0;
};

struct Present { // подарки
    virtual void create() = 0;
};

struct Cake { // торт
    virtual void create() = 0;
};


// новогодние открытки
struct NYCard : PostCard {
    void create() {
        std::cout << "Открытка на Новый Год создана" << std::endl;
    }
};

// открытки на день рождения
struct BDCard : PostCard {
    void create() {
        std::cout << "Открытка на День Рождения создана" << std::endl;
    }
};

// открытки на 8 марта
struct WomenDayCard : PostCard {
    void create() {
        std::cout << "Открытка на 8 марта создана" << std::endl;
    }
};

// новогодние подарки
struct NYPresent : Present {
    void create() {
        std::cout << "Подарок на Новый Год готов" << std::endl;
    }
};

// подарки на день рождения
struct BDPresent : Present {
    void create() {
        std::cout << "Подарок на День Рождения готов" << std::endl;
    }
};

// подарки на 8 марта
struct WomenDayPresent : Present {
    void create() {
        std::cout << "Подарок на 8 марта готов" << std::endl;
    }
};

// торт на новый год
struct NYCake : Cake {
    void create() {
        std::cout << "Новогодний торт готов" << std::endl;
    }
};

// торт на день рождения
struct BDCake : Cake {
    void create() {
        std::cout << "Торт на День Рождения готов" << std::endl;
    }
};

// абстрактная фабрика
struct AbstractFactory {
    virtual PostCard* createPostCard() = 0;
    virtual Present* createPresent() = 0;
    virtual Cake* createCake() = 0;
};

// фабрика для создания новогодних продуктов
struct NYFactory : AbstractFactory {

    PostCard* createPostCard() {
        return new NYCard(); // новогодняя открытка
    }

    Present* createPresent() {
        return new NYPresent(); // новогодний подарок
    }

    Cake* createCake() {
        return new NYCake(); // новогодний торт
    }
};

// фабрика для создания продуктов на день рождения
struct BDFactory : AbstractFactory {

    PostCard* createPostCard() {
        return new BDCard(); // открытка на ДР
    }

    Present* createPresent() {
        return new BDPresent(); // подарок на ДР 
    }

    Cake* createCake() {
        return new BDCake(); // торт на ДР
    }
};

// фабрика для создания продуктов на 8 марта
struct WomenDayFactory : AbstractFactory {

    PostCard* createPostCard() {
        return new WomenDayCard(); // открытка на 8 марта
    }

    Present* createPresent() {
        return new WomenDayPresent(); // подарок на 8 марта
    }

    Cake* createCake() {
        return nullptr; // на 8 марта нет торта
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    // новогодние продуктов
    AbstractFactory* nyFactory = new NYFactory();
    PostCard* nyCard = nyFactory->createPostCard();
    Present* nyPresent = nyFactory->createPresent();
    Cake* nyCake = nyFactory->createCake();

    nyCard->create();
    nyPresent->create();
    if (nyCake) nyCake->create();

    // продуктов на день рождения
    AbstractFactory* bdFactory = new BDFactory();
    PostCard* bdCard = bdFactory->createPostCard();
    Present* bdPresent = bdFactory->createPresent();
    Cake* bdCake = bdFactory->createCake();

    bdCard->create();
    bdPresent->create();
    if (bdCake) bdCake->create();

    // продукты на 8 марта
    AbstractFactory* womenDayFactory = new WomenDayFactory();
    PostCard* womenDayCard = womenDayFactory->createPostCard();
    Present* womenDayPresent = womenDayFactory->createPresent();
    Cake* womenDayCake = womenDayFactory->createCake();

    womenDayCard->create();
    womenDayPresent->create();
    if (womenDayCake) womenDayCake->create();

    delete nyFactory; delete nyCard; delete nyPresent; delete nyCake;

    delete bdFactory; delete bdCard; delete bdPresent; delete bdCake;

    delete womenDayFactory; delete womenDayCard; delete womenDayPresent; delete womenDayCake;

    return 0;
}




