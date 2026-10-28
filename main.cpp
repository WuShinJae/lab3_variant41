#include <iostream>
#include <cmath>
using namespace std;

// Завдання 1.1: If15. Дано три числа. Знайти суму двох найбільших з них.
void task_if15();
// Завдання 1.2: If26. Для заданого дійсного x знайти значення функції f(x).
void task_if26();
// Завдання 2: Geom9. Чи потрапляє точка (x, y) у фігуру 9 варіанту (світло-зелена).
void task_geom9();

int main() {
    int menu;
    cout << "Task number (1 - If15, 2 - If26, 3 - Geom9): ";
    cin >> menu;
    if (!cin) {                       // перевірка: введено не число
        cout << "Wrong task! (Only 1,2,3)" << endl;
        return 0;
    }
    // перемикання між завданнями
    switch (menu) {
        case 1: task_if15(); break;
        case 2: task_if26(); break;
        case 3: task_geom9(); break;
        default: cout << "Wrong task! (Only 1,2,3)" << endl; // повідомлення про помилку
    }
    return 0;
}

// If15: сума двох найбільших з трьох чисел
void task_if15() {
    double a, b, c;
    cout << "************* If 15 *****************" << endl;
    cout << "Enter three numbers a b c: ";
    cin >> a >> b >> c;
    if (!cin) {                       // перевірка коректності введення
        cout << "Wrong numbers!" << endl;
        return;
    }
    double minimum = a;               // шукаємо найменше з трьох
    if (b < minimum) minimum = b;
    if (c < minimum) minimum = c;
    double sum = a + b + c - minimum; // сума всіх мінус найменше = сума двох найбільших
    cout << "Sum of two largest = " << sum << endl;
}

// If26: f(x) = -x при x <= 0; x при 0 < x < 2; x при x >= 2
void task_if26() {
    double x, f;
    cout << "************* If 26 *****************" << endl;
    cout << "Enter real x: ";
    cin >> x;
    if (!cin) {                       // перевірка коректності введення
        cout << "Wrong real number!" << endl;
        return;
    }
    if (x <= 0)
        f = -x;
    else if (x < 2)
        f = x;
    else
        f = x;
    cout << "f(x) = " << f << endl;
}

// Geom9: квадрат зі стороною a, верхня сторона лежить на осі x,
// центр квадрата і вписаного кола (0, -a/2), радіус кола a/2.
// Світло-зелена область розбита на три прості частини (відносно центра кола):
// 1) повний сектор (чверть кола): зліва вгорі від центра;
// 2) половина сектора (45 градусів): зліва внизу, між горизонталлю і діагоналлю;
// 3) прямокутний трикутний сектор справа: між вертикаллю вгору і діагоналлю.
void task_geom9() {
    double a, x, y;
    cout << "************* Geom 9 *****************" << endl;
    cout << "Enter side of square a: ";
    cin >> a;
    if (!cin || a <= 0) {             // перевірка: сторона має бути додатним числом
        cout << "Wrong side!" << endl;
        return;
    }
    cout << "Enter point x y: ";
    cin >> x >> y;
    if (!cin) {                       // перевірка координат
        cout << "Wrong coordinates!" << endl;
        return;
    }
    double xc = 0, yc = -a / 2, r = a / 2;
    double dx = x - xc, dy = y - yc;  // координати відносно центра кола
    bool inCircle = dx * dx + dy * dy <= r * r;          // всередині кола
    bool fullSector = dx <= 0 && dy >= 0;                // частина 1: повний сектор
    bool halfSector = dx <= 0 && dy < 0 && dy >= dx;     // частина 2: половина сектора
    bool rightPart = dx > 0 && dy >= dx;                 // частина 3: правий трикутний сектор
    if (inCircle && (fullSector || halfSector || rightPart))
        cout << "Point is in the light green area." << endl;
    else
        cout << "Point is NOT in the light green area." << endl;
}
